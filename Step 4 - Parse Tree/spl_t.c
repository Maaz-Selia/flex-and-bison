
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "spl.y"


#include <stdio.h>
#include <stdlib.h>

int yylex (void);
void yyerror (char *);

/* 
   Some constants.
*/

  /* These constants are used later in the code */
#define SYMTABSIZE     50
#define IDLENGTH       15
#define NOTHING        -1
#define INDENTOFFSET    2

enum ParseTreeNodeType { PROGRAM, BLOCK, IDENTIFIER, IDENTIFIER_LIST, DECLARATION_BLOCK, TYPE_T, STATEMENT_LIST, STATEMENT, ASSIGNMENT_STATEMENT, IF_STATEMENT, DO_STATEMENT, 
						WHILE_STATEMENT, FOR_STATEMENT, WRITE_STATEMENT, READ_STATEMENT, OUTPUT_LIST, LOGICAL_OPERATOR, BASIC_CONDITIONAL, CONDITIONAL, COMPARATOR, EXPRESSION, PLUS_EXPRESSION, 
						MINUS_EXPRESSION, TERM, TIMES_TERM, DIVIDE_TERM, VALUE, IDENTIFIER_VALUE, CONSTANT_VALUE, CONSTANT, CHARACTER_CONSTANT, NUMBER_CONSTANT} ;

char *NodeName[] = { "PROGRAM", "BLOCK", "IDENTIFIER", "IDENTIFIER_LIST", "DECLARATION_BLOCK", "TYPE_T", "STATEMENT_LIST", "STATEMENT", "ASSIGNMENT_STATEMENT", "IF_STATEMENT", 
					"DO_STATEMENT", "WHILE_STATEMENT", "FOR_STATEMENT", "WRITE_STATEMENT", "READ_STATEMENT", "OUTPUT_LIST", "LOGICAL_OPERATOR", "BASIC_CONDITIONAL", "CONDITIONAL", 
					"COMPARATOR", "EXPRESSION", "PLUS_EXPRESSION", "MINUS_EXPRESSION", "TERM", "TIMES_TERM", "DIVIDE_TERM", "VALUE", "IDENTIFIER_VALUE", "CONSTANT_VALUE", 
					"CONSTANT", "CHARACTER_CONSTANT", "NUMBER_CONSTANT"} ;

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef NULL
#define NULL 0
#endif

/* ------------- statement trackerS ------------------------------ */

int firstRead = 1;
int firstFor = 1;
int insideStat = 0;
int singleOutput = 1;
char* currentID[80];

/* ------------- parse tree definition --------------------------- */

struct treeNode {
    int  item;
    int  nodeIdentifier;
    struct treeNode *first;
    struct treeNode *second;
    struct treeNode *third;
  };

typedef  struct treeNode TREE_NODE;
typedef  TREE_NODE        *TERNARY_TREE;

/* ------------- forward declarations --------------------------- */

TERNARY_TREE create_node(int,int,TERNARY_TREE,TERNARY_TREE,TERNARY_TREE);
#ifdef DEBUG
void PrintTree(TERNARY_TREE, int);
#else
void codeGenerate(TERNARY_TREE);
#endif
/* ------------- symbol table definition --------------------------- */

struct symTabNode {
    char identifier[IDLENGTH];
};

typedef  struct symTabNode SYMTABNODE;
typedef  SYMTABNODE        *SYMTABNODEPTR;

SYMTABNODEPTR  symTab[SYMTABSIZE]; 

int currentSymTabSize = 0;



/* Line 189 of yacc.c  */
#line 157 "spl_t.c"

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     FULLSTOP = 258,
     COMMA = 259,
     COLON = 260,
     SEMICOLON = 261,
     ASSIGN = 262,
     BRA = 263,
     KET = 264,
     EQUAL = 265,
     NOT_EQUAL = 266,
     LESS_THAN = 267,
     GREATER_THAN = 268,
     LESS_THAN_OR_EQUAL = 269,
     GREATER_THAN_OR_EQUAL = 270,
     PLUS = 271,
     MINUS = 272,
     TIMES = 273,
     DIVIDE = 274,
     APOSTROPHE = 275,
     ENDP = 276,
     DECLARATIONS = 277,
     CODE = 278,
     OF = 279,
     TYPE = 280,
     CHARACTER = 281,
     INTEGER = 282,
     REAL = 283,
     IF = 284,
     THEN = 285,
     ENDIF = 286,
     ELSE = 287,
     DO = 288,
     WHILE = 289,
     ENDDO = 290,
     ENDWHILE = 291,
     FOR = 292,
     IS = 293,
     BY = 294,
     TO = 295,
     ENDFOR = 296,
     WRITE = 297,
     READ = 298,
     NEWLINE = 299,
     NOT = 300,
     AND = 301,
     OR = 302,
     LETTER = 303,
     DIGIT = 304,
     ID = 305
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 94 "spl.y"

    int iVal;
    TERNARY_TREE  tVal;



/* Line 214 of yacc.c  */
#line 250 "spl_t.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 262 "spl_t.c"

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
# if YYENABLE_NLS
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   172

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNRULES -- Number of states.  */
#define YYNSTATES  122

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,    10,    15,    18,    20,    22,    26,    32,
      39,    41,    43,    45,    47,    51,    53,    55,    57,    59,
      61,    63,    65,    69,    75,    83,    89,    95,   107,   112,
     114,   119,   121,   125,   127,   129,   133,   136,   138,   142,
     144,   146,   148,   150,   152,   154,   156,   159,   163,   167,
     169,   173,   177,   179,   181,   185,   187,   189,   191
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      52,     0,    -1,    54,     5,    53,    21,    54,     3,    -1,
      22,    56,    23,    58,    -1,    23,    58,    -1,    50,    -1,
      54,    -1,    55,     4,    54,    -1,    55,    24,    25,    57,
       6,    -1,    56,    55,    24,    25,    57,     6,    -1,    26,
      -1,    27,    -1,    28,    -1,    59,    -1,    58,     6,    59,
      -1,    60,    -1,    61,    -1,    62,    -1,    63,    -1,    64,
      -1,    65,    -1,    66,    -1,    72,     7,    54,    -1,    29,
      70,    30,    58,    31,    -1,    29,    70,    30,    58,    32,
      58,    31,    -1,    33,    58,    34,    70,    35,    -1,    34,
      70,    33,    58,    36,    -1,    37,    54,    38,    72,    39,
      72,    40,    72,    33,    58,    41,    -1,    42,     8,    67,
       9,    -1,    44,    -1,    43,     8,    54,     9,    -1,    74,
      -1,    67,     4,    74,    -1,    46,    -1,    47,    -1,    72,
      71,    72,    -1,    45,    69,    -1,    69,    -1,    70,    68,
      69,    -1,    10,    -1,    11,    -1,    12,    -1,    13,    -1,
      14,    -1,    15,    -1,    73,    -1,    72,    73,    -1,    72,
      16,    73,    -1,    72,    17,    73,    -1,    74,    -1,    73,
      18,    74,    -1,    73,    19,    74,    -1,    54,    -1,    75,
      -1,     8,    72,     9,    -1,    77,    -1,    76,    -1,    48,
      -1,    49,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   107,   107,   119,   123,   128,   134,   138,   143,   147,
     152,   156,   160,   165,   169,   174,   178,   182,   186,   190,
     194,   198,   203,   208,   212,   217,   222,   227,   234,   238,
     243,   248,   252,   257,   261,   266,   270,   275,   279,   284,
     288,   292,   296,   300,   304,   309,   313,   317,   321,   326,
     330,   334,   339,   343,   347,   352,   356,   361,   367
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FULLSTOP", "COMMA", "COLON",
  "SEMICOLON", "ASSIGN", "BRA", "KET", "EQUAL", "NOT_EQUAL", "LESS_THAN",
  "GREATER_THAN", "LESS_THAN_OR_EQUAL", "GREATER_THAN_OR_EQUAL", "PLUS",
  "MINUS", "TIMES", "DIVIDE", "APOSTROPHE", "ENDP", "DECLARATIONS", "CODE",
  "OF", "TYPE", "CHARACTER", "INTEGER", "REAL", "IF", "THEN", "ENDIF",
  "ELSE", "DO", "WHILE", "ENDDO", "ENDWHILE", "FOR", "IS", "BY", "TO",
  "ENDFOR", "WRITE", "READ", "NEWLINE", "NOT", "AND", "OR", "LETTER",
  "DIGIT", "ID", "$accept", "program", "block", "identifier",
  "identifier_list", "declaration_block", "type", "statement_list",
  "statement", "assignment_statement", "if_statement", "do_statement",
  "while_statement", "for_statement", "write_statement", "read_statement",
  "output_list", "logical_operator", "basic_conditional", "conditional",
  "comparator", "expression", "term", "value", "constant",
  "character_constant", "number_constant", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    54,    55,    55,    56,    56,
      57,    57,    57,    58,    58,    59,    59,    59,    59,    59,
      59,    59,    60,    61,    61,    62,    63,    64,    65,    65,
      66,    67,    67,    68,    68,    69,    69,    70,    70,    71,
      71,    71,    71,    71,    71,    72,    72,    72,    72,    73,
      73,    73,    74,    74,    74,    75,    75,    76,    77
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     4,     2,     1,     1,     3,     5,     6,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     3,     5,     7,     5,     5,    11,     4,     1,
       4,     1,     3,     1,     1,     3,     2,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     3,     1,
       3,     3,     1,     1,     3,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,     0,     0,     1,     0,     0,     0,     0,     6,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    29,
      57,    58,    52,     4,    13,    15,    16,    17,    18,    19,
      20,    21,     0,    45,    49,    53,    56,    55,     0,     0,
       0,     0,     0,     0,     0,    37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    46,     0,     0,
       0,     7,     0,     3,     0,    54,    36,     0,    33,    34,
       0,    39,    40,    41,    42,    43,    44,     0,     0,     0,
       0,     0,    31,     0,    14,    22,    47,    48,    50,    51,
       2,    10,    11,    12,     0,     0,     0,    38,    35,     0,
       0,     0,     0,    28,    30,     8,     0,    23,     0,    25,
      26,     0,    32,     9,     0,     0,    24,     0,     0,     0,
       0,    27
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     8,    22,    10,    11,    94,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    81,    70,    45,    46,
      77,    32,    33,    34,    35,    36,    37
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -32
static const yytype_int16 yypact[] =
{
     -31,   -32,    24,    20,   -32,    84,   -31,    52,     9,   -32,
      51,    -2,    95,    14,    52,    14,   -31,    37,    82,   -32,
     -32,   -32,   -32,    91,   -32,   -32,   -32,   -32,   -32,   -32,
     -32,   -32,    30,    -4,   -32,   -32,   -32,   -32,   -31,   -31,
      79,    52,    63,    34,    14,   -32,    46,   100,     5,   107,
      80,    95,   -31,    52,   -31,    95,    95,    -4,    95,    95,
     116,   -32,    98,    91,    96,   -32,   -32,    52,   -32,   -32,
      14,   -32,   -32,   -32,   -32,   -32,   -32,    95,    14,    52,
      95,     8,   -32,   113,   -32,   -32,    -4,    -4,   -32,   -32,
     -32,   -32,   -32,   -32,   127,    98,    21,   -32,   122,    26,
       0,   112,    95,   -32,   -32,   -32,   128,   -32,    52,   -32,
     -32,    95,   -32,   -32,     4,   115,   -32,    95,   119,    52,
       3,   -32
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -32,   -32,   -32,     2,   126,   -32,    47,   -10,    88,   -32,
     -32,   -32,   -32,   -32,   -32,   -32,   -32,   -32,   -21,    -8,
     -32,   -12,   -27,   -25,   -32,   -32,   -32
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      43,    47,     3,    47,    48,    57,    53,    49,     9,    53,
      53,    53,   102,     9,    58,    59,    57,   103,    50,     1,
      57,    41,    12,    66,     4,     5,    82,    53,    86,    87,
      38,    63,    47,    88,    89,   116,   110,    54,    12,    78,
      60,    61,    12,    65,   121,    51,    55,    56,     1,    97,
      55,    56,   107,   108,    83,    39,    85,    96,    47,    44,
      12,   109,    20,    21,     1,    98,    47,    39,   101,   100,
      99,    57,    68,    69,    57,    40,    67,   112,    20,    21,
       1,    13,    20,    21,     1,    14,    15,    64,    57,    16,
      52,    57,    68,    69,    17,    18,    19,    53,   114,   115,
      20,    21,     1,    12,    62,   118,     6,     7,    12,   120,
      71,    72,    73,    74,    75,    76,    55,    56,    80,    90,
      12,    95,   104,    12,    91,    92,    93,    12,    55,    56,
      12,    55,    56,   105,   113,    55,    56,    42,    55,    56,
      79,    84,   106,    20,    21,     1,     0,     0,    20,    21,
       1,   111,   119,    68,    69,   117,     0,     0,     0,     0,
      20,    21,     1,    20,    21,     1,     0,    20,    21,     1,
      20,    21,     1
};

static const yytype_int8 yycheck[] =
{
      12,    13,     0,    15,    14,    32,     6,    15,     6,     6,
       6,     6,     4,    11,    18,    19,    43,     9,    16,    50,
      47,    23,     8,    44,     0,     5,    51,     6,    55,    56,
      21,    41,    44,    58,    59,    31,    36,     7,     8,    34,
      38,    39,     8,     9,    41,     8,    16,    17,    50,    70,
      16,    17,    31,    32,    52,     4,    54,    67,    70,    45,
       8,    35,    48,    49,    50,    77,    78,     4,    80,    79,
      78,    98,    46,    47,   101,    24,    30,   102,    48,    49,
      50,    29,    48,    49,    50,    33,    34,    24,   115,    37,
       8,   118,    46,    47,    42,    43,    44,     6,   108,   111,
      48,    49,    50,     8,    25,   117,    22,    23,     8,   119,
      10,    11,    12,    13,    14,    15,    16,    17,    38,     3,
       8,    25,     9,     8,    26,    27,    28,     8,    16,    17,
       8,    16,    17,     6,     6,    16,    17,    11,    16,    17,
      33,    53,    95,    48,    49,    50,    -1,    -1,    48,    49,
      50,    39,    33,    46,    47,    40,    -1,    -1,    -1,    -1,
      48,    49,    50,    48,    49,    50,    -1,    48,    49,    50,
      48,    49,    50
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    50,    52,    54,     0,     5,    22,    23,    53,    54,
      55,    56,     8,    29,    33,    34,    37,    42,    43,    44,
      48,    49,    54,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    72,    73,    74,    75,    76,    77,    21,     4,
      24,    23,    55,    72,    45,    69,    70,    72,    58,    70,
      54,     8,     8,     6,     7,    16,    17,    73,    18,    19,
      54,    54,    25,    58,    24,     9,    69,    30,    46,    47,
      68,    10,    11,    12,    13,    14,    15,    71,    34,    33,
      38,    67,    74,    54,    59,    54,    73,    73,    74,    74,
       3,    26,    27,    28,    57,    25,    58,    69,    72,    70,
      58,    72,     4,     9,     9,     6,    57,    31,    32,    35,
      36,    39,    74,     6,    58,    72,    31,    40,    72,    33,
      58,    41
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
# if YYLTYPE_IS_TRIVIAL
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

/* Line 1455 of yacc.c  */
#line 108 "spl.y"
    {
			TERNARY_TREE ParseTree;
			ParseTree = create_node(NOTHING, PROGRAM, (yyvsp[(1) - (6)].tVal), (yyvsp[(3) - (6)].tVal), (yyvsp[(5) - (6)].tVal));			
			
			#ifdef DEBUG
				PrintTree(ParseTree, 0);
			#else
				codeGenerate(ParseTree);
			#endif
		;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 120 "spl.y"
    {
			(yyval.tVal) = create_node(NOTHING, BLOCK, (yyvsp[(2) - (4)].tVal), (yyvsp[(4) - (4)].tVal), NULL);
		;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 124 "spl.y"
    {
			(yyval.tVal) = create_node(NOTHING, BLOCK, (yyvsp[(2) - (2)].tVal), NULL, NULL);
		;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 129 "spl.y"
    {
				(yyval.tVal) = create_node((yyvsp[(1) - (1)].iVal), IDENTIFIER, NULL, NULL, NULL);
			;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 135 "spl.y"
    {
					(yyval.tVal) = create_node(NOTHING, IDENTIFIER_LIST, (yyvsp[(1) - (1)].tVal), NULL, NULL);
				;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 139 "spl.y"
    {
					(yyval.tVal) = create_node(NOTHING, IDENTIFIER_LIST, (yyvsp[(1) - (3)].tVal), (yyvsp[(3) - (3)].tVal), NULL);
				;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 144 "spl.y"
    {
						(yyval.tVal) = create_node(NOTHING, DECLARATION_BLOCK, (yyvsp[(1) - (5)].tVal), (yyvsp[(4) - (5)].tVal), NULL);
					;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 148 "spl.y"
    {
						(yyval.tVal) = create_node(NOTHING, DECLARATION_BLOCK, (yyvsp[(1) - (6)].tVal), (yyvsp[(2) - (6)].tVal), (yyvsp[(5) - (6)].tVal));
					;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 153 "spl.y"
    {
			(yyval.tVal) =  create_node(CHARACTER, TYPE_T, NULL, NULL, NULL);
		;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 157 "spl.y"
    {
			(yyval.tVal) =  create_node(INTEGER, TYPE_T, NULL, NULL, NULL);
		;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 161 "spl.y"
    {
			(yyval.tVal) =  create_node(REAL, TYPE_T, NULL, NULL, NULL);
		;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 166 "spl.y"
    {
					(yyval.tVal) = create_node(NOTHING, STATEMENT_LIST, (yyvsp[(1) - (1)].tVal), NULL, NULL);
				;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 170 "spl.y"
    {
					(yyval.tVal) = create_node(NOTHING, STATEMENT_LIST, (yyvsp[(1) - (3)].tVal), (yyvsp[(3) - (3)].tVal), NULL);
				;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 175 "spl.y"
    {
				(yyval.tVal) = create_node(NOTHING, STATEMENT, (yyvsp[(1) - (1)].tVal), NULL, NULL);
			;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 179 "spl.y"
    {
				(yyval.tVal) = create_node(NOTHING, STATEMENT, (yyvsp[(1) - (1)].tVal), NULL, NULL);
			;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 183 "spl.y"
    {
				(yyval.tVal) = create_node(NOTHING, STATEMENT, (yyvsp[(1) - (1)].tVal), NULL, NULL);
			;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 187 "spl.y"
    {
				(yyval.tVal) = create_node(NOTHING, STATEMENT, (yyvsp[(1) - (1)].tVal), NULL, NULL);
			;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 191 "spl.y"
    {
				(yyval.tVal) = create_node(NOTHING, STATEMENT, (yyvsp[(1) - (1)].tVal), NULL, NULL);
			;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 195 "spl.y"
    {
				(yyval.tVal) = create_node(NOTHING, STATEMENT, (yyvsp[(1) - (1)].tVal), NULL, NULL);
			;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 199 "spl.y"
    {
				(yyval.tVal) = create_node(NOTHING, STATEMENT, (yyvsp[(1) - (1)].tVal), NULL, NULL);
			;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 204 "spl.y"
    {
							(yyval.tVal) = create_node(NOTHING, ASSIGNMENT_STATEMENT, (yyvsp[(1) - (3)].tVal), (yyvsp[(3) - (3)].tVal), NULL);
						;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 209 "spl.y"
    {
					(yyval.tVal) = create_node(NOTHING, IF_STATEMENT, (yyvsp[(2) - (5)].tVal), (yyvsp[(4) - (5)].tVal), NULL);
				;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 213 "spl.y"
    {
					(yyval.tVal) = create_node(NOTHING, IF_STATEMENT, (yyvsp[(2) - (7)].tVal), (yyvsp[(4) - (7)].tVal), (yyvsp[(6) - (7)].tVal));
				;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 218 "spl.y"
    { 
					(yyval.tVal) = create_node(NOTHING, DO_STATEMENT, (yyvsp[(2) - (5)].tVal), (yyvsp[(4) - (5)].tVal), NULL);
				;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 223 "spl.y"
    {
					(yyval.tVal) = create_node(NOTHING, WHILE_STATEMENT, (yyvsp[(2) - (5)].tVal), (yyvsp[(4) - (5)].tVal), NULL);
				;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 228 "spl.y"
    {
					(yyval.tVal) = create_node(NOTHING, FOR_STATEMENT, (yyvsp[(2) - (11)].tVal), 
															create_node(NOTHING, FOR_STATEMENT, (yyvsp[(4) - (11)].tVal), (yyvsp[(6) - (11)].tVal), (yyvsp[(8) - (11)].tVal)),
															(yyvsp[(10) - (11)].tVal));
				;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 235 "spl.y"
    {
					(yyval.tVal) = create_node(NOTHING, WRITE_STATEMENT, (yyvsp[(3) - (4)].tVal), NULL, NULL);
				;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 239 "spl.y"
    {
					(yyval.tVal) = create_node(NEWLINE, WRITE_STATEMENT, NULL, NULL, NULL);
				;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 244 "spl.y"
    {
					(yyval.tVal) = create_node(NOTHING, READ_STATEMENT, (yyvsp[(3) - (4)].tVal), NULL, NULL);
				;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 249 "spl.y"
    {
					(yyval.tVal) = create_node(NOTHING, OUTPUT_LIST, (yyvsp[(1) - (1)].tVal), NULL, NULL);
				;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 253 "spl.y"
    {
					(yyval.tVal) = create_node(NOTHING, OUTPUT_LIST, (yyvsp[(1) - (3)].tVal), (yyvsp[(3) - (3)].tVal), NULL);
				;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 258 "spl.y"
    {
						(yyval.tVal) = create_node(AND, LOGICAL_OPERATOR, NULL, NULL, NULL);
					;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 262 "spl.y"
    {
						(yyval.tVal) = create_node(OR, LOGICAL_OPERATOR, NULL, NULL, NULL);
					;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 267 "spl.y"
    {
						(yyval.tVal) = create_node(NOTHING, BASIC_CONDITIONAL, (yyvsp[(1) - (3)].tVal), (yyvsp[(2) - (3)].tVal), (yyvsp[(3) - (3)].tVal));
					;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 271 "spl.y"
    {
						(yyval.tVal) = create_node(NOTHING, BASIC_CONDITIONAL, (yyvsp[(2) - (2)].tVal), NULL, NULL);
					;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 276 "spl.y"
    {
					(yyval.tVal) = create_node(NOTHING, CONDITIONAL, (yyvsp[(1) - (1)].tVal), NULL, NULL);
				;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 280 "spl.y"
    {
					(yyval.tVal) = create_node(NOTHING, CONDITIONAL, (yyvsp[(1) - (3)].tVal), (yyvsp[(2) - (3)].tVal), (yyvsp[(3) - (3)].tVal));
				;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 285 "spl.y"
    {
				(yyval.tVal) = create_node(EQUAL, COMPARATOR, NULL, NULL, NULL);
			;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 289 "spl.y"
    {
				(yyval.tVal) = create_node(NOT_EQUAL, COMPARATOR, NULL, NULL, NULL);
			;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 293 "spl.y"
    {
				(yyval.tVal) = create_node(LESS_THAN, COMPARATOR, NULL, NULL, NULL);
			;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 297 "spl.y"
    {
				(yyval.tVal) = create_node(GREATER_THAN, COMPARATOR, NULL, NULL, NULL);
			;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 301 "spl.y"
    {
				(yyval.tVal) = create_node(LESS_THAN_OR_EQUAL, COMPARATOR, NULL, NULL, NULL);
			;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 305 "spl.y"
    {
				(yyval.tVal) = create_node(GREATER_THAN_OR_EQUAL, COMPARATOR, NULL, NULL, NULL);
			;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 310 "spl.y"
    {
				(yyval.tVal) = create_node(NOTHING, EXPRESSION, (yyvsp[(1) - (1)].tVal), NULL, NULL);
			;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 314 "spl.y"
    {
				(yyval.tVal) = create_node(NOTHING, EXPRESSION, (yyvsp[(1) - (2)].tVal), (yyvsp[(2) - (2)].tVal), NULL);
			;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 318 "spl.y"
    {
				(yyval.tVal) = create_node(NOTHING, PLUS_EXPRESSION, (yyvsp[(1) - (3)].tVal), (yyvsp[(3) - (3)].tVal), NULL);
			;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 322 "spl.y"
    {
				(yyval.tVal) = create_node(NOTHING, MINUS_EXPRESSION, (yyvsp[(1) - (3)].tVal), (yyvsp[(3) - (3)].tVal), NULL);
			;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 327 "spl.y"
    {
			(yyval.tVal) = create_node(NOTHING, TERM, (yyvsp[(1) - (1)].tVal), NULL, NULL);
		;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 331 "spl.y"
    {
			(yyval.tVal) = create_node(NOTHING, TIMES_TERM, (yyvsp[(1) - (3)].tVal), (yyvsp[(3) - (3)].tVal), NULL);
		;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 335 "spl.y"
    {
			(yyval.tVal) = create_node(NOTHING, DIVIDE_TERM, (yyvsp[(1) - (3)].tVal), (yyvsp[(3) - (3)].tVal), NULL);
		;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 340 "spl.y"
    {
			(yyval.tVal) = create_node(NOTHING, IDENTIFIER_VALUE, (yyvsp[(1) - (1)].tVal), NULL, NULL);
		;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 344 "spl.y"
    {
			(yyval.tVal) = create_node(NOTHING, CONSTANT_VALUE, (yyvsp[(1) - (1)].tVal), NULL, NULL);
		;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 348 "spl.y"
    {
			(yyval.tVal) = create_node(NOTHING, VALUE, (yyvsp[(2) - (3)].tVal), NULL, NULL);
		;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 353 "spl.y"
    {
				(yyval.tVal) = create_node(NOTHING, CONSTANT, (yyvsp[(1) - (1)].tVal), NULL, NULL);
			;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 357 "spl.y"
    {
				(yyval.tVal) = create_node(NOTHING, CONSTANT, (yyvsp[(1) - (1)].tVal), NULL, NULL);
			;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 362 "spl.y"
    {
						(yyval.tVal) = create_node((yyvsp[(1) - (1)].iVal), CHARACTER_CONSTANT, NULL, NULL, NULL);
					;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 368 "spl.y"
    {
						(yyval.tVal) = create_node((yyvsp[(1) - (1)].iVal), NUMBER_CONSTANT, NULL, NULL, NULL);
					;}
    break;



/* Line 1455 of yacc.c  */
#line 2096 "spl_t.c"
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
		      yytoken, &yylval);
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
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



/* Line 1675 of yacc.c  */
#line 373 "spl.y"


TERNARY_TREE create_node(int ival, int case_identifier, TERNARY_TREE p1,
			 TERNARY_TREE  p2, TERNARY_TREE  p3)
{
    TERNARY_TREE t;
    t = (TERNARY_TREE)malloc(sizeof(TREE_NODE));
    t->item = ival;
    t->nodeIdentifier = case_identifier;
    t->first = p1;
    t->second = p2;
    t->third = p3;
    return (t);
}

#ifdef DEBUG
void PrintTree(TERNARY_TREE t, int indent)
{
	int i;
	if (t == NULL) return;
	for (i=indent; i; i--) printf(" ");

	if (t->nodeIdentifier == NUMBER_CONSTANT)
			printf("%d ", t->item);
	else if (t->nodeIdentifier == CHARACTER_CONSTANT) {
			/* EDIT ME */
	}
	else if (t->nodeIdentifier == IDENTIFIER || t->nodeIdentifier == ASSIGNMENT_STATEMENT) 
		if (t->item >= 0 && t->item < SYMTABSIZE)
			printf("'%s'", symTab[t->item]->identifier);
		else 
			printf("Unknown Identifier: %d ", t->item);
			
	if(t->item != NOTHING) printf(" Item: %d ", t->item);
	if (t->nodeIdentifier < 0 || t->nodeIdentifier > sizeof(NodeName))
		printf("Unknown nodeIdentifier: %d\n", t->nodeIdentifier);
	else
	{
		printf("%s\n", NodeName[t->nodeIdentifier]);
		PrintTree(t->first, indent+3);
		PrintTree(t->second, indent+3);
		PrintTree(t->third, indent+3);		
	}
}

#else
void codeGenerate(TERNARY_TREE t)
{
	if (t == NULL) return;
	
	switch(t->nodeIdentifier)
	{
		case(PROGRAM) :
		
			/* ------ Header files - for generated .c file ------ */			
			printf("#include <stdio.h>\n");
			printf("#include <stddef.h>\n");
			printf("#include <stdlib.h>\n");
			printf("#include <stdint.h>\n");
			printf("\n");
			
			
			/* ------ Type introspection ------ */
			/* ------ https://stackoverflow.com/questions/26728333/is-there-a-generic-conversion-specifier-for-printf ------ */		
			printf("#define typename(x) _Generic((x), int: \"int\", float: \"float\", default: \"other\")\n");
			
			
			/* ------ Runtime Type specific printf ------ */
			/* ------ https://stackoverflow.com/questions/26728333/is-there-a-generic-conversion-specifier-for-printf/26728390 ------ */
			printf("#define print_any(X) _Generic((X), int: print_int, char *: print_pchar, char: print_char, float: print_float)(X)\n");
			printf("\nint print_int(int i) { return printf(\"%%d\", i); }\n");
			printf("\nint print_float(float f) { return printf(\"%%f\", f); }\n");
			printf("\nint print_pchar(char *c) { return printf(\"%%s\", c); }\n");
			printf("\nint print_char(char c) { return printf(\"%%c\", c); }\n");
			
			/* ------ writing out main function ------ */
			printf("\nint main(void) {\n\n");
			codeGenerate(t->second);
			printf("\n}\n");
			
			return;
			
		case(BLOCK) :
		
			codeGenerate(t->first);
			if(t->second != NULL)
				codeGenerate(t->second);
			
			return;
		
		case(IDENTIFIER) :		
			
			/* ------ Retrieve identifier from SYMTAB and print ------ */
			if (t->item >= 0 && t->item < SYMTABSIZE) {
				printf("%s", symTab[t->item]->identifier);
				*currentID = symTab[t->item]->identifier;
			}
			
			return;
			
		case(IDENTIFIER_LIST) :
			
			if(t->second != NULL) {		
				codeGenerate(t->first);
				printf(", ");
				codeGenerate(t->second);
			} 
			else {
				codeGenerate(t->first);
			}
			
			return;
			
		case(DECLARATION_BLOCK) :
			
			if(t->third != NULL) {
				codeGenerate(t->first);
				codeGenerate(t->third);
				printf(" ");
				codeGenerate(t->second);
				printf(";\n\n");
			}
			else {
				codeGenerate(t->second);
				printf(" ");
				codeGenerate(t->first);
				printf(";\n\n");
			}			
			
			return;
			
		case(TYPE_T) :
			
			if(t->item == CHARACTER)
				printf("\tchar");
			else if(t->item == INTEGER)
				printf("\tint");
			else if(t->item == REAL)
				printf("\tfloat");
			
			return;
			
		case(STATEMENT_LIST) :
		
			if(t->second != NULL) {
				codeGenerate(t->first);
				if(insideStat == 1)
					printf("\t");
				codeGenerate(t->second);
			}
			else {
				codeGenerate(t->first);
			}
			return;
			
		case(STATEMENT) :
			
			codeGenerate(t->first);
		
			return;
			
		case(ASSIGNMENT_STATEMENT) :
			
			printf("\t");
			codeGenerate(t->second);
			printf(" = ");
			codeGenerate(t->first);
			printf(";\n");
			
			return;
			
		case(IF_STATEMENT) :
			
			if(t->third != NULL) {			
				/* ------ if with else ------ */
				printf("\n\tif (");
				codeGenerate(t->first);
				printf(") {\n\t");
				codeGenerate(t->second);
				printf("\t}\n\telse {\n\t");
				codeGenerate(t->third);
				printf("\t}\n\n");
			}
			else {
				printf("\n\tif (");
				codeGenerate(t->first);
				printf(") {\n\t");
				codeGenerate(t->second);
				printf("\t}\n\n");
			}
			return;
			
		case(DO_STATEMENT) :
		
			printf("\n\tdo {\n\t");
			codeGenerate(t->first);
			printf("\t} while (");
			codeGenerate(t->second);
			printf(");\n\n");
			
			return;
			
		case(WHILE_STATEMENT) :
			
			printf("\n\twhile (");
			codeGenerate(t->first);
			printf(") {\n\t");
			codeGenerate(t->second);
			printf("\t}\n\n");
			
			return;
			
		case(FOR_STATEMENT) :

			/* ------ implementation of for loop from FORLOOP.html, from coursework notes ------ */
			/* ------ if first forloop the file: add _by variable ------ */
			if(firstFor == 1) {
				printf("\tregister int _by;\n");
				firstFor = 0;
			}

			printf("\tfor ( ");
			codeGenerate(t->first);
			printf(" = ");
			codeGenerate(t->second->first);
			printf(" ; _by = ");
			codeGenerate(t->second->second);
			printf(" , ( ");
			codeGenerate(t->first);
			printf(" -( ");
			codeGenerate(t->second->third);
			printf(" ))*((_by > 0) - (_by < 0)) <= 0 ; ");
			codeGenerate(t->first);
			printf(" += _by) {\n\t");
			codeGenerate(t->third);
			printf("\t}\n\n");
			
			return;
			
		case(WRITE_STATEMENT) :
			
			if(t->item == NEWLINE) {
				printf("\tprintf(\"\\n\");\n");
			}
			else {
				printf("\t");
				codeGenerate(t->first);
			}			
			
			return;
			
		case(READ_STATEMENT) :
			
			/* ------ if first read of the file: add read variable ------ */
			if(firstRead == 1) {
				printf("\tchar str[254];\n");
				firstRead = 0;
			}
			
			/* printf("\tprintf(\"Please enter a value: \");\n"); */
			printf("\tscanf(\"%%s\", str);\n");
			
			
			/* ---------- Type introspection ---------- */		
			printf("\tif(typename(");
			codeGenerate(t->first);
			printf(") == \"other\")\n\t\t");
			codeGenerate(t->first);
			printf(" = *str;\n");
			printf("\telse if(typename(");
			codeGenerate(t->first);
			printf(") == \"int\")\n\t\t");
			codeGenerate(t->first);
			printf(" = atoi(str);\n");
			printf("\telse if(typename(");
			codeGenerate(t->first);
			printf(") == \"float\")\n\t\t");
			codeGenerate(t->first);
			printf(" = atof(str);\n\n");
			
			return;
			
		case(OUTPUT_LIST) :
		
			if(t->second != NULL) {
				singleOutput = 0;
				codeGenerate(t->first);
				printf("\tprint_any(");				
				codeGenerate(t->second);
				printf(");\n");
			}
			else {
				printf("print_any(");
				/*
				if (singleOutput == 1)
					printf("%s", *currentID);
				else
					codeGenerate(t->first);
				*/
				codeGenerate(t->first);
				printf(");\n");
				singleOutput = 1;
			}
			return;
			
		case(LOGICAL_OPERATOR) :
		
			if(t->item == AND)
				printf(" && ");
			if(t->item == OR)
				printf(" || ");
			
			return;
			
		case(BASIC_CONDITIONAL) :
		
			if(t->second != NULL) {
				codeGenerate(t->first);
				codeGenerate(t->second);
				codeGenerate(t->third);
				return;
			}
			printf("!( ");
			codeGenerate(t->first);
			printf(" )");
			
			return;
			
		case(CONDITIONAL) :
		
			if(t->second == NULL)
				codeGenerate(t->first);
			else {
				codeGenerate(t->first);
				codeGenerate(t->second);
				codeGenerate(t->third);
			}
			
			return;
			
		case(COMPARATOR) :
		
			if (t->item == EQUAL)
				printf(" == ");
			else if (t->item == NOT_EQUAL)
				printf(" != ");
			else if (t->item == LESS_THAN)
				printf(" < ");
			else if (t->item == GREATER_THAN)
				printf(" > ");
			else if (t->item == LESS_THAN_OR_EQUAL)
				printf(" <= ");
			else if (t->item == GREATER_THAN_OR_EQUAL)
				printf(" >= ");
				
			return;
			
		case(EXPRESSION) :
		
			if(t->second != NULL) {
				codeGenerate(t->first);
				codeGenerate(t->second);
			}
			else {
				codeGenerate(t->first);
			}
			
			return;
			
		case(PLUS_EXPRESSION) :
		
			codeGenerate(t->first);
			printf(" + ");
			codeGenerate(t->second);
			
			return;
			
		case(MINUS_EXPRESSION) :
		
			codeGenerate(t->first);
			printf(" - ");
			codeGenerate(t->second);
			
			return;
			
		case(TERM) :
			
			codeGenerate(t->first);
			
			return;
			
		case(TIMES_TERM) :
		
			codeGenerate(t->first);
			printf(" * ");
			codeGenerate(t->second);
			
			return;
			
		case(DIVIDE_TERM) :
		
			codeGenerate(t->first);
			printf(" / ");
			codeGenerate(t->second);
			
			return;
			
		case(VALUE) :
		
			printf("(");
			codeGenerate(t->first);
			printf(")");
			
			return;
			
		case(IDENTIFIER_VALUE) :
			
			codeGenerate(t->first);
			
			return;
			
		case(CONSTANT_VALUE) :
			
			codeGenerate(t->first);
			
			return;
			
		case(CONSTANT) :
			
			codeGenerate(t->first);
			
			return;
			
		case(CHARACTER_CONSTANT) :
			
			;	
			char *str;
			str = symTab[t->item]->identifier;
			printf("\"");
			printf("%c", str[1]);
			printf("\"");
			
			return;
			
		case(NUMBER_CONSTANT) :
		
			if (t->item >= 0 && t->item < SYMTABSIZE) {
				printf("%s", symTab[t->item]->identifier);
			}
			
			return;
		
		default :
		
			codeGenerate(t->first);
			codeGenerate(t->second);
			codeGenerate(t->third);
			
			return;
	}
	codeGenerate(t->first);
	codeGenerate(t->second);
	codeGenerate(t->third);
}
#endif
#include "lex.yy.c"

