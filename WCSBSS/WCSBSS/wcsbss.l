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
"}"  { return yytext[0]; }

"if"    { return IF; }
"then"  { return THEN; }
"else"  { return ELSE; }
"while" { return WHILE; }
"let"   { return LET; }
"func"  { return FUNCTION; }

"print" { return PRINT; }

[0-9]+"."[0-9]*{EXP}? |
"."?[0-9]+{EXP}? { yylvalp->num = atof(yytext); return NUMBER; }

[A-Za-z][A-Za-z0-9_]*	{ 
				yylvalp->nameId = ((CParserContext *) pParser)->GetIdentifierId(yytext);
				return ID;
			}

[ \t\n]         /* white space */
.   {  std::cout << "Mystery character " <<  yytext << std::endl; }

%%