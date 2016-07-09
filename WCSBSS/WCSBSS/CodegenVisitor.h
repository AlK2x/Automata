#pragma once

#include "stdafx.h"
#include "ASTVisitor.h"
#include "NodeAST.h"
#include "FrontendContext.h"
#include "ParserContext.h"

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
* ’ранит регистры с указател€ми на строки, которыми никто не владеет.
* ѕока указател€ми никто не владеет, этот класс позвол€ет управл€ть их временем жизни.
* Ёто один из элементов гарантии отсутстви€ утечек пам€ти.
*/
class CManagedStrings
{
public:
	CManagedStrings(CCodegenContext &context);
	~CManagedStrings();

	// ¬ызывает free() дл€ всех строк.
	void FreeAll(llvm::IRBuilder<> & builder);

	// —брасывает список неудалЄнных строк.
	void Clear();

	// ≈сли строкой никто не владеет, снимает еЄ с контрол€ и возвращает.
	// »наче дублирует строку и возвращает дубликат.
	llvm::Value *TakeStringOrCopy(llvm::IRBuilder<> & builder, llvm::Value *pString);

	// ƒобавл€ет строку под контроль времени жизни.
	void Manage(llvm::Value *pString);

private:
	CCodegenContext &m_context;
	std::unordered_set<llvm::Value *> m_pointers;
};


class CCodegenContext
{
public:
	CCodegenContext(CParserContext &context);
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

	CParserContext &m_context;
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

	// —тек используетс€ дл€ временного хранени€
	// по мере рекурсивного обхода дерева выражени€.
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
	void Visit(CReturnAST &ast) override;
	void Visit(CWhileAST &ast) override;
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
