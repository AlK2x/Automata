%{
#define YYPARSE_PARAM pParser
  #include "NodeAST.h"
  #include "Value.h"
  #include "Parser_private.h"
  #include "wcsbss.flex.h"
  #include "ParserContext.h"
  //int yyerror(char const *);

  using namespace parser_private;

%}

%code requires {
  #include <stdio.h>
  #include "ParserContext.h"

  /* structs used in the %union declaration would go here */
}

%define api.pure full
%locations
%parse-param { void* pParser }
%lex-param { void* pParser }

%code provides {
   #define YY_DECL \
       int yylex(YYSTYPE* yylvalp, YYLTYPE* yyllocp, void* pParser)
   YY_DECL;

   int yyerror(YYLTYPE* yyllocp, void* pParser, const char* message);
}


%union {
	class IExpressionAST* e;
	class IStatementAST *s;
	class IDeclarationAST *d;
	struct ExpressionListContainer * el;
	double num;
	unsigned nameId;
}

%token <num> NUMBER
%token <nameId> ID
%token IF THEN ELSE WHILE LET FUNCTION
%token PRINT
%token EOL

%type <e> exp
%type <el> expression_list
%type <d> declaration function_declaration

%right '='
%left '+' '-'
%left '*' '/'

%start declaration_list

%%

declaration_list : /* */
	| declaration ';'
	| declaration_list declaration ';'
	;

declaration : exp {
			SValue v = $1->Evaluate(); 
			std::cout << " = " << v.value  << std::endl;
		}
;

declaration : function_declaration {
			((CParserContext *) pParser)->AddFunction(Take($1));
		}
;

function_declaration : FUNCTION '(' ')' '{' expression_list '}' {
				std::cout << "Add function" << std::endl;
				EmplaceAST<CFunctionAst>($$, 42, std::move(*($5->list)));
			}
;

expression_list : /* empty */
		| exp ';' {
				std::cout << "exp" << std::endl;
				CreateList($$->list, $1);
			}
		| expression_list ';' exp {
				std::cout << "expression_list EOL exp" << std::endl;
				ConcatList($$->list, $1->list, $3);
			}
;

exp : exp '+' exp { 
				EmplaceAST<BinaryExpressionAST>($$, BinaryOperator::Add, Take($1), Take($3));
			}
		| exp '-' exp {
				EmplaceAST<BinaryExpressionAST>($$, BinaryOperator::Substract, Take($1), Take($3));
			}
		| exp '*' exp {
				EmplaceAST<BinaryExpressionAST>($$, BinaryOperator::Multiply, Take($1), Take($3));
			}
		| exp '/' exp {
				EmplaceAST<BinaryExpressionAST>($$, BinaryOperator::Divide, Take($1), Take($3));
			}
		| NUMBER {
				EmplaceAST<CLiteralAST>($$, SValue::create($1));
			}
		| ID {
				EmplaceAST<CVariableRefAST>($$, $1);
			}
;

%%

int yyerror (YYLTYPE* yyllocp, void* pParser, const char* message) {
   fprintf (stderr, "%s\n", message);
   return 1;
 }