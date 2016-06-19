#include "ParserContext.h"
#include <iostream>


CParserContext::CParserContext()
{
}

void CParserContext::Call()
{
	std::cout << "Call parser" << std::endl;
}

void CParserContext::AddFunction(IDeclarationASTUniquePtr function)
{
	if (function)
	{
		m_declarations.emplace_back(std::move(function));
	}
}

unsigned CParserContext::GetIdentifierId(char * identifier)
{
	return m_pool.Insert(identifier);
}

const DeclrationList & CParserContext::GetDeclarations() const
{
	return m_declarations;
}

CParserContext::~CParserContext()
{
}

