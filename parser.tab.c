/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT_VAL = 258,
     FLOAT_VAL = 259,
     CHAR_VAL = 260,
     STRING_VAL = 261,
     ID = 262,
     INT = 263,
     FLOAT = 264,
     CHAR_TYPE = 265,
     VOID = 266,
     RETURN = 267,
     IF = 268,
     ELSE = 269,
     WHILE = 270,
     FOR = 271,
     AND = 272,
     OR = 273,
     NOT = 274,
     LE = 275,
     GE = 276,
     LT = 277,
     GT = 278,
     EQ = 279,
     NE = 280,
     INC = 281,
     DEC = 282,
     PLUS_ASSIGN = 283,
     MINUS_ASSIGN = 284,
     MULT_ASSIGN = 285,
     DIV_ASSIGN = 286,
     END = 287,
     UMINUS = 288,
     LOWER_THAN_ELSE = 289
   };
#endif
/* Tokens.  */
#define INT_VAL 258
#define FLOAT_VAL 259
#define CHAR_VAL 260
#define STRING_VAL 261
#define ID 262
#define INT 263
#define FLOAT 264
#define CHAR_TYPE 265
#define VOID 266
#define RETURN 267
#define IF 268
#define ELSE 269
#define WHILE 270
#define FOR 271
#define AND 272
#define OR 273
#define NOT 274
#define LE 275
#define GE 276
#define LT 277
#define GT 278
#define EQ 279
#define NE 280
#define INC 281
#define DEC 282
#define PLUS_ASSIGN 283
#define MINUS_ASSIGN 284
#define MULT_ASSIGN 285
#define DIV_ASSIGN 286
#define END 287
#define UMINUS 288
#define LOWER_THAN_ELSE 289




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"  // Include the AST header
#include "ir.h"   // Add this to the includes section

/* Declarations for Flex */
extern FILE *yyin;
extern int yylex(void);
extern int yyparse(void);
extern int yylineno;
void yyerror(const char *s);

/* For AST evaluation */
ASTNode *root = NULL;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 19 "parser.y"
{
    int intval;
    float floatval;
    char charval;
    char *strval;
    ASTNode *ast;  // Add AST type
}
/* Line 193 of yacc.c.  */
#line 190 "parser.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 203 "parser.tab.c"

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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  45
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   350

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNRULES -- Number of states.  */
#define YYNSTATES  114

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    38,     2,     2,
      44,    45,    36,    34,    48,    35,     2,    37,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    41,
       2,    42,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    33,     2,    43,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,    47,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    39,    40
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     9,    11,    14,    17,    20,    23,
      25,    27,    29,    31,    34,    37,    42,    48,    50,    52,
      54,    56,    60,    64,    66,    68,    70,    72,    76,    80,
      84,    88,    92,    96,   100,   104,   108,   112,   116,   120,
     124,   127,   130,   133,   136,   140,   145,   149,   155,   163,
     169,   179,   180,   182,   184,   186,   190,   193,   195,   198,
     199,   201,   203
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      50,     0,    -1,    51,    32,    -1,    56,    32,    -1,    52,
      -1,    51,    52,    -1,    53,    41,    -1,    56,    41,    -1,
      55,    41,    -1,    57,    -1,    58,    -1,    59,    -1,    61,
      -1,    62,    41,    -1,    54,     7,    -1,    54,     7,    42,
      56,    -1,    54,     7,    33,     3,    43,    -1,     8,    -1,
       9,    -1,    10,    -1,    11,    -1,     7,    42,    56,    -1,
       7,    28,    56,    -1,     7,    -1,     3,    -1,     6,    -1,
       4,    -1,    56,    34,    56,    -1,    56,    35,    56,    -1,
      56,    36,    56,    -1,    56,    37,    56,    -1,    56,    38,
      56,    -1,    56,    24,    56,    -1,    56,    25,    56,    -1,
      56,    22,    56,    -1,    56,    23,    56,    -1,    56,    20,
      56,    -1,    56,    21,    56,    -1,    56,    17,    56,    -1,
      56,    18,    56,    -1,    19,    56,    -1,    35,    56,    -1,
       7,    26,    -1,     7,    27,    -1,     7,    44,    45,    -1,
       7,    44,    64,    45,    -1,    44,    56,    45,    -1,    13,
      44,    56,    45,    52,    -1,    13,    44,    56,    45,    52,
      14,    52,    -1,    15,    44,    56,    45,    52,    -1,    16,
      44,    60,    41,    63,    41,    63,    45,    52,    -1,    -1,
      56,    -1,    55,    -1,    53,    -1,    46,    51,    47,    -1,
      46,    47,    -1,    12,    -1,    12,    56,    -1,    -1,    56,
      -1,    56,    -1,    64,    48,    56,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    65,    65,    88,   112,   113,   122,   123,   124,   125,
     126,   127,   128,   129,   133,   137,   141,   148,   149,   150,
     151,   155,   159,   170,   174,   178,   182,   186,   190,   194,
     198,   202,   206,   210,   214,   218,   222,   226,   230,   234,
     238,   242,   246,   250,   254,   258,   264,   268,   272,   279,
     286,   293,   294,   295,   296,   300,   301,   305,   309,   316,
     317,   321,   328
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT_VAL", "FLOAT_VAL", "CHAR_VAL",
  "STRING_VAL", "ID", "INT", "FLOAT", "CHAR_TYPE", "VOID", "RETURN", "IF",
  "ELSE", "WHILE", "FOR", "AND", "OR", "NOT", "LE", "GE", "LT", "GT", "EQ",
  "NE", "INC", "DEC", "PLUS_ASSIGN", "MINUS_ASSIGN", "MULT_ASSIGN",
  "DIV_ASSIGN", "END", "'['", "'+'", "'-'", "'*'", "'/'", "'%'", "UMINUS",
  "LOWER_THAN_ELSE", "';'", "'='", "']'", "'('", "')'", "'{'", "'}'",
  "','", "$accept", "program", "statements", "statement", "declaration",
  "type", "assignment", "expression", "if_statement", "while_statement",
  "for_statement", "for_init", "compound_statement", "return_statement",
  "expression_opt", "argument_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,    91,    43,    45,    42,    47,    37,   288,
     289,    59,    61,    93,    40,    41,   123,   125,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    50,    51,    51,    52,    52,    52,    52,
      52,    52,    52,    52,    53,    53,    53,    54,    54,    54,
      54,    55,    55,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    57,    57,    58,
      59,    60,    60,    60,    60,    61,    61,    62,    62,    63,
      63,    64,    64
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     1,     2,     2,     2,     2,     1,
       1,     1,     1,     2,     2,     4,     5,     1,     1,     1,
       1,     3,     3,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     2,     3,     4,     3,     5,     7,     5,
       9,     0,     1,     1,     1,     3,     2,     1,     2,     0,
       1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    24,    26,    25,    23,    17,    18,    19,    20,    57,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     4,
       0,     0,     0,     0,     9,    10,    11,    12,     0,    42,
      43,     0,     0,     0,    23,    58,     0,     0,    51,    40,
      41,     0,    56,     0,     0,     1,     2,     5,     6,    14,
       8,     0,     0,     0,     0,     0,     0,     0,     0,     3,
       0,     0,     0,     0,     0,     7,    13,    22,    21,    44,
      61,     0,     0,     0,    54,    53,    52,     0,    46,    55,
       0,     0,    38,    39,    36,    37,    34,    35,    32,    33,
      27,    28,    29,    30,    31,    45,     0,     0,     0,    59,
       0,    15,    62,    47,    49,    60,     0,    16,     0,    59,
      48,     0,     0,    50
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    17,    18,    19,    20,    21,    22,    44,    24,    25,
      26,    77,    27,    28,   106,    71
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -45
static const yytype_int16 yypact[] =
{
     177,   -45,   -45,   -45,    -2,   -45,   -45,   -45,   -45,    15,
     -42,   -39,   -38,    15,    15,    15,   104,    12,   163,   -45,
     -25,    10,   -21,   262,   -45,   -45,   -45,   -45,   -14,   -45,
     -45,    15,    15,     4,     3,   306,    15,    15,   207,   -45,
     -45,    50,   -45,   118,   284,   -45,   -45,   -45,   -45,     2,
     -45,    15,    15,    15,    15,    15,    15,    15,    15,   -45,
      15,    15,    15,    15,    15,   -45,   -45,   306,   306,   -45,
     306,   -44,   210,   236,   -45,   -45,   306,     5,   -45,   -45,
      38,    15,   312,   121,    42,    42,    42,    42,   255,   255,
      53,    53,   -45,   -45,   -45,   -45,    15,   177,   177,    15,
      22,   306,   306,    29,   -45,   306,    25,   -45,   177,    15,
     -45,    24,   177,   -45
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -45,   -45,    76,   -15,     7,   -45,    56,     0,   -45,   -45,
     -45,   -45,   -45,   -45,   -11,   -45
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      23,    95,    36,    47,    96,    37,    38,     1,     2,    35,
       3,    34,    45,    39,    40,    41,    48,    49,     1,     2,
      50,     3,    34,    13,    29,    30,    31,    66,    47,    29,
      30,    67,    68,    70,    13,    80,    72,    73,    76,    14,
      32,   100,    33,   108,    81,    74,    99,    33,    15,    69,
      14,    82,    83,    84,    85,    86,    87,    88,    89,    15,
      90,    91,    92,    93,    94,   107,   109,    51,    52,   112,
      53,    54,    55,    56,    57,    58,    60,    61,    62,    63,
      64,   101,   103,   104,    60,    61,    62,    63,    64,    62,
      63,    64,    43,   110,    75,    78,   102,   113,   111,   105,
       0,     0,     0,     0,     0,     0,     0,     1,     2,   105,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
      12,     1,     2,    13,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,    12,     0,     0,    13,    51,    14,
       0,    53,    54,    55,    56,    57,    58,     0,    15,     0,
      16,    42,     0,    14,     0,    60,    61,    62,    63,    64,
       0,     0,    15,     0,    16,    79,     1,     2,     0,     3,
       4,     5,     6,     7,     8,     9,    10,     0,    11,    12,
       1,     2,    13,     3,     4,     5,     6,     7,     8,     9,
      10,     0,    11,    12,     0,    46,    13,     0,    14,     0,
       0,     0,     0,     0,     0,     0,     0,    15,     0,    16,
       1,     2,    14,     3,     4,     5,     6,     7,     8,     0,
       0,    15,     0,    16,     0,     0,    13,    51,    52,     0,
      53,    54,    55,    56,    57,    58,     0,     0,     0,     0,
       0,     0,    14,     0,    60,    61,    62,    63,    64,     0,
       0,    15,     0,    51,    52,    97,    53,    54,    55,    56,
      57,    58,     0,     0,     0,     0,     0,     0,     0,     0,
      60,    61,    62,    63,    64,    53,    54,    55,    56,    51,
      52,    98,    53,    54,    55,    56,    57,    58,     0,    60,
      61,    62,    63,    64,    59,     0,    60,    61,    62,    63,
      64,    51,    52,    65,    53,    54,    55,    56,    57,    58,
       0,     0,     0,     0,     0,     0,     0,     0,    60,    61,
      62,    63,    64,    51,    52,    65,    53,    54,    55,    56,
      57,    58,    53,    54,    55,    56,    57,    58,     0,     0,
      60,    61,    62,    63,    64,     0,    60,    61,    62,    63,
      64
};

static const yytype_int8 yycheck[] =
{
       0,    45,    44,    18,    48,    44,    44,     3,     4,     9,
       6,     7,     0,    13,    14,    15,    41,     7,     3,     4,
      41,     6,     7,    19,    26,    27,    28,    41,    43,    26,
      27,    31,    32,    33,    19,    33,    36,    37,    38,    35,
      42,     3,    44,    14,    42,    38,    41,    44,    44,    45,
      35,    51,    52,    53,    54,    55,    56,    57,    58,    44,
      60,    61,    62,    63,    64,    43,    41,    17,    18,    45,
      20,    21,    22,    23,    24,    25,    34,    35,    36,    37,
      38,    81,    97,    98,    34,    35,    36,    37,    38,    36,
      37,    38,    16,   108,    38,    45,    96,   112,   109,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,   109,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,    15,
      16,     3,     4,    19,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    15,    16,    -1,    -1,    19,    17,    35,
      -1,    20,    21,    22,    23,    24,    25,    -1,    44,    -1,
      46,    47,    -1,    35,    -1,    34,    35,    36,    37,    38,
      -1,    -1,    44,    -1,    46,    47,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    15,    16,
       3,     4,    19,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    15,    16,    -1,    32,    19,    -1,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,    46,
       3,     4,    35,     6,     7,     8,     9,    10,    11,    -1,
      -1,    44,    -1,    46,    -1,    -1,    19,    17,    18,    -1,
      20,    21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    -1,    34,    35,    36,    37,    38,    -1,
      -1,    44,    -1,    17,    18,    45,    20,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    36,    37,    38,    20,    21,    22,    23,    17,
      18,    45,    20,    21,    22,    23,    24,    25,    -1,    34,
      35,    36,    37,    38,    32,    -1,    34,    35,    36,    37,
      38,    17,    18,    41,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      36,    37,    38,    17,    18,    41,    20,    21,    22,    23,
      24,    25,    20,    21,    22,    23,    24,    25,    -1,    -1,
      34,    35,    36,    37,    38,    -1,    34,    35,    36,    37,
      38
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     6,     7,     8,     9,    10,    11,    12,
      13,    15,    16,    19,    35,    44,    46,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    61,    62,    26,
      27,    28,    42,    44,     7,    56,    44,    44,    44,    56,
      56,    56,    47,    51,    56,     0,    32,    52,    41,     7,
      41,    17,    18,    20,    21,    22,    23,    24,    25,    32,
      34,    35,    36,    37,    38,    41,    41,    56,    56,    45,
      56,    64,    56,    56,    53,    55,    56,    60,    45,    47,
      33,    42,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    45,    48,    45,    45,    41,
       3,    56,    56,    52,    52,    56,    63,    43,    14,    41,
      52,    63,    45,    52
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



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
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 65 "parser.y"
    { 
        printf("\nProgram is syntactically correct!\n"); 
        if ((yyvsp[(1) - (2)].ast) != NULL) {
            int result = evaluate_ast((yyvsp[(1) - (2)].ast));
            printf("Program evaluation result: %d\n", result);
            
            // Debug
            printf("Generating IR code...\n");
            IRNode *ir_code = generate_ir((yyvsp[(1) - (2)].ast));
            printf("IR code %s generated\n", ir_code ? "successfully" : "failed to be");
            
            if (ir_code) {
                printf("\n--- Intermediate Code ---\n");
                print_ir(ir_code);
                free_ir_list(ir_code);
            } else {
                printf("No intermediate code was generated\n");
            }
            
            free_ast((yyvsp[(1) - (2)].ast));
        }
        exit(0); 
    ;}
    break;

  case 3:
#line 88 "parser.y"
    {
        printf("\nExpression is syntactically correct!\n");
        int result = evaluate_ast((yyvsp[(1) - (2)].ast));
        printf("Expression evaluation result: %d\n", result);
        
        // Debug
        printf("Generating IR code...\n");
        IRNode *ir_code = generate_ir((yyvsp[(1) - (2)].ast));
        printf("IR code %s generated\n", ir_code ? "successfully" : "failed to be");
        
        if (ir_code) {
            printf("\n--- Intermediate Code ---\n");
            print_ir(ir_code);
            free_ir_list(ir_code);
        } else {
            printf("No intermediate code was generated\n");
        }
        
        free_ast((yyvsp[(1) - (2)].ast));
        exit(0);
    ;}
    break;

  case 4:
#line 112 "parser.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); ;}
    break;

  case 5:
#line 113 "parser.y"
    { 
        // In a real compiler, you'd create a block node here
        // For simplicity, we'll just evaluate the last statement
        free_ast((yyvsp[(1) - (2)].ast));
        (yyval.ast) = (yyvsp[(2) - (2)].ast); 
    ;}
    break;

  case 6:
#line 122 "parser.y"
    { (yyval.ast) = (yyvsp[(1) - (2)].ast); ;}
    break;

  case 7:
#line 123 "parser.y"
    { (yyval.ast) = (yyvsp[(1) - (2)].ast); ;}
    break;

  case 8:
#line 124 "parser.y"
    { (yyval.ast) = (yyvsp[(1) - (2)].ast); ;}
    break;

  case 9:
#line 125 "parser.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); ;}
    break;

  case 10:
#line 126 "parser.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); ;}
    break;

  case 11:
#line 127 "parser.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); ;}
    break;

  case 12:
#line 128 "parser.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); ;}
    break;

  case 13:
#line 129 "parser.y"
    { (yyval.ast) = (yyvsp[(1) - (2)].ast); ;}
    break;

  case 14:
#line 133 "parser.y"
    { 
        printf("DECLARE: %s\n", (yyvsp[(2) - (2)].strval));
        (yyval.ast) = NULL; // For simplicity
    ;}
    break;

  case 15:
#line 137 "parser.y"
    { 
        printf("DECLARE_ASSIGN: %s\n", (yyvsp[(2) - (4)].strval));
        (yyval.ast) = create_assign_node((yyvsp[(2) - (4)].strval), (yyvsp[(4) - (4)].ast));
    ;}
    break;

  case 16:
#line 141 "parser.y"
    { 
        printf("DECLARE ARRAY: %s[%d]\n", (yyvsp[(2) - (5)].strval), (yyvsp[(4) - (5)].intval));
        (yyval.ast) = NULL; // For simplicity
    ;}
    break;

  case 21:
#line 155 "parser.y"
    { 
        printf("ASSIGN: %s\n", (yyvsp[(1) - (3)].strval));
        (yyval.ast) = create_assign_node((yyvsp[(1) - (3)].strval), (yyvsp[(3) - (3)].ast));
    ;}
    break;

  case 22:
#line 159 "parser.y"
    { 
        printf("PLUS_ASSIGN: %s\n", (yyvsp[(1) - (3)].strval));
        // Create AST for ID + expression, then assign
        ASTNode *id_node = create_id_node((yyvsp[(1) - (3)].strval));
        ASTNode *add_node = create_binop_node(OP_ADD, id_node, (yyvsp[(3) - (3)].ast));
        (yyval.ast) = create_assign_node((yyvsp[(1) - (3)].strval), add_node);
    ;}
    break;

  case 23:
#line 170 "parser.y"
    { 
        printf("VAR: %s\n", (yyvsp[(1) - (1)].strval));
        (yyval.ast) = create_id_node((yyvsp[(1) - (1)].strval));
    ;}
    break;

  case 24:
#line 174 "parser.y"
    { 
        printf("INT: %d\n", (yyvsp[(1) - (1)].intval));
        (yyval.ast) = create_int_node((yyvsp[(1) - (1)].intval));
    ;}
    break;

  case 25:
#line 178 "parser.y"
    { 
        printf("STRING: %s\n", (yyvsp[(1) - (1)].strval));
        (yyval.ast) = create_string_node((yyvsp[(1) - (1)].strval));
    ;}
    break;

  case 26:
#line 182 "parser.y"
    { 
        printf("FLOAT: %f\n", (yyvsp[(1) - (1)].floatval));
        (yyval.ast) = create_float_node((yyvsp[(1) - (1)].floatval));
    ;}
    break;

  case 27:
#line 186 "parser.y"
    { 
        printf("ADD\n");
        (yyval.ast) = create_binop_node(OP_ADD, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));
    ;}
    break;

  case 28:
#line 190 "parser.y"
    { 
        printf("SUBTRACT\n");
        (yyval.ast) = create_binop_node(OP_SUB, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast)); 
    ;}
    break;

  case 29:
#line 194 "parser.y"
    { 
        printf("MULTIPLY\n");
        (yyval.ast) = create_binop_node(OP_MUL, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));
    ;}
    break;

  case 30:
#line 198 "parser.y"
    { 
        printf("DIVIDE\n");
        (yyval.ast) = create_binop_node(OP_DIV, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));
    ;}
    break;

  case 31:
#line 202 "parser.y"
    { 
        printf("MODULO\n");
        (yyval.ast) = create_binop_node(OP_MOD, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));
    ;}
    break;

  case 32:
#line 206 "parser.y"
    { 
        printf("EQUALS\n");
        (yyval.ast) = create_binop_node(OP_EQ, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));
    ;}
    break;

  case 33:
#line 210 "parser.y"
    { 
        printf("NOT_EQUALS\n");
        (yyval.ast) = create_binop_node(OP_NE, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));
    ;}
    break;

  case 34:
#line 214 "parser.y"
    { 
        printf("LESS_THAN\n");
        (yyval.ast) = create_binop_node(OP_LT, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));
    ;}
    break;

  case 35:
#line 218 "parser.y"
    { 
        printf("GREATER_THAN\n");
        (yyval.ast) = create_binop_node(OP_GT, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));
    ;}
    break;

  case 36:
#line 222 "parser.y"
    { 
        printf("LESS_EQUAL\n");
        (yyval.ast) = create_binop_node(OP_LE, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));
    ;}
    break;

  case 37:
#line 226 "parser.y"
    { 
        printf("GREATER_EQUAL\n");
        (yyval.ast) = create_binop_node(OP_GE, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));
    ;}
    break;

  case 38:
#line 230 "parser.y"
    { 
        printf("LOGICAL_AND\n");
        (yyval.ast) = create_binop_node(OP_AND, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));
    ;}
    break;

  case 39:
#line 234 "parser.y"
    { 
        printf("LOGICAL_OR\n");
        (yyval.ast) = create_binop_node(OP_OR, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));
    ;}
    break;

  case 40:
#line 238 "parser.y"
    { 
        printf("LOGICAL_NOT\n");
        (yyval.ast) = create_unaryop_node(OP_NOT, (yyvsp[(2) - (2)].ast));
    ;}
    break;

  case 41:
#line 242 "parser.y"
    { 
        printf("NEGATE\n");
        (yyval.ast) = create_unaryop_node(OP_NEG, (yyvsp[(2) - (2)].ast));
    ;}
    break;

  case 42:
#line 246 "parser.y"
    { 
        printf("POST_INCREMENT: %s\n", (yyvsp[(1) - (2)].strval));
        (yyval.ast) = create_unaryop_node(OP_INC, create_id_node((yyvsp[(1) - (2)].strval)));
    ;}
    break;

  case 43:
#line 250 "parser.y"
    { 
        printf("POST_DECREMENT: %s\n", (yyvsp[(1) - (2)].strval));
        (yyval.ast) = create_unaryop_node(OP_DEC, create_id_node((yyvsp[(1) - (2)].strval)));
    ;}
    break;

  case 44:
#line 254 "parser.y"
    { 
        printf("FUNCTION_CALL: %s()\n", (yyvsp[(1) - (3)].strval));
        (yyval.ast) = create_funcall_node((yyvsp[(1) - (3)].strval), NULL, 0);
    ;}
    break;

  case 45:
#line 258 "parser.y"
    { 
        printf("FUNCTION_CALL_WITH_ARGS: %s(...)\n", (yyvsp[(1) - (4)].strval));
        // $3 is now an argument list node, use its fields
        (yyval.ast) = create_funcall_node((yyvsp[(1) - (4)].strval), (yyvsp[(3) - (4)].ast)->data.funcall.args, (yyvsp[(3) - (4)].ast)->data.funcall.arg_count);
        free((yyvsp[(3) - (4)].ast));  // Free the argument list node but not its args
    ;}
    break;

  case 46:
#line 264 "parser.y"
    { (yyval.ast) = (yyvsp[(2) - (3)].ast); ;}
    break;

  case 47:
#line 268 "parser.y"
    { 
        printf("IF\n");
        (yyval.ast) = NULL; // To be implemented
    ;}
    break;

  case 48:
#line 272 "parser.y"
    { 
        printf("IF-ELSE\n");
        (yyval.ast) = NULL; // To be implemented
    ;}
    break;

  case 49:
#line 279 "parser.y"
    { 
        printf("WHILE\n");
        (yyval.ast) = NULL; // To be implemented
    ;}
    break;

  case 50:
#line 286 "parser.y"
    { 
        printf("FOR\n");
        (yyval.ast) = NULL; // To be implemented
    ;}
    break;

  case 51:
#line 293 "parser.y"
    { (yyval.ast) = NULL; ;}
    break;

  case 52:
#line 294 "parser.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); ;}
    break;

  case 53:
#line 295 "parser.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); ;}
    break;

  case 54:
#line 296 "parser.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); ;}
    break;

  case 55:
#line 300 "parser.y"
    { (yyval.ast) = (yyvsp[(2) - (3)].ast); ;}
    break;

  case 56:
#line 301 "parser.y"
    { (yyval.ast) = NULL; ;}
    break;

  case 57:
#line 305 "parser.y"
    { 
        printf("RETURN\n");
        (yyval.ast) = NULL; 
    ;}
    break;

  case 58:
#line 309 "parser.y"
    { 
        printf("RETURN VALUE\n");
        (yyval.ast) = NULL; // To be implemented
    ;}
    break;

  case 59:
#line 316 "parser.y"
    { (yyval.ast) = NULL; ;}
    break;

  case 60:
#line 317 "parser.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); ;}
    break;

  case 61:
#line 321 "parser.y"
    { 
        printf("ARGUMENT\n");
        // Create an array with a single argument
        ASTNode **args = malloc(sizeof(ASTNode*));
        args[0] = (yyvsp[(1) - (1)].ast);
        (yyval.ast) = create_argument_list_node(args, 1);
    ;}
    break;

  case 62:
#line 328 "parser.y"
    { 
        printf("ARGUMENT_LIST\n");
        // Add the new expression to the existing argument list
        int new_count = (yyvsp[(1) - (3)].ast)->data.funcall.arg_count + 1;
        ASTNode **new_args = malloc(new_count * sizeof(ASTNode*));
        
        // Copy existing arguments
        for(int i = 0; i < (yyvsp[(1) - (3)].ast)->data.funcall.arg_count; i++) {
            new_args[i] = (yyvsp[(1) - (3)].ast)->data.funcall.args[i];
        }
        
        // Add the new argument
        new_args[new_count - 1] = (yyvsp[(3) - (3)].ast);
        
        // Create a new argument list node
        (yyval.ast) = create_argument_list_node(new_args, new_count);
    ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2007 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
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
      if (yyn != YYPACT_NINF)
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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


#line 347 "parser.y"


// Error handling function
void yyerror(const char *s) {  
    fprintf(stderr, "Syntax Error: %s at line %d\n", s, yylineno);  
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    yyin = file;  // Set the input stream for Flex
    yyparse();

    fclose(file);
    return 0;
}

