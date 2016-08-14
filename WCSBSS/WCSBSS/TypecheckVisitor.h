#include "ASTVisitor.h"
#include "NodeAST.h"
#include "StringPool.h"
#include "ParserContext.h"

class CFrontendContext;

// Класс рекурсивно расставляет и проверяет типы в подвыражениях данного выражения.
// Для расстановки типов в программе достаточно обработать один раз на каждое выражение.
class CTypeEvaluator : protected IExpressionVisitor
{
public:
	CTypeEvaluator(CParserContext &context, CScopeChain<BaseType> &variableTypesRef,
		CScopeChain<IDeclarationAST*> &functionsRef);

	BaseType EvaluateTypes(IExpressionAST & expr);

	// IExpressionVisitor interface
protected:
	void Visit(CBinaryExpressionAST &expr) override;
	void Visit(CUnaryExpressionAST &expr) override;
	void Visit(CLiteralAST &expr) override;
	void Visit(CCallAST &expr) override;
	void Visit(CVariableRefAST &expr) override;
	void Visit(CParameterDeclAST &expr) override;
	void Visit(CPositionAccessAST &expr) override;

private:
	std::vector<BaseType> EvaluateArgumentTypes(CCallAST &expr);

	CParserContext & m_context;
	CScopeChain<BaseType> &m_variableTypesRef;
	CScopeChain<IDeclarationAST*> &m_functionsRef;
};

class CTypecheckVisitor : protected IStatementVisitor
{
public:
	CTypecheckVisitor(CParserContext & context);

	void RunSemanticPass(CProgramAST &ast);

protected:
	// Расставляет и проверяет типы в выражениях.
	// Проверяет семантические правила в функции:
	//  - наличие объявлений переменных,
	//  - наличие хотя бы одного return в функции.
	void CheckTypes(IDeclarationAST & ast);

	// IStatementVisitor interface
	void Visit(CPrintAST &ast) override;
	void Visit(CAssignmentAST &ast) override;
	void Visit(CReturnAST &ast) override;
	void Visit(CWhileAST &ast) override;
	void Visit(CIfAST &ast) override;
	void CheckConditionalAstTypes(IExpressionAST &condition, const StatementList &body);

private:
	CParserContext & m_context;
	CScopeChain<BaseType> m_variableTypes;
	CScopeChain<IDeclarationAST*> m_functions;
	boost::optional<BaseType> m_returnType;
	CTypeEvaluator m_evaluator;
};
