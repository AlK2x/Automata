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

}