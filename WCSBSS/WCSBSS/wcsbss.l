%option noyywrap
%{
  #include "ParserContext.h"
  #include "wcsbss.tab.h"
  #include <iostream>
%}

EXP	([Ee][-+]?[0-9]+)
%x IN_COMMENT
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
"[" |
"]" |
"{" |
"<" |
"!" |
"}"  { BOOST_LOG_TRIVIAL(debug) << "token: " << yytext[0]; return yytext[0]; }

"==" { return EQUAL; }
"!=" |
"<>" { return NOTEQUAL; }

"if"    { return IF; }
"then"  { return THEN; }
"else"  { return ELSE; }
"while" { return WHILE; }
"let"   { return LET; }
"func"  { BOOST_LOG_TRIVIAL(debug) << "token: func"; return FUNCTION; }

"double" { return NUMBER_TYPE; }
"string" { return STRING_TYPE; }
"bool"   { return BOOLEAN_TYPE; }
"char"   { return CHAR_TYPE; }

"true"  { yylvalp->b = true; return BOOLEAN; }
"false" { yylvalp->b = false; return BOOLEAN; }
"return" { return RETURN; }

"print" { return PRINT; }

[a-zA-Z_]?\"(\\.|[^\\"\n])*\" {
				yylvalp->str = yytext;
				BOOST_LOG_TRIVIAL(debug) << "token: some str" << yylvalp->str;
				return STRING;
			}

'([^'\\\n]|\\.)+' {
				BOOST_LOG_TRIVIAL(debug) << "token: char " << yytext[0];
				yylvalp->ch = yytext[0];
				return CHAR;
			}

[0-9]+"."[0-9]*{EXP}?	|
"."?[0-9]+{EXP}? { 
				yylvalp->num = atof(yytext);
				BOOST_LOG_TRIVIAL(debug) << "token: number" << yylvalp->num;
				return NUMBER; 
			}

[A-Za-z][A-Za-z0-9_]*	{ 
				yylvalp->nameId = ((CParserContext *) pParser)->GetIdentifierId(yytext);
				BOOST_LOG_TRIVIAL(debug) << "token: ID " << yylvalp->nameId;
				return ID;
			}

"//"[^\n]* 			/* comment */

<INITIAL>"/*"				BEGIN(IN_COMMENT);
<IN_COMMENT>"*/"			BEGIN(INITIAL);  
<IN_COMMENT>[.\n]+			{ }

[ \t\n]			/* white space */
.   {  std::cout << "Mystery character " <<  yytext << std::endl; }

%%

