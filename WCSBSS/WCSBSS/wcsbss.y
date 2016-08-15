%{
#define YYPARSE_PARAM pParser
  #include "NodeAST.h"
  #include "Parser_private.h"
  #include "wcsbss.flex.h"
  #include "ParserContext.h"
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
	char ch;
}

%token <nameId> ID
%token <num> NUMBER
%token <b> BOOLEAN
%token <str> STRING
%token <ch> CHAR
%token IF THEN ELSE WHILE LET FUNCTION
%token EQUAL NOTEQUAL
%token NUMBER_TYPE STRING_TYPE BOOLEAN_TYPE CHAR_TYPE
%token PRINT RETURN
%token EOL

%type <pl> parameter_declaration_list
%type <e> expression
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

declaration_list : EOL
	| declaration
	| declaration_list declaration
;

declaration : function_declaration {
			BOOST_LOG_TRIVIAL(debug) << "function_declaration";
			((CParserContext *) pParser)->AddFunction(Take($1));
		}
;

function_declaration : FUNCTION ID '('  parameter_declaration_list ')' type_specifier '{' statement_list '}' {
				BOOST_LOG_TRIVIAL(debug) << "Add function";
				auto params = $4->list;
				auto body = $8->list;
				EmplaceAST<CFunctionAST>($$, $2, static_cast<BaseType>($6), std::move(*params), std::move(*body));
			}
;

statement_list : {
				$$ = new StatementListContainer();
				$$->list = Make<StatementList>().release();
			}
		|
		 statement ';' {
				BOOST_LOG_TRIVIAL(debug) << "statement ;";
				$$ = new StatementListContainer();
				CreateList($$->list, $1);
			}
		| statement_list statement ';' {
				BOOST_LOG_TRIVIAL(debug) << "statement_list ';' statement";
				ConcatList($$->list, $1->list, $2);
			}
;

statement : ID '=' expression {
				EmplaceAST<CAssignmentAST>($$, Take($3), $1);
				BOOST_LOG_TRIVIAL(debug) << "ID : " << $1 << " = expression";
			}
		| PRINT expression {
				EmplaceAST<CPrintAST>($$, Take($2));
			}
		| IF '(' expression ')' '{' statement_list '}' {
				BOOST_LOG_TRIVIAL(debug) << "IF '(' expression ')' '{' statement_list '}'";
				EmplaceAST<CIfAST>($$, Take($3), std::move(*($6->list)));
			}
		| IF '(' expression ')' '{' statement_list '}' ELSE '{' statement_list '}' {
				BOOST_LOG_TRIVIAL(debug) << "IF '(' expression ')' '{' statement_list '}' ELSE '{' statement_list '}'";
				EmplaceAST<CIfAST>($$, Take($3), std::move(*($6->list)), std::move(*($10->list)));
			}
		| WHILE '(' expression ')' '{' statement_list '}' {
				BOOST_LOG_TRIVIAL(debug) << "(' expression ')' '{' statement_list '}'";
				EmplaceAST<CWhileAST>($$, Take($3), std::move(*($6->list)));
			}
		| RETURN expression {
				EmplaceAST<CReturnAST>($$, Take($2));
			}
		| ID '[' expression ']' '=' expression {
				BOOST_LOG_TRIVIAL(debug) << "statement::ID[expression]=expression";
			}
;

expression_list :
		expression {
				BOOST_LOG_TRIVIAL(debug) << "expression";
				$$ = new ExpressionListContainer();
				auto b = $1;
				CreateList($$->list, $1);
			}
		| expression_list ',' expression {
				BOOST_LOG_TRIVIAL(debug) << "expression_list EOL expression";
				ConcatList($$->list, $1->list, $3);
			}
;

expression : '(' expression ')' {
				BOOST_LOG_TRIVIAL(debug) << "expression::(expression)";
				MovePointer($2, $$);
			}
		| expression '+' expression { 
				EmplaceAST<CBinaryExpressionAST>($$, BinaryOperation::Add, Take($1), Take($3));
			}
		| expression '-' expression {
				EmplaceAST<CBinaryExpressionAST>($$, BinaryOperation::Substract, Take($1), Take($3));
			}
		| expression '*' expression {
				EmplaceAST<CBinaryExpressionAST>($$, BinaryOperation::Multiply, Take($1), Take($3));
			}
		| expression '/' expression {
				EmplaceAST<CBinaryExpressionAST>($$, BinaryOperation::Divide, Take($1), Take($3));
			}
		| expression '<' expression {
				EmplaceAST<CBinaryExpressionAST>($$, BinaryOperation::Less, Take($1), Take($3));
			}
		| expression EQUAL expression {
				EmplaceAST<CBinaryExpressionAST>($$, BinaryOperation::Equal, Take($1), Take($3));
			}
		| expression NOTEQUAL expression {
				EmplaceAST<CBinaryExpressionAST>($$, BinaryOperation::NotEqual, Take($1), Take($3));
			}
		| '-' expression {
				EmplaceAST<CUnaryExpressionAST>($$, UnaryOperator::Minus, Take($2));
			}
		| '+' expression {
				EmplaceAST<CUnaryExpressionAST>($$, UnaryOperator::Plus, Take($2));
			}
		| '!' expression {
				EmplaceAST<CUnaryExpressionAST>($$, UnaryOperator::Not, Take($2));
			}
		| ID '[' expression ']' {
				BOOST_LOG_TRIVIAL(debug) << "expression::ID[expression]";
				EmplaceAST<CPositionAccessAST>($$, $1, Take($3));
			}
		| ID '(' ')' {
				BOOST_LOG_TRIVIAL(debug) << "expression::ID()";
				EmplaceAST<CCallAST>($$, $1, ExpressionList());
			}
		| ID '(' expression_list ')' {
				BOOST_LOG_TRIVIAL(debug) << "expression::ID(expression_list)";
				EmplaceAST<CCallAST>($$, $1, std::move(*($3->list)));
			}
		| NUMBER {
				BOOST_LOG_TRIVIAL(debug) << "expression::NUMBER::" << $1;
				EmplaceAST<CLiteralAST>($$, CLiteralAST::Value($1));
			}
		| STRING {
				std::string str($1);
				EmplaceAST<CLiteralAST>($$, CLiteralAST::Value(str));
			}
		| BOOLEAN {
				EmplaceAST<CLiteralAST>($$, CLiteralAST::Value($1));
			}
		| CHAR {
				EmplaceAST<CLiteralAST>($$, CLiteralAST::Value($1));
			}
		| ID {
				BOOST_LOG_TRIVIAL(debug) << "expression::ID";
				EmplaceAST<CVariableRefAST>($$, $1);
			}
;

parameter_declaration_list
		: {
				BOOST_LOG_TRIVIAL(debug) << "parameter_declaration_list";
				$$ = new ParameterDeclListContainer();
				$$->list = Make<ParameterDeclList>().release();
			}
		| parameter_declaration {
				$$ = new ParameterDeclListContainer();
				CreateList($$->list, $1);
			}
		| parameter_declaration_list ',' parameter_declaration {
				ConcatList($$->list, $1->list, $3);
			}
;

parameter_declaration
	: type_specifier ID {
		BOOST_LOG_TRIVIAL(debug) << "parameter_declaration:: type_specifier ID";
		EmplaceAST<CParameterDeclAST>($$, $2, static_cast<BaseType>$1);
	}
;

type_specifier
	: NUMBER_TYPE {
			BOOST_LOG_TRIVIAL(debug) << "type_specifier::NUMBER_TYPE";
			$$ = static_cast<unsigned>(BaseType::Double);
		}
	| STRING_TYPE {
			BOOST_LOG_TRIVIAL(debug) << "type_specifier::STRING_TYPE";
			$$ = static_cast<unsigned>(BaseType::String);
		}
	| BOOLEAN_TYPE {
			BOOST_LOG_TRIVIAL(debug) << "type_specifier::BOOLEAN_TYPE";
			$$ = static_cast<unsigned>(BaseType::Boolean);
		}
	| CHAR_TYPE {
			BOOST_LOG_TRIVIAL(debug) << "type_specifier::CHAR_TYPE";
			$$ = static_cast<char>(BaseType::Char);
		}
;

%%

int yyerror (YYLTYPE* yyllocp, void* pParser, const char* message) {
   std::cout << "ERROR: " << message << std::endl;
   std::cout << "first_line: " << yyllocp->first_line << std::endl;
   std::cout << "first_column: " << yyllocp->first_column << std::endl;
   std::cout << "Last Line: " << yyllocp->last_line << std::endl;
   std::cout << "last_column: " << yyllocp->last_column << std::endl;
   return 1;
 }