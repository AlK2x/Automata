%{
  #include "stdio.h"
  #include "NodeAST.h"
  #include "Value.h"
  #include "Parser_private.h"
  int yylex(void);
  int yyerror(char const *);

  using namespace parser_private;
%}

%union {
    struct IExpressionAST *d;
	double num;
}

%token <num> NUMBER
%token MUL ADD SUB DIV ABS
%token EOL

%type <d> exp factor calclist term

%%

calclist : /* nothing */
        | calclist exp EOL { SValue v = $2->Evaluate(); std::cout << " = " << v.value  << std::endl; }
;

exp : factor
      | exp ADD factor { 
			EmplaceAST<BinaryExpressionAST>($$, BinaryOperator::Add, Take($1), Take($3));
		  }
      | exp SUB factor { 
			EmplaceAST<BinaryExpressionAST>($$, BinaryOperator::Substract, Take($1), Take($3));
		  }
;

factor : term
      | factor MUL term { 
				EmplaceAST<BinaryExpressionAST>($$, BinaryOperator::Multiply, Take($1), Take($3));
			  }
      | factor DIV term {
				EmplaceAST<BinaryExpressionAST>($$, BinaryOperator::Divide, Take($1), Take($3));
			  }
;

term :  NUMBER {
			EmplaceAST<CLiteralAST>($$, SValue::create($1));
		 }
;

%%

int yyerror (char const *s) {
   fprintf (stderr, "%s\n", s);
   return 1;
 }