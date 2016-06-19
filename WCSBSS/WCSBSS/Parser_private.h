#pragma once
#include "NodeAST.h"

namespace parser_private
{

template <class TNode, class TRuleNode, class ...TArgs>
void EmplaceAST(TRuleNode *& stackRecord, TArgs&&... args)
{
	stackRecord = new (std::nothrow) TNode(std::forward<TArgs>(args)...);
}

template <class T>
std::unique_ptr<T> Take(T* & stackRecord)
{
	std::unique_ptr<T> ret(stackRecord);
	stackRecord = nullptr;
	return ret;
}

// ������ ����� ���� AST �� ������ ����������.
// ���������� unique_ptr �� ����.
template <class T, class ...TArgs>
std::unique_ptr<T> Make(TArgs&&... args)
{
	return std::unique_ptr<T>(new (std::nothrow) T(std::forward<TArgs>(args)...));
}

// ������ ������ ���������� �� ���� AST, �������� � ���� ������ 2-� ��������.
// ����� �������� ��������� �� ������ � ������ �����, ���������� 1-� ����������.
template <class TTarget, class TItem>
void CreateList(TTarget *& target, TItem *& item)
{
	auto list = Make<TTarget>();
	if (item)
	{
		list->emplace_back(Take(item));
	}
	target = list.release();
};

// ��������� ������ ���������� �� ���� AST, ���������� 2-� ����������,
// ��������� � ���� ������ 3-� ��������.
// ����� �������� ��������� �� ������ � ������ �����, ���������� 1-� ����������.
template <class TTarget, class TItem>
void ConcatList(TTarget *& target, TTarget *& source, TItem *& item)
{
	auto pList = Take(source);
	if (item)
	{
		pList->emplace_back(Take(item));
	}
	target = pList.release();
};

using ExpressionListPtr = ExpressionList*;
using StatementListPtr = StatementList*;

using StatementPtr = IStatementAST*;
using ExpressionPtr = IExpressionAST*;

struct ExpressionListContainer {
	ExpressionListPtr list;
};

}