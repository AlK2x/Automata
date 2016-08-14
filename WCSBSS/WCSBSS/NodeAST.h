#pragma once
#include "stdafx.h"
#include "ASTVisitor.h"

class IExpressionAST;
class IStatementAST;
class IDeclarationAST;
class CParameterDeclAST;

using IExpressionASTUniquePtr = std::unique_ptr<IExpressionAST>;
using IStatementASTUniquePtr = std::unique_ptr<IStatementAST>;
using IDeclarationASTUniquePtr = std::unique_ptr<IDeclarationAST>;
using CParameterDeclASTUniquePtr = std::unique_ptr<CParameterDeclAST>;

using ExpressionList = std::vector<IExpressionASTUniquePtr>;
using StatementList = std::vector<IStatementASTUniquePtr>;
using DeclarationList = std::vector<IDeclarationASTUniquePtr>;
using ParameterDeclList = std::vector<CParameterDeclASTUniquePtr>;


enum class BaseType
{
	Boolean,
	Double,
	String,
	Char
};

enum class BinaryOperation
{
	Less,
	Equal,
	NotEqual,
	And,
	Or,
	Not,
	Add,
	Substract,
	Multiply,
	Divide
};

enum class UnaryOperator
{
	Minus,
	Plus,
	Not
};

class IExpressionAST
{
public:
	virtual void Accept(IExpressionVisitor & visitor) = 0;
	virtual BaseType GetType()const = 0;

	virtual ~IExpressionAST() = default;
};

class IStatementAST
{
public:
	virtual void Accept(IStatementVisitor & visitor) = 0;
	virtual void Test() const { std::cout << "IStatementAST" << std::endl; };

	virtual ~IStatementAST() = default;
};

class IDeclarationAST
{
public:
	virtual unsigned GetNameId()const = 0;
	virtual BaseType GetReturnType()const = 0;
	virtual const ParameterDeclList &GetParameters()const = 0;
	virtual const StatementList &GetBody()const = 0;

	//virtual ~IDeclarationAST() = default;
};


class CAbstractExpressionAST : public IExpressionAST
{
public:
	BaseType GetType()const override;
	void SetType(BaseType type);

private:
	boost::optional<BaseType> m_type;
};

class CParameterDeclAST : public CAbstractExpressionAST
{
public:
	CParameterDeclAST(unsigned nameId, BaseType type);

	void Accept(IExpressionVisitor & visitor) override;
	const unsigned &GetName()const;

private:
	const unsigned m_nameId;
};


class CBinaryExpressionAST : public CAbstractExpressionAST
{
public:
	CBinaryExpressionAST(BinaryOperation op, IExpressionASTUniquePtr && left, IExpressionASTUniquePtr && right);

	virtual void Accept(IExpressionVisitor & visitor) override;

	BinaryOperation GetOperation() const;
	IExpressionAST & GetLeft();
	IExpressionAST & GetRight();

private:
	BinaryOperation m_op;
	IExpressionASTUniquePtr m_left;
	IExpressionASTUniquePtr m_right;
};

class CUnaryExpressionAST : public CAbstractExpressionAST
{
public:
	CUnaryExpressionAST(UnaryOperator op, IExpressionASTUniquePtr && expr);

	virtual void Accept(IExpressionVisitor & visitor) override;
	UnaryOperator GetOperation() const;

	IExpressionAST & GetOperand();
	
private:
	UnaryOperator m_op;
	IExpressionASTUniquePtr m_expr;
};

class CLiteralAST : public CAbstractExpressionAST
{
public:
	typedef boost::variant<
		bool,
		double,
		std::string,
		char
	> Value;

	CLiteralAST(Value const& value);
	void Accept(IExpressionVisitor & visitor) override;
	BaseType GetType()const override;

	const Value &GetValue()const;

private:
	const Value m_value;
};

class CPrintAST : public IStatementAST
{
public:
	CPrintAST(IExpressionASTUniquePtr && expr);

	void Accept(IStatementVisitor & visitor) override;
	void Test() { std::cout << "CPrintAST:TEST" << std::endl; }
	IExpressionAST &GetValue();
	~CPrintAST() {
		std::cout << "diestroy print ast" << std::endl;
	}
private:
	IExpressionASTUniquePtr m_expr;
};

class CVariableRefAST : public CAbstractExpressionAST
{
public:
	CVariableRefAST(unsigned nameId);

	unsigned GetNameId()const;

	virtual void Accept(IExpressionVisitor & visitor) override;
private:
	const unsigned m_nameId;
};

class CIfAST : public IStatementAST
{
public:
	CIfAST(IExpressionASTUniquePtr && condition, 
		StatementList && thenPart = StatementList(), 
		StatementList && elsePart = StatementList());

	virtual void Accept(IStatementVisitor & visitor) override;

	IExpressionAST &GetCondition()const;
	const StatementList &GetThenBody()const;
	const StatementList &GetElseBody()const;

private:
	IExpressionASTUniquePtr m_condition;

	StatementList m_thenPart;
	StatementList m_elsePart;
};

class CFunctionAST : public IDeclarationAST
{
public:
	CFunctionAST(unsigned nameId, BaseType returnType, ParameterDeclList && parameters, StatementList && body);

	unsigned GetNameId()const override;
	const ParameterDeclList &GetParameters()const override;
	const StatementList &GetBody()const override;
	BaseType GetReturnType() const override;

	~CFunctionAST() {
		std::cout << "destroy function" << std::endl;
	}

private:
	unsigned m_nameId;
	ParameterDeclList m_parameters;
	StatementList m_body;
	BaseType m_returnType;
};

class CAssignmentAST : public IStatementAST
{
public:
	CAssignmentAST(IExpressionASTUniquePtr && expr, unsigned nameId);

	virtual void Accept(IStatementVisitor & visitor) override;
	unsigned GetNameId()const;
	IExpressionAST & GetValue();

private:
	unsigned m_nameId;
	IExpressionASTUniquePtr m_expression;
};

class CWhileAST : public IStatementAST
{
public:
	CWhileAST(IExpressionASTUniquePtr && condition, StatementList &&body = StatementList());

	virtual void Accept(IStatementVisitor & visitor) override;

	IExpressionAST &GetCondition()const;
	const StatementList &GetBody()const;

private:
	IExpressionASTUniquePtr m_condition;
	StatementList m_body;
};

class CCallAST : public CAbstractExpressionAST
{
public:
	CCallAST(unsigned nameId, ExpressionList && arguments);

	virtual void Accept(IExpressionVisitor & visitor) override;

	unsigned GetFunctionNameId()const;
	const ExpressionList &GetArguments()const;
private:
	unsigned m_nameId;
	ExpressionList m_arguments;
};

class CProgramAST
{
public:
	CProgramAST();

	void AddDeclaration(IDeclarationASTUniquePtr && declaration);

	const DeclarationList & GetDeclarations() const;

	~CProgramAST() = default;

private:
	DeclarationList m_declarations;
};

class CReturnAST : public IStatementAST
{
public:
	CReturnAST(IExpressionASTUniquePtr && value);

	IExpressionAST &GetValue();

protected:
	void Accept(IStatementVisitor & visitor) override;

private:
	IExpressionASTUniquePtr m_value;
};

class CPositionAccessAST : public CAbstractExpressionAST
{
public:
	CPositionAccessAST(unsigned nameId, IExpressionASTUniquePtr && position);
	void Accept(IExpressionVisitor & visitor) override;
private:
	unsigned m_nameId;
	IExpressionASTUniquePtr m_position;
};
