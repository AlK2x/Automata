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
	class CParameterDeclAST * p;
	struct ExpressionListContainer * el;
	struct StatementListContainer * sl;
	struct ParameterDeclListContainer * pl;
	double num;
	unsigned nameId;
	bool b;
	char * str;
}

%token <nameId> ID
%token <num> NUMBER
%token <b> BOOLEAN
%token <str> STRING
%token IF THEN ELSE WHILE LET FUNCTION
%token EQUAL NOTEQUAL
%token NUMBER_TYPE STRING_TYPE BOOLEAN_TYPE
%token PRINT RETURN
%token EOL

%type <pl> parameter_declaration_list
%type <e> exp
%type <p> parameter_declaration
%type <el> expression_list
%type <d> declaration function_declaration
%type <s> statement
%type <sl> statement_list
%type <nameId> type_specifier

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
;

declaration : function_declaration {
			((CParserContext *) pParser)->AddFunction(Take($1));
		}
;

function_declaration : FUNCTION ID parameter_declaration_list type_specifier '{' statement_list '}' {
				// TODO: use BOOST_LOG_TRIVIAL()
				std::cout << "Add function" << std::endl;
				auto params = $3->list;
				auto body = $6->list;
				EmplaceAST<CFunctionAST>($$, $2, static_cast<BaseType>($4), std::move(*params), std::move(*body));
			}
;

statement_list : {
				$$ = new StatementListContainer();
				$$->list = Make<StatementList>().release();
			}
		|
		 statement ';' {
				std::cout << "statement ';'" << std::endl;
				$$ = new StatementListContainer();
				CreateList($$->list, $1);
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
		| RETURN exp {
				EmplaceAST<CReturnAST>($$, Take($2));
			}
;

expression_list :
		exp ';' {
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

// TODO: exp -> expression or expr
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
				EmplaceAST<CLiteralAST>($$, CLiteralAST::Value($1));
			}
		| STRING {
				std::string str($1);
				EmplaceAST<CLiteralAST>($$, CLiteralAST::Value(str));
			}
		| BOOLEAN {
				EmplaceAST<CLiteralAST>($$, CLiteralAST::Value($1));
			}
		| ID {
				std::cout << "ID" << std::endl;
				EmplaceAST<CVariableRefAST>($$, $1);
			}
;

parameter_declaration_list
		: '(' ')' {
				$$ = new ParameterDeclListContainer();
				$$->list = Make<ParameterDeclList>().release();
			}
		| '(' parameter_declaration ')' {
				$$ = new ParameterDeclListContainer();
				CreateList($$->list, $2);
			}
		| parameter_declaration_list ',' '(' parameter_declaration ')' {
				ConcatList($$->list, $1->list, $4);
			}
;

parameter_declaration
	: type_specifier ID {
		EmplaceAST<CParameterDeclAST>($$, $2, static_cast<BaseType>$1);
	}
;

type_specifier
	: NUMBER_TYPE {
			$$ = static_cast<unsigned>(BaseType::Double);
		}
	| STRING_TYPE {
			$$ = static_cast<unsigned>(BaseType::String);
		}
	| BOOLEAN_TYPE {
			$$ = static_cast<unsigned>(BaseType::Boolean);
		}
;

%%

int yyerror (YYLTYPE* yyllocp, void* pParser, const char* message) {
   std::cout << "ERROR: " << message << std::endl;
   return 1;
 }