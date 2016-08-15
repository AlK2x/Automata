#pragma once

class IExpressionAST;
class CBinaryExpressionAST;
class CUnaryExpressionAST;
class CLiteralAST;
class CCallAST;
class CVariableRefAST;
class CParameterDeclAST;
class CPositionAccessAST;

class IExpressionVisitor
{
public:
	virtual ~IExpressionVisitor() = default;
	virtual void Visit(CBinaryExpressionAST & expr) = 0;
	virtual void Visit(CUnaryExpressionAST & expr) = 0;
	virtual void Visit(CLiteralAST & expr) = 0;
	virtual void Visit(CCallAST & expr) = 0;
	virtual void Visit(CVariableRefAST & expr) = 0;
	virtual void Visit(CParameterDeclAST & expr) = 0;
	virtual void Visit(CPositionAccessAST & expr) = 0;
};

class IStatementAST;
class CPrintAST;
class CAssignmentAST;
class CReturnAST;
class CWhileAST;
class CRepeatAst;
class CIfAST;
class CIndexAssignmentAST;

class IStatementVisitor
{
public:
	virtual ~IStatementVisitor() = default;
	virtual void Visit(CPrintAST & ast) = 0;
	virtual void Visit(CAssignmentAST & ast) = 0;
	virtual void Visit(CReturnAST & ast) = 0;
	virtual void Visit(CWhileAST & ast) = 0;
	virtual void Visit(CIfAST & ast) = 0;
	virtual void Visit(CIndexAssignmentAST & ast) = 0;
};
