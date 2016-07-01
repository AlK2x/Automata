#include <iostream>
#include "Value.h"
#include "wcsbss.tab.h"
#include "wcsbss.flex.h"
#include "ParserContext.h"

using namespace std;

//int yyparse(void * pParser);

int main(int argc, char ** argv)
{
	CParserContext p;
	yyparse(&p);
	auto program = p.TakeAwayProgram();

	for (const auto & pDecl : program->GetDeclarations())
	{

	}

	system("pause");
	return 0;
}
