%option noyywrap
%{
  #include "ParserContext.h"
  #include "wcsbss.tab.h"
  #include <iostream>
%}

EXP	([Ee][-+]?[0-9]+)

%%

"+" |
"-" |
"*" |
"/" |
"(" |
")" |
"=" |
"," |
";" |
"|" |
"{" |
"<" |
"!" |
"}"  { return yytext[0]; }

"==" { return EQUAL; }
"!=" |
"<>" { return NOTEQUAL; }

"if"    { return IF; }
"then"  { return THEN; }
"else"  { return ELSE; }
"while" { return WHILE; }
"let"   { return LET; }
"func"  { return FUNCTION; }

"double" { return NUMBER_TYPE; }
"string" { return STRING_TYPE; }
"bool"   { return BOOLEAN_TYPE; }

"true"  { yylvalp->b = true; return BOOLEAN; }
"false" { yylvalp->b = false; return BOOLEAN; }

"print" { return PRINT; }

[a-zA-Z_]?\"(\\.|[^\\"\n])*\" {
				yylvalp->str = yytext;
				return STRING;
			}

[0-9]+"."[0-9]*{EXP}?	|
"."?[0-9]+{EXP}? { 
				yylvalp->num = atof(yytext); 
				return NUMBER; 
			}

[A-Za-z][A-Za-z0-9_]*	{ 
				yylvalp->nameId = ((CParserContext *) pParser)->GetIdentifierId(yytext);
				return ID;
			}

[ \t\n]         /* white space */
.   {  std::cout << "Mystery character " <<  yytext << std::endl; }

%%