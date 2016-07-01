#pragma once
#include "NodeAST.h"
#include "StringPool.h"

class CParserContext
{
public:
	CParserContext();

	void AddFunction(IDeclarationASTUniquePtr function);
	unsigned GetIdentifierId(char * identifier);

	std::unique_ptr<CProgramAST> TakeAwayProgram();

	~CParserContext();

private:
	std::unique_ptr<CProgramAST> m_program;
	CStringPool m_pool;
};

