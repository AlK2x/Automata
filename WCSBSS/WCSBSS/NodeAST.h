#pragma once
#include "Value.h"
#include <memory>
#include <climits>
#include <iostream>
#include <vector>

class IExpressionAST;

using IExpressionASTUniquePtr = std::unique_ptr<IExpressionAST>;
using IStatementASTUniquePtr = std::unique_ptr<IStatementAST>;
using ExpressionList = std::vector<IExpressionASTUniquePtr>;
using StatementList = std::vector<IStatementASTUniquePtr>;

class IExpressionAST
{
public:
	virtual SValue Evaluate() const = 0;

	virtual ~IExpressionAST() = default;
};

class IStatementAST
{
public:
	virtual void Evaluate() = 0;
	
	virtual ~IStatementAST() = default;
};

enum class BinaryOperator
{
	Less,
	Greateher,
	And,
	Or,
	Not,
	Add,
	Substract,
	Multiply,
	Divide,
	Abs
};

class BinaryExpressionAST : public IExpressionAST
{
public:
	BinaryExpressionAST(BinaryOperator op, IExpressionASTUniquePtr && left, IExpressionASTUniquePtr && right);

	virtual SValue Evaluate() const override;

private:
	BinaryOperator m_op;
	IExpressionASTUniquePtr m_left;
	IExpressionASTUniquePtr m_right;
};

class CLiteralAST : public IExpressionAST
{
public:
	CLiteralAST(SValue value);

	virtual SValue Evaluate() const override;

private:
	SValue m_value;
};

class CPrintAST : public IExpressionAST
{
public:
	CPrintAST(IExpressionAST * expr);

	virtual SValue Evaluate() const override;

private:
	IExpressionAST * m_expr;
};

class CIfAST : public IExpressionAST
{
public:
	CIfAST(IExpressionASTUniquePtr && condition, 
		StatementList && thenPart = StatementList(), 
		StatementList && elsePart = StatementList());

	virtual SValue Evaluate() const override;

private:
	IExpressionASTUniquePtr m_condition;

	StatementList m_thenPart;
	StatementList m_elsePart;
};