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

// —оздаЄт новый узел AST из списка аргументов.
// ¬озвращает unique_ptr на узел.
template <class T, class ...TArgs>
std::unique_ptr<T> Make(TArgs&&... args)
{
	return std::unique_ptr<T>(new (std::nothrow) T(std::forward<TArgs>(args)...));
}

// —оздаЄт список указателей на узлы AST, помещает в этот список 2-й аргумент.
// «атем помещает указатель на список в €чейку стека, переданную 1-м аргументом.
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

// »звлекает список указателей на узлы AST, переданный 2-м аргументом,
// добавл€ет в этот список 3-й аргумент.
// «атем помещает указатель на список в €чейку стека, переданную 1-м аргументом.
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

// ѕеремещает указатель из одной €чейки стека в другую, обнул€€ исходной €чейки.
template <class T>
void MovePointer(T *& stackRecord, T *& targetRecord)
{
	targetRecord = stackRecord;
	stackRecord = nullptr;
}

using ExpressionListPtr = ExpressionList*;
using StatementListPtr = StatementList*;

using StatementPtr = IStatementAST*;
using ExpressionPtr = IExpressionAST*;

struct ExpressionListContainer {
	ExpressionListPtr list;
};

struct StatementListContainer {
	StatementListPtr list;
};

}