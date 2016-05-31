%option noyywrap
%{
  #include "wcsbss.tab.h"
  #include <iostream>
%}

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

[0-9]+ { yylval.num = atof(yytext); return NUMBER; }
\n  { return EOL; }
[ \t] { }
.   {  std::cout << "Mystery character " <<  yytext << std::endl; }

%%