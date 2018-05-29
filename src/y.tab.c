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
#line 1 "Pascal.y" /* yacc.c:339  */


#include <stdio.h>
#include "util.h" 
#include "errormsg.h"
#include "symbol.h"
#include "absyn.h"

int yyerror(char* msg);
int yylex(void);
// root for parsed abstract syntax tree
A_exp A_synTreeRoot;

// helper function for constructing abstract tree
// link fieldlists
A_fieldList A_linkFieldList(A_fieldList front, A_fieldList tail);
// set type for fieldlist
A_fieldList A_setFieldListType(A_fieldList fieldList, A_ty ty);

// link declists
A_decList A_linkDecList(A_decList front, A_decList tail);
// set type for declist
A_decList A_setDecListType(A_decList decList, A_ty ty);

// convert fieldlist to declist
A_decList A_unDecList(A_fieldList fieldList);


#line 95 "y.tab.c" /* yacc.c:339  */

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

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    LP = 258,
    RP = 259,
    LB = 260,
    RB = 261,
    DOT = 262,
    COMMA = 263,
    COLON = 264,
    SEMI = 265,
    PLUS = 266,
    MINUS = 267,
    MUL = 268,
    REALDIV = 269,
    INTDIV = 270,
    MOD = 271,
    AND = 272,
    OR = 273,
    NOT = 274,
    GE = 275,
    GT = 276,
    LE = 277,
    LT = 278,
    EQUAL = 279,
    UNEQUAL = 280,
    ASSIGN = 281,
    PROGRAM = 282,
    FUNCTION = 283,
    PROCEDURE = 284,
    BEGIN_T = 285,
    END = 286,
    TYPE = 287,
    ARRAY = 288,
    OF = 289,
    RECORD = 290,
    VAR = 291,
    IF = 292,
    THEN = 293,
    ELSE = 294,
    REPEAT = 295,
    TO = 296,
    DOWNTO = 297,
    UNTIL = 298,
    WHILE = 299,
    DO = 300,
    FOR = 301,
    CASE = 302,
    GOTO = 303,
    READ = 304,
    CONST = 305,
    DOTDOT = 306,
    INTEGER = 307,
    REAL = 308,
    CHAR = 309,
    ID = 310,
    STRING = 311,
    SYS_CON = 312,
    SYS_FUNCT = 313,
    SYS_PROC = 314,
    SYS_TYPE = 315
  };
#endif
/* Tokens.  */
#define LP 258
#define RP 259
#define LB 260
#define RB 261
#define DOT 262
#define COMMA 263
#define COLON 264
#define SEMI 265
#define PLUS 266
#define MINUS 267
#define MUL 268
#define REALDIV 269
#define INTDIV 270
#define MOD 271
#define AND 272
#define OR 273
#define NOT 274
#define GE 275
#define GT 276
#define LE 277
#define LT 278
#define EQUAL 279
#define UNEQUAL 280
#define ASSIGN 281
#define PROGRAM 282
#define FUNCTION 283
#define PROCEDURE 284
#define BEGIN_T 285
#define END 286
#define TYPE 287
#define ARRAY 288
#define OF 289
#define RECORD 290
#define VAR 291
#define IF 292
#define THEN 293
#define ELSE 294
#define REPEAT 295
#define TO 296
#define DOWNTO 297
#define UNTIL 298
#define WHILE 299
#define DO 300
#define FOR 301
#define CASE 302
#define GOTO 303
#define READ 304
#define CONST 305
#define DOTDOT 306
#define INTEGER 307
#define REAL 308
#define CHAR 309
#define ID 310
#define STRING 311
#define SYS_CON 312
#define SYS_FUNCT 313
#define SYS_PROC 314
#define SYS_TYPE 315

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 39 "Pascal.y" /* yacc.c:355  */

    int pos;
    int ival; 
    double rval;
    char cval;
    string sval;

    A_var var;
    A_exp exp;
    S_symbol sym;
    A_dec dec;
    A_decList declist;
    A_expList explist;
    A_efieldList efieldlist;
    A_ty ty;
    A_fieldList fieldlist;
    A_fundec fundec;
    A_fundecList fundeclist;
    A_namety namety;
    A_nametyList nametylist;

#line 277 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 294 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   390

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  133
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  269

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   315

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    81,    81,    82,    83,    84,    98,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   130,   131,   132,   133,   134,   137,   138,
     139,   140,   141,   144,   145,   146,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   192,   193,   203,
     204,   205,   206,   207,   208,   209,   210,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   245,   246,
     247,   248,   249,   251
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LP", "RP", "LB", "RB", "DOT", "COMMA",
  "COLON", "SEMI", "PLUS", "MINUS", "MUL", "REALDIV", "INTDIV", "MOD",
  "AND", "OR", "NOT", "GE", "GT", "LE", "LT", "EQUAL", "UNEQUAL", "ASSIGN",
  "PROGRAM", "FUNCTION", "PROCEDURE", "BEGIN_T", "END", "TYPE", "ARRAY",
  "OF", "RECORD", "VAR", "IF", "THEN", "ELSE", "REPEAT", "TO", "DOWNTO",
  "UNTIL", "WHILE", "DO", "FOR", "CASE", "GOTO", "READ", "CONST", "DOTDOT",
  "INTEGER", "REAL", "CHAR", "ID", "STRING", "SYS_CON", "SYS_FUNCT",
  "SYS_PROC", "SYS_TYPE", "$accept", "program", "program_head", "routine",
  "routine_head", "label_part", "const_part", "const_expr_list",
  "const_value", "type_part", "type_decl_list", "type_definition",
  "type_decl", "simple_type_decl", "array_type_decl", "record_type_decl",
  "field_decl_list", "field_decl", "name_list", "var_part",
  "var_decl_list", "var_decl", "routine_part", "function_decl",
  "function_head", "procedure_decl", "procedure_head", "sub_routine",
  "parameters", "para_decl_list", "para_type_list", "var_para_list",
  "val_para_list", "routine_body", "compound_stmt", "stmt_list", "stmt",
  "non_label_stmt", "assign_stmt", "proc_stmt", "if_stmt", "else_clause",
  "repeat_stmt", "while_stmt", "for_stmt", "direction", "case_stmt",
  "case_expr_list", "case_expr", "goto_stmt", "expression_list",
  "expression", "expr", "term", "factor", "args_list", "id", "sys_con",
  "sys_funct", "sys_proc", "sys_type", "stat", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315
};
# endif

#define YYPACT_NINF -204

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-204)))

#define YYTABLE_NINF -63

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -23,   -38,    33,  -204,  -204,    32,  -204,    52,    37,    28,
    -204,  -204,    88,  -204,  -204,   -38,    54,    74,   233,   262,
     233,   -38,   233,    36,   104,   107,  -204,  -204,    98,   110,
    -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,     5,
     138,  -204,  -204,   109,   -38,   106,  -204,   233,   233,   233,
    -204,  -204,  -204,  -204,  -204,  -204,  -204,   338,    34,   190,
    -204,    25,  -204,   142,   108,     2,   120,   344,  -204,   233,
     282,  -204,    88,   233,   233,   -38,   233,   233,   197,  -204,
     -38,   125,   -38,    68,   198,  -204,  -204,   233,   233,   233,
     233,   233,   233,   262,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   -38,   233,   233,   262,   233,   318,
     149,  -204,  -204,   359,    58,   326,   140,   359,   160,   273,
     162,  -204,   213,   114,  -204,   -38,  -204,   -38,   -38,  -204,
      68,   163,    68,   165,  -204,    34,    34,    34,    34,    34,
      34,   131,   190,   190,   190,  -204,  -204,  -204,  -204,  -204,
      64,   332,  -204,    72,   359,  -204,    89,   167,   146,   318,
     169,  -204,  -204,   233,   157,   233,  -204,   233,   -38,   -38,
     197,   182,   -38,  -204,   137,   181,  -204,  -204,  -204,   141,
    -204,   -38,   213,  -204,   192,   192,  -204,  -204,  -204,  -204,
     262,  -204,  -204,  -204,  -204,  -204,  -204,   233,   262,  -204,
    -204,   262,   359,   233,   359,  -204,  -204,    79,   145,   223,
     168,   -38,   130,   197,  -204,   -38,  -204,   191,    -7,   200,
    -204,    37,   201,   202,  -204,    15,   203,   214,   359,  -204,
     103,   221,  -204,  -204,   213,  -204,  -204,  -204,   -38,   220,
      11,  -204,   222,   225,   223,  -204,  -204,  -204,   262,  -204,
    -204,   197,  -204,   195,   228,   220,  -204,    -7,   223,   223,
    -204,  -204,  -204,   213,  -204,  -204,  -204,  -204,  -204
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     6,   128,     0,     1,     0,     0,     8,
       3,     2,     0,     4,    59,     0,    17,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   131,    68,     0,     0,
      65,    66,    67,    69,    70,    71,    72,    73,    74,    78,
      80,    63,     7,     0,     0,    39,   133,     0,     0,     0,
      11,    12,    13,    14,   129,   130,   120,     0,   105,   109,
     115,   116,    15,   118,     0,     0,     0,     0,    96,     0,
       0,    60,     0,     0,     0,     0,     0,     0,     0,    16,
      19,     0,     0,    45,     0,   123,   122,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    64,    61,   127,     0,     0,     0,    75,     0,    98,
       0,    18,     0,     0,    38,    41,    37,     0,     0,     5,
      45,     0,    45,     0,   121,    99,   100,   101,   102,   103,
     104,    85,   106,   107,   108,   110,   112,   111,   113,   114,
       0,     0,   125,     0,    86,    87,     0,     0,     0,    93,
       0,    82,    79,     0,     0,     0,    81,     0,    10,     0,
       0,     0,     0,   132,     0,     0,    21,    22,    23,    25,
      24,     0,     0,    40,    52,    52,    43,     6,    44,     6,
       0,    83,   117,   124,   119,    89,    90,     0,     0,    91,
      92,     0,   126,     0,    77,    97,     9,     0,     0,     0,
       0,    34,     0,     0,    20,     0,    36,     0,     0,     0,
      49,     0,     0,     0,    84,     0,     0,     0,    76,    26,
       0,     0,    32,    33,     0,    27,    30,    42,     0,    58,
       0,    54,     0,     0,     0,    50,    46,    48,     0,    94,
      95,     0,    28,     0,     0,    57,    51,     0,     0,     0,
      47,    88,    29,     0,    35,    53,    55,    56,    31
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -204,  -204,  -204,  -204,   227,  -204,  -204,    71,   -65,  -204,
     161,  -204,  -181,  -203,  -204,  -204,    29,  -204,  -153,  -204,
     117,  -204,   -57,  -204,  -204,  -204,  -204,    55,    70,  -204,
       3,  -204,  -204,    38,    -6,   189,   -16,   193,  -204,  -204,
    -204,  -204,  -204,  -204,  -204,  -204,  -204,   105,  -204,  -204,
     115,   -13,   298,    67,     1,   -51,    -1,  -204,  -204,  -204,
    -204,  -204
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     7,   221,     9,    16,    42,    56,    45,
      79,    80,   175,   176,   177,   178,   210,   211,   123,    83,
     124,   125,   129,   130,   131,   132,   133,   222,   219,   240,
     241,   242,   243,    13,    27,    28,    29,    30,    31,    32,
      33,   191,    34,    35,    36,   197,    37,   158,   159,    38,
     118,   113,    58,    59,    60,   114,    61,    62,    63,    40,
     180,    41
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       5,   217,    14,    64,     1,    57,   231,    65,    73,    67,
      74,    39,    75,   120,    43,   256,   207,     4,    39,   212,
      66,   257,    87,    88,    89,    90,    91,    92,   102,   238,
     103,    76,   104,     6,    84,    87,    88,    89,    90,    91,
      92,   260,    10,    81,   157,    94,    95,   107,     4,    85,
      86,   150,    96,   254,   153,   266,   267,   174,   212,    11,
     248,   115,   162,   117,   119,   239,   163,    12,   192,    39,
     110,    39,   163,   186,   116,   188,   194,   141,    15,    81,
     163,   126,   268,   229,    46,   255,    44,   181,    68,    17,
     151,   155,    39,   154,   157,   156,   127,   128,   145,   146,
     147,   148,   149,   152,   239,   208,    39,    69,   160,    87,
      88,    89,    90,    91,    92,   251,    70,   174,    12,   -62,
      72,   179,   181,   182,   126,    18,   184,   185,    19,    71,
     195,   196,    20,    78,    21,    22,    23,    24,   181,   234,
      25,    77,    82,     4,   174,   105,   108,    26,   235,   122,
     202,   106,   204,   161,   119,    50,    51,    52,   160,    53,
      54,   142,   143,   144,   166,   252,   165,    43,   126,   174,
     190,   126,   168,   187,   224,   189,   198,   199,   201,   174,
     216,   179,   226,   203,   225,   227,   262,   209,   213,    39,
     228,   214,   215,   174,   174,   218,   230,    39,   174,   232,
      39,   237,   134,    97,    98,    99,   100,   101,   179,   244,
     126,   246,   247,   249,   236,    14,   169,   126,    87,    88,
      89,    90,    91,    92,   250,   170,   169,   253,   181,   263,
       8,   258,   261,   179,   259,   170,    47,   126,   264,   206,
     233,   121,   183,   179,   223,    48,   171,    39,   172,    50,
      51,    52,    49,    53,    54,   220,   126,   179,   179,   245,
     265,   112,   179,   111,   200,    50,    51,    52,     4,    53,
      54,     0,     0,   173,     0,    50,    51,    52,     4,    53,
      54,   167,   205,   173,     0,    50,    51,    52,     4,    53,
      54,    55,    12,    87,    88,    89,    90,    91,    92,    18,
       0,     0,    19,     0,     0,     0,    20,     0,    21,    22,
      23,    24,    12,     0,    25,     0,     0,     4,     0,    18,
       0,    26,    19,     0,     0,     0,    20,     0,    21,    22,
      23,    24,   164,     0,     0,     0,     0,     4,   193,     0,
       0,    26,     0,     0,     0,     0,    87,    88,    89,    90,
      91,    92,    87,    88,    89,    90,    91,    92,    87,    88,
      89,    90,    91,    92,    87,    88,    89,    90,    91,    92,
      50,    51,    52,     4,    53,    54,    93,     0,   109,    87,
      88,    89,    90,    91,    92,   135,   136,   137,   138,   139,
     140
};

static const yytype_int16 yycheck[] =
{
       1,   182,     8,    19,    27,    18,   209,    20,     3,    22,
       5,    12,     7,    78,    15,     4,   169,    55,    19,   172,
      21,    10,    20,    21,    22,    23,    24,    25,     3,    36,
       5,    26,     7,     0,    47,    20,    21,    22,    23,    24,
      25,   244,    10,    44,   109,    11,    12,    45,    55,    48,
      49,   102,    18,   234,   105,   258,   259,   122,   211,     7,
      45,    74,     4,    76,    77,   218,     8,    30,     4,    70,
      69,    72,     8,   130,    75,   132,     4,    93,    50,    80,
       8,    82,   263,     4,    10,   238,    32,     8,    52,     1,
     103,   107,    93,   106,   159,   108,    28,    29,    97,    98,
      99,   100,   101,   104,   257,   170,   107,     3,   109,    20,
      21,    22,    23,    24,    25,    12,     9,   182,    30,    31,
      10,   122,     8,     9,   125,    37,   127,   128,    40,    31,
      41,    42,    44,    24,    46,    47,    48,    49,     8,     9,
      52,     3,    36,    55,   209,     3,    26,    59,   213,    24,
     163,    43,   165,     4,   167,    52,    53,    54,   159,    56,
      57,    94,    95,    96,     4,   230,    26,   168,   169,   234,
      39,   172,    10,    10,   190,    10,     9,    31,     9,   244,
     181,   182,   198,    26,   197,   201,   251,     5,    51,   190,
     203,    10,    51,   258,   259,     3,    51,   198,   263,    31,
     201,    10,     4,    13,    14,    15,    16,    17,   209,     9,
     211,    10,    10,    10,   215,   221,     3,   218,    20,    21,
      22,    23,    24,    25,    10,    12,     3,     6,     8,    34,
       3,     9,   248,   234,     9,    12,     3,   238,    10,   168,
     211,    80,   125,   244,   189,    12,    33,   248,    35,    52,
      53,    54,    19,    56,    57,   185,   257,   258,   259,   221,
     257,    72,   263,    70,   159,    52,    53,    54,    55,    56,
      57,    -1,    -1,    60,    -1,    52,    53,    54,    55,    56,
      57,     8,   167,    60,    -1,    52,    53,    54,    55,    56,
      57,    58,    30,    20,    21,    22,    23,    24,    25,    37,
      -1,    -1,    40,    -1,    -1,    -1,    44,    -1,    46,    47,
      48,    49,    30,    -1,    52,    -1,    -1,    55,    -1,    37,
      -1,    59,    40,    -1,    -1,    -1,    44,    -1,    46,    47,
      48,    49,     6,    -1,    -1,    -1,    -1,    55,     6,    -1,
      -1,    59,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    20,    21,    22,    23,    24,    25,    20,    21,
      22,    23,    24,    25,    20,    21,    22,    23,    24,    25,
      52,    53,    54,    55,    56,    57,    38,    -1,    34,    20,
      21,    22,    23,    24,    25,    87,    88,    89,    90,    91,
      92
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    27,    62,    63,    55,   117,     0,    64,    65,    66,
      10,     7,    30,    94,    95,    50,    67,     1,    37,    40,
      44,    46,    47,    48,    49,    52,    59,    95,    96,    97,
      98,    99,   100,   101,   103,   104,   105,   107,   110,   117,
     120,   122,    68,   117,    32,    70,    10,     3,    12,    19,
      52,    53,    54,    56,    57,    58,    69,   112,   113,   114,
     115,   117,   118,   119,    97,   112,   117,   112,    52,     3,
       9,    31,    10,     3,     5,     7,    26,     3,    24,    71,
      72,   117,    36,    80,   112,   115,   115,    20,    21,    22,
      23,    24,    25,    38,    11,    12,    18,    13,    14,    15,
      16,    17,     3,     5,     7,     3,    43,    45,    26,    34,
     115,    98,    96,   112,   116,   112,   117,   112,   111,   112,
      69,    71,    24,    79,    81,    82,   117,    28,    29,    83,
      84,    85,    86,    87,     4,   113,   113,   113,   113,   113,
     113,    97,   114,   114,   114,   115,   115,   115,   115,   115,
     116,   112,   117,   116,   112,    97,   112,    69,   108,   109,
     117,     4,     4,     8,     6,    26,     4,     8,    10,     3,
      12,    33,    35,    60,    69,    73,    74,    75,    76,   117,
     121,     8,     9,    81,   117,   117,    83,    10,    83,    10,
      39,   102,     4,     6,     4,    41,    42,   106,     9,    31,
     108,     9,   112,    26,   112,   111,    68,    79,    69,     5,
      77,    78,    79,    51,    10,    51,   117,    73,     3,    89,
      89,    65,    88,    88,    97,   112,    97,    97,   112,     4,
      51,    74,    31,    77,     9,    69,   117,    10,    36,    79,
      90,    91,    92,    93,     9,    94,    10,    10,    45,    10,
      10,    12,    69,     6,    73,    79,     4,    10,     9,     9,
      74,    97,    69,    34,    10,    91,    74,    74,    73
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    62,    63,    64,    65,    66,    67,    67,    68,
      68,    69,    69,    69,    69,    69,    70,    70,    71,    71,
      72,    73,    73,    73,    74,    74,    74,    74,    74,    74,
      74,    75,    76,    77,    77,    78,    79,    79,    80,    80,
      81,    81,    82,    83,    83,    83,    84,    85,    86,    87,
      88,    89,    89,    90,    90,    91,    91,    92,    93,    94,
      95,    96,    96,    96,    97,    97,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    99,    99,    99,   100,   100,
     100,   100,   100,   101,   102,   102,   103,   104,   105,   106,
     106,   107,   108,   108,   109,   109,   110,   111,   111,   112,
     112,   112,   112,   112,   112,   112,   113,   113,   113,   113,
     114,   114,   114,   114,   114,   114,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   116,   116,   117,   118,
     119,   120,   121,   122
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     2,     5,     0,     2,     0,     5,
       4,     1,     1,     1,     1,     1,     2,     0,     2,     1,
       4,     1,     1,     1,     1,     1,     3,     3,     4,     5,
       3,     6,     3,     2,     1,     4,     3,     1,     2,     0,
       2,     1,     4,     2,     2,     0,     4,     5,     4,     3,
       2,     3,     0,     3,     1,     3,     3,     2,     1,     1,
       3,     3,     0,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     6,     5,     1,     4,
       1,     4,     4,     5,     2,     0,     4,     4,     8,     1,
       1,     5,     2,     1,     4,     4,     2,     3,     1,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     3,     1,
       3,     3,     3,     3,     3,     1,     1,     4,     1,     4,
       1,     3,     2,     2,     4,     3,     3,     1,     1,     1,
       1,     1,     1,     2
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
#line 81 "Pascal.y" /* yacc.c:1646  */
    {/*set root for abstract syntax tree*/ A_synTreeRoot = (yyvsp[-1].exp); /*printf("Program parsed.\n");*/}
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 82 "Pascal.y" /* yacc.c:1646  */
    {/*printf("Program head.\n");*/}
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 83 "Pascal.y" /* yacc.c:1646  */
    {/*head:declaration with type A_decList,  body:expression with type A_exp*/ (yyval.exp) = A_LetExp(EM_tokPos, (yyvsp[-1].declist), (yyvsp[0].exp));}
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 84 "Pascal.y" /* yacc.c:1646  */
    { 
        /* placeholder*/
        A_decList decList = A_DecList(A_TypeDec(0, NULL), NULL);
        if ((yyvsp[-3].declist)) 
            A_linkDecList(decList, (yyvsp[-3].declist));
        if ((yyvsp[-2].declist))
            A_linkDecList(decList, (yyvsp[-2].declist));
        if ((yyvsp[-1].declist)) 
            A_linkDecList(decList, (yyvsp[-1].declist));
        if ((yyvsp[0].fundeclist))
            A_linkDecList(decList, A_DecList(A_FunctionDec(EM_tokPos, (yyvsp[0].fundeclist)), NULL));
        (yyval.declist) = decList->tail;
    }
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 98 "Pascal.y" /* yacc.c:1646  */
    {/*label part is empty in pascal*/ (yyval.declist) = NULL;}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 101 "Pascal.y" /* yacc.c:1646  */
    {/*const declaration part*/ (yyval.declist) = (yyvsp[0].declist);}
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 102 "Pascal.y" /* yacc.c:1646  */
    {/*no const declaration*/ (yyval.declist) = NULL;}
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 103 "Pascal.y" /* yacc.c:1646  */
    {/*const declaration list*/ (yyval.declist) = A_DecList(A_ConstDec(EM_tokPos, (yyvsp[-4].sym), (yyvsp[-2].exp)),(yyvsp[0].declist));}
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 104 "Pascal.y" /* yacc.c:1646  */
    {/*first one in list*/ (yyval.declist) = A_DecList(A_ConstDec(EM_tokPos, (yyvsp[-3].sym), (yyvsp[-1].exp)), NULL);}
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 105 "Pascal.y" /* yacc.c:1646  */
    {/*integer value*/ (yyval.exp) = A_IntExp(EM_tokPos, (yyvsp[0].ival));}
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 106 "Pascal.y" /* yacc.c:1646  */
    {/*real value*/ (yyval.exp) = A_RealExp(EM_tokPos, (yyvsp[0].rval));}
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 107 "Pascal.y" /* yacc.c:1646  */
    {/*char value*/ (yyval.exp) = A_CharExp(EM_tokPos, (yyvsp[0].cval));}
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 108 "Pascal.y" /* yacc.c:1646  */
    {/*string value*/ (yyval.exp) = A_StringExp(EM_tokPos, (yyvsp[0].sval));}
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 109 "Pascal.y" /* yacc.c:1646  */
    {/*system const value*/ /*$$ = A_SysConstExp(EM_tokPos, $1);*/}
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 112 "Pascal.y" /* yacc.c:1646  */
    {/*type declaration part*/ (yyval.declist) = A_DecList(A_TypeDec(EM_tokPos, (yyvsp[0].nametylist)), NULL);}
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 113 "Pascal.y" /* yacc.c:1646  */
    {/*no type declaration*/ (yyval.declist) = NULL;}
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 114 "Pascal.y" /* yacc.c:1646  */
    {/*type declaration list*/ (yyval.nametylist) = A_NametyList((yyvsp[-1].namety), (yyvsp[0].nametylist));}
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 115 "Pascal.y" /* yacc.c:1646  */
    {/*last type definition, tail points to NULL*/(yyval.nametylist) = A_NametyList((yyvsp[0].namety), NULL);}
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 116 "Pascal.y" /* yacc.c:1646  */
    {/*type declaration*/(yyval.namety) =A_Namety((yyvsp[-3].sym), (yyvsp[-1].ty));}
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 117 "Pascal.y" /* yacc.c:1646  */
    {/*simple type*/ (yyval.ty) = (yyvsp[0].ty);}
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 118 "Pascal.y" /* yacc.c:1646  */
    {/*array type*/ (yyval.ty) = (yyvsp[0].ty);}
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 119 "Pascal.y" /* yacc.c:1646  */
    {/*record type*/ (yyval.ty) = (yyvsp[0].ty);}
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 120 "Pascal.y" /* yacc.c:1646  */
    {/*system defined type*/ (yyval.ty) = A_NameTy(EM_tokPos, (yyvsp[0].sym));}
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 121 "Pascal.y" /* yacc.c:1646  */
    {/*self define simple type*/ (yyval.ty) = A_NameTy(EM_tokPos, (yyvsp[0].sym));}
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 122 "Pascal.y" /* yacc.c:1646  */
    {/*enum type*/ (yyval.ty) = A_EnumType(EM_tokPos, (yyvsp[-1].fieldlist));}
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 123 "Pascal.y" /* yacc.c:1646  */
    {/*subrange type*/ (yyval.ty) = A_RangeTy(EM_tokPos, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 124 "Pascal.y" /* yacc.c:1646  */
    {/*subrange type*/ A_RangeTy(EM_tokPos, A_OpExp(EM_tokPos, A_minusOp, A_IntExp(EM_tokPos, 0), (yyvsp[-2].exp)), (yyvsp[0].exp));}
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 125 "Pascal.y" /* yacc.c:1646  */
    {/*subrange type*/ A_RangeTy(EM_tokPos, A_OpExp(EM_tokPos, A_minusOp, A_IntExp(EM_tokPos, 0), (yyvsp[-3].exp)), A_OpExp(EM_tokPos, A_minusOp, A_IntExp(EM_tokPos, 0), (yyvsp[0].exp)));}
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 126 "Pascal.y" /* yacc.c:1646  */
    {/*subrange type*/ A_RangeTy(EM_tokPos, A_VarExp(EM_tokPos, A_SimpleVar(EM_tokPos, (yyvsp[-2].sym))), A_VarExp(EM_tokPos, A_SimpleVar(EM_tokPos, (yyvsp[0].sym))));}
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 127 "Pascal.y" /* yacc.c:1646  */
    {/*array type, simple_type_dec is range of array, type_dec is actual type of array element*/ (yyval.ty) = A_ArrayTy(EM_tokPos, (yyvsp[-3].ty), (yyvsp[0].ty)->u.name);}
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 128 "Pascal.y" /* yacc.c:1646  */
    {/*record type*/ (yyval.ty) = A_RecordTy(EM_tokPos, (yyvsp[-1].fieldlist));}
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 130 "Pascal.y" /* yacc.c:1646  */
    {/*link parts of fieldlists*/ (yyval.fieldlist) = A_linkFieldList((yyvsp[-1].fieldlist), (yyvsp[0].fieldlist)); }
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 131 "Pascal.y" /* yacc.c:1646  */
    {(yyval.fieldlist) = (yyvsp[0].fieldlist);}
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 132 "Pascal.y" /* yacc.c:1646  */
    { /*set type of namelist*/(yyval.fieldlist) = A_setFieldListType((yyvsp[-3].fieldlist), (yyvsp[-1].ty));}
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 133 "Pascal.y" /* yacc.c:1646  */
    {/*namelist is fieldlist of same unknown type*/ (yyval.fieldlist) = A_linkFieldList((yyvsp[-2].fieldlist), A_FieldList(A_Field(EM_tokPos, (yyvsp[0].sym), NULL), NULL));}
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 134 "Pascal.y" /* yacc.c:1646  */
    {(yyval.fieldlist) = A_FieldList(A_Field(EM_tokPos, (yyvsp[0].sym), NULL), NULL);}
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 137 "Pascal.y" /* yacc.c:1646  */
    {/*variable declaration part*/ (yyval.declist) = (yyvsp[0].declist);}
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 138 "Pascal.y" /* yacc.c:1646  */
    {/*no variable declaration*/ (yyval.declist) = NULL;}
#line 1831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 139 "Pascal.y" /* yacc.c:1646  */
    {/*variable declaration list*/ (yyval.declist) = A_linkDecList((yyvsp[-1].declist), (yyvsp[0].declist));}
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 140 "Pascal.y" /* yacc.c:1646  */
    {(yyval.declist) = (yyvsp[0].declist);}
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 141 "Pascal.y" /* yacc.c:1646  */
    {/*change name_list to variable declaration list*/ (yyval.declist) = A_setDecListType(A_unDecList((yyvsp[-3].fieldlist)), (yyvsp[-1].ty));}
#line 1849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 144 "Pascal.y" /* yacc.c:1646  */
    {/*routine declaration part, new function*/ (yyval.fundeclist) = A_FundecList((yyvsp[-1].fundec), (yyvsp[0].fundeclist));}
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 145 "Pascal.y" /* yacc.c:1646  */
    {/*routine declaration part, new routine*/ (yyval.fundeclist) = A_FundecList((yyvsp[-1].fundec), (yyvsp[0].fundeclist));}
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 146 "Pascal.y" /* yacc.c:1646  */
    {(yyval.fundeclist) = NULL;}
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 148 "Pascal.y" /* yacc.c:1646  */
    {/*set function body*/(yyval.fundec) = (yyvsp[-3].fundec); (yyval.fundec)->body = (yyvsp[-1].exp);}
#line 1873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 149 "Pascal.y" /* yacc.c:1646  */
    {/*declare function head*/(yyval.fundec) = A_Fundec(EM_tokPos, (yyvsp[-3].sym), (yyvsp[-2].fieldlist), (yyvsp[0].ty)->u.name, NULL);}
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 150 "Pascal.y" /* yacc.c:1646  */
    {/*set procedure body*/ (yyval.fundec) = (yyvsp[-3].fundec); (yyval.fundec)->body = (yyvsp[-1].exp);}
#line 1885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 151 "Pascal.y" /* yacc.c:1646  */
    {/*declare procedure head, return type is NULL*/ (yyval.fundec) = A_Fundec(EM_tokPos, (yyvsp[-1].sym), (yyvsp[0].fieldlist), NULL, NULL);}
#line 1891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 152 "Pascal.y" /* yacc.c:1646  */
    {/*sub_routine in declaration*/(yyval.exp) = A_LetExp(EM_tokPos, (yyvsp[-1].declist), (yyvsp[0].exp));}
#line 1897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 153 "Pascal.y" /* yacc.c:1646  */
    {/*parameters declaration*/ (yyval.fieldlist) = (yyvsp[-1].fieldlist);}
#line 1903 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 154 "Pascal.y" /* yacc.c:1646  */
    {/*no parameters*/ (yyval.fieldlist) = NULL;}
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 155 "Pascal.y" /* yacc.c:1646  */
    {/*represent parameter declaration as A_fieldList*/ (yyval.fieldlist) = A_linkFieldList((yyvsp[-2].fieldlist), (yyvsp[0].fieldlist));}
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 156 "Pascal.y" /* yacc.c:1646  */
    {(yyval.fieldlist) = (yyvsp[0].fieldlist);}
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 157 "Pascal.y" /* yacc.c:1646  */
    { (yyval.fieldlist) = A_setFieldListType((yyvsp[-2].fieldlist), (yyvsp[0].ty));}
#line 1927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 158 "Pascal.y" /* yacc.c:1646  */
    { (yyval.fieldlist) = A_setFieldListType((yyvsp[-2].fieldlist), (yyvsp[0].ty));}
#line 1933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 159 "Pascal.y" /* yacc.c:1646  */
    {(yyval.fieldlist) = (yyvsp[0].fieldlist);}
#line 1939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 160 "Pascal.y" /* yacc.c:1646  */
    {(yyval.fieldlist) = (yyvsp[0].fieldlist);}
#line 1945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 163 "Pascal.y" /* yacc.c:1646  */
    {/*set routine body as A_exp*/ (yyval.exp) = (yyvsp[0].exp);}
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 164 "Pascal.y" /* yacc.c:1646  */
    { (yyval.exp) = A_SeqExp(EM_tokPos, (yyvsp[-1].explist));}
#line 1957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 165 "Pascal.y" /* yacc.c:1646  */
    { /*statement in routine body*/(yyval.explist) = A_ExpList((yyvsp[-2].exp), (yyvsp[0].explist));}
#line 1963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 166 "Pascal.y" /* yacc.c:1646  */
    {(yyval.explist) = NULL;}
#line 1969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 167 "Pascal.y" /* yacc.c:1646  */
    {(yyval.explist) = NULL;}
#line 1975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 168 "Pascal.y" /* yacc.c:1646  */
    {(yyval.exp) = (yyvsp[0].exp);}
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 169 "Pascal.y" /* yacc.c:1646  */
    { (yyval.exp) = (yyvsp[0].exp);}
#line 1987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 170 "Pascal.y" /* yacc.c:1646  */
    { (yyval.exp) = (yyvsp[0].exp);}
#line 1993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 171 "Pascal.y" /* yacc.c:1646  */
    {/*call function or procedure*/ (yyval.exp) = (yyvsp[0].exp);}
#line 1999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 172 "Pascal.y" /* yacc.c:1646  */
    {(yyval.exp) = (yyvsp[0].exp);}
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 173 "Pascal.y" /* yacc.c:1646  */
    {(yyval.exp) = (yyvsp[0].exp);}
#line 2011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 174 "Pascal.y" /* yacc.c:1646  */
    {  (yyval.exp) = (yyvsp[0].exp);}
#line 2017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 175 "Pascal.y" /* yacc.c:1646  */
    {(yyval.exp) = (yyvsp[0].exp);}
#line 2023 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 176 "Pascal.y" /* yacc.c:1646  */
    {(yyval.exp) = (yyvsp[0].exp);}
#line 2029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 177 "Pascal.y" /* yacc.c:1646  */
    {(yyval.exp) = (yyvsp[0].exp);}
#line 2035 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 178 "Pascal.y" /* yacc.c:1646  */
    {(yyval.exp) = (yyvsp[0].exp);}
#line 2041 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 179 "Pascal.y" /* yacc.c:1646  */
    {/*simple variable assignment*/ (yyval.exp) = A_AssignExp(EM_tokPos,A_SimpleVar(EM_tokPos, (yyvsp[-2].sym)), (yyvsp[0].exp));}
#line 2047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 180 "Pascal.y" /* yacc.c:1646  */
    {/*subscript variable of array assignment*/ (yyval.exp) = A_AssignExp(EM_tokPos, A_SubscriptVar(EM_tokPos, A_SimpleVar(EM_tokPos, (yyvsp[-5].sym)), (yyvsp[-3].exp)),(yyvsp[0].exp));}
#line 2053 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 181 "Pascal.y" /* yacc.c:1646  */
    {/*field variable of record assignment*/(yyval.exp) = A_AssignExp(EM_tokPos, A_FieldVar(EM_tokPos, A_SimpleVar(EM_tokPos, (yyvsp[-4].sym)), (yyvsp[-2].sym)),(yyvsp[0].exp));}
#line 2059 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 182 "Pascal.y" /* yacc.c:1646  */
    {/*call function*/ (yyval.exp) = A_CallExp(EM_tokPos, (yyvsp[0].sym), NULL);}
#line 2065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 183 "Pascal.y" /* yacc.c:1646  */
    {/*call function with arguments*/ (yyval.exp) = A_CallExp(EM_tokPos, (yyvsp[-3].sym), (yyvsp[-1].explist));}
#line 2071 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 184 "Pascal.y" /* yacc.c:1646  */
    {/*call system procedure*/(yyval.exp) = A_CallExp(EM_tokPos, (yyvsp[0].sym), NULL);}
#line 2077 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 185 "Pascal.y" /* yacc.c:1646  */
    {/*call system procedure with arguments*/(yyval.exp) = A_CallExp(EM_tokPos, (yyvsp[-3].sym), (yyvsp[-1].explist));}
#line 2083 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 186 "Pascal.y" /* yacc.c:1646  */
    {}
#line 2089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 187 "Pascal.y" /* yacc.c:1646  */
    {/*if statement*/ (yyval.exp) = A_IfExp(EM_tokPos, (yyvsp[-3].exp), (yyvsp[-1].exp), (yyvsp[0].exp));}
#line 2095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 188 "Pascal.y" /* yacc.c:1646  */
    {/*with else clause*/ (yyval.exp) = (yyvsp[0].exp);}
#line 2101 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 189 "Pascal.y" /* yacc.c:1646  */
    {/*no else clause*/ (yyval.exp) = NULL;}
#line 2107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 190 "Pascal.y" /* yacc.c:1646  */
    {/*repeat statement*/ 
          (yyval.exp) = A_RepeatExp(EM_tokPos, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 2114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 192 "Pascal.y" /* yacc.c:1646  */
    {/*while statement*/ (yyval.exp) = A_WhileExp(EM_tokPos, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 2120 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 193 "Pascal.y" /* yacc.c:1646  */
    {/*for statement*/
    A_var var =  A_SimpleVar(EM_tokPos, (yyvsp[-6].sym));
    if (!((yyvsp[-3].cval))) {
        // to 
        (yyval.exp) = A_SeqExp(EM_tokPos, A_ExpList(A_AssignExp(EM_tokPos, var, (yyvsp[-4].exp)), A_ExpList(A_WhileExp(EM_tokPos, A_OpExp(EM_tokPos, A_ltOp, A_VarExp(EM_tokPos, var), (yyvsp[-2].exp)), (yyvsp[0].exp)), NULL )));
    } else {
        // downto 
        (yyval.exp) = A_SeqExp(EM_tokPos, A_ExpList(A_AssignExp(EM_tokPos, var, (yyvsp[-4].exp)), A_ExpList(A_WhileExp(EM_tokPos, A_OpExp(EM_tokPos, A_gtOp, A_VarExp(EM_tokPos ,var), (yyvsp[-2].exp)), (yyvsp[0].exp)), NULL )));
    }  
}
#line 2135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 203 "Pascal.y" /* yacc.c:1646  */
    {(yyval.cval) = 0;}
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 204 "Pascal.y" /* yacc.c:1646  */
    {(yyval.cval) = 1;}
#line 2147 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 205 "Pascal.y" /* yacc.c:1646  */
    {/*case statement, case_expr_list is all the possible value*/ (yyval.exp) = A_CaseExp(EM_tokPos, (yyvsp[-3].exp), (yyvsp[-1].explist));}
#line 2153 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 206 "Pascal.y" /* yacc.c:1646  */
    {(yyval.explist) = A_ExpList((yyvsp[-1].exp), (yyvsp[0].explist));}
#line 2159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 207 "Pascal.y" /* yacc.c:1646  */
    {(yyval.explist) = A_ExpList((yyvsp[0].exp), NULL);}
#line 2165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 208 "Pascal.y" /* yacc.c:1646  */
    {(yyval.exp) = A_CaseValExp(EM_tokPos, (yyvsp[-3].exp), (yyvsp[-1].exp));}
#line 2171 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 209 "Pascal.y" /* yacc.c:1646  */
    {(yyval.exp) = A_CaseValExp(EM_tokPos, A_VarExp(EM_tokPos, A_SimpleVar(EM_tokPos, (yyvsp[-3].sym))), (yyvsp[-1].exp));}
#line 2177 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 210 "Pascal.y" /* yacc.c:1646  */
    {/*goto statement*/ (yyval.exp) = A_GotoExp(EM_tokPos, A_IntExp(EM_tokPos, (yyvsp[0].ival)));}
#line 2183 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 212 "Pascal.y" /* yacc.c:1646  */
    { (yyval.explist) = A_ExpList((yyvsp[-2].exp), (yyvsp[0].explist));}
#line 2189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 213 "Pascal.y" /* yacc.c:1646  */
    {(yyval.explist) = A_ExpList((yyvsp[0].exp), NULL);}
#line 2195 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 214 "Pascal.y" /* yacc.c:1646  */
    {/*greater equal expression*/ (yyval.exp) = A_OpExp(EM_tokPos, A_geOp, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 2201 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 215 "Pascal.y" /* yacc.c:1646  */
    {/*greater than expression*/ (yyval.exp) = A_OpExp(EM_tokPos, A_gtOp, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 2207 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 216 "Pascal.y" /* yacc.c:1646  */
    {/*less equal expression*/ (yyval.exp) = A_OpExp(EM_tokPos, A_leOp, (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 2213 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 217 "Pascal.y" /* yacc.c:1646  */
    {/*less than expression*/ (yyval.exp) = A_OpExp(EM_tokPos, A_ltOp, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 2219 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 218 "Pascal.y" /* yacc.c:1646  */
    {/*equal expression*/ (yyval.exp) = A_OpExp(EM_tokPos, A_eqOp, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 2225 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 219 "Pascal.y" /* yacc.c:1646  */
    {/*unequal expression*/ (yyval.exp) = A_OpExp(EM_tokPos, A_neqOp, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 2231 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 220 "Pascal.y" /* yacc.c:1646  */
    { (yyval.exp) = (yyvsp[0].exp);}
#line 2237 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 222 "Pascal.y" /* yacc.c:1646  */
    {(yyval.exp) = A_OpExp(EM_tokPos, A_plusOp, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 2243 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 223 "Pascal.y" /* yacc.c:1646  */
    {(yyval.exp) = A_OpExp(EM_tokPos, A_minusOp, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 2249 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 224 "Pascal.y" /* yacc.c:1646  */
    {/*bool operation or*/ (yyval.exp) = A_IfExp(EM_tokPos, (yyvsp[-2].exp), A_IntExp(EM_tokPos, 1), (yyvsp[0].exp));}
#line 2255 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 225 "Pascal.y" /* yacc.c:1646  */
    { (yyval.exp) = (yyvsp[0].exp);}
#line 2261 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 226 "Pascal.y" /* yacc.c:1646  */
    { (yyval.exp) = A_OpExp(EM_tokPos, A_timesOp, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 2267 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 227 "Pascal.y" /* yacc.c:1646  */
    { /*intdiv operation*/ (yyval.exp) = A_OpExp(EM_tokPos, A_divideOp, (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 2273 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 228 "Pascal.y" /* yacc.c:1646  */
    { /*real div operaiton*/ (yyval.exp) = A_OpExp(EM_tokPos, A_realDivideOp, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 2279 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 229 "Pascal.y" /* yacc.c:1646  */
    { /*mod operation*/ (yyval.exp) = A_OpExp(EM_tokPos, A_modOp, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 2285 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 230 "Pascal.y" /* yacc.c:1646  */
    { /*bool operation and*/ (yyval.exp) = A_IfExp(EM_tokPos, (yyvsp[-2].exp), (yyvsp[0].exp), A_IntExp(EM_tokPos, 0));}
#line 2291 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 231 "Pascal.y" /* yacc.c:1646  */
    { (yyval.exp) = (yyvsp[0].exp);}
#line 2297 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 232 "Pascal.y" /* yacc.c:1646  */
    {(yyval.exp) = A_VarExp(EM_tokPos, A_SimpleVar(EM_tokPos, (yyvsp[0].sym)));}
#line 2303 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 233 "Pascal.y" /* yacc.c:1646  */
    {/*call function*/(yyval.exp) = A_CallExp(EM_tokPos, (yyvsp[-3].sym), (yyvsp[-1].explist));}
#line 2309 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 234 "Pascal.y" /* yacc.c:1646  */
    {/*call system function without argument*/(yyval.exp) = A_CallExp(EM_tokPos, (yyvsp[0].sym), NULL);}
#line 2315 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 235 "Pascal.y" /* yacc.c:1646  */
    {/*call system function with arguments*/(yyval.exp) = A_CallExp(EM_tokPos, (yyvsp[-3].sym), (yyvsp[-1].explist));}
#line 2321 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 236 "Pascal.y" /* yacc.c:1646  */
    {/*const expression*/ (yyval.exp) = (yyvsp[0].exp);}
#line 2327 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 237 "Pascal.y" /* yacc.c:1646  */
    { /*expression*/ (yyval.exp) = (yyvsp[-1].exp);}
#line 2333 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 238 "Pascal.y" /* yacc.c:1646  */
    { /*bool operation, not*/ (yyval.exp) = A_IfExp(EM_tokPos, (yyvsp[0].exp), A_IntExp(EM_tokPos, 0), A_IntExp(EM_tokPos,1));}
#line 2339 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 239 "Pascal.y" /* yacc.c:1646  */
    {/*expression with negative value*/ (yyval.exp) = A_OpExp(EM_tokPos, A_minusOp, A_IntExp(EM_tokPos, 0), (yyvsp[0].exp));}
#line 2345 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 240 "Pascal.y" /* yacc.c:1646  */
    { /*subscript variable expression*/ (yyval.exp) = A_VarExp(EM_tokPos,A_SubscriptVar(EM_tokPos, A_SimpleVar(EM_tokPos, (yyvsp[-3].sym)), (yyvsp[-1].exp)));}
#line 2351 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 241 "Pascal.y" /* yacc.c:1646  */
    { /*field variable expression*/ (yyval.exp) = A_VarExp(EM_tokPos, A_FieldVar(EM_tokPos, A_SimpleVar(EM_tokPos, (yyvsp[-2].sym)), (yyvsp[0].sym)));}
#line 2357 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 242 "Pascal.y" /* yacc.c:1646  */
    {(yyval.explist) = (yyvsp[-2].explist); (yyvsp[-2].explist)->tail = A_ExpList((yyvsp[0].exp), NULL);}
#line 2363 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 243 "Pascal.y" /* yacc.c:1646  */
    {(yyval.explist) = A_ExpList((yyvsp[0].exp), NULL);}
#line 2369 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 245 "Pascal.y" /* yacc.c:1646  */
    {(yyval.sym) = S_Symbol((yyvsp[0].sval));}
#line 2375 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 246 "Pascal.y" /* yacc.c:1646  */
    {(yyval.sym) = S_Symbol((yyvsp[0].sval));}
#line 2381 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 247 "Pascal.y" /* yacc.c:1646  */
    {(yyval.sym) = S_Symbol((yyvsp[0].sval));}
#line 2387 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 248 "Pascal.y" /* yacc.c:1646  */
    {(yyval.sym) = S_Symbol((yyvsp[0].sval));}
#line 2393 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 249 "Pascal.y" /* yacc.c:1646  */
    {(yyval.sym) = S_Symbol((yyvsp[0].sval));}
#line 2399 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 251 "Pascal.y" /* yacc.c:1646  */
    {/*jump to next semi after error */}
#line 2405 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2409 "y.tab.c" /* yacc.c:1646  */
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
#line 253 "Pascal.y" /* yacc.c:1906  */

int yyerror(char* msg) {
    EM_error(EM_tokPos, "%s", msg);
    return 0;   
}

// link two fieldlists 
A_fieldList A_linkFieldList(A_fieldList front, A_fieldList tail) {
    if (!front)
        return tail;
    A_fieldList pos = front;
    for (;pos->tail;pos = pos->tail);
    pos->tail = tail; 

    return front;
}

// set fieldList's type to ty 
A_fieldList A_setFieldListType(A_fieldList fieldList, A_ty ty) {
    A_fieldList front = fieldList;
    for (;fieldList;fieldList = fieldList->tail) {
        fieldList->head->typ = ty->u.name;
    }

    return front;
}

A_decList A_linkDecList(A_decList front, A_decList tail) {
    if (!front)
        return tail;
    A_decList pos = front;
    for (;pos->tail;pos = pos->tail);
    pos->tail = tail;

    return front;
}

A_decList A_setDecListType(A_decList decList, A_ty ty) {
    A_decList front = decList;
    for (;decList;decList = decList->tail) {
        decList->head->u.var.typ = ty->u.name;
    }

    return front;
}

A_decList A_unDecList(A_fieldList fieldList) {
    // null field list 
    if (!fieldList)
        return NULL;

    A_field field = fieldList->head;
    A_decList decList = A_DecList(A_VarDec(field->pos, field->name, field->typ, NULL), NULL);
    A_decList front = decList;

    for(fieldList= fieldList->tail;fieldList;fieldList = fieldList->tail, decList = decList->tail) {
        field = fieldList->head;
        decList->tail = A_DecList(A_VarDec(field->pos, field->name, field->typ, NULL), NULL);
    }

    return front;
}
