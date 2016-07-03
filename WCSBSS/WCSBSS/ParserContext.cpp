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

std::string CParserContext::GetString(unsigned stringId) const
{
	return m_pool.GetString(stringId);
}

void CParserContext::PrintError(const std::string &message)const
{
	std::cout << "  Error: " << message << std::endl;
}

std::unique_ptr<CProgramAST> CParserContext::TakeAwayProgram()
{
	return std::move(m_program);
}

CParserContext::~CParserContext()
{
	std::cout << "~CParserContext" << std::endl;
}

