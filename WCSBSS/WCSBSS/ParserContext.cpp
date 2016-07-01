#include "ParserContext.h"
#include <iostream>


CParserContext::CParserContext()
	:m_program(new CProgramAST)
{
}

void CParserContext::AddFunction(IDeclarationASTUniquePtr function)
{
	m_program->AddDeclaration(std::move(function));
}

unsigned CParserContext::GetIdentifierId(char * identifier)
{
	return m_pool.Insert(identifier);
}

std::unique_ptr<CProgramAST> CParserContext::TakeAwayProgram()
{
	return std::move(m_program);
}

CParserContext::~CParserContext()
{
}

