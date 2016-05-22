%option noyywrap
%{
  #include "wcsbss.tab.h"
  #include <iostream>
%}

%%

"+" { return ADD; }
"-" { return SUB; }
"*" { return MUL; }
"/" { return DIV; }
"|" { return ABS; }
[0-9]+ { yylval.num = atof(yytext); return NUMBER; }
\n  { return EOL; }
[ \t] { }
.   {  std::cout << "Mystery character " <<  yytext << std::endl; }

%%