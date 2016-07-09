#include <iostream>
#include "wcsbss.tab.h"
#include "wcsbss.flex.h"
#include "ParserContext.h"
#include "CodegenVisitor.h"
#include "CompilerBackend.h"
#include "TypecheckVisitor.h"

using namespace std;

//int yyparse(void * pParser);

int main(int argc, char ** argv)
{
	try
	{
		CParserContext p;
		int a = yyparse(&p);

		auto program = p.TakeAwayProgram();

		CTypecheckVisitor visitor(p);
		visitor.RunSemanticPass(*program);

		CCodegenContext m_codegenContext(p);
		CCodeGenerator codegen(m_codegenContext);
		unsigned mainId = p.GetIdentifierId("main");
		for (const auto &pAst : program->GetDeclarations())
		{
			if (pAst->GetNameId() == mainId)
			{
				codegen.AcceptMainFunction(*pAst);
			}
			else
			{
				codegen.AcceptFunction(*pAst);
			}
		}

		CCompilerBackend backend;
	
		backend.GenerateObjectFile(m_codegenContext.GetModule(), true, "output.obj");
	}
	catch (const std::exception &ex)
	{
		cout << ex.what() << endl;
		return 1;
	}
	system("pause");
	return 0;
}
