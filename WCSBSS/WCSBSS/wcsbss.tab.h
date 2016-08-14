/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_WCSBSS_TAB_H_INCLUDED
# define YY_YY_WCSBSS_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
/* Line 2058 of yacc.c  */
#line 10 "wcsbss.y"

  #include <stdio.h>
  #include "ParserContext.h"

  /* structs used in the %union declaration would go here */


/* Line 2058 of yacc.c  */
#line 54 "wcsbss.tab.h"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     NUMBER = 259,
     BOOLEAN = 260,
     STRING = 261,
     CHAR = 262,
     IF = 263,
     THEN = 264,
     ELSE = 265,
     WHILE = 266,
     LET = 267,
     FUNCTION = 268,
     EQUAL = 269,
     NOTEQUAL = 270,
     NUMBER_TYPE = 271,
     STRING_TYPE = 272,
     BOOLEAN_TYPE = 273,
     CHAR_TYPE = 274,
     PRINT = 275,
     RETURN = 276,
     EOL = 277
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 31 "wcsbss.y"

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


/* Line 2058 of yacc.c  */
#line 107 "wcsbss.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void* pParser);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */
/* "%code provides" blocks.  */
/* Line 2058 of yacc.c  */
#line 22 "wcsbss.y"

   #define YY_DECL \
       int yylex(YYSTYPE* yylvalp, YYLTYPE* yyllocp, void* pParser)
   YY_DECL;

   int yyerror(YYLTYPE* yyllocp, void* pParser, const char* message);


/* Line 2058 of yacc.c  */
#line 153 "wcsbss.tab.h"

#endif /* !YY_YY_WCSBSS_TAB_H_INCLUDED  */
