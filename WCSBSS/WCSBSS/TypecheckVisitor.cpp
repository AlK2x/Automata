#include "TypecheckVisitor.h"
#include "FrontendContext.h"
#include <boost/range/algorithm.hpp>

namespace
{
	std::string PrettyPrint(BaseType type)
	{
		switch (type)
		{
		case BaseType::Boolean:
			return "Boolean";
		case BaseType::Double:
			return "Double";
		case BaseType::String:
			return "String";
		}
		throw std::logic_error("cannot print unknown type name");
	}

	std::string PrettyPrint(BinaryOperation op)
	{
		switch (op)
		{
		case BinaryOperation::Less:
			return "<";
		case BinaryOperation::Equal:
			return "==";
		case BinaryOperation::Add:
			return "+";
		case BinaryOperation::Substract:
			return "-";
		case BinaryOperation::Multiply:
			return "*";
		case BinaryOperation::Divide:
			return "/";
		}
		return "?";
	}

	std::string PrettyPrint(UnaryOperator op)
	{
		switch (op)
		{
		case UnaryOperator::Minus:
			return "-";
		case UnaryOperator::Plus:
			return "+";
		}
		return "?";
	}

	BaseType EvaluateBinaryOperationType(BinaryOperation op, BaseType left, BaseType right)
	{
		auto check = [&](bool condition) {
			if (!condition)
			{
				std::string msg = "Operation " + PrettyPrint(op) + " not allowed for types "
					+ PrettyPrint(left) + " and " + PrettyPrint(right);
				throw std::runtime_error(msg);
			}
		};
		switch (op)
		{
		case BinaryOperation::Less:
		case BinaryOperation::Equal:
			check(left == right);
			return BaseType::Boolean;
		case BinaryOperation::Add:
			check(left == right && left != BaseType::Boolean);
			return left;
		case BinaryOperation::Substract:
		case BinaryOperation::Multiply:
		case BinaryOperation::Divide:
			check(left == right && left == BaseType::Double);
			return BaseType::Double;
		}
		throw std::logic_error("GetBinaryOperationResultType() not implemented for this type");
	}

	BaseType EvaluateUnaryOperationType(UnaryOperator op, BaseType operandType)
	{
		auto check = [&](bool condition) {
			if (!condition)
			{
				std::string msg = "Operation " + PrettyPrint(op) + " not allowed for type "
					+ PrettyPrint(operandType);
				throw std::runtime_error(msg);
			}
		};
		switch (op)
		{
		case UnaryOperator::Minus:
		case UnaryOperator::Plus:
			check(operandType == BaseType::Double);
			return BaseType::Double;
		}
		throw std::logic_error("GetUnaryOperationResultType() not implemented for this type");
	}
}

CTypeEvaluator::CTypeEvaluator(CParserContext &context, CScopeChain<BaseType> &variableTypesRef,
	CScopeChain<IDeclarationAST *> &functionsRef)
	: m_context(context)
	, m_variableTypesRef(variableTypesRef)
	, m_functionsRef(functionsRef)
{
}

BaseType CTypeEvaluator::EvaluateTypes(IExpressionAST &expr)
{
	expr.Accept(*this);
	return expr.GetType();
}

void CTypeEvaluator::Visit(CBinaryExpressionAST &expr)
{
	expr.GetLeft().Accept(*this);
	expr.GetRight().Accept(*this);
	expr.SetType(EvaluateBinaryOperationType(expr.GetOperation(), expr.GetLeft().GetType(), expr.GetRight().GetType()));
}

void CTypeEvaluator::Visit(CUnaryExpressionAST &expr)
{
	expr.GetOperand().Accept(*this);
	expr.SetType(EvaluateUnaryOperationType(expr.GetOperation(), expr.GetOperand().GetType()));
}

void CTypeEvaluator::Visit(CLiteralAST &)
{
	// Constant type is known at parsing time.
}

void CTypeEvaluator::Visit(CCallAST &expr)
{
	const unsigned functionNameId = expr.GetFunctionNameId();
	const auto functionOpt = m_functionsRef.GetSymbol(functionNameId);
	if (!functionOpt)
	{
		std::string fnName = m_context.GetString(functionNameId);
		throw std::logic_error("function " + fnName + " is undefined");
	}
	IDeclarationAST &function = **functionOpt;
	const ParameterDeclList &params = function.GetParameters();
	const ExpressionList &args = expr.GetArguments();
	if (params.size() != args.size())
	{
		std::string fnName = m_context.GetString(functionNameId);
		throw std::logic_error("function " + fnName + " requires " + std::to_string(params.size())
			+ " arguments, while " + std::to_string(args.size()) + " provided");
	}
	std::vector<BaseType> argTypes = EvaluateArgumentTypes(expr);
	for (size_t i = 0; i < argTypes.size(); ++i)
	{
		BaseType expectedType = params.at(i)->GetType();
		if (argTypes.at(i) != params.at(i)->GetType())
		{
			std::string fnName = m_context.GetString(functionNameId);
			throw std::logic_error("function " + fnName + " expects " + PrettyPrint(expectedType)
				+ " in the " + std::to_string(i) + " parameter");
		}
	}
	expr.SetType(function.GetReturnType());
}

void CTypeEvaluator::Visit(CVariableRefAST &expr)
{
	if (auto typeOpt = m_variableTypesRef.GetSymbol(expr.GetNameId()))
	{
		expr.SetType(*typeOpt);
	}
	else
	{
		std::string varName = m_context.GetString(expr.GetNameId());
		throw std::logic_error("used undefined variable " + varName);
	}
}

void CTypeEvaluator::Visit(CParameterDeclAST &)
{
	// Parameter type is known at parsing time.
}

std::vector<BaseType> CTypeEvaluator::EvaluateArgumentTypes(CCallAST &expr)
{
	std::vector<BaseType> argTypes;
	argTypes.reserve(expr.GetArguments().size());
	for (const auto &pExpr : expr.GetArguments())
	{
		pExpr->Accept(*this);
		argTypes.push_back(pExpr->GetType());
	}
	return argTypes;
}

CTypecheckVisitor::CTypecheckVisitor(CParserContext &context)
	: m_context(context)
	, m_evaluator(m_context, m_variableTypes, m_functions)
{
}

void CTypecheckVisitor::RunSemanticPass(CProgramAST &ast)
{
	// TODO: add 'main' function signature checks.
	m_functions.PushScope();
	for (const auto &pFunction : ast.GetDeclarations())
	{
		const unsigned nameId = pFunction->GetNameId();
		if (m_functions.HasSymbol(nameId))
		{
			std::string fnName = m_context.GetString(nameId);
			m_context.PrintError("function " + fnName + " should not be redefined");
		}
		else
		{
			m_functions.DefineSymbol(nameId, pFunction.get());
		}
	}
	for (const auto &pFunction : ast.GetDeclarations())
	{
		CheckTypes(*pFunction);
	}
}

void CTypecheckVisitor::CheckTypes(IDeclarationAST &ast)
{
	m_variableTypes.PushScope();
	m_returnType = ast.GetReturnType();
	for (const auto &pParam : ast.GetParameters())
	{
		m_variableTypes.DefineSymbol(pParam->GetName(), pParam->GetType());
	}
	for (const auto &pStmt : ast.GetBody())
	{
		pStmt->Accept(*this);
	}
	m_variableTypes.PopScope();
}

void CTypecheckVisitor::Visit(CPrintAST &ast)
{
	m_evaluator.EvaluateTypes(ast.GetValue());
}

void CTypecheckVisitor::Visit(CAssignmentAST &ast)
{
	BaseType type = m_evaluator.EvaluateTypes(ast.GetValue());
	unsigned nameId = ast.GetNameId();
	if (auto typeOpt = m_variableTypes.GetSymbol(nameId))
	{
		if (type != *typeOpt)
		{
			std::string varName = m_context.GetString(nameId);
			throw std::logic_error("Cannot reassign variable " + varName + " to different type");
		}
	}
	else
	{
		m_variableTypes.DefineSymbol(nameId, type);
	}
}

void CTypecheckVisitor::Visit(CReturnAST &ast)
{
	BaseType type = m_evaluator.EvaluateTypes(ast.GetValue());
	if (type != *m_returnType)
	{
		std::string typeName = PrettyPrint(type);
		throw std::logic_error("Function cannot return value of type " + typeName);
	}
}

void CTypecheckVisitor::Visit(CWhileAST &ast)
{
	CheckConditionalAstTypes(ast.GetCondition(), ast.GetBody());
}

void CTypecheckVisitor::Visit(CIfAST &ast)
{
	CheckConditionalAstTypes(ast.GetCondition(), ast.GetThenBody());
	for (const auto &pStmt : ast.GetElseBody())
	{
		pStmt->Accept(*this);
	}
}

void CTypecheckVisitor::CheckConditionalAstTypes(IExpressionAST &condition, const StatementList &body)
{
	BaseType type = m_evaluator.EvaluateTypes(condition);
	if (type != BaseType::Boolean)
	{
		throw std::logic_error("Cannot use " + PrettyPrint(type) + " in condition, expected Boolean");
	}
	for (const auto &pStmt : body)
	{
		pStmt->Accept(*this);
	}
}
