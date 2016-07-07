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
	struct StatementListContainer * sl;
	double num;
	unsigned nameId;
}

%token <nameId> ID
%token <num> NUMBER
%token IF THEN ELSE WHILE LET FUNCTION
%token EQUAL NOTEQUAL
%token PRINT
%token EOL

%type <e> exp
%type <el> expression_list
%type <d> declaration function_declaration
%type <s> statement
%type <sl> statement_list

%right '='
%left '!'
%left '+' '-'
%left '*' '/'
%left '<'

%start declaration_list

%%

declaration_list : EOL { std::cout << "TOP EOL" << std::endl; }
	| declaration { std::cout << "TOP declaration" << std::endl; }
	| declaration_list declaration { std::cout << "TOP declaration_list" << std::endl; }
	| statement_list { std::cout << "TOP statement_list" << std::endl; }
	| expression_list { std::cout << "TOP expression_list" << std::endl; }
;

declaration : function_declaration {
			((CParserContext *) pParser)->AddFunction(Take($1));
		}
;

function_declaration : FUNCTION ID '(' ')' '{' statement_list '}' {
				std::cout << "Add function" << std::endl;
				auto params = Make<ParameterDeclList>().release();
				auto body = $6->list;
				for (const IStatementASTUniquePtr & pAst : (*body))
				{
					if (!pAst)
					{
						std::cout << "CFunctionCodeGenerator::Codegen No body" << std::endl;
					}
					else
					{
						pAst->Test();
					}
		
				}
				EmplaceAST<CFunctionAST>($$, $2, BaseType::Double, std::move(*params), std::move(*body));
			}
;

statement_list : /* empty */
		| statement ';' {
				std::cout << "statement ';'" << std::endl;
				$$ = new StatementListContainer();
				auto b = $1;
				CreateList($$->list, $1);
				for (const IStatementASTUniquePtr & pAst : *($$->list))
				{
					if (!pAst)
					{
						std::cout << "CFunctionCodeGenerator::Codegen No body" << std::endl;
					}
					else
					{
						pAst->Test();
					}
				}
			}
		| statement_list statement ';' {
				std::cout << "statement_list ';' statement" << std::endl;
				ConcatList($$->list, $1->list, $2);
			}
;

statement : ID '=' exp {
				EmplaceAST<CAssignmentAST>($$, Take($3), $1);
				std::cout << "ID: " << $1 << " '=' exp" << std::endl;
			}
		| PRINT exp {
				EmplaceAST<CPrintAST>($$, Take($2));
			}
		| IF '(' exp ')' '{' statement_list '}' {
				std::cout << "IF '(' exp ')' '{' statement_list '}'" << std::endl;
				EmplaceAST<CIfAST>($$, Take($3), std::move(*($6->list)));
			}
		| IF '(' exp ')' '{' statement_list '}' ELSE '{' statement_list '}' {
				std::cout << "IF '(' exp ')' '{' statement_list '}' ELSE '{' statement_list '}'" << std::endl;
				EmplaceAST<CIfAST>($$, Take($3), std::move(*($6->list)), std::move(*($10->list)));
			}
		| WHILE '(' exp ')' '{' statement_list '}' {
				std::cout << "'(' exp ')' '{' statement_list '}'" << std::endl;
				EmplaceAST<CWhileAST>($$, Take($3), std::move(*($6->list)));
			}
;

expression_list : /* empty */
		| exp ';' {
				std::cout << "exp" << std::endl;
				$$ = new ExpressionListContainer();
				auto b = $1;
				CreateList($$->list, $1);
			}
		| expression_list exp ';' {
				std::cout << "expression_list EOL exp" << std::endl;
				ConcatList($$->list, $1->list, $2);
			}
;

exp :	'(' exp ')' {
				MovePointer($2, $$);
			}
		| exp '+' exp { 
				EmplaceAST<CBinaryExpressionAST>($$, BinaryOperation::Add, Take($1), Take($3));
			}
		| exp '-' exp {
				EmplaceAST<CBinaryExpressionAST>($$, BinaryOperation::Substract, Take($1), Take($3));
			}
		| exp '*' exp {
				EmplaceAST<CBinaryExpressionAST>($$, BinaryOperation::Multiply, Take($1), Take($3));
			}
		| exp '/' exp {
				EmplaceAST<CBinaryExpressionAST>($$, BinaryOperation::Divide, Take($1), Take($3));
			}
		| exp '<' exp {
				EmplaceAST<CBinaryExpressionAST>($$, BinaryOperation::Less, Take($1), Take($3));
			}
		| exp EQUAL exp {
				EmplaceAST<CBinaryExpressionAST>($$, BinaryOperation::Equal, Take($1), Take($3));
			}
		| exp NOTEQUAL exp {
				EmplaceAST<CBinaryExpressionAST>($$, BinaryOperation::NotEqual, Take($1), Take($3));
			}
		| '-' exp {
				EmplaceAST<CUnaryExpressionAST>($$, UnaryOperator::Minus, Take($2));
			}
		| '+' exp {
				EmplaceAST<CUnaryExpressionAST>($$, UnaryOperator::Plus, Take($2));
			}
		| '!' exp {
				EmplaceAST<CUnaryExpressionAST>($$, UnaryOperator::Not, Take($2));
			}
		| ID '(' ')' {
				std::cout << "ID '(' ')'" << std::endl;
				EmplaceAST<CCallAST>($$, $1, ExpressionList());
			}
		| ID '(' expression_list ')' {
				std::cout << "ID '(' expression_list ')'" << std::endl;
				EmplaceAST<CCallAST>($$, $1, ExpressionList());
			}
		| NUMBER {
		std::cout << "NUMBER" << std::endl;
				EmplaceAST<CLiteralAST>($$, $1);
			}
		| ID {
				std::cout << "ID" << std::endl;
				EmplaceAST<CVariableRefAST>($$, $1);
			}
;

%%

int yyerror (YYLTYPE* yyllocp, void* pParser, const char* message) {
   std::cout << "ERROR: " << message << std::endl;
   return 1;
 }
