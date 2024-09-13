/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "spl.y" /* yacc.c:339  */


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

/* ------------- statement trackers ------------------------------ */

int abortParse = 0;

int firstRead = 1;
int firstFor = 1;
int insideStat = 0;
int singleOutput = 1;
int comingFromOL = 0;
int comingFromDB = 0;
int comingFromAS = 0;
char* currentID[80];
char* identifierArr[254];
char* typeArr[254];
int identifierIndex = 0;
int typeIndex = 0;
char* currentType[7];
char* errMsg[254];
char* errIdentifier[254];

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

#ifdef PRINTIDS
void printArrays();
#endif
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


#line 164 "spl.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 109 "spl.y" /* yacc.c:355  */

    int iVal;
    TERNARY_TREE  tVal;

#line 257 "spl.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 274 "spl.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
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
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

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
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   315

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  165

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   122,   122,   154,   156,   158,   160,   162,   164,   166,
     168,   170,   174,   176,   178,   180,   182,   184,   186,   188,
     192,   196,   198,   202,   204,   208,   210,   212,   216,   218,
     220,   222,   226,   228,   230,   232,   234,   236,   238,   242,
     246,   248,   252,   256,   260,   266,   268,   272,   276,   278,
     282,   284,   288,   290,   294,   296,   300,   302,   304,   306,
     308,   310,   314,   316,   318,   320,   324,   326,   328,   332,
     334,   336,   340,   342,   346,   350
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
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
  "character_constant", "number_constant", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
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

#define YYPACT_NINF -59

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-59)))

#define YYTABLE_NINF -22

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      11,   121,   -59,    20,    28,    23,   -59,   147,    12,   131,
       2,   -59,   147,   162,    91,     1,    -2,    23,    -2,    49,
      70,    99,   -59,   -59,   -59,    72,   101,   -16,   109,   -59,
     -59,   -59,   -59,   -59,   -59,   -59,   -59,    86,   148,   -59,
     -59,   -59,   -59,   100,   110,   -59,     9,    91,   -59,   109,
      49,   126,   108,    89,   207,   197,    -2,   -59,   125,   218,
      74,   145,    92,     1,    49,    49,   124,    23,   107,   153,
      49,     1,     1,   148,     1,     1,    49,    23,    23,   175,
     156,    49,    49,    49,    14,   -59,   -59,   -59,    23,   -59,
     -59,    -2,   -59,   -59,   -59,   -59,   -59,   -59,     1,    -2,
      23,     1,    26,   -59,   184,   -59,   172,   109,   137,   -59,
     -59,   -59,   148,   148,   -59,   -59,   191,   109,   109,    91,
     109,   -59,   204,   208,   213,   217,    80,     8,   -59,   261,
     142,    68,   244,     1,   -59,   -59,   -59,   -59,   -59,   215,
     172,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,    23,
     -59,   -59,     1,   -59,   -59,   216,    83,   255,   -59,   -59,
       1,   265,    23,    13,   -59
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    20,     0,     0,     0,    11,     0,     0,     0,
       0,     1,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    46,    74,    75,    69,     0,     0,    18,    28,
      32,    33,    34,    35,    36,    37,    38,     0,    62,    66,
      70,    73,    72,     0,     0,    21,     0,    19,    69,    13,
       0,     0,     0,     0,     0,     0,     0,    54,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    63,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,     0,    31,    71,    53,     0,    50,
      51,     0,    56,    57,    58,    59,    60,    61,     0,     0,
       0,     0,     0,    48,     0,    22,     0,    14,     0,    30,
      29,    39,    64,    65,    67,    68,     0,    15,    16,    17,
      12,     9,     0,     0,     0,     0,     0,     0,    55,    52,
       0,     0,     0,     0,    45,    47,    25,    26,    27,     0,
       0,     3,     4,     5,     6,     7,     8,     2,    40,     0,
      42,    43,     0,    49,    23,     0,     0,     0,    24,    41,
       0,     0,     0,     0,    44
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -59,   -59,    15,    36,    -1,   202,    87,    -9,    59,   -59,
     -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -38,    -7,
     -59,   -14,   -34,   -58,   -59,   -59,   -59
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,    10,    48,    26,    27,   139,    28,    29,    30,
      31,    32,    33,    34,    35,    36,   102,    91,    57,    58,
      98,    37,    38,    39,    40,    41,    42
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,    55,    59,    73,    59,   103,    15,    67,    60,    15,
      78,    61,     1,    44,    69,   125,   114,   115,    87,    69,
      11,    73,    43,    50,    14,    73,    68,    51,    53,    12,
     133,    15,    79,    13,     2,   134,     4,   112,   113,   148,
     149,    25,    59,    56,    45,    68,    23,    24,     2,    23,
      24,     2,    16,   128,   164,    62,    17,    18,   107,     2,
      19,     2,     2,    45,     2,    20,    21,    22,   117,   118,
     120,    23,    24,     2,    69,   153,   -21,    59,    63,   127,
      69,   146,    45,   147,   129,    59,    80,   132,    25,    69,
      83,   131,   130,    70,    15,    73,   -21,    54,    73,     2,
     104,   105,    71,    72,   151,    65,   111,    64,    99,    14,
      84,    65,   116,    85,   159,    69,    15,   122,   123,   124,
     126,    76,     5,    73,     6,    66,     7,    73,   110,    82,
     101,   108,    47,    77,    23,    24,     2,    16,   157,    15,
     156,    17,    18,     8,     9,    19,   161,    81,     5,   106,
      20,    21,    22,   163,   109,    88,    23,    24,     2,   121,
      16,    15,   140,    52,    17,    18,    74,    75,    19,     8,
       9,    89,    90,    20,    21,    22,   119,   150,   100,    23,
      24,     2,    16,    15,     8,     9,    17,    18,    89,    90,
      19,    89,    90,   135,   141,    20,    21,    22,   136,   137,
     138,    23,    24,     2,    16,    15,    86,   142,    17,    18,
      46,   143,    19,    71,    72,    15,   144,    20,    21,    22,
     145,   154,   158,    23,    24,     2,    15,   155,    92,    93,
      94,    95,    96,    97,    71,    72,    16,     0,     0,     0,
      17,    18,     0,     0,    19,    23,    24,     2,     0,    20,
      21,    22,    15,     0,     0,    23,    24,     2,     0,     0,
      71,    72,     0,    15,     0,     0,    23,    24,     2,    15,
       0,    71,    72,    15,     0,     0,     0,    71,    72,     0,
       0,    71,    72,   152,     0,     0,     0,     0,     0,     0,
       0,     0,    23,    24,     2,   160,     0,     0,   162,     0,
       0,     0,     0,    23,    24,     2,     0,     0,     0,    23,
      24,     2,     0,    23,    24,     2
};

static const yytype_int16 yycheck[] =
{
       9,    15,    16,    37,    18,    63,     8,    23,    17,     8,
       1,    18,     1,     1,     6,     1,    74,    75,    56,     6,
       0,    55,     7,    21,     1,    59,    27,    12,    13,     1,
       4,     8,    23,     5,    50,     9,     0,    71,    72,    31,
      32,     5,    56,    45,     8,    46,    48,    49,    50,    48,
      49,    50,    29,    91,    41,    19,    33,    34,    67,    50,
      37,    50,    50,    27,    50,    42,    43,    44,    77,    78,
      79,    48,    49,    50,     6,   133,     4,    91,     8,    88,
       6,     1,    46,     3,    98,    99,    50,   101,    52,     6,
       1,   100,    99,     7,     8,   129,    24,     6,   132,    50,
      64,    65,    16,    17,    36,     4,    70,     8,    34,     1,
      21,     4,    76,    54,    31,     6,     8,    81,    82,    83,
      84,    21,     1,   157,     3,    24,     5,   161,    69,    21,
      38,    24,     1,    23,    48,    49,    50,    29,   152,     8,
     149,    33,    34,    22,    23,    37,   160,    21,     1,    25,
      42,    43,    44,   162,     1,    30,    48,    49,    50,     3,
      29,     8,    25,     1,    33,    34,    18,    19,    37,    22,
      23,    46,    47,    42,    43,    44,     1,    35,    33,    48,
      49,    50,    29,     8,    22,    23,    33,    34,    46,    47,
      37,    46,    47,     9,     3,    42,    43,    44,    26,    27,
      28,    48,    49,    50,    29,     8,     9,     3,    33,    34,
       8,     3,    37,    16,    17,     8,     3,    42,    43,    44,
       3,     6,     6,    48,    49,    50,     8,   140,    10,    11,
      12,    13,    14,    15,    16,    17,    29,    -1,    -1,    -1,
      33,    34,    -1,    -1,    37,    48,    49,    50,    -1,    42,
      43,    44,     8,    -1,    -1,    48,    49,    50,    -1,    -1,
      16,    17,    -1,     8,    -1,    -1,    48,    49,    50,     8,
      -1,    16,    17,     8,    -1,    -1,    -1,    16,    17,    -1,
      -1,    16,    17,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    40,    -1,    -1,    33,    -1,
      -1,    -1,    -1,    48,    49,    50,    -1,    -1,    -1,    48,
      49,    50,    -1,    48,    49,    50
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    50,    52,    54,     1,     3,     5,    22,    23,
      53,     0,     1,     5,     1,     8,    29,    33,    34,    37,
      42,    43,    44,    48,    49,    54,    55,    56,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    72,    73,    74,
      75,    76,    77,    53,     1,    54,    56,     1,    54,    58,
      21,    53,     1,    53,     6,    72,    45,    69,    70,    72,
      58,    70,    54,     8,     8,     4,    24,    23,    55,     6,
       7,    16,    17,    73,    18,    19,    21,    23,     1,    23,
      54,    21,    21,     1,    21,    59,     9,    69,    30,    46,
      47,    68,    10,    11,    12,    13,    14,    15,    71,    34,
      33,    38,    67,    74,    54,    54,    25,    58,    24,     1,
      59,    54,    73,    73,    74,    74,    54,    58,    58,     1,
      58,     3,    54,    54,    54,     1,    54,    58,    69,    72,
      70,    58,    72,     4,     9,     9,    26,    27,    28,    57,
      25,     3,     3,     3,     3,     3,     1,     3,    31,    32,
      35,    36,    39,    74,     6,    57,    58,    72,     6,    31,
      40,    72,    33,    58,    41
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    53,    53,    53,    53,    53,    53,    53,    53,
      54,    55,    55,    56,    56,    57,    57,    57,    58,    58,
      58,    58,    59,    59,    59,    59,    59,    59,    59,    60,
      61,    61,    62,    63,    64,    65,    65,    66,    67,    67,
      68,    68,    69,    69,    70,    70,    71,    71,    71,    71,
      71,    71,    72,    72,    72,    72,    73,    73,    73,    74,
      74,    74,    75,    75,    76,    77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     6,     6,     6,     6,     6,     6,     5,
       4,     2,     4,     2,     4,     4,     4,     4,     2,     2,
       1,     1,     3,     5,     6,     1,     1,     1,     1,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     3,
       5,     7,     5,     5,    11,     4,     1,     4,     1,     3,
       1,     1,     3,     2,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     3,     1,     3,     3,     1,
       1,     3,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
     '$$ = $1'.

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
#line 122 "spl.y" /* yacc.c:1646  */
    { 
			
			TERNARY_TREE ParseTree;

			ParseTree = create_node(NOTHING, PROGRAM, (yyvsp[-5].tVal), (yyvsp[-3].tVal), (yyvsp[-1].tVal));			
			
			#ifdef DEBUG
				PrintTree(ParseTree, 0);
			#else
				codeGenerate(ParseTree);
			#endif
			
			#ifdef PRINTIDS
			printArrays();
			#endif
			
			if(abortParse > 0) {
			
				if(abortParse == 1) {
					fprintf(stderr, "\"%s\" was re-used.\n%s\n", *errIdentifier, *errMsg); 
				}
				else if (abortParse == 2) {
					fprintf(stderr, "\"%s\" was not declared.\n%s\n", *errIdentifier, *errMsg); 
				}
				
				/* https://stackoverflow.com/questions/22567775/clear-stdout-in-c */
				stdout->_ptr = stdout->_base;
				
				YYERROR; return 1; 
			}
		}
#line 1526 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 154 "spl.y" /* yacc.c:1646  */
    { fprintf(stderr, "Program identifier missing at start of file. \n"); abortParse = 3; yyerrok; }
#line 1532 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 156 "spl.y" /* yacc.c:1646  */
    { fprintf(stderr, "COLON after initial program identifier missing. \n"); abortParse = 3; yyerrok; }
#line 1538 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 158 "spl.y" /* yacc.c:1646  */
    { fprintf(stderr, "Syntax error in (Or missing) code block. \n"); abortParse = 3; yyerrok; }
#line 1544 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 160 "spl.y" /* yacc.c:1646  */
    { fprintf(stderr, "ENDP keyword missing after code block. \n"); abortParse = 3; yyerrok; }
#line 1550 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 162 "spl.y" /* yacc.c:1646  */
    { fprintf(stderr, "Program identifier missing at end of file. \n"); abortParse = 3; abortParse = 3; yyerrok; }
#line 1556 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 164 "spl.y" /* yacc.c:1646  */
    { fprintf(stderr, "FULLSTOP at end of file missing. \n"); abortParse = 3; abortParse = 3; yyerrok; }
#line 1562 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 166 "spl.y" /* yacc.c:1646  */
    { fprintf(stderr, "Program identifier and COLON at start of file missing. \n"); abortParse = 3; abortParse = 3; yyerrok; }
#line 1568 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 168 "spl.y" /* yacc.c:1646  */
    { fprintf(stderr, "ENDP, program identifier, and FULLSTOP missing at end of file. \n"); abortParse = 3; abortParse = 3; yyerrok; }
#line 1574 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 170 "spl.y" /* yacc.c:1646  */
    { fprintf(stderr, "Major syntax error. \n"); abortParse = 3; abortParse = 3; yyerrok; }
#line 1580 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 174 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(NOTHING, BLOCK, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL); }
#line 1586 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 176 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(NOTHING, BLOCK, (yyvsp[0].tVal), NULL, NULL); }
#line 1592 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 178 "spl.y" /* yacc.c:1646  */
    { fprintf(stderr, "CODE keyword missin. \n"); abortParse = 3; abortParse = 3; abortParse = 3; yyerrok; }
#line 1598 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 180 "spl.y" /* yacc.c:1646  */
    { fprintf(stderr, "Syntax error in (Or missing) declaration block.\n"); abortParse = 3; abortParse = 3; abortParse = 3; yyerrok; }
#line 1604 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 182 "spl.y" /* yacc.c:1646  */
    { fprintf(stderr, "CODE keyword missing.\n"); abortParse = 3; abortParse = 3; abortParse = 3; yyerrok; }
#line 1610 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 184 "spl.y" /* yacc.c:1646  */
    { fprintf(stderr, "Syntax error in (Or missing) statement list.\n"); abortParse = 3; abortParse = 3; abortParse = 3; yyerrok; }
#line 1616 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 186 "spl.y" /* yacc.c:1646  */
    { fprintf(stderr, "CODE keyword missing."); abortParse = 3; abortParse = 3; abortParse = 3; yyerrok; }
#line 1622 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 188 "spl.y" /* yacc.c:1646  */
    { fprintf(stderr, "Syntax error in (Or missing) statement list. Cannot compile."); abortParse = 3; abortParse = 3; abortParse = 3; yyerrok; }
#line 1628 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 192 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node((yyvsp[0].iVal), IDENTIFIER, NULL, NULL, NULL); }
#line 1634 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 196 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(NOTHING, IDENTIFIER_LIST, (yyvsp[0].tVal), NULL, NULL); }
#line 1640 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 198 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(NOTHING, IDENTIFIER_LIST, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL); }
#line 1646 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 202 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(NOTHING, DECLARATION_BLOCK, (yyvsp[-4].tVal), (yyvsp[-1].tVal), NULL); }
#line 1652 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 204 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(NOTHING, DECLARATION_BLOCK, (yyvsp[-5].tVal), (yyvsp[-4].tVal), (yyvsp[-1].tVal)); }
#line 1658 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 208 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) =  create_node(CHARACTER, TYPE_T, NULL, NULL, NULL); }
#line 1664 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 210 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) =  create_node(INTEGER, TYPE_T, NULL, NULL, NULL); }
#line 1670 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 212 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) =  create_node(REAL, TYPE_T, NULL, NULL, NULL); }
#line 1676 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 216 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(NOTHING, STATEMENT_LIST, (yyvsp[0].tVal), NULL, NULL); }
#line 1682 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 218 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(NOTHING, STATEMENT_LIST, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL); }
#line 1688 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 220 "spl.y" /* yacc.c:1646  */
    { fprintf(stderr, "Syntax error in statements.\n"); }
#line 1694 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 222 "spl.y" /* yacc.c:1646  */
    { fprintf(stderr, "Syntax error in statements.\n"); }
#line 1700 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 226 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(NOTHING, STATEMENT, (yyvsp[0].tVal), NULL, NULL); }
#line 1706 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 228 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(NOTHING, STATEMENT, (yyvsp[0].tVal), NULL, NULL); }
#line 1712 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 230 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(NOTHING, STATEMENT, (yyvsp[0].tVal), NULL, NULL); }
#line 1718 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 232 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(NOTHING, STATEMENT, (yyvsp[0].tVal), NULL, NULL); }
#line 1724 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 234 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(NOTHING, STATEMENT, (yyvsp[0].tVal), NULL, NULL); }
#line 1730 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 236 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(NOTHING, STATEMENT, (yyvsp[0].tVal), NULL, NULL); }
#line 1736 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 238 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(NOTHING, STATEMENT, (yyvsp[0].tVal), NULL, NULL); }
#line 1742 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 242 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(NOTHING, ASSIGNMENT_STATEMENT, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL); }
#line 1748 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 246 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(NOTHING, IF_STATEMENT, (yyvsp[-3].tVal), (yyvsp[-1].tVal), NULL); }
#line 1754 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 248 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(NOTHING, IF_STATEMENT, (yyvsp[-5].tVal), (yyvsp[-3].tVal), (yyvsp[-1].tVal)); }
#line 1760 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 252 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(NOTHING, DO_STATEMENT, (yyvsp[-3].tVal), (yyvsp[-1].tVal), NULL); }
#line 1766 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 256 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(NOTHING, WHILE_STATEMENT, (yyvsp[-3].tVal), (yyvsp[-1].tVal), NULL); }
#line 1772 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 260 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(NOTHING, FOR_STATEMENT, (yyvsp[-9].tVal), 
																									create_node(NOTHING, FOR_STATEMENT, (yyvsp[-7].tVal), (yyvsp[-5].tVal), (yyvsp[-3].tVal)),
																									(yyvsp[-1].tVal)); }
#line 1780 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 266 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(NOTHING, WRITE_STATEMENT, (yyvsp[-1].tVal), NULL, NULL); }
#line 1786 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 268 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(NEWLINE, WRITE_STATEMENT, NULL, NULL, NULL); }
#line 1792 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 272 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(NOTHING, READ_STATEMENT, (yyvsp[-1].tVal), NULL, NULL); }
#line 1798 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 276 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(NOTHING, OUTPUT_LIST, (yyvsp[0].tVal), NULL, NULL); }
#line 1804 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 278 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(NOTHING, OUTPUT_LIST, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL); }
#line 1810 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 282 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(AND, LOGICAL_OPERATOR, NULL, NULL, NULL); }
#line 1816 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 284 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(OR, LOGICAL_OPERATOR, NULL, NULL, NULL); }
#line 1822 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 288 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(NOTHING, BASIC_CONDITIONAL, (yyvsp[-2].tVal), (yyvsp[-1].tVal), (yyvsp[0].tVal)); }
#line 1828 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 290 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(NOTHING, BASIC_CONDITIONAL, (yyvsp[0].tVal), NULL, NULL); }
#line 1834 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 294 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(NOTHING, CONDITIONAL, (yyvsp[0].tVal), NULL, NULL); }
#line 1840 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 296 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(NOTHING, CONDITIONAL, (yyvsp[-2].tVal), (yyvsp[-1].tVal), (yyvsp[0].tVal)); }
#line 1846 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 300 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(EQUAL, COMPARATOR, NULL, NULL, NULL); }
#line 1852 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 302 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(NOT_EQUAL, COMPARATOR, NULL, NULL, NULL); }
#line 1858 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 304 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(LESS_THAN, COMPARATOR, NULL, NULL, NULL); }
#line 1864 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 306 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(GREATER_THAN, COMPARATOR, NULL, NULL, NULL); }
#line 1870 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 308 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(LESS_THAN_OR_EQUAL, COMPARATOR, NULL, NULL, NULL); }
#line 1876 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 310 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(GREATER_THAN_OR_EQUAL, COMPARATOR, NULL, NULL, NULL); }
#line 1882 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 314 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(NOTHING, EXPRESSION, (yyvsp[0].tVal), NULL, NULL); }
#line 1888 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 316 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(NOTHING, EXPRESSION, (yyvsp[-1].tVal), (yyvsp[0].tVal), NULL); }
#line 1894 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 318 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(NOTHING, PLUS_EXPRESSION, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL); }
#line 1900 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 320 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(NOTHING, MINUS_EXPRESSION, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL); }
#line 1906 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 324 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(NOTHING, TERM, (yyvsp[0].tVal), NULL, NULL); }
#line 1912 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 326 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(NOTHING, TIMES_TERM, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL); }
#line 1918 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 328 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(NOTHING, DIVIDE_TERM, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL); }
#line 1924 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 332 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(NOTHING, IDENTIFIER_VALUE, (yyvsp[0].tVal), NULL, NULL); }
#line 1930 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 334 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(NOTHING, CONSTANT_VALUE, (yyvsp[0].tVal), NULL, NULL); }
#line 1936 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 336 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(NOTHING, VALUE, (yyvsp[-1].tVal), NULL, NULL); }
#line 1942 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 340 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(NOTHING, CONSTANT, (yyvsp[0].tVal), NULL, NULL); }
#line 1948 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 342 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node(NOTHING, CONSTANT, (yyvsp[0].tVal), NULL, NULL); }
#line 1954 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 346 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node((yyvsp[0].iVal), CHARACTER_CONSTANT, NULL, NULL, NULL); }
#line 1960 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 350 "spl.y" /* yacc.c:1646  */
    { (yyval.tVal) = create_node((yyvsp[0].iVal), NUMBER_CONSTANT, NULL, NULL, NULL); }
#line 1966 "spl.tab.c" /* yacc.c:1646  */
    break;


#line 1970 "spl.tab.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
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
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
  yyerror (YY_("memory exhausted"));
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 352 "spl.y" /* yacc.c:1906  */


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
			printf("'%d' ", t->item);
	else if (t->nodeIdentifier == CHARACTER_CONSTANT) {
			;	
			char *str;
			str = symTab[t->item]->identifier;
			printf("'");
			printf("%c", str[1]);
			printf("' ");
	}
	else if (t->nodeIdentifier == IDENTIFIER) /* || t->nodeIdentifier == ASSIGNMENT_STATEMENT */
		if (t->item >= 0 && t->item < SYMTABSIZE)
			printf("\"%s\" ", symTab[t->item]->identifier);
		else 
			printf("Unknown Identifier: %d ", t->item);
			
	else if(t->item == NEWLINE) printf("NEWLINE ");
	else if(t->item != NOTHING) printf(" Item: %d ", t->item);
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
			
			/* Declaration block : ID handling */
			if (t->item >= 0 && t->item < SYMTABSIZE && comingFromDB == 1) {
				
				*currentID = symTab[t->item]->identifier;
				
				for(int i = 0; i < identifierIndex; i++) {
					if(*currentID == identifierArr[i]) {
						if(abortParse == 0) {
							*errIdentifier = *currentID;
							*errMsg = "Identifier name re-used. Exiting compilation.\n";
							abortParse = 1;
						}
					}
				}
				
				
				identifierArr[identifierIndex] = *currentID; identifierIndex++;
				typeArr[typeIndex] = *currentType; typeIndex++;
				printf("%s", symTab[t->item]->identifier);
			}
			/* Assignment statement : ID handling */
			else if (t->item >= 0 && t->item < SYMTABSIZE) {
				
				*currentID = symTab[t->item]->identifier;
				int idExists = 0;
				
				for(int i = 0; i < identifierIndex; i++) {
					if(*currentID == identifierArr[i]) {
						idExists = 1;
					}
				}
				
				if(idExists == 1) {
					printf("%s", symTab[t->item]->identifier);
				}
				else {
					if(abortParse == 0) {
						abortParse = 2;
						*errIdentifier = *currentID;
						*errMsg = "Undeclared identifier used.";
					}
					
				}
			}
			/* Basic ID handling 
			else if (t->item >= 0 && t->item < SYMTABSIZE) {
				printf("%s", symTab[t->item]->identifier);
				*currentID = symTab[t->item]->identifier;
			}*/
			
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
				comingFromDB = 1;
				codeGenerate(t->second);
				comingFromDB = 0;
				printf(";\n\n");
			}
			else {
				codeGenerate(t->second);
				printf(" ");
				comingFromDB = 1;
				codeGenerate(t->first);			
				comingFromDB = 0;
				printf(";\n\n");
			}			
			
			
			return;
			
		case(TYPE_T) :
			
			if(t->item == CHARACTER) {
				printf("\tchar"); 
				*currentType = "char"; }
			else if(t->item == INTEGER) {
				printf("\tint");
				*currentType = "int"; }
			else if(t->item == REAL) {
				printf("\tfloat");
				*currentType = "float"; }
			
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
			comingFromAS = 1;
			codeGenerate(t->second);
			comingFromAS = 0;
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
				printf("\tregister float _by;\n");
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
			printf(") == \"other\")\n\t\t*");
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
				comingFromOL = 1;
				codeGenerate(t->second);
				comingFromOL = 0;
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
				comingFromOL = 1;
				codeGenerate(t->first);
				comingFromOL = 0;
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
			
			if(comingFromOL == 1)
				printf("\"");
			else
				printf("'");
				
			printf("%c", str[1]);
			
			if(comingFromOL == 1)
				printf("\"");
			else
				printf("'");
			
			return;
			
		case(NUMBER_CONSTANT) :
			
			if(comingFromOL == 1)
				printf("\"");
			
			if (t->item >= 0 && t->item < SYMTABSIZE) {
				printf("%s", symTab[t->item]->identifier);
			}
			
			if(comingFromOL == 1)
				printf("\"");
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
#ifdef PRINTIDS
void printArrays() {

	for(int i = 0; i < identifierIndex; i++) {
		fprintf(stderr, identifierArr[i]);
		fprintf(stderr, " : ");
		fprintf(stderr, typeArr[i]);
		fprintf(stderr, "\n");
	}
}
#endif
#include "lex.yy.c"
