#include <iostream>
#include "Value.h"
#include "token.h"
#include "wcsbss.tab.h"

using namespace std;

int main(int argc, char ** argv)
{
	SValue::create(10);
	cout << "Oppa" << endl;
	yyparse();
	return 0;
}
