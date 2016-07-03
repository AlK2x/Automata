#include <iostream>
#include "Value.h"
#include "wcsbss.tab.h"
#include "wcsbss.flex.h"
#include "ParserContext.h"
#include "CodegenVisitor.h"
#include "CompilerBackend.h"

using namespace std;

//int yyparse(void * pParser);

int main(int argc, char ** argv)
{
	CParserContext p;
	int a = yyparse(&p);

	auto program = p.TakeAwayProgram();

	CCodegenContext m_codegenContext(p);
	CCodeGenerator codegen(m_codegenContext);

	for (const auto &pAst : program->GetDeclarations())
	{

		codegen.AcceptMainFunction(*pAst);
	}

	CCompilerBackend backend;
	try
	{
		backend.GenerateObjectFile(m_codegenContext.GetModule(), true, "output.prog");
	}
	catch (const std::exception &ex)
	{
		cout << ex.what() << endl;
		return 1;
	}
	system("pause");
	return 0;
}
