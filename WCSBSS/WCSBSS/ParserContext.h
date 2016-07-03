#pragma once
#include "NodeAST.h"
#include "StringPool.h"

class CParserContext
{
public:
	CParserContext();

	void AddFunction(IDeclarationASTUniquePtr function);
	unsigned GetIdentifierId(char * identifier);

	std::string GetString(unsigned stringId)const;
	void PrintError(std::string const& message) const;

	std::unique_ptr<CProgramAST> TakeAwayProgram();

	~CParserContext();

private:
	std::unique_ptr<CProgramAST> m_program;
	CStringPool m_pool;
};

