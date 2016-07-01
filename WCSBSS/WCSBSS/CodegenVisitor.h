#pragma once

#include <stdint.h>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-parameter"
#include <llvm/IR/Value.h>
#include <llvm/IR/IRBuilder.h>
#pragma clang diagnostic pop
#include "ASTVisitor.h"
#include "NodeAST.h"
#include "FrontendContext.h"
#include <boost/optional.hpp>
#include <boost/noncopyable.hpp>
#include <boost/range/adaptor/reversed.hpp>

class CFrontendContext;
class CCodegenContext;
namespace llvm
{
	class AllocaInst;
	class Function;
	class LLVMContext;
	class Module;
	class Constant;
}

enum class BuiltinFunction
{
	PRINTF,
	STRCPY,
	STRDUP,
	STRLEN,
	STRCMP,
	MALLOC,
	FREE,
};

/*
* ������ �������� � ����������� �� ������, �������� ����� �� �������.
* ���� ����������� ����� �� �������, ���� ����� ��������� ��������� �� �������� �����.
* ��� ���� �� ��������� �������� ���������� ������ ������.
*/
class CManagedStrings
{
public:
	CManagedStrings(CCodegenContext &context);
	~CManagedStrings();

	// �������� free() ��� ���� �����.
	void FreeAll(llvm::IRBuilder<> & builder);

	// ���������� ������ ���������� �����.
	void Clear();

	// ���� ������� ����� �� �������, ������� � � �������� � ����������.
	// ����� ��������� ������ � ���������� ��������.
	llvm::Value *TakeStringOrCopy(llvm::IRBuilder<> & builder, llvm::Value *pString);

	// ��������� ������ ��� �������� ������� �����.
	void Manage(llvm::Value *pString);

private:
	CCodegenContext &m_context;
	std::unordered_set<llvm::Value *> m_pointers;
};

// ������� �������� ���������� ��� �������� (���� ����� ����������).
// TSymbol - ���� ������� ��� ��������� � ��������� �������.
template <class TSymbol>
class CScopeChain
{
public:
	using Scope = std::unordered_map<unsigned, TSymbol>;

	void PushScope()
	{
		m_scopes.push_back(Scope());
	}

	void PopScope()
	{
		m_scopes.pop_back();
	}

	bool HasSymbol(unsigned nameId)const
	{
		return GetSymbol(nameId).is_initialized();
	}

	// ���������� �������� ��� ������� � �������� ������.
	boost::optional<TSymbol> GetSymbol(unsigned nameId)const
	{
		for (const Scope &scope : boost::adaptors::reverse(m_scopes))
		{
			auto it = scope.find(nameId);
			if (it != scope.end())
			{
				return it->second;
			}
		}
		return boost::none;
	}

	// ���������� true � ������������� �������� ��� �������, ���� �� ��� ����� ��������.
	// ����� ���������� false.
	bool SetSymbol(unsigned nameId, const TSymbol &value)
	{
		for (Scope &scope : boost::adaptors::reverse(m_scopes))
		{
			auto it = scope.find(nameId);
			if (it != scope.end())
			{
				it->second = value;
				return true;
			}
		}
		return false;
	}

	void DefineSymbol(unsigned nameId, const TSymbol &value)
	{
		m_scopes.back()[nameId] = value;
	}

private:
	std::vector<Scope> m_scopes;
};

class CCodegenContext
{
public:
	CCodegenContext(CFrontendContext &context);
	~CCodegenContext();

	std::string GetString(unsigned stringId)const;
	void PrintError(std::string const& message) const;
	llvm::LLVMContext &GetLLVMContext();
	llvm::Module &GetModule();
	CScopeChain<llvm::AllocaInst*> &GetVariables();
	CScopeChain<llvm::Function*> &GetFunctions();
	std::unordered_map<std::string, llvm::Constant *> GetStrings();
	llvm::Constant *AddStringLiteral(const std::string &value);

	llvm::Function *GetBuiltinFunction(BuiltinFunction id)const;
	CManagedStrings &GetExpressionStrings();
	CManagedStrings &GetFunctionStrings();

private:
	void InitLibCBuiltins();

	CFrontendContext &m_context;
	std::unique_ptr<llvm::LLVMContext> m_pLLVMContext;
	std::unique_ptr<llvm::Module> m_pModule;
	std::map<BuiltinFunction, llvm::Function*> m_builtinFunctions;
	CScopeChain<llvm::AllocaInst*> m_variables;
	CScopeChain<llvm::Function*> m_functions;
	std::unordered_map<std::string, llvm::Constant *> m_strings;
	CManagedStrings m_expressionStrings;
	CManagedStrings m_functionStrings;
};

class CExpressionCodeGenerator : protected IExpressionVisitor
{
public:
	CExpressionCodeGenerator(llvm::IRBuilder<> & builder, CCodegenContext & context);

	// Can throw std::exception.
	llvm::Value *Codegen(IExpressionAST & ast);

protected:
	void Visit(CBinaryExpressionAST &expr) override;
	void Visit(CUnaryExpressionAST &expr) override;
	void Visit(CLiteralAST &expr) override;
	void Visit(CCallAST &expr) override;
	void Visit(CVariableRefAST &expr) override;
	void Visit(CParameterDeclAST & expr) override;

private:
	llvm::Value *GenerateNumericExpr(llvm::Value *a, BinaryOperation op, llvm::Value *b);
	llvm::Value *GenerateStringExpr(llvm::Value *a, BinaryOperation op, llvm::Value *b);
	llvm::Value *GenerateBooleanExpr(llvm::Value *a, BinaryOperation op, llvm::Value *b);
	llvm::Value *GenerateStrcmp(llvm::Value *a, llvm::Value *b);

	// ���� ������������ ��� ���������� ��������
	// �� ���� ������������ ������ ������ ���������.
	std::vector<llvm::Value *> m_values;
	CCodegenContext & m_context;
	llvm::IRBuilder<> & m_builder;
};

class CFunctionCodeGenerator : protected IStatementVisitor
{
public:
	CFunctionCodeGenerator(CCodegenContext & context);

	void Codegen(const ParameterDeclList &parameters, const StatementList &block, llvm::Function & fn);
	void AddExitMain();

	// IStatementVisitor interface
protected:
	void Visit(CPrintAST &ast) override;
	void Visit(CAssignmentAST &ast) override;
	//void Visit(CReturnAST &ast) override;
	void Visit(CWhileAST &ast) override;
	//void Visit(CRepeatAst &ast) override;
	void Visit(CIfAST &ast) override;

private:
	void LoadParameters(llvm::Function &fn, const ParameterDeclList &parameterNames);
	void CodegenLoop(CWhileAST &ast, bool skipFirstCheck);
	void FillBlockAndJump(const StatementList &statements,
		llvm::BasicBlock *block, llvm::BasicBlock *nextBlock);
	llvm::Value *MakeValueCopy(llvm::Value *pValue);
	void FreeExpressionAllocs();
	void FreeFunctionAllocs();
	void RemoveUnusedBlocks(llvm::Function &fn);

	CCodegenContext & m_context;
	llvm::IRBuilder<> m_builder;
	CExpressionCodeGenerator m_exprGen;
};

class CCodeGenerator
{
public:
	CCodeGenerator(CCodegenContext & context);
	llvm::Function *AcceptFunction(IDeclarationAST & ast);
	llvm::Function *AcceptMainFunction(IDeclarationAST & ast);

private:
	llvm::Function *GenerateDeclaration(IDeclarationAST & ast, bool isMain);
	bool GenerateDefinition(llvm::Function &fn, IDeclarationAST & ast, bool isMain);

	CCodegenContext & m_context;
};
