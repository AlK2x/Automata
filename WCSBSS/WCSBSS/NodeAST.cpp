#include "NodeAST.h"

// Генерирует код константы LLVM.
struct LiteralTypeEvaluator : boost::static_visitor<BaseType>
{
	BaseType operator ()(double const&) const
	{
		return BaseType::Double;
	}

	BaseType operator ()(bool const&) const
	{
		return BaseType::Boolean;
	}

	BaseType operator ()(std::string const&)
	{
		return BaseType::String;
	}

	BaseType operator()(char const&) const
	{
		return BaseType::Char;
	}
};

CBinaryExpressionAST::CBinaryExpressionAST(BinaryOperation op, IExpressionASTUniquePtr && left, IExpressionASTUniquePtr && right)
	:m_left(std::move(left)), m_right(std::move(right)), m_op(op)
{
}

void CBinaryExpressionAST::Accept(IExpressionVisitor & visitor)
{
	visitor.Visit(*this);
}

BinaryOperation CBinaryExpressionAST::GetOperation() const
{
	return m_op;
}

IExpressionAST & CBinaryExpressionAST::GetLeft()
{
	return *m_left;
}

IExpressionAST & CBinaryExpressionAST::GetRight()
{
	return *m_right;
}

CLiteralAST::CLiteralAST(Value const& value)
	:m_value(value)
{
}

void CLiteralAST::Accept(IExpressionVisitor &visitor)
{
	visitor.Visit(*this);
}

BaseType CLiteralAST::GetType() const
{
	LiteralTypeEvaluator visitor;
	return m_value.apply_visitor(visitor);
}

CPrintAST::CPrintAST(IExpressionASTUniquePtr && expr)
	:m_expr(std::move(expr))
{
}

const CLiteralAST::Value &CLiteralAST::GetValue() const
{
	return m_value;
}

void CPrintAST::Accept(IStatementVisitor & visitor)
{
	visitor.Visit(*this);
}

IExpressionAST & CPrintAST::GetValue()
{
	return *m_expr;
}

CVariableRefAST::CVariableRefAST(unsigned nameId)
	: m_nameId(nameId)
{
}

unsigned CVariableRefAST::GetNameId() const
{
	return m_nameId;
}

void CVariableRefAST::Accept(IExpressionVisitor & visitor)
{
	visitor.Visit(*this);
}

CIfAST::CIfAST(IExpressionASTUniquePtr && condition,
	StatementList && thenPart,
	StatementList && elsePart)
	:m_condition(std::move(condition)),
	m_thenPart(std::move(thenPart)),
	m_elsePart(std::move(elsePart))
{
}

void CIfAST::Accept(IStatementVisitor & visitor)
{
	visitor.Visit(*this);
}

IExpressionAST & CIfAST::GetCondition() const
{
	return *m_condition;
}

const StatementList & CIfAST::GetThenBody() const
{
	return m_thenPart;
}

const StatementList & CIfAST::GetElseBody() const
{
	return m_elsePart;
}


CFunctionAST::CFunctionAST(unsigned nameId, BaseType returnType, ParameterDeclList && parameters, StatementList && body)
	: m_nameId(nameId)
	, m_parameters(std::move(parameters))
	, m_body(std::move(body))
	, m_returnType(returnType)
{
}

unsigned CFunctionAST::GetNameId() const
{
	return m_nameId;
}

const ParameterDeclList &CFunctionAST::GetParameters() const
{
	return m_parameters;
}

const StatementList &CFunctionAST::GetBody() const
{
	return m_body;
}

BaseType CFunctionAST::GetReturnType() const
{
	return m_returnType;
}

CUnaryExpressionAST::CUnaryExpressionAST(UnaryOperator op, IExpressionASTUniquePtr && expr)
	:m_op(op), m_expr(std::move(expr))
{
}

void CUnaryExpressionAST::Accept(IExpressionVisitor & visitor)
{
	visitor.Visit(*this);
}

UnaryOperator CUnaryExpressionAST::GetOperation() const
{
	return m_op;
}

IExpressionAST & CUnaryExpressionAST::GetOperand()
{
	return *m_expr;
}

CAssignmentAST::CAssignmentAST(IExpressionASTUniquePtr && expr, unsigned nameId)
	:m_expression(std::move(expr)), m_nameId(nameId)
{
}

void CAssignmentAST::Accept(IStatementVisitor & visitor)
{
	visitor.Visit(*this);
}

unsigned CAssignmentAST::GetNameId() const
{
	return m_nameId;
}

IExpressionAST & CAssignmentAST::GetValue()
{
	return *m_expression;
}

CWhileAST::CWhileAST(IExpressionASTUniquePtr && condition, StatementList && body)
	:m_condition(std::move(condition)), m_body(std::move(body))
{
}

void CWhileAST::Accept(IStatementVisitor & visitor)
{
	visitor.Visit(*this);
}

IExpressionAST & CWhileAST::GetCondition() const
{
	return *m_condition;
}

const StatementList & CWhileAST::GetBody() const
{
	return m_body;
}

CProgramAST::CProgramAST()
{
}

void CProgramAST::AddDeclaration(IDeclarationASTUniquePtr && declaration)
{
	if (declaration)
	{
		m_declarations.emplace_back(std::move(declaration));
	}
}

const DeclarationList & CProgramAST::GetDeclarations() const
{
	return m_declarations;
}
	

CCallAST::CCallAST(unsigned nameId, ExpressionList && arguments)
	:m_nameId(nameId), m_arguments(std::move(arguments))
{
}

void CCallAST::Accept(IExpressionVisitor & visitor)
{
	visitor.Visit(*this);
}

unsigned CCallAST::GetFunctionNameId() const
{
	return m_nameId;
}

const ExpressionList &CCallAST::GetArguments() const
{
	return m_arguments;
}

BaseType CAbstractExpressionAST::GetType() const
{
	if (!m_type.is_initialized())
	{
		throw std::logic_error("attempt to get expression type before it was assigned");
	}
	return *m_type;
}

void CAbstractExpressionAST::SetType(BaseType type)
{
	m_type = type;
}

CParameterDeclAST::CParameterDeclAST(unsigned nameId, BaseType type)
	: m_nameId(nameId)
{
	SetType(type);
}

void CParameterDeclAST::Accept(IExpressionVisitor &visitor)
{
	visitor.Visit(*this);
}

const unsigned &CParameterDeclAST::GetName() const
{
	return m_nameId;
}

CReturnAST::CReturnAST(IExpressionASTUniquePtr &&value)
	: m_value(std::move(value))
{
}

IExpressionAST &CReturnAST::GetValue()
{
	return *m_value;
}

void CReturnAST::Accept(IStatementVisitor &visitor)
{
	visitor.Visit(*this);
}

CPositionAccessAST::CPositionAccessAST(IExpressionASTUniquePtr && id, IExpressionASTUniquePtr && position)
	:m_variable(std::move(id)), m_position(std::move(position))
{
}

void CPositionAccessAST::Accept(IExpressionVisitor & visitor)
{
//	visitor.Visit(*this);
}
