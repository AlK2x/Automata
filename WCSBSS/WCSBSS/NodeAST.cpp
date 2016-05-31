#include "NodeAST.h"

BinaryExpressionAST::BinaryExpressionAST(BinaryOperator op, IExpressionASTUniquePtr && left, IExpressionASTUniquePtr && right)
	:m_left(std::move(left)), m_right(std::move(right)), m_op(op)
{
}

SValue BinaryExpressionAST::Evaluate() const
{
	SValue a = m_left->Evaluate();
	SValue b = m_right->Evaluate();
	double result;
	switch (m_op)
	{
	case BinaryOperator::Add:
		result = a.value + b.value;
		break;
	case BinaryOperator::Substract:
		std::cout << a.value << " - " << b.value << std::endl;
		result = a.value - b.value;
		break;
	case BinaryOperator::Multiply:
		result = a.value * b.value;
		break;
	case BinaryOperator::Divide:
		result = a.value / b.value;
		break;
	default:
		result = std::numeric_limits<double>::quiet_NaN();
	}

	return{ result };
}

CLiteralAST::CLiteralAST(SValue value)
	:m_value(value)
{
}

SValue CLiteralAST::Evaluate() const
{
	return m_value;
}

CPrintAST::CPrintAST(IExpressionAST * expr)
	:m_expr(expr)
{
}

SValue CPrintAST::Evaluate() const
{
	SValue value = m_expr->Evaluate();
	std::cout << value.value << std::endl;
	return value;
}

CIfAST::CIfAST(IExpressionASTUniquePtr && condition,
	StatementList && thenPart,
	StatementList && elsePart)
	:m_condition(std::move(condition)),
	m_thenPart(std::move(thenPart)),
	m_elsePart(std::move(elsePart))
{
}

SValue CIfAST::Evaluate() const
{
	SValue cond = m_condition->Evaluate();
	if (cond.value)
	{

	}
	else
	{

	}
	return cond;
}
