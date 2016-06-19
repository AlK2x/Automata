#pragma once
#include "NodeAST.h"
#include "StringPool.h"

class CParserContext
{
public:
	CParserContext();
	void Call();

	void AddFunction(IDeclarationASTUniquePtr function);
	unsigned GetIdentifierId(char * identifier);

	const DeclrationList & GetDeclarations() const;

	~CParserContext();

private:
	DeclrationList m_declarations;
	CStringPool m_pool;
};

