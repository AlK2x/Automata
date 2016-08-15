/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "wcsbss.y"

#define YYPARSE_PARAM pParser
  #include "NodeAST.h"
  #include "Parser_private.h"
  #include "wcsbss.flex.h"
  #include "ParserContext.h"
  using namespace parser_private;

/* Line 371 of yacc.c  */
#line 77 "wcsbss.tab.cpp"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "wcsbss.tab.h".  */
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
/* Line 387 of yacc.c  */
#line 10 "wcsbss.y"

  #include <stdio.h>
  #include "ParserContext.h"

  /* structs used in the %union declaration would go here */


/* Line 387 of yacc.c  */
#line 117 "wcsbss.tab.cpp"

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
/* Line 387 of yacc.c  */
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


/* Line 387 of yacc.c  */
#line 170 "wcsbss.tab.cpp"
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
/* Line 387 of yacc.c  */
#line 22 "wcsbss.y"

   #define YY_DECL \
       int yylex(YYSTYPE* yylvalp, YYLTYPE* yyllocp, void* pParser)
   YY_DECL;

   int yyerror(YYLTYPE* yyllocp, void* pParser, const char* message);


/* Line 387 of yacc.c  */
#line 216 "wcsbss.tab.cpp"

#endif /* !YY_YY_WCSBSS_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 223 "wcsbss.tab.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   190

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  45
/* YYNRULES -- Number of states.  */
#define YYNSTATES  97

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   277

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    24,     2,     2,     2,     2,     2,     2,
      30,    31,    27,    25,    37,    26,     2,    28,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    34,
      29,    23,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    35,     2,    36,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    32,     2,    33,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    22,    23,    26,
      30,    34,    37,    45,    57,    65,    68,    75,    77,    81,
      85,    89,    93,    97,   101,   105,   109,   113,   116,   119,
     122,   127,   131,   136,   138,   140,   142,   144,   146,   147,
     149,   153,   156,   158,   160,   162
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      39,     0,    -1,    22,    -1,    40,    -1,    39,    40,    -1,
      41,    -1,    13,     3,    30,    46,    31,    48,    32,    42,
      33,    -1,    -1,    43,    34,    -1,    42,    43,    34,    -1,
       3,    23,    45,    -1,    20,    45,    -1,     8,    30,    45,
      31,    32,    42,    33,    -1,     8,    30,    45,    31,    32,
      42,    33,    10,    32,    42,    33,    -1,    11,    30,    45,
      31,    32,    42,    33,    -1,    21,    45,    -1,     3,    35,
      45,    36,    23,    45,    -1,    45,    -1,    44,    37,    45,
      -1,    30,    45,    31,    -1,    45,    25,    45,    -1,    45,
      26,    45,    -1,    45,    27,    45,    -1,    45,    28,    45,
      -1,    45,    29,    45,    -1,    45,    14,    45,    -1,    45,
      15,    45,    -1,    26,    45,    -1,    25,    45,    -1,    24,
      45,    -1,     3,    35,    45,    36,    -1,     3,    30,    31,
      -1,     3,    30,    44,    31,    -1,     4,    -1,     6,    -1,
       5,    -1,     7,    -1,     3,    -1,    -1,    47,    -1,    46,
      37,    47,    -1,    48,     3,    -1,    16,    -1,    17,    -1,
      18,    -1,    19,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    76,    76,    77,    78,    81,    87,    95,   100,   105,
     111,   115,   118,   122,   126,   130,   133,   139,   145,   151,
     155,   158,   161,   164,   167,   170,   173,   176,   179,   182,
     185,   189,   193,   197,   201,   205,   208,   211,   218,   223,
     227,   233,   240,   244,   248,   252
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "NUMBER", "BOOLEAN", "STRING",
  "CHAR", "IF", "THEN", "ELSE", "WHILE", "LET", "FUNCTION", "EQUAL",
  "NOTEQUAL", "NUMBER_TYPE", "STRING_TYPE", "BOOLEAN_TYPE", "CHAR_TYPE",
  "PRINT", "RETURN", "EOL", "'='", "'!'", "'+'", "'-'", "'*'", "'/'",
  "'<'", "'('", "')'", "'{'", "'}'", "';'", "'['", "']'", "','", "$accept",
  "declaration_list", "declaration", "function_declaration",
  "statement_list", "statement", "expression_list", "expression",
  "parameter_declaration_list", "parameter_declaration", "type_specifier", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,    61,    33,    43,    45,    42,    47,    60,
      40,    41,   123,   125,    59,    91,    93,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    39,    39,    39,    40,    41,    42,    42,    42,
      43,    43,    43,    43,    43,    43,    43,    44,    44,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    46,    46,
      46,    47,    48,    48,    48,    48
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     9,     0,     2,     3,
       3,     2,     7,    11,     7,     2,     6,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       4,     3,     4,     1,     1,     1,     1,     1,     0,     1,
       3,     2,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     2,     0,     3,     5,     0,     1,     4,    38,
      42,    43,    44,    45,     0,    39,     0,     0,     0,    41,
       0,    40,     7,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    37,    33,    35,    34,    36,     0,
       0,     0,     0,    11,    15,     6,     0,     8,    10,     0,
       0,     0,     0,     0,    29,    28,    27,     0,     0,     0,
       0,     0,     0,     0,     0,     9,     0,     0,     0,    31,
       0,    17,     0,    19,    25,    26,    20,    21,    22,    23,
      24,     0,     7,     7,    32,     0,    30,    16,     0,     0,
      18,    12,    14,     0,     7,     0,    13
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,    28,    29,    70,    43,    14,    15,
      16
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -29
static const yytype_int16 yypact[] =
{
     -11,     0,   -29,     8,   -29,   -29,    -8,   -29,   -29,    68,
     -29,   -29,   -29,   -29,   -12,   -29,    15,    68,    68,   -29,
      13,   -29,   110,    27,    18,    22,    75,    75,     9,    24,
      75,    75,    75,    75,    53,   -29,   -29,   -29,   -29,    75,
      75,    75,    75,   145,   145,   -29,    34,   -29,   145,    81,
     113,   120,    67,    75,   145,   161,   161,   138,    75,    75,
      75,    75,    75,    75,    75,   -29,    52,    57,    58,   -29,
      12,   145,    97,   -29,   145,   145,   161,   161,    -5,    -5,
      88,    75,   110,   110,   -29,    75,   -29,   145,    20,    36,
     145,    84,   -29,    72,   110,    43,   -29
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -29,   -29,   111,   -29,   -17,   -28,   -29,   -26,   -29,    98,
     102
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      46,    44,     1,     6,    48,    49,    50,    51,     7,    58,
      59,     2,    23,    54,    55,    56,    57,    24,    19,    17,
      25,     1,     9,    23,    64,    18,    71,    72,    24,    26,
      27,    25,    74,    75,    76,    77,    78,    79,    80,    23,
      26,    27,    45,    84,    24,    22,    23,    25,    32,    85,
      30,    24,    33,    91,    25,    87,    26,    27,    47,    90,
      46,    46,    31,    26,    27,    88,    89,    46,    65,    92,
      34,    35,    36,    37,    38,    81,    96,    95,    34,    35,
      36,    37,    38,    52,    10,    11,    12,    13,    53,    82,
      83,    39,    40,    41,    93,    58,    59,    42,    69,    39,
      40,    41,    58,    59,    94,    42,    60,    61,    62,    63,
      64,    58,    59,    23,     8,     0,    21,    66,    24,    20,
       0,    25,    60,    61,    62,    63,    64,    58,    59,     0,
      26,    27,     0,    86,    58,    59,     0,     0,    60,    61,
      62,    63,    64,     0,    67,    60,    61,    62,    63,    64,
       0,    68,    58,    59,     0,     0,     0,     0,     0,    58,
      59,     0,     0,    60,    61,    62,    63,    64,     0,    73,
      60,    61,    62,    63,    64,    58,    59,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    62,    63,
      64
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-29)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int8 yycheck[] =
{
      28,    27,    13,     3,    30,    31,    32,    33,     0,    14,
      15,    22,     3,    39,    40,    41,    42,     8,     3,    31,
      11,    13,    30,     3,    29,    37,    52,    53,     8,    20,
      21,    11,    58,    59,    60,    61,    62,    63,    64,     3,
      20,    21,    33,    31,     8,    32,     3,    11,    30,    37,
      23,     8,    30,    33,    11,    81,    20,    21,    34,    85,
      88,    89,    35,    20,    21,    82,    83,    95,    34,    33,
       3,     4,     5,     6,     7,    23,    33,    94,     3,     4,
       5,     6,     7,    30,    16,    17,    18,    19,    35,    32,
      32,    24,    25,    26,    10,    14,    15,    30,    31,    24,
      25,    26,    14,    15,    32,    30,    25,    26,    27,    28,
      29,    14,    15,     3,     3,    -1,    18,    36,     8,    17,
      -1,    11,    25,    26,    27,    28,    29,    14,    15,    -1,
      20,    21,    -1,    36,    14,    15,    -1,    -1,    25,    26,
      27,    28,    29,    -1,    31,    25,    26,    27,    28,    29,
      -1,    31,    14,    15,    -1,    -1,    -1,    -1,    -1,    14,
      15,    -1,    -1,    25,    26,    27,    28,    29,    -1,    31,
      25,    26,    27,    28,    29,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,
      29
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    13,    22,    39,    40,    41,     3,     0,    40,    30,
      16,    17,    18,    19,    46,    47,    48,    31,    37,     3,
      48,    47,    32,     3,     8,    11,    20,    21,    42,    43,
      23,    35,    30,    30,     3,     4,     5,     6,     7,    24,
      25,    26,    30,    45,    45,    33,    43,    34,    45,    45,
      45,    45,    30,    35,    45,    45,    45,    45,    14,    15,
      25,    26,    27,    28,    29,    34,    36,    31,    31,    31,
      44,    45,    45,    31,    45,    45,    45,    45,    45,    45,
      45,    23,    32,    32,    31,    37,    36,    45,    42,    42,
      45,    33,    33,    10,    32,    42,    33
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (&yylloc, pParser, YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (YYID (N))                                                     \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (YYID (0))
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

__attribute__((__unused__))
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
#else
static unsigned
yy_location_print_ (yyo, yylocp)
    FILE *yyo;
    YYLTYPE const * const yylocp;
#endif
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += fprintf (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += fprintf (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += fprintf (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += fprintf (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += fprintf (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, &yylloc, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval, &yylloc, pParser)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location, pParser); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, void* pParser)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, pParser)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    void* pParser;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
  YYUSE (pParser);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, void* pParser)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp, pParser)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    void* pParser;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, pParser);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, void* pParser)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule, pParser)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
    void* pParser;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       , pParser);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule, pParser); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, void* pParser)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp, pParser)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
    void* pParser;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (pParser);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void* pParser)
#else
int
yyparse (pParser)
    void* pParser;
#endif
#endif
{
/* The lookahead symbol.  */
int yychar;


#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
static YYSTYPE yyval_default;
# define YY_INITIAL_VALUE(Value) = Value
#endif
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc = yyloc_default;


    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 5:
/* Line 1792 of yacc.c  */
#line 81 "wcsbss.y"
    {
			BOOST_LOG_TRIVIAL(debug) << "function_declaration";
			((CParserContext *) pParser)->AddFunction(Take((yyvsp[(1) - (1)].d)));
		}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 87 "wcsbss.y"
    {
				BOOST_LOG_TRIVIAL(debug) << "Add function";
				auto params = (yyvsp[(4) - (9)].pl)->list;
				auto body = (yyvsp[(8) - (9)].sl)->list;
				EmplaceAST<CFunctionAST>((yyval.d), (yyvsp[(2) - (9)].nameId), static_cast<BaseType>((yyvsp[(6) - (9)].nameId)), std::move(*params), std::move(*body));
			}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 95 "wcsbss.y"
    {
				(yyval.sl) = new StatementListContainer();
				(yyval.sl)->list = Make<StatementList>().release();
			}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 100 "wcsbss.y"
    {
				BOOST_LOG_TRIVIAL(debug) << "statement ;";
				(yyval.sl) = new StatementListContainer();
				CreateList((yyval.sl)->list, (yyvsp[(1) - (2)].s));
			}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 105 "wcsbss.y"
    {
				BOOST_LOG_TRIVIAL(debug) << "statement_list ';' statement";
				ConcatList((yyval.sl)->list, (yyvsp[(1) - (3)].sl)->list, (yyvsp[(2) - (3)].s));
			}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 111 "wcsbss.y"
    {
				EmplaceAST<CAssignmentAST>((yyval.s), Take((yyvsp[(3) - (3)].e)), (yyvsp[(1) - (3)].nameId));
				BOOST_LOG_TRIVIAL(debug) << "ID : " << (yyvsp[(1) - (3)].nameId) << " = expression";
			}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 115 "wcsbss.y"
    {
				EmplaceAST<CPrintAST>((yyval.s), Take((yyvsp[(2) - (2)].e)));
			}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 118 "wcsbss.y"
    {
				BOOST_LOG_TRIVIAL(debug) << "IF '(' expression ')' '{' statement_list '}'";
				EmplaceAST<CIfAST>((yyval.s), Take((yyvsp[(3) - (7)].e)), std::move(*((yyvsp[(6) - (7)].sl)->list)));
			}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 122 "wcsbss.y"
    {
				BOOST_LOG_TRIVIAL(debug) << "IF '(' expression ')' '{' statement_list '}' ELSE '{' statement_list '}'";
				EmplaceAST<CIfAST>((yyval.s), Take((yyvsp[(3) - (11)].e)), std::move(*((yyvsp[(6) - (11)].sl)->list)), std::move(*((yyvsp[(10) - (11)].sl)->list)));
			}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 126 "wcsbss.y"
    {
				BOOST_LOG_TRIVIAL(debug) << "(' expression ')' '{' statement_list '}'";
				EmplaceAST<CWhileAST>((yyval.s), Take((yyvsp[(3) - (7)].e)), std::move(*((yyvsp[(6) - (7)].sl)->list)));
			}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 130 "wcsbss.y"
    {
				EmplaceAST<CReturnAST>((yyval.s), Take((yyvsp[(2) - (2)].e)));
			}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 133 "wcsbss.y"
    {
				BOOST_LOG_TRIVIAL(debug) << "statement::ID[expression]=expression";
			}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 139 "wcsbss.y"
    {
				BOOST_LOG_TRIVIAL(debug) << "expression";
				(yyval.el) = new ExpressionListContainer();
				auto b = (yyvsp[(1) - (1)].e);
				CreateList((yyval.el)->list, (yyvsp[(1) - (1)].e));
			}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 145 "wcsbss.y"
    {
				BOOST_LOG_TRIVIAL(debug) << "expression_list EOL expression";
				ConcatList((yyval.el)->list, (yyvsp[(1) - (3)].el)->list, (yyvsp[(3) - (3)].e));
			}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 151 "wcsbss.y"
    {
				BOOST_LOG_TRIVIAL(debug) << "expression::(expression)";
				MovePointer((yyvsp[(2) - (3)].e), (yyval.e));
			}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 155 "wcsbss.y"
    { 
				EmplaceAST<CBinaryExpressionAST>((yyval.e), BinaryOperation::Add, Take((yyvsp[(1) - (3)].e)), Take((yyvsp[(3) - (3)].e)));
			}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 158 "wcsbss.y"
    {
				EmplaceAST<CBinaryExpressionAST>((yyval.e), BinaryOperation::Substract, Take((yyvsp[(1) - (3)].e)), Take((yyvsp[(3) - (3)].e)));
			}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 161 "wcsbss.y"
    {
				EmplaceAST<CBinaryExpressionAST>((yyval.e), BinaryOperation::Multiply, Take((yyvsp[(1) - (3)].e)), Take((yyvsp[(3) - (3)].e)));
			}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 164 "wcsbss.y"
    {
				EmplaceAST<CBinaryExpressionAST>((yyval.e), BinaryOperation::Divide, Take((yyvsp[(1) - (3)].e)), Take((yyvsp[(3) - (3)].e)));
			}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 167 "wcsbss.y"
    {
				EmplaceAST<CBinaryExpressionAST>((yyval.e), BinaryOperation::Less, Take((yyvsp[(1) - (3)].e)), Take((yyvsp[(3) - (3)].e)));
			}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 170 "wcsbss.y"
    {
				EmplaceAST<CBinaryExpressionAST>((yyval.e), BinaryOperation::Equal, Take((yyvsp[(1) - (3)].e)), Take((yyvsp[(3) - (3)].e)));
			}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 173 "wcsbss.y"
    {
				EmplaceAST<CBinaryExpressionAST>((yyval.e), BinaryOperation::NotEqual, Take((yyvsp[(1) - (3)].e)), Take((yyvsp[(3) - (3)].e)));
			}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 176 "wcsbss.y"
    {
				EmplaceAST<CUnaryExpressionAST>((yyval.e), UnaryOperator::Minus, Take((yyvsp[(2) - (2)].e)));
			}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 179 "wcsbss.y"
    {
				EmplaceAST<CUnaryExpressionAST>((yyval.e), UnaryOperator::Plus, Take((yyvsp[(2) - (2)].e)));
			}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 182 "wcsbss.y"
    {
				EmplaceAST<CUnaryExpressionAST>((yyval.e), UnaryOperator::Not, Take((yyvsp[(2) - (2)].e)));
			}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 185 "wcsbss.y"
    {
				BOOST_LOG_TRIVIAL(debug) << "expression::ID[expression]";
				EmplaceAST<CPositionAccessAST>((yyval.e), (yyvsp[(1) - (4)].nameId), Take((yyvsp[(3) - (4)].e)));
			}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 189 "wcsbss.y"
    {
				BOOST_LOG_TRIVIAL(debug) << "expression::ID()";
				EmplaceAST<CCallAST>((yyval.e), (yyvsp[(1) - (3)].nameId), ExpressionList());
			}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 193 "wcsbss.y"
    {
				BOOST_LOG_TRIVIAL(debug) << "expression::ID(expression_list)";
				EmplaceAST<CCallAST>((yyval.e), (yyvsp[(1) - (4)].nameId), std::move(*((yyvsp[(3) - (4)].el)->list)));
			}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 197 "wcsbss.y"
    {
				BOOST_LOG_TRIVIAL(debug) << "expression::NUMBER::" << (yyvsp[(1) - (1)].num);
				EmplaceAST<CLiteralAST>((yyval.e), CLiteralAST::Value((yyvsp[(1) - (1)].num)));
			}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 201 "wcsbss.y"
    {
				std::string str((yyvsp[(1) - (1)].str));
				EmplaceAST<CLiteralAST>((yyval.e), CLiteralAST::Value(str));
			}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 205 "wcsbss.y"
    {
				EmplaceAST<CLiteralAST>((yyval.e), CLiteralAST::Value((yyvsp[(1) - (1)].b)));
			}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 208 "wcsbss.y"
    {
				EmplaceAST<CLiteralAST>((yyval.e), CLiteralAST::Value((yyvsp[(1) - (1)].ch)));
			}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 211 "wcsbss.y"
    {
				BOOST_LOG_TRIVIAL(debug) << "expression::ID";
				EmplaceAST<CVariableRefAST>((yyval.e), (yyvsp[(1) - (1)].nameId));
			}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 218 "wcsbss.y"
    {
				BOOST_LOG_TRIVIAL(debug) << "parameter_declaration_list";
				(yyval.pl) = new ParameterDeclListContainer();
				(yyval.pl)->list = Make<ParameterDeclList>().release();
			}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 223 "wcsbss.y"
    {
				(yyval.pl) = new ParameterDeclListContainer();
				CreateList((yyval.pl)->list, (yyvsp[(1) - (1)].p));
			}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 227 "wcsbss.y"
    {
				ConcatList((yyval.pl)->list, (yyvsp[(1) - (3)].pl)->list, (yyvsp[(3) - (3)].p));
			}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 233 "wcsbss.y"
    {
		BOOST_LOG_TRIVIAL(debug) << "parameter_declaration:: type_specifier ID";
		EmplaceAST<CParameterDeclAST>((yyval.p), (yyvsp[(2) - (2)].nameId), static_cast<BaseType>(yyvsp[(1) - (2)].nameId));
	}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 240 "wcsbss.y"
    {
			BOOST_LOG_TRIVIAL(debug) << "type_specifier::NUMBER_TYPE";
			(yyval.nameId) = static_cast<unsigned>(BaseType::Double);
		}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 244 "wcsbss.y"
    {
			BOOST_LOG_TRIVIAL(debug) << "type_specifier::STRING_TYPE";
			(yyval.nameId) = static_cast<unsigned>(BaseType::String);
		}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 248 "wcsbss.y"
    {
			BOOST_LOG_TRIVIAL(debug) << "type_specifier::BOOLEAN_TYPE";
			(yyval.nameId) = static_cast<unsigned>(BaseType::Boolean);
		}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 252 "wcsbss.y"
    {
			BOOST_LOG_TRIVIAL(debug) << "type_specifier::CHAR_TYPE";
			(yyval.nameId) = static_cast<char>(BaseType::Char);
		}
    break;


/* Line 1792 of yacc.c  */
#line 2004 "wcsbss.tab.cpp"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (&yylloc, pParser, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (&yylloc, pParser, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc, pParser);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp, pParser);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, pParser, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, pParser);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp, pParser);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 258 "wcsbss.y"


int yyerror (YYLTYPE* yyllocp, void* pParser, const char* message) {
   std::cout << "ERROR: " << message << std::endl;
   std::cout << "first_line: " << yyllocp->first_line << std::endl;
   std::cout << "first_column: " << yyllocp->first_column << std::endl;
   std::cout << "Last Line: " << yyllocp->last_line << std::endl;
   std::cout << "last_column: " << yyllocp->last_column << std::endl;
   return 1;
 }