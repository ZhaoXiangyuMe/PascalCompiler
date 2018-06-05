
/*  A Bison parser, made from pascal.y
    by GNU Bison version 1.28  */

#define YYBISON 1  /* Identify Bison output.  */

#define	LP	257
#define	RP	258
#define	LB	259
#define	RB	260
#define	DOT	261
#define	COMMA	262
#define	COLON	263
#define	SEMI	264
#define	PLUS	265
#define	MINUS	266
#define	MUL	267
#define	REALDIV	268
#define	INTDIV	269
#define	MOD	270
#define	AND	271
#define	OR	272
#define	NOT	273
#define	GE	274
#define	GT	275
#define	LE	276
#define	LT	277
#define	EQUAL	278
#define	UNEQUAL	279
#define	ASSIGN	280
#define	PROGRAM	281
#define	FUNCTION	282
#define	PROCEDURE	283
#define	BEGIN_T	284
#define	END	285
#define	TYPE	286
#define	ARRAY	287
#define	OF	288
#define	RECORD	289
#define	VAR	290
#define	IF	291
#define	THEN	292
#define	ELSE	293
#define	REPEAT	294
#define	TO	295
#define	DOWNTO	296
#define	UNTIL	297
#define	WHILE	298
#define	DO	299
#define	FOR	300
#define	CASE	301
#define	GOTO	302
#define	READ	303
#define	CONST	304
#define	DOTDOT	305
#define	INTEGER	306
#define	REAL	307
#define	CHAR	308
#define	ID	309
#define	STRING	310
#define	SYS_CON	311
#define	SYS_FUNCT	312
#define	SYS_PROC	313
#define	SYS_TYPE	314

#line 1 "pascal.y"


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


#line 39 "pascal.y"
typedef union {
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
} YYSTYPE;
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		269
#define	YYFLAG		-32768
#define	YYNTBASE	61

#define YYTRANSLATE(x) ((unsigned)(x) <= 314 ? yytranslate[x] : 122)

static const char yytranslate[] = {     0,
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
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
    47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
    57,    58,    59,    60
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     4,     8,    11,    17,    18,    21,    22,    28,    33,
    35,    37,    39,    41,    43,    46,    47,    50,    52,    57,
    59,    61,    63,    65,    67,    71,    75,    80,    86,    90,
    97,   101,   104,   106,   111,   115,   117,   120,   121,   124,
   126,   131,   134,   137,   138,   143,   149,   154,   158,   161,
   165,   166,   170,   172,   176,   180,   183,   185,   187,   191,
   195,   196,   198,   202,   204,   206,   208,   210,   212,   214,
   216,   218,   220,   222,   226,   233,   239,   241,   246,   248,
   253,   258,   264,   267,   268,   273,   278,   287,   289,   291,
   297,   300,   302,   307,   312,   315,   319,   321,   325,   329,
   333,   337,   341,   345,   347,   351,   355,   359,   361,   365,
   369,   373,   377,   381,   383,   385,   390,   392,   397,   399,
   403,   406,   409,   414,   418,   422,   424,   426,   428,   430,
   432,   434
};

static const short yyrhs[] = {    62,
    63,     7,     0,    27,   116,    10,     0,    64,    93,     0,
    65,    66,    69,    79,    82,     0,     0,    50,    67,     0,
     0,   116,    24,    68,    10,    67,     0,   116,    24,    68,
    10,     0,    52,     0,    53,     0,    54,     0,    56,     0,
   117,     0,    32,    70,     0,     0,    71,    70,     0,    71,
     0,   116,    24,    72,    10,     0,    73,     0,    74,     0,
    75,     0,   120,     0,   116,     0,     3,    78,     4,     0,
    68,    51,    68,     0,    12,    68,    51,    68,     0,    12,
    68,    51,    12,    68,     0,   116,    51,   116,     0,    33,
     5,    73,     6,    34,    72,     0,    35,    76,    31,     0,
    77,    76,     0,    77,     0,    78,     9,    72,    10,     0,
    78,     8,   116,     0,   116,     0,    36,    80,     0,     0,
    81,    80,     0,    81,     0,    78,     9,    72,    10,     0,
    83,    82,     0,    85,    82,     0,     0,    84,    10,    87,
    10,     0,    28,   116,    88,     9,    73,     0,    86,    10,
    87,    10,     0,    29,   116,    88,     0,    64,    93,     0,
     3,    89,     4,     0,     0,    89,    10,    90,     0,    90,
     0,    91,     9,    73,     0,    92,     9,    73,     0,    36,
    78,     0,    78,     0,    94,     0,    30,    95,    31,     0,
    96,    10,    95,     0,     0,   121,     0,    52,     9,    97,
     0,    97,     0,    98,     0,    99,     0,    94,     0,   100,
     0,   102,     0,   103,     0,   104,     0,   106,     0,   109,
     0,   116,    26,   111,     0,   116,     5,   111,     6,    26,
   111,     0,   116,     7,   116,    26,   111,     0,   116,     0,
   116,     3,   115,     4,     0,   119,     0,   119,     3,   110,
     4,     0,    49,     3,   114,     4,     0,    37,   111,    38,
    96,   101,     0,    39,    96,     0,     0,    40,    96,    43,
   111,     0,    44,   111,    45,    96,     0,    46,   116,    26,
   111,   105,   111,    45,    96,     0,    41,     0,    42,     0,
    47,   111,    34,   107,    31,     0,   108,   107,     0,   108,
     0,    68,     9,    96,    10,     0,   116,     9,    96,    10,
     0,    48,    52,     0,   111,     8,   110,     0,   111,     0,
   111,    20,   112,     0,   111,    21,   112,     0,   111,    22,
   112,     0,   111,    23,   112,     0,   111,    24,   112,     0,
   111,    25,   112,     0,   112,     0,   112,    11,   113,     0,
   112,    12,   113,     0,   112,    18,   113,     0,   113,     0,
   113,    13,   114,     0,   113,    15,   114,     0,   113,    14,
   114,     0,   113,    16,   114,     0,   113,    17,   114,     0,
   114,     0,   116,     0,   116,     3,   115,     4,     0,   118,
     0,   118,     3,   115,     4,     0,    68,     0,     3,   111,
     4,     0,    19,   114,     0,    12,   114,     0,   116,     5,
   111,     6,     0,   116,     7,   116,     0,   115,     8,   111,
     0,   111,     0,    55,     0,    57,     0,    58,     0,    59,
     0,    60,     0,     1,    10,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    81,    82,    83,    84,    98,   101,   102,   103,   104,   105,
   106,   107,   108,   109,   112,   113,   114,   115,   116,   117,
   118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
   128,   130,   131,   132,   133,   134,   137,   138,   139,   140,
   141,   144,   145,   146,   148,   149,   150,   151,   152,   153,
   154,   155,   156,   157,   158,   159,   160,   163,   164,   165,
   166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
   176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
   186,   187,   188,   189,   190,   192,   193,   203,   204,   205,
   206,   207,   208,   209,   210,   212,   213,   214,   215,   216,
   217,   218,   219,   220,   222,   223,   224,   225,   226,   227,
   228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
   238,   239,   240,   241,   242,   243,   245,   246,   247,   248,
   249,   251
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","LP","RP",
"LB","RB","DOT","COMMA","COLON","SEMI","PLUS","MINUS","MUL","REALDIV","INTDIV",
"MOD","AND","OR","NOT","GE","GT","LE","LT","EQUAL","UNEQUAL","ASSIGN","PROGRAM",
"FUNCTION","PROCEDURE","BEGIN_T","END","TYPE","ARRAY","OF","RECORD","VAR","IF",
"THEN","ELSE","REPEAT","TO","DOWNTO","UNTIL","WHILE","DO","FOR","CASE","GOTO",
"READ","CONST","DOTDOT","INTEGER","REAL","CHAR","ID","STRING","SYS_CON","SYS_FUNCT",
"SYS_PROC","SYS_TYPE","program","program_head","routine","routine_head","label_part",
"const_part","const_expr_list","const_value","type_part","type_decl_list","type_definition",
"type_decl","simple_type_decl","array_type_decl","record_type_decl","field_decl_list",
"field_decl","name_list","var_part","var_decl_list","var_decl","routine_part",
"function_decl","function_head","procedure_decl","procedure_head","sub_routine",
"parameters","para_decl_list","para_type_list","var_para_list","val_para_list",
"routine_body","compound_stmt","stmt_list","stmt","non_label_stmt","assign_stmt",
"proc_stmt","if_stmt","else_clause","repeat_stmt","while_stmt","for_stmt","direction",
"case_stmt","case_expr_list","case_expr","goto_stmt","expression_list","expression",
"expr","term","factor","args_list","id","sys_con","sys_funct","sys_proc","sys_type",
"stat", NULL
};
#endif

static const short yyr1[] = {     0,
    61,    62,    63,    64,    65,    66,    66,    67,    67,    68,
    68,    68,    68,    68,    69,    69,    70,    70,    71,    72,
    72,    72,    73,    73,    73,    73,    73,    73,    73,    74,
    75,    76,    76,    77,    78,    78,    79,    79,    80,    80,
    81,    82,    82,    82,    83,    84,    85,    86,    87,    88,
    88,    89,    89,    90,    90,    91,    92,    93,    94,    95,
    95,    95,    96,    96,    97,    97,    97,    97,    97,    97,
    97,    97,    97,    98,    98,    98,    99,    99,    99,    99,
    99,   100,   101,   101,   102,   103,   104,   105,   105,   106,
   107,   107,   108,   108,   109,   110,   110,   111,   111,   111,
   111,   111,   111,   111,   112,   112,   112,   112,   113,   113,
   113,   113,   113,   113,   114,   114,   114,   114,   114,   114,
   114,   114,   114,   114,   115,   115,   116,   117,   118,   119,
   120,   121
};

static const short yyr2[] = {     0,
     3,     3,     2,     5,     0,     2,     0,     5,     4,     1,
     1,     1,     1,     1,     2,     0,     2,     1,     4,     1,
     1,     1,     1,     1,     3,     3,     4,     5,     3,     6,
     3,     2,     1,     4,     3,     1,     2,     0,     2,     1,
     4,     2,     2,     0,     4,     5,     4,     3,     2,     3,
     0,     3,     1,     3,     3,     2,     1,     1,     3,     3,
     0,     1,     3,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     3,     6,     5,     1,     4,     1,     4,
     4,     5,     2,     0,     4,     4,     8,     1,     1,     5,
     2,     1,     4,     4,     2,     3,     1,     3,     3,     3,
     3,     3,     3,     1,     3,     3,     3,     1,     3,     3,
     3,     3,     3,     1,     1,     4,     1,     4,     1,     3,
     2,     2,     4,     3,     3,     1,     1,     1,     1,     1,
     1,     2
};

static const short yydefact[] = {     0,
     0,     5,   127,     0,     0,     0,     7,     2,     1,     0,
     3,    58,     0,    16,     0,     0,     0,     0,     0,     0,
     0,     0,     0,   130,    67,     0,     0,    64,    65,    66,
    68,    69,    70,    71,    72,    73,    77,    79,    62,     6,
     0,     0,    38,   132,     0,     0,     0,    10,    11,    12,
    13,   128,   129,   119,     0,   104,   108,   114,   115,    14,
   117,     0,     0,     0,     0,    95,     0,     0,    59,     0,
     0,     0,     0,     0,     0,     0,    15,    18,     0,     0,
    44,     0,   122,   121,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,    63,    60,
   126,     0,     0,     0,    74,     0,    97,     0,    17,     0,
     0,    37,    40,    36,     0,     0,     4,    44,     0,    44,
     0,   120,    98,    99,   100,   101,   102,   103,    84,   105,
   106,   107,   109,   111,   110,   112,   113,     0,     0,   124,
     0,    85,    86,     0,     0,     0,    92,     0,    81,    78,
     0,     0,     0,    80,     0,     9,     0,     0,     0,     0,
   131,     0,     0,    20,    21,    22,    24,    23,     0,     0,
    39,    51,    51,    42,     5,    43,     5,     0,    82,   116,
   123,   118,    88,    89,     0,     0,    90,    91,     0,   125,
     0,    76,    96,     8,     0,     0,     0,     0,    33,     0,
     0,    19,     0,    35,     0,     0,     0,    48,     0,     0,
     0,    83,     0,     0,     0,    75,    25,     0,     0,    31,
    32,     0,    26,    29,    41,     0,    57,     0,    53,     0,
     0,     0,    49,    45,    47,     0,    93,    94,     0,    27,
     0,     0,    56,    50,     0,     0,     0,    46,    87,    28,
     0,    34,    52,    54,    55,    30,     0,     0,     0
};

static const short yydefgoto[] = {   267,
     2,     5,   219,     7,    14,    40,    54,    43,    77,    78,
   173,   174,   175,   176,   208,   209,   121,    81,   122,   123,
   127,   128,   129,   130,   131,   220,   217,   238,   239,   240,
   241,    11,    25,    26,    27,    28,    29,    30,    31,   189,
    32,    33,    34,   195,    35,   156,   157,    36,   116,   111,
    56,    57,    58,   112,    59,    60,    61,    38,   178,    39
};

static const short yypact[] = {   -25,
   -33,-32768,-32768,    38,    44,    28,    21,-32768,-32768,   173,
-32768,-32768,   -33,    41,    66,     7,   228,     7,   -33,     7,
    34,    88,    85,-32768,-32768,    71,   103,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,    18,   108,-32768,-32768,
    94,   -33,    90,-32768,     7,     7,     7,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,   322,    -5,   223,-32768,    63,-32768,
   133,   110,   226,   128,   333,-32768,     7,   -10,-32768,   173,
     7,     7,   -33,     7,     7,    43,-32768,   -33,   136,   -33,
    92,   290,-32768,-32768,     7,     7,     7,     7,     7,     7,
   228,     7,     7,     7,     7,     7,     7,     7,     7,     7,
     7,   -33,     7,     7,   228,     7,   317,   160,-32768,-32768,
   355,    20,   310,   147,   355,   171,   341,   166,-32768,    75,
   125,-32768,   -33,-32768,   -33,   -33,-32768,    92,   172,    92,
   175,-32768,    -5,    -5,    -5,    -5,    -5,    -5,   142,   223,
   223,   223,-32768,-32768,-32768,-32768,-32768,    42,   316,-32768,
    49,   355,-32768,   284,   177,   157,   317,   180,-32768,-32768,
     7,   164,     7,-32768,     7,   -33,   -33,    43,   188,   -33,
-32768,   143,   189,-32768,-32768,-32768,   150,-32768,   -33,    75,
-32768,   202,   202,-32768,-32768,-32768,-32768,   228,-32768,-32768,
-32768,-32768,-32768,-32768,     7,   228,-32768,-32768,   228,   355,
     7,   355,-32768,-32768,   101,   156,    95,   178,   -33,   131,
    43,-32768,   -33,-32768,   201,   -22,   205,-32768,    28,   208,
   213,-32768,   278,   214,   216,   355,-32768,   105,   221,-32768,
-32768,    75,-32768,-32768,-32768,   -33,   225,    25,-32768,   220,
   233,    95,-32768,-32768,-32768,   228,-32768,-32768,    43,-32768,
   200,   234,   225,-32768,   -22,    95,    95,-32768,-32768,-32768,
    75,-32768,-32768,-32768,-32768,-32768,   243,   252,-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,   251,-32768,-32768,    97,   -65,-32768,   184,-32768,
  -176,  -119,-32768,-32768,    55,-32768,  -162,-32768,   144,-32768,
  -113,-32768,-32768,-32768,-32768,    79,    86,-32768,    15,-32768,
-32768,    54,    -3,   209,   -16,   210,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,   124,-32768,-32768,   117,    96,
   296,    51,   -15,   -60,    -1,-32768,-32768,-32768,-32768,-32768
};


#define	YYLAST		386


static const short yytable[] = {     4,
    62,     1,    12,   215,   205,    92,    93,   210,    37,    45,
   118,    41,    94,   236,   184,    37,   186,    64,    46,    10,
    71,     3,    72,   160,    73,    47,    16,   161,   254,    17,
    83,    84,     3,    18,   255,    19,    20,    21,    22,   148,
    79,   155,   151,    74,     3,   190,   210,     8,    24,   161,
     9,   108,   192,   237,   172,   252,   161,    10,    48,    49,
    50,     3,    51,    52,    53,   100,    37,   101,    37,   102,
    13,   114,    42,   253,   139,    44,    79,   167,   124,   143,
   144,   145,   146,   147,   266,    66,   168,   229,   153,    37,
    67,   155,   237,    68,    48,    49,    50,   167,    51,    52,
   150,    69,   206,    37,   227,   158,   168,   169,   179,   170,
    75,    55,    70,    63,   172,    65,   249,    76,   177,   125,
   126,   124,   258,   182,   183,    80,    48,    49,    50,     3,
    51,    52,   179,   180,   171,   103,   264,   265,   179,   232,
    82,   172,   140,   141,   142,   233,    48,    49,    50,     3,
    51,    52,   104,   106,   171,   158,    48,    49,    50,   120,
    51,    52,   250,   159,    41,   124,   172,   113,   124,   115,
   117,   222,   163,    15,   164,   166,   172,   214,   177,   224,
   188,   185,   225,   260,   187,   196,    37,   197,   199,   201,
   172,   172,   207,   211,    37,   172,   149,    37,   212,   152,
   213,   154,    10,   -61,   216,   177,   228,   124,   230,    16,
   235,   234,    17,   242,   124,    12,    18,   244,    19,    20,
    21,    22,   245,   247,    23,   248,   251,     3,   256,   259,
   177,    24,   179,   261,   124,    95,    96,    97,    98,    99,
   177,   257,   268,   262,    37,    85,    86,    87,    88,    89,
    90,   269,     6,   124,   177,   177,   200,    10,   202,   177,
   117,   119,   204,   231,    16,   221,   181,    17,   218,   263,
   105,    18,   243,    19,    20,    21,    22,   109,   110,    23,
   198,   203,     3,     0,     0,     0,    24,     0,     0,     0,
   223,     0,     0,   132,     0,     0,   226,    85,    86,    87,
    88,    89,    90,    85,    86,    87,    88,    89,    90,    85,
    86,    87,    88,    89,    90,   162,     0,     0,     0,     0,
     0,   191,   246,     0,   193,   194,     0,     0,     0,    85,
    86,    87,    88,    89,    90,    85,    86,    87,    88,    89,
    90,    85,    86,    87,    88,    89,    90,     0,   165,     0,
     0,     0,    85,    86,    87,    88,    89,    90,     0,    91,
    85,    86,    87,    88,    89,    90,   107,     0,    48,    49,
    50,     3,    51,    52,    85,    86,    87,    88,    89,    90,
   133,   134,   135,   136,   137,   138
};

static const short yycheck[] = {     1,
    17,    27,     6,   180,   167,    11,    12,   170,    10,     3,
    76,    13,    18,    36,   128,    17,   130,    19,    12,    30,
     3,    55,     5,     4,     7,    19,    37,     8,     4,    40,
    46,    47,    55,    44,    10,    46,    47,    48,    49,   100,
    42,   107,   103,    26,    55,     4,   209,    10,    59,     8,
     7,    67,     4,   216,   120,   232,     8,    30,    52,    53,
    54,    55,    56,    57,    58,     3,    68,     5,    70,     7,
    50,    73,    32,   236,    91,    10,    78,     3,    80,    95,
    96,    97,    98,    99,   261,    52,    12,   207,   105,    91,
     3,   157,   255,     9,    52,    53,    54,     3,    56,    57,
   102,    31,   168,   105,     4,   107,    12,    33,     8,    35,
     3,    16,    10,    18,   180,    20,    12,    24,   120,    28,
    29,   123,   242,   125,   126,    36,    52,    53,    54,    55,
    56,    57,     8,     9,    60,     3,   256,   257,     8,     9,
    45,   207,    92,    93,    94,   211,    52,    53,    54,    55,
    56,    57,    43,    26,    60,   157,    52,    53,    54,    24,
    56,    57,   228,     4,   166,   167,   232,    72,   170,    74,
    75,   188,    26,     1,     4,    10,   242,   179,   180,   196,
    39,    10,   199,   249,    10,     9,   188,    31,     9,    26,
   256,   257,     5,    51,   196,   261,   101,   199,    10,   104,
    51,   106,    30,    31,     3,   207,    51,   209,    31,    37,
    10,   213,    40,     9,   216,   219,    44,    10,    46,    47,
    48,    49,    10,    10,    52,    10,     6,    55,     9,   246,
   232,    59,     8,    34,   236,    13,    14,    15,    16,    17,
   242,     9,     0,    10,   246,    20,    21,    22,    23,    24,
    25,     0,     2,   255,   256,   257,   161,    30,   163,   261,
   165,    78,   166,   209,    37,   187,   123,    40,   183,   255,
    45,    44,   219,    46,    47,    48,    49,    68,    70,    52,
   157,   165,    55,    -1,    -1,    -1,    59,    -1,    -1,    -1,
   195,    -1,    -1,     4,    -1,    -1,   201,    20,    21,    22,
    23,    24,    25,    20,    21,    22,    23,    24,    25,    20,
    21,    22,    23,    24,    25,     6,    -1,    -1,    -1,    -1,
    -1,     6,    45,    -1,    41,    42,    -1,    -1,    -1,    20,
    21,    22,    23,    24,    25,    20,    21,    22,    23,    24,
    25,    20,    21,    22,    23,    24,    25,    -1,     8,    -1,
    -1,    -1,    20,    21,    22,    23,    24,    25,    -1,    38,
    20,    21,    22,    23,    24,    25,    34,    -1,    52,    53,
    54,    55,    56,    57,    20,    21,    22,    23,    24,    25,
    85,    86,    87,    88,    89,    90
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/usr/local/share/bison.simple"
/* This file comes from bison-1.28.  */

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

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
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

#ifndef YYSTACK_USE_ALLOCA
#ifdef alloca
#define YYSTACK_USE_ALLOCA
#else /* alloca not defined */
#ifdef __GNUC__
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi) || (defined (__sun) && defined (__i386))
#define YYSTACK_USE_ALLOCA
#include <alloca.h>
#else /* not sparc */
/* We think this test detects Watcom and Microsoft C.  */
/* This used to test MSDOS, but that is a bad idea
   since that symbol is in the user namespace.  */
#if (defined (_MSDOS) || defined (_MSDOS_)) && !defined (__TURBOC__)
#if 0 /* No need for malloc.h, which pollutes the namespace;
	 instead, just don't use alloca.  */
#include <malloc.h>
#endif
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
/* I don't know what this was needed for, but it pollutes the namespace.
   So I turned it off.   rms, 2 May 1997.  */
/* #include <malloc.h>  */
 #pragma alloca
#define YYSTACK_USE_ALLOCA
#else /* not MSDOS, or __TURBOC__, or _AIX */
#if 0
#ifdef __hpux /* haible@ilog.fr says this works for HPUX 9.05 and up,
		 and on HPUX 10.  Eventually we can turn this on.  */
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#endif /* __hpux */
#endif
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc */
#endif /* not GNU C */
#endif /* alloca not defined */
#endif /* YYSTACK_USE_ALLOCA not defined */

#ifdef YYSTACK_USE_ALLOCA
#define YYSTACK_ALLOC alloca
#else
#define YYSTACK_ALLOC malloc
#endif

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Define __yy_memcpy.  Note that the size argument
   should be passed with type unsigned int, because that is what the non-GCC
   definitions require.  With GCC, __builtin_memcpy takes an arg
   of type size_t, but it can handle unsigned int.  */

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (to, from, count)
     char *to;
     char *from;
     unsigned int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *to, char *from, unsigned int count)
{
  register char *t = to;
  register char *f = from;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 217 "/usr/local/share/bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
#ifdef YYPARSE_PARAM
int yyparse (void *);
#else
int yyparse (void);
#endif
#endif

int
yyparse(YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;
  int yyfree_stacks = 0;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  if (yyfree_stacks)
	    {
	      free (yyss);
	      free (yyvs);
#ifdef YYLSP_NEEDED
	      free (yyls);
#endif
	    }
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
#ifndef YYSTACK_USE_ALLOCA
      yyfree_stacks = 1;
#endif
      yyss = (short *) YYSTACK_ALLOC (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss, (char *)yyss1,
		   size * (unsigned int) sizeof (*yyssp));
      yyvs = (YYSTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs, (char *)yyvs1,
		   size * (unsigned int) sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls, (char *)yyls1,
		   size * (unsigned int) sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 81 "pascal.y"
{/*set root for abstract syntax tree*/ A_synTreeRoot = yyvsp[-1].exp; /*printf("Program parsed.\n");*/;
    break;}
case 2:
#line 82 "pascal.y"
{/*printf("Program head.\n");*/;
    break;}
case 3:
#line 83 "pascal.y"
{/*head:declaration with type A_decList,  body:expression with type A_exp*/ yyval.exp = A_LetExp(EM_tokPos, yyvsp[-1].declist, yyvsp[0].exp);;
    break;}
case 4:
#line 84 "pascal.y"
{ 
        /* placeholder*/
        A_decList decList = A_DecList(A_TypeDec(0, NULL), NULL);
        if (yyvsp[-3].declist) 
            A_linkDecList(decList, yyvsp[-3].declist);
        if (yyvsp[-2].declist)
            A_linkDecList(decList, yyvsp[-2].declist);
        if (yyvsp[-1].declist) 
            A_linkDecList(decList, yyvsp[-1].declist);
        if (yyvsp[0].fundeclist)
            A_linkDecList(decList, A_DecList(A_FunctionDec(EM_tokPos, yyvsp[0].fundeclist), NULL));
        yyval.declist = decList->tail;
    ;
    break;}
case 5:
#line 98 "pascal.y"
{/*label part is empty in pascal*/ yyval.declist = NULL;;
    break;}
case 6:
#line 101 "pascal.y"
{/*const declaration part*/ yyval.declist = yyvsp[0].declist;;
    break;}
case 7:
#line 102 "pascal.y"
{/*no const declaration*/ yyval.declist = NULL;;
    break;}
case 8:
#line 103 "pascal.y"
{/*const declaration list*/ yyval.declist = A_DecList(A_ConstDec(EM_tokPos, yyvsp[-4].sym, yyvsp[-2].exp),yyvsp[0].declist);;
    break;}
case 9:
#line 104 "pascal.y"
{/*first one in list*/ yyval.declist = A_DecList(A_ConstDec(EM_tokPos, yyvsp[-3].sym, yyvsp[-1].exp), NULL);;
    break;}
case 10:
#line 105 "pascal.y"
{/*integer value*/ yyval.exp = A_IntExp(EM_tokPos, yyvsp[0].ival);;
    break;}
case 11:
#line 106 "pascal.y"
{/*real value*/ yyval.exp = A_RealExp(EM_tokPos, yyvsp[0].rval);;
    break;}
case 12:
#line 107 "pascal.y"
{/*char value*/ yyval.exp = A_CharExp(EM_tokPos, yyvsp[0].cval);;
    break;}
case 13:
#line 108 "pascal.y"
{/*string value*/ yyval.exp = A_StringExp(EM_tokPos, yyvsp[0].sval);;
    break;}
case 14:
#line 109 "pascal.y"
{/*system const value*/ /*$$ = A_SysConstExp(EM_tokPos, $1);*/;
    break;}
case 15:
#line 112 "pascal.y"
{/*type declaration part*/ yyval.declist = A_DecList(A_TypeDec(EM_tokPos, yyvsp[0].nametylist), NULL);;
    break;}
case 16:
#line 113 "pascal.y"
{/*no type declaration*/ yyval.declist = NULL;;
    break;}
case 17:
#line 114 "pascal.y"
{/*type declaration list*/ yyval.nametylist = A_NametyList(yyvsp[-1].namety, yyvsp[0].nametylist);;
    break;}
case 18:
#line 115 "pascal.y"
{/*last type definition, tail points to NULL*/yyval.nametylist = A_NametyList(yyvsp[0].namety, NULL);;
    break;}
case 19:
#line 116 "pascal.y"
{/*type declaration*/yyval.namety =A_Namety(yyvsp[-3].sym, yyvsp[-1].ty);;
    break;}
case 20:
#line 117 "pascal.y"
{/*simple type*/ yyval.ty = yyvsp[0].ty;;
    break;}
case 21:
#line 118 "pascal.y"
{/*array type*/ yyval.ty = yyvsp[0].ty;;
    break;}
case 22:
#line 119 "pascal.y"
{/*record type*/ yyval.ty = yyvsp[0].ty;;
    break;}
case 23:
#line 120 "pascal.y"
{/*system defined type*/ yyval.ty = A_NameTy(EM_tokPos, yyvsp[0].sym);;
    break;}
case 24:
#line 121 "pascal.y"
{/*self define simple type*/ yyval.ty = A_NameTy(EM_tokPos, yyvsp[0].sym);;
    break;}
case 25:
#line 122 "pascal.y"
{/*enum type*/ yyval.ty = A_EnumType(EM_tokPos, yyvsp[-1].fieldlist);;
    break;}
case 26:
#line 123 "pascal.y"
{/*subrange type*/ yyval.ty = A_RangeTy(EM_tokPos, yyvsp[-2].exp, yyvsp[0].exp);;
    break;}
case 27:
#line 124 "pascal.y"
{/*subrange type*/ A_RangeTy(EM_tokPos, A_OpExp(EM_tokPos, A_minusOp, A_IntExp(EM_tokPos, 0), yyvsp[-2].exp), yyvsp[0].exp);;
    break;}
case 28:
#line 125 "pascal.y"
{/*subrange type*/ A_RangeTy(EM_tokPos, A_OpExp(EM_tokPos, A_minusOp, A_IntExp(EM_tokPos, 0), yyvsp[-3].exp), A_OpExp(EM_tokPos, A_minusOp, A_IntExp(EM_tokPos, 0), yyvsp[0].exp));;
    break;}
case 29:
#line 126 "pascal.y"
{/*subrange type*/ A_RangeTy(EM_tokPos, A_VarExp(EM_tokPos, A_SimpleVar(EM_tokPos, yyvsp[-2].sym)), A_VarExp(EM_tokPos, A_SimpleVar(EM_tokPos, yyvsp[0].sym)));;
    break;}
case 30:
#line 127 "pascal.y"
{/*array type, simple_type_dec is range of array, type_dec is actual type of array element*/ yyval.ty = A_ArrayTy(EM_tokPos, yyvsp[-3].ty, yyvsp[0].ty);;
    break;}
case 31:
#line 128 "pascal.y"
{/*record type*/ yyval.ty = A_RecordTy(EM_tokPos, yyvsp[-1].fieldlist);;
    break;}
case 32:
#line 130 "pascal.y"
{/*link parts of fieldlists*/ yyval.fieldlist = A_linkFieldList(yyvsp[-1].fieldlist, yyvsp[0].fieldlist); ;
    break;}
case 33:
#line 131 "pascal.y"
{yyval.fieldlist = yyvsp[0].fieldlist;;
    break;}
case 34:
#line 132 "pascal.y"
{ /*set type of namelist*/yyval.fieldlist = A_setFieldListType(yyvsp[-3].fieldlist, yyvsp[-1].ty);;
    break;}
case 35:
#line 133 "pascal.y"
{/*namelist is fieldlist of same unknown type*/ yyval.fieldlist = A_linkFieldList(yyvsp[-2].fieldlist, A_FieldList(A_Field(EM_tokPos, yyvsp[0].sym, NULL), NULL));;
    break;}
case 36:
#line 134 "pascal.y"
{yyval.fieldlist = A_FieldList(A_Field(EM_tokPos, yyvsp[0].sym, NULL), NULL);;
    break;}
case 37:
#line 137 "pascal.y"
{/*variable declaration part*/ yyval.declist = yyvsp[0].declist;;
    break;}
case 38:
#line 138 "pascal.y"
{/*no variable declaration*/ yyval.declist = NULL;;
    break;}
case 39:
#line 139 "pascal.y"
{/*variable declaration list*/ yyval.declist = A_linkDecList(yyvsp[-1].declist, yyvsp[0].declist);;
    break;}
case 40:
#line 140 "pascal.y"
{yyval.declist = yyvsp[0].declist;;
    break;}
case 41:
#line 141 "pascal.y"
{/*change name_list to variable declaration list*/ yyval.declist = A_setDecListType(A_unDecList(yyvsp[-3].fieldlist), yyvsp[-1].ty);;
    break;}
case 42:
#line 144 "pascal.y"
{/*routine declaration part, new function*/ yyval.fundeclist = A_FundecList(yyvsp[-1].fundec, yyvsp[0].fundeclist);;
    break;}
case 43:
#line 145 "pascal.y"
{/*routine declaration part, new routine*/ yyval.fundeclist = A_FundecList(yyvsp[-1].fundec, yyvsp[0].fundeclist);;
    break;}
case 44:
#line 146 "pascal.y"
{yyval.fundeclist = NULL;;
    break;}
case 45:
#line 148 "pascal.y"
{/*set function body*/yyval.fundec = yyvsp[-3].fundec; yyval.fundec->body = yyvsp[-1].exp;;
    break;}
case 46:
#line 149 "pascal.y"
{/*declare function head*/yyval.fundec = A_Fundec(EM_tokPos, yyvsp[-3].sym, yyvsp[-2].fieldlist, yyvsp[0].ty->u.name, NULL);;
    break;}
case 47:
#line 150 "pascal.y"
{/*set procedure body*/ yyval.fundec = yyvsp[-3].fundec; yyval.fundec->body = yyvsp[-1].exp;;
    break;}
case 48:
#line 151 "pascal.y"
{/*declare procedure head, return type is NULL*/ yyval.fundec = A_Fundec(EM_tokPos, yyvsp[-1].sym, yyvsp[0].fieldlist, NULL, NULL);;
    break;}
case 49:
#line 152 "pascal.y"
{/*sub_routine in declaration*/yyval.exp = A_LetExp(EM_tokPos, yyvsp[-1].declist, yyvsp[0].exp);;
    break;}
case 50:
#line 153 "pascal.y"
{/*parameters declaration*/ yyval.fieldlist = yyvsp[-1].fieldlist;;
    break;}
case 51:
#line 154 "pascal.y"
{/*no parameters*/ yyval.fieldlist = NULL;;
    break;}
case 52:
#line 155 "pascal.y"
{/*represent parameter declaration as A_fieldList*/ yyval.fieldlist = A_linkFieldList(yyvsp[-2].fieldlist, yyvsp[0].fieldlist);;
    break;}
case 53:
#line 156 "pascal.y"
{yyval.fieldlist = yyvsp[0].fieldlist;;
    break;}
case 54:
#line 157 "pascal.y"
{ yyval.fieldlist = A_setFieldListType(yyvsp[-2].fieldlist, yyvsp[0].ty);;
    break;}
case 55:
#line 158 "pascal.y"
{ yyval.fieldlist = A_setFieldListType(yyvsp[-2].fieldlist, yyvsp[0].ty);;
    break;}
case 56:
#line 159 "pascal.y"
{yyval.fieldlist = yyvsp[0].fieldlist;;
    break;}
case 57:
#line 160 "pascal.y"
{yyval.fieldlist = yyvsp[0].fieldlist;;
    break;}
case 58:
#line 163 "pascal.y"
{/*set routine body as A_exp*/ yyval.exp = yyvsp[0].exp;;
    break;}
case 59:
#line 164 "pascal.y"
{ yyval.exp = A_SeqExp(EM_tokPos, yyvsp[-1].explist);;
    break;}
case 60:
#line 165 "pascal.y"
{ /*statement in routine body*/yyval.explist = A_ExpList(yyvsp[-2].exp, yyvsp[0].explist);;
    break;}
case 61:
#line 166 "pascal.y"
{yyval.explist = NULL;;
    break;}
case 62:
#line 167 "pascal.y"
{yyval.explist = NULL;;
    break;}
case 63:
#line 168 "pascal.y"
{yyval.exp = yyvsp[0].exp;;
    break;}
case 64:
#line 169 "pascal.y"
{ yyval.exp = yyvsp[0].exp;;
    break;}
case 65:
#line 170 "pascal.y"
{ yyval.exp = yyvsp[0].exp;;
    break;}
case 66:
#line 171 "pascal.y"
{/*call function or procedure*/ yyval.exp = yyvsp[0].exp;;
    break;}
case 67:
#line 172 "pascal.y"
{yyval.exp = yyvsp[0].exp;;
    break;}
case 68:
#line 173 "pascal.y"
{yyval.exp = yyvsp[0].exp;;
    break;}
case 69:
#line 174 "pascal.y"
{  yyval.exp = yyvsp[0].exp;;
    break;}
case 70:
#line 175 "pascal.y"
{yyval.exp = yyvsp[0].exp;;
    break;}
case 71:
#line 176 "pascal.y"
{yyval.exp = yyvsp[0].exp;;
    break;}
case 72:
#line 177 "pascal.y"
{yyval.exp = yyvsp[0].exp;;
    break;}
case 73:
#line 178 "pascal.y"
{yyval.exp = yyvsp[0].exp;;
    break;}
case 74:
#line 179 "pascal.y"
{/*simple variable assignment*/ yyval.exp = A_AssignExp(EM_tokPos,A_SimpleVar(EM_tokPos, yyvsp[-2].sym), yyvsp[0].exp);;
    break;}
case 75:
#line 180 "pascal.y"
{/*subscript variable of array assignment*/ yyval.exp = A_AssignExp(EM_tokPos, A_SubscriptVar(EM_tokPos, A_SimpleVar(EM_tokPos, yyvsp[-5].sym), yyvsp[-3].exp),yyvsp[0].exp);;
    break;}
case 76:
#line 181 "pascal.y"
{/*field variable of record assignment*/yyval.exp = A_AssignExp(EM_tokPos, A_FieldVar(EM_tokPos, A_SimpleVar(EM_tokPos, yyvsp[-4].sym), yyvsp[-2].sym),yyvsp[0].exp);;
    break;}
case 77:
#line 182 "pascal.y"
{/*call function*/ yyval.exp = A_CallExp(EM_tokPos, yyvsp[0].sym, NULL);;
    break;}
case 78:
#line 183 "pascal.y"
{/*call function with arguments*/ yyval.exp = A_CallExp(EM_tokPos, yyvsp[-3].sym, yyvsp[-1].explist);;
    break;}
case 79:
#line 184 "pascal.y"
{/*call system procedure*/yyval.exp = A_CallExp(EM_tokPos, yyvsp[0].sym, NULL);;
    break;}
case 80:
#line 185 "pascal.y"
{/*call system procedure with arguments*/yyval.exp = A_CallExp(EM_tokPos, yyvsp[-3].sym, yyvsp[-1].explist);;
    break;}
case 81:
#line 186 "pascal.y"
{;
    break;}
case 82:
#line 187 "pascal.y"
{/*if statement*/ yyval.exp = A_IfExp(EM_tokPos, yyvsp[-3].exp, yyvsp[-1].exp, yyvsp[0].exp);;
    break;}
case 83:
#line 188 "pascal.y"
{/*with else clause*/ yyval.exp = yyvsp[0].exp;;
    break;}
case 84:
#line 189 "pascal.y"
{/*no else clause*/ yyval.exp = NULL;;
    break;}
case 85:
#line 190 "pascal.y"
{/*repeat statement*/ 
          yyval.exp = A_RepeatExp(EM_tokPos, yyvsp[-2].exp, yyvsp[0].exp);;
    break;}
case 86:
#line 192 "pascal.y"
{/*while statement*/ yyval.exp = A_WhileExp(EM_tokPos, yyvsp[-2].exp, yyvsp[0].exp);;
    break;}
case 87:
#line 193 "pascal.y"
{/*for statement*/
    A_var var =  A_SimpleVar(EM_tokPos, yyvsp[-6].sym);
    if (!(yyvsp[-3].cval)) {
        // to 
        yyval.exp = A_SeqExp(EM_tokPos, A_ExpList(A_AssignExp(EM_tokPos, var, yyvsp[-4].exp), A_ExpList(A_WhileExp(EM_tokPos, A_OpExp(EM_tokPos, A_ltOp, A_VarExp(EM_tokPos, var), yyvsp[-2].exp), yyvsp[0].exp), NULL )));
    } else {
        // downto 
        yyval.exp = A_SeqExp(EM_tokPos, A_ExpList(A_AssignExp(EM_tokPos, var, yyvsp[-4].exp), A_ExpList(A_WhileExp(EM_tokPos, A_OpExp(EM_tokPos, A_gtOp, A_VarExp(EM_tokPos ,var), yyvsp[-2].exp), yyvsp[0].exp), NULL )));
    }  
;
    break;}
case 88:
#line 203 "pascal.y"
{yyval.cval = 0;;
    break;}
case 89:
#line 204 "pascal.y"
{yyval.cval = 1;;
    break;}
case 90:
#line 205 "pascal.y"
{/*case statement, case_expr_list is all the possible value*/ yyval.exp = A_CaseExp(EM_tokPos, yyvsp[-3].exp, yyvsp[-1].explist);;
    break;}
case 91:
#line 206 "pascal.y"
{yyval.explist = A_ExpList(yyvsp[-1].exp, yyvsp[0].explist);;
    break;}
case 92:
#line 207 "pascal.y"
{yyval.explist = A_ExpList(yyvsp[0].exp, NULL);;
    break;}
case 93:
#line 208 "pascal.y"
{yyval.exp = A_CaseValExp(EM_tokPos, yyvsp[-3].exp, yyvsp[-1].exp);;
    break;}
case 94:
#line 209 "pascal.y"
{yyval.exp = A_CaseValExp(EM_tokPos, A_VarExp(EM_tokPos, A_SimpleVar(EM_tokPos, yyvsp[-3].sym)), yyvsp[-1].exp);;
    break;}
case 95:
#line 210 "pascal.y"
{/*goto statement*/ yyval.exp = A_GotoExp(EM_tokPos, A_IntExp(EM_tokPos, yyvsp[0].ival));;
    break;}
case 96:
#line 212 "pascal.y"
{ yyval.explist = A_ExpList(yyvsp[-2].exp, yyvsp[0].explist);;
    break;}
case 97:
#line 213 "pascal.y"
{yyval.explist = A_ExpList(yyvsp[0].exp, NULL);;
    break;}
case 98:
#line 214 "pascal.y"
{/*greater equal expression*/ yyval.exp = A_OpExp(EM_tokPos, A_geOp, yyvsp[-2].exp, yyvsp[0].exp);;
    break;}
case 99:
#line 215 "pascal.y"
{/*greater than expression*/ yyval.exp = A_OpExp(EM_tokPos, A_gtOp, yyvsp[-2].exp, yyvsp[0].exp);;
    break;}
case 100:
#line 216 "pascal.y"
{/*less equal expression*/ yyval.exp = A_OpExp(EM_tokPos, A_leOp, yyvsp[-2].exp, yyvsp[0].exp); ;
    break;}
case 101:
#line 217 "pascal.y"
{/*less than expression*/ yyval.exp = A_OpExp(EM_tokPos, A_ltOp, yyvsp[-2].exp, yyvsp[0].exp);;
    break;}
case 102:
#line 218 "pascal.y"
{/*equal expression*/ yyval.exp = A_OpExp(EM_tokPos, A_eqOp, yyvsp[-2].exp, yyvsp[0].exp);;
    break;}
case 103:
#line 219 "pascal.y"
{/*unequal expression*/ yyval.exp = A_OpExp(EM_tokPos, A_neqOp, yyvsp[-2].exp, yyvsp[0].exp);;
    break;}
case 104:
#line 220 "pascal.y"
{ yyval.exp = yyvsp[0].exp;;
    break;}
case 105:
#line 222 "pascal.y"
{yyval.exp = A_OpExp(EM_tokPos, A_plusOp, yyvsp[-2].exp, yyvsp[0].exp);;
    break;}
case 106:
#line 223 "pascal.y"
{yyval.exp = A_OpExp(EM_tokPos, A_minusOp, yyvsp[-2].exp, yyvsp[0].exp);;
    break;}
case 107:
#line 224 "pascal.y"
{/*bool operation or*/ yyval.exp = A_IfExp(EM_tokPos, yyvsp[-2].exp, A_IntExp(EM_tokPos, 1), yyvsp[0].exp);;
    break;}
case 108:
#line 225 "pascal.y"
{ yyval.exp = yyvsp[0].exp;;
    break;}
case 109:
#line 226 "pascal.y"
{ yyval.exp = A_OpExp(EM_tokPos, A_timesOp, yyvsp[-2].exp, yyvsp[0].exp);;
    break;}
case 110:
#line 227 "pascal.y"
{ /*intdiv operation*/ yyval.exp = A_OpExp(EM_tokPos, A_divideOp, yyvsp[-2].exp, yyvsp[0].exp); ;
    break;}
case 111:
#line 228 "pascal.y"
{ /*real div operaiton*/ yyval.exp = A_OpExp(EM_tokPos, A_realDivideOp, yyvsp[-2].exp, yyvsp[0].exp);;
    break;}
case 112:
#line 229 "pascal.y"
{ /*mod operation*/ yyval.exp = A_OpExp(EM_tokPos, A_modOp, yyvsp[-2].exp, yyvsp[0].exp);;
    break;}
case 113:
#line 230 "pascal.y"
{ /*bool operation and*/ yyval.exp = A_IfExp(EM_tokPos, yyvsp[-2].exp, yyvsp[0].exp, A_IntExp(EM_tokPos, 0));;
    break;}
case 114:
#line 231 "pascal.y"
{ yyval.exp = yyvsp[0].exp;;
    break;}
case 115:
#line 232 "pascal.y"
{yyval.exp = A_VarExp(EM_tokPos, A_SimpleVar(EM_tokPos, yyvsp[0].sym));;
    break;}
case 116:
#line 233 "pascal.y"
{/*call function*/yyval.exp = A_CallExp(EM_tokPos, yyvsp[-3].sym, yyvsp[-1].explist);;
    break;}
case 117:
#line 234 "pascal.y"
{/*call system function without argument*/yyval.exp = A_CallExp(EM_tokPos, yyvsp[0].sym, NULL);;
    break;}
case 118:
#line 235 "pascal.y"
{/*call system function with arguments*/yyval.exp = A_CallExp(EM_tokPos, yyvsp[-3].sym, yyvsp[-1].explist);;
    break;}
case 119:
#line 236 "pascal.y"
{/*const expression*/ yyval.exp = yyvsp[0].exp;;
    break;}
case 120:
#line 237 "pascal.y"
{ /*expression*/ yyval.exp = yyvsp[-1].exp;;
    break;}
case 121:
#line 238 "pascal.y"
{ /*bool operation, not*/ yyval.exp = A_IfExp(EM_tokPos, yyvsp[0].exp, A_IntExp(EM_tokPos, 0), A_IntExp(EM_tokPos,1));;
    break;}
case 122:
#line 239 "pascal.y"
{/*expression with negative value*/ yyval.exp = A_OpExp(EM_tokPos, A_minusOp, A_IntExp(EM_tokPos, 0), yyvsp[0].exp);;
    break;}
case 123:
#line 240 "pascal.y"
{ /*subscript variable expression*/ yyval.exp = A_VarExp(EM_tokPos,A_SubscriptVar(EM_tokPos, A_SimpleVar(EM_tokPos, yyvsp[-3].sym), yyvsp[-1].exp));;
    break;}
case 124:
#line 241 "pascal.y"
{ /*field variable expression*/ yyval.exp = A_VarExp(EM_tokPos, A_FieldVar(EM_tokPos, A_SimpleVar(EM_tokPos, yyvsp[-2].sym), yyvsp[0].sym));;
    break;}
case 125:
#line 242 "pascal.y"
{yyval.explist = yyvsp[-2].explist; yyvsp[-2].explist->tail = A_ExpList(yyvsp[0].exp, NULL);;
    break;}
case 126:
#line 243 "pascal.y"
{yyval.explist = A_ExpList(yyvsp[0].exp, NULL);;
    break;}
case 127:
#line 245 "pascal.y"
{yyval.sym = S_Symbol(yyvsp[0].sval);;
    break;}
case 128:
#line 246 "pascal.y"
{yyval.sym = S_Symbol(yyvsp[0].sval);;
    break;}
case 129:
#line 247 "pascal.y"
{yyval.sym = S_Symbol(yyvsp[0].sval);;
    break;}
case 130:
#line 248 "pascal.y"
{yyval.sym = S_Symbol(yyvsp[0].sval);;
    break;}
case 131:
#line 249 "pascal.y"
{yyval.sym = S_Symbol(yyvsp[0].sval);;
    break;}
case 132:
#line 251 "pascal.y"
{/*jump to next semi after error */;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 543 "/usr/local/share/bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;

 yyacceptlab:
  /* YYACCEPT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 0;

 yyabortlab:
  /* YYABORT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 1;
}
#line 253 "pascal.y"

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
        fieldList->head->typ = ty;
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
        decList->head->u.var.typ = ty;
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
