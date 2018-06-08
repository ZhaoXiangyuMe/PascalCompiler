
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



#define	YYFINAL		276
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
    36,    38,    40,    42,    44,    46,    48,    51,    52,    55,
    57,    60,    62,    67,    69,    71,    73,    75,    77,    81,
    85,    90,    96,   100,   107,   111,   114,   116,   121,   125,
   127,   130,   131,   134,   136,   139,   141,   146,   149,   152,
   153,   158,   164,   169,   173,   176,   180,   181,   185,   187,
   191,   195,   198,   200,   202,   206,   210,   211,   214,   218,
   220,   222,   224,   226,   228,   230,   232,   234,   236,   238,
   242,   249,   255,   257,   262,   264,   269,   274,   280,   283,
   284,   289,   294,   303,   305,   307,   313,   316,   318,   323,
   328,   331,   335,   337,   341,   345,   349,   353,   357,   361,
   363,   367,   371,   375,   377,   381,   385,   389,   393,   397,
   399,   401,   406,   408,   413,   415,   419,   422,   425,   430,
   434,   438,   440,   442,   444,   446,   448,   450
};

static const short yyrhs[] = {    62,
    63,     7,     0,    27,   116,    10,     0,    64,    93,     0,
    65,    66,    69,    79,    82,     0,     0,    50,    67,     0,
     0,   116,    24,    68,    10,    67,     0,   116,    24,    68,
    10,     0,   121,    67,     0,   121,     0,    52,     0,    53,
     0,    54,     0,    56,     0,   117,     0,    32,    70,     0,
     0,    71,    70,     0,    71,     0,   121,    70,     0,   121,
     0,   116,    24,    72,    10,     0,    73,     0,    74,     0,
    75,     0,   120,     0,   116,     0,     3,    78,     4,     0,
    68,    51,    68,     0,    12,    68,    51,    68,     0,    12,
    68,    51,    12,    68,     0,   116,    51,   116,     0,    33,
     5,    73,     6,    34,    72,     0,    35,    76,    31,     0,
    77,    76,     0,    77,     0,    78,     9,    72,    10,     0,
    78,     8,   116,     0,   116,     0,    36,    80,     0,     0,
    81,    80,     0,    81,     0,   121,    80,     0,   121,     0,
    78,     9,    72,    10,     0,    83,    82,     0,    85,    82,
     0,     0,    84,    10,    87,    10,     0,    28,   116,    88,
     9,    73,     0,    86,    10,    87,    10,     0,    29,   116,
    88,     0,    64,    93,     0,     3,    89,     4,     0,     0,
    89,    10,    90,     0,    90,     0,    91,     9,    73,     0,
    92,     9,    73,     0,    36,    78,     0,    78,     0,    94,
     0,    30,    95,    31,     0,    96,    10,    95,     0,     0,
   121,    95,     0,    52,     9,    97,     0,    97,     0,    98,
     0,    99,     0,    94,     0,   100,     0,   102,     0,   103,
     0,   104,     0,   106,     0,   109,     0,   116,    26,   111,
     0,   116,     5,   111,     6,    26,   111,     0,   116,     7,
   116,    26,   111,     0,   116,     0,   116,     3,   115,     4,
     0,   119,     0,   119,     3,   110,     4,     0,    49,     3,
   114,     4,     0,    37,   111,    38,    96,   101,     0,    39,
    96,     0,     0,    40,    96,    43,   111,     0,    44,   111,
    45,    96,     0,    46,   116,    26,   111,   105,   111,    45,
    96,     0,    41,     0,    42,     0,    47,   111,    34,   107,
    31,     0,   108,   107,     0,   108,     0,    68,     9,    96,
    10,     0,   116,     9,    96,    10,     0,    48,    52,     0,
   111,     8,   110,     0,   111,     0,   111,    20,   112,     0,
   111,    21,   112,     0,   111,    22,   112,     0,   111,    23,
   112,     0,   111,    24,   112,     0,   111,    25,   112,     0,
   112,     0,   112,    11,   113,     0,   112,    12,   113,     0,
   112,    18,   113,     0,   113,     0,   113,    13,   114,     0,
   113,    15,   114,     0,   113,    14,   114,     0,   113,    16,
   114,     0,   113,    17,   114,     0,   114,     0,   116,     0,
   116,     3,   115,     4,     0,   118,     0,   118,     3,   115,
     4,     0,    68,     0,     3,   111,     4,     0,    19,   114,
     0,    12,   114,     0,   116,     5,   111,     6,     0,   116,
     7,   116,     0,   115,     8,   111,     0,   111,     0,    55,
     0,    57,     0,    58,     0,    59,     0,    60,     0,     1,
    10,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    81,    82,    83,    84,    98,   101,   102,   103,   104,   105,
   106,   107,   108,   109,   110,   111,   114,   115,   116,   117,
   118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
   128,   129,   130,   131,   132,   134,   135,   136,   137,   138,
   141,   142,   143,   144,   145,   146,   147,   150,   151,   152,
   154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
   164,   165,   166,   169,   170,   171,   172,   173,   174,   175,
   176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
   186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
   196,   198,   199,   209,   210,   211,   212,   213,   214,   215,
   216,   218,   219,   220,   221,   222,   223,   224,   225,   226,
   228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
   238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
   248,   249,   251,   252,   253,   254,   255,   257
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
"error_stmt", NULL
};
#endif

static const short yyr1[] = {     0,
    61,    62,    63,    64,    65,    66,    66,    67,    67,    67,
    67,    68,    68,    68,    68,    68,    69,    69,    70,    70,
    70,    70,    71,    72,    72,    72,    73,    73,    73,    73,
    73,    73,    73,    74,    75,    76,    76,    77,    78,    78,
    79,    79,    80,    80,    80,    80,    81,    82,    82,    82,
    83,    84,    85,    86,    87,    88,    88,    89,    89,    90,
    90,    91,    92,    93,    94,    95,    95,    95,    96,    96,
    97,    97,    97,    97,    97,    97,    97,    97,    97,    98,
    98,    98,    99,    99,    99,    99,    99,   100,   101,   101,
   102,   103,   104,   105,   105,   106,   107,   107,   108,   108,
   109,   110,   110,   111,   111,   111,   111,   111,   111,   111,
   112,   112,   112,   112,   113,   113,   113,   113,   113,   113,
   114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
   115,   115,   116,   117,   118,   119,   120,   121
};

static const short yyr2[] = {     0,
     3,     3,     2,     5,     0,     2,     0,     5,     4,     2,
     1,     1,     1,     1,     1,     1,     2,     0,     2,     1,
     2,     1,     4,     1,     1,     1,     1,     1,     3,     3,
     4,     5,     3,     6,     3,     2,     1,     4,     3,     1,
     2,     0,     2,     1,     2,     1,     4,     2,     2,     0,
     4,     5,     4,     3,     2,     3,     0,     3,     1,     3,
     3,     2,     1,     1,     3,     3,     0,     2,     3,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
     6,     5,     1,     4,     1,     4,     4,     5,     2,     0,
     4,     4,     8,     1,     1,     5,     2,     1,     4,     4,
     2,     3,     1,     3,     3,     3,     3,     3,     3,     1,
     3,     3,     3,     1,     3,     3,     3,     3,     3,     1,
     1,     4,     1,     4,     1,     3,     2,     2,     4,     3,
     3,     1,     1,     1,     1,     1,     1,     2
};

static const short yydefact[] = {     0,
     0,     5,   133,     0,     0,     0,     7,     2,     1,     0,
     3,    64,     0,    18,     0,     0,     0,     0,     0,     0,
     0,     0,     0,   136,    73,     0,     0,    70,    71,    72,
    74,    75,    76,    77,    78,    79,    83,    85,     0,     6,
     0,     0,     0,    42,   138,     0,     0,     0,    12,    13,
    14,    15,   134,   135,   125,     0,   110,   114,   120,   121,
    16,   123,     0,     0,     0,     0,   101,     0,     0,    65,
     0,     0,     0,     0,     0,     0,    68,     0,    10,    17,
     0,     0,     0,     0,    50,     0,   128,   127,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,    69,    66,   132,     0,     0,     0,    80,     0,
   103,     0,    19,     0,    21,     0,    41,     0,    40,     0,
     0,     0,     4,    50,     0,    50,     0,   126,   104,   105,
   106,   107,   108,   109,    90,   111,   112,   113,   115,   117,
   116,   118,   119,     0,     0,   130,     0,    91,    92,     0,
     0,     0,    98,     0,    87,    84,     0,     0,     0,    86,
     0,     0,     0,     0,     0,     0,   137,     0,     0,    24,
    25,    26,    28,    27,     0,     0,    43,    45,    57,    57,
    48,     5,    49,     5,     0,    88,   122,   129,   124,    94,
    95,     0,     0,    96,    97,     0,   131,     0,    82,   102,
     8,     0,     0,     0,     0,    37,     0,     0,    23,     0,
    39,     0,     0,     0,    54,     0,     0,     0,    89,     0,
     0,     0,    81,    29,     0,     0,    35,    36,     0,    30,
    33,    47,     0,    63,     0,    59,     0,     0,     0,    55,
    51,    53,     0,    99,   100,     0,    31,     0,     0,    62,
    56,     0,     0,     0,    52,    93,    32,     0,    38,    58,
    60,    61,    34,     0,     0,     0
};

static const short yydefgoto[] = {   274,
     2,     5,   226,     7,    14,    40,    55,    44,    80,    81,
   179,   180,   181,   182,   215,   216,   126,    85,   127,   128,
   133,   134,   135,   136,   137,   227,   224,   245,   246,   247,
   248,    11,    25,    26,    27,    28,    29,    30,    31,   196,
    32,    33,    34,   202,    35,   162,   163,    36,   120,   115,
    57,    58,    59,   116,    60,    61,    62,    38,   184,    39
};

static const short yypact[] = {   -20,
   -42,-32768,-32768,    24,    37,    41,     4,-32768,-32768,   228,
-32768,-32768,    14,    70,    86,   252,   284,   252,   -42,   252,
    62,   106,   116,-32768,-32768,    97,   131,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,   130,   146,   228,-32768,
   136,     3,    14,   119,-32768,   252,   252,   252,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,   388,    95,   275,-32768,    40,
-32768,   155,   126,     5,   147,   399,-32768,   252,   304,-32768,
   228,   252,   252,   -42,   252,   252,-32768,   401,-32768,-32768,
    23,   159,   152,    14,    57,   356,-32768,-32768,   252,   252,
   252,   252,   252,   252,   284,   252,   252,   252,   252,   252,
   252,   252,   252,   252,   252,   -42,   252,   252,   284,   252,
   383,   182,-32768,-32768,   421,    73,   376,   163,   421,   192,
   407,   187,-32768,    64,-32768,   156,-32768,   202,-32768,   283,
   -42,   -42,-32768,    57,   194,    57,   196,-32768,    95,    95,
    95,    95,    95,    95,   169,   275,   275,   275,-32768,-32768,
-32768,-32768,-32768,   107,   382,-32768,   118,   421,-32768,   350,
   200,   179,   383,   205,-32768,-32768,   252,   185,   252,-32768,
   252,   138,   -42,   401,   212,   -42,-32768,   167,   210,-32768,
-32768,-32768,   170,-32768,   -42,    64,-32768,-32768,   221,   221,
-32768,-32768,-32768,-32768,   284,-32768,-32768,-32768,-32768,-32768,
-32768,   252,   284,-32768,-32768,   284,   421,   252,   421,-32768,
-32768,   134,   174,   241,   197,   -42,   168,   401,-32768,   -42,
-32768,   217,   -15,   225,-32768,    41,   226,   229,-32768,   344,
   233,   236,   421,-32768,   266,   243,-32768,-32768,    64,-32768,
-32768,-32768,   -42,   227,    52,-32768,   238,   242,   241,-32768,
-32768,-32768,   284,-32768,-32768,   401,-32768,   216,   244,   227,
-32768,   -15,   241,   241,-32768,-32768,-32768,    64,-32768,-32768,
-32768,-32768,-32768,   256,   260,-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,   264,-32768,-32768,   -40,   -23,-32768,    -9,-32768,
  -164,  -203,-32768,-32768,    53,-32768,  -159,-32768,    20,-32768,
    18,-32768,-32768,-32768,-32768,    76,    83,-32768,    17,-32768,
-32768,    55,    -3,   -34,   -16,   213,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,   122,-32768,-32768,   115,   -10,
   358,   103,    44,   -84,    -1,-32768,-32768,-32768,-32768,     6
};


#define	YYLAST		458


static const short yytable[] = {     4,
    63,    79,    12,    15,    77,    56,     1,    64,    37,    66,
   236,    41,     3,   212,    15,    37,   217,    65,    42,   154,
   243,   222,   157,    15,    89,    90,    91,    92,    93,    94,
   -11,   -11,   -11,     8,   -11,    86,   114,    37,   -11,     3,
    41,    82,   104,     9,   105,   265,   106,    42,    83,   109,
   -20,   -20,   -20,    13,   122,   261,   217,     3,   -20,   271,
   272,   262,   117,   244,   119,   121,   173,    37,     3,    37,
    10,   123,   118,   125,   259,   174,   166,     3,   145,    82,
   167,    82,   129,   260,   131,   132,    83,   161,    83,   130,
    87,    88,   159,    37,   155,    45,   175,   158,   176,   160,
   178,    43,   244,   273,   156,    96,    97,    37,    68,   164,
   197,   112,    98,    67,   167,    49,    50,    51,     3,    52,
    53,   199,   183,   177,    69,   167,   129,    70,   129,   189,
   190,   211,    72,   130,    73,   130,    74,   234,    15,   161,
    71,   185,   149,   150,   151,   152,   153,   187,    76,   188,
   213,   191,    15,   193,    84,    75,   207,   107,   209,    78,
   121,   164,   178,   185,   186,    -9,    -9,    -9,   108,    -9,
    41,   129,   110,    -9,   129,   185,   239,    42,   229,   -22,
   -22,   -22,   124,   221,   183,   165,   231,   -22,   169,   232,
   178,   230,     3,    37,   240,   170,   172,   233,   146,   147,
   148,    37,    15,   192,    37,   194,     3,   195,   203,   204,
   208,   257,   183,   206,   129,   178,   214,   218,   241,   219,
   220,   129,    12,   223,   235,   178,   242,   237,    15,   -44,
   -44,   -44,   267,   249,   185,   251,   266,   183,   252,   178,
   178,   129,   254,   173,   178,   255,   263,   183,   258,   268,
   264,    37,   174,   269,    46,   275,     3,    10,   -67,   276,
   129,   183,   183,    47,    16,     6,   183,    17,   238,   228,
    48,    18,   225,    19,    20,    21,    22,   256,   270,    23,
   250,   113,     3,    15,   205,   210,    24,    99,   100,   101,
   102,   103,    49,    50,    51,     3,    52,    53,     0,     0,
   177,     0,     0,    49,    50,    51,     3,    52,    53,    54,
   -46,   -46,   -46,    10,     0,     0,     0,    49,    50,    51,
    16,    52,    53,    17,     0,     0,     0,    18,     0,    19,
    20,    21,    22,    10,     0,    23,     0,     3,     3,     0,
    16,     0,    24,    17,     0,     0,     0,    18,     0,    19,
    20,    21,    22,     0,     0,     0,     0,     0,     3,   138,
     0,     0,    24,    89,    90,    91,    92,    93,    94,    89,
    90,    91,    92,    93,    94,    89,    90,    91,    92,    93,
    94,   168,     0,     0,     0,     0,     0,   198,   253,     0,
   200,   201,     0,     0,     0,    89,    90,    91,    92,    93,
    94,    89,    90,    91,    92,    93,    94,    89,    90,    91,
    92,    93,    94,     0,   171,     0,     0,     0,    89,    90,
    91,    92,    93,    94,     0,    95,    89,    90,    91,    92,
    93,    94,   111,     0,    49,    50,    51,     3,    52,    53,
    89,    90,    91,    92,    93,    94,   139,   140,   141,   142,
   143,   144,    49,    50,    51,     0,    52,    53
};

static const short yycheck[] = {     1,
    17,    42,     6,     1,    39,    16,    27,    18,    10,    20,
   214,    13,    55,   173,     1,    17,   176,    19,    13,   104,
    36,   186,   107,     1,    20,    21,    22,    23,    24,    25,
    28,    29,    30,    10,    32,    46,    71,    39,    36,    55,
    42,    43,     3,     7,     5,   249,     7,    42,    43,    45,
    28,    29,    30,    50,    78,     4,   216,    55,    36,   263,
   264,    10,    73,   223,    75,    76,     3,    69,    55,    71,
    30,    81,    74,    83,   239,    12,     4,    55,    95,    81,
     8,    83,    84,   243,    28,    29,    81,   111,    83,    84,
    47,    48,   109,    95,   105,    10,    33,   108,    35,   110,
   124,    32,   262,   268,   106,    11,    12,   109,     3,   111,
     4,    68,    18,    52,     8,    52,    53,    54,    55,    56,
    57,     4,   124,    60,     9,     8,   128,    31,   130,   131,
   132,   172,     3,   128,     5,   130,     7,     4,     1,   163,
    10,     8,    99,   100,   101,   102,   103,   128,     3,   130,
   174,   134,     1,   136,    36,    26,   167,     3,   169,    24,
   171,   163,   186,     8,     9,    28,    29,    30,    43,    32,
   172,   173,    26,    36,   176,     8,     9,   172,   195,    28,
    29,    30,    24,   185,   186,     4,   203,    36,    26,   206,
   214,   202,    55,   195,   218,     4,    10,   208,    96,    97,
    98,   203,     1,    10,   206,    10,    55,    39,     9,    31,
    26,   235,   214,     9,   216,   239,     5,    51,   220,    10,
    51,   223,   226,     3,    51,   249,    10,    31,     1,    28,
    29,    30,   256,     9,     8,    10,   253,   239,    10,   263,
   264,   243,    10,     3,   268,    10,     9,   249,     6,    34,
     9,   253,    12,    10,     3,     0,    55,    30,    31,     0,
   262,   263,   264,    12,    37,     2,   268,    40,   216,   194,
    19,    44,   190,    46,    47,    48,    49,    12,   262,    52,
   226,    69,    55,     1,   163,   171,    59,    13,    14,    15,
    16,    17,    52,    53,    54,    55,    56,    57,    -1,    -1,
    60,    -1,    -1,    52,    53,    54,    55,    56,    57,    58,
    28,    29,    30,    30,    -1,    -1,    -1,    52,    53,    54,
    37,    56,    57,    40,    -1,    -1,    -1,    44,    -1,    46,
    47,    48,    49,    30,    -1,    52,    -1,    55,    55,    -1,
    37,    -1,    59,    40,    -1,    -1,    -1,    44,    -1,    46,
    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    55,     4,
    -1,    -1,    59,    20,    21,    22,    23,    24,    25,    20,
    21,    22,    23,    24,    25,    20,    21,    22,    23,    24,
    25,     6,    -1,    -1,    -1,    -1,    -1,     6,    45,    -1,
    41,    42,    -1,    -1,    -1,    20,    21,    22,    23,    24,
    25,    20,    21,    22,    23,    24,    25,    20,    21,    22,
    23,    24,    25,    -1,     8,    -1,    -1,    -1,    20,    21,
    22,    23,    24,    25,    -1,    38,    20,    21,    22,    23,
    24,    25,    34,    -1,    52,    53,    54,    55,    56,    57,
    20,    21,    22,    23,    24,    25,    89,    90,    91,    92,
    93,    94,    52,    53,    54,    -1,    56,    57
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
{/*set root for abstract syntax tree*/ A_synTreeRoot = yyvsp[-1].exp; ;
    break;}
case 2:
#line 82 "pascal.y"
{;
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
{/*run into error*/ yyval.declist = yyvsp[0].declist;;
    break;}
case 11:
#line 106 "pascal.y"
{yyval.declist = NULL;;
    break;}
case 12:
#line 107 "pascal.y"
{/*integer value*/ yyval.exp = A_IntExp(EM_tokPos, yyvsp[0].ival);;
    break;}
case 13:
#line 108 "pascal.y"
{/*real value*/ yyval.exp = A_RealExp(EM_tokPos, yyvsp[0].rval);;
    break;}
case 14:
#line 109 "pascal.y"
{/*char value*/ yyval.exp = A_CharExp(EM_tokPos, yyvsp[0].cval);;
    break;}
case 15:
#line 110 "pascal.y"
{/*string value*/ yyval.exp = A_StringExp(EM_tokPos, yyvsp[0].sval);;
    break;}
case 16:
#line 111 "pascal.y"
{/*system const value*/ /*$$ = A_SysConstExp(EM_tokPos, $1);*/;
    break;}
case 17:
#line 114 "pascal.y"
{/*type declaration part*/ yyval.declist = A_DecList(A_TypeDec(EM_tokPos, yyvsp[0].nametylist), NULL);;
    break;}
case 18:
#line 115 "pascal.y"
{/*no type declaration*/ yyval.declist = NULL;;
    break;}
case 19:
#line 116 "pascal.y"
{/*type declaration list*/ yyval.nametylist = A_NametyList(yyvsp[-1].namety, yyvsp[0].nametylist);;
    break;}
case 20:
#line 117 "pascal.y"
{/*last type definition, tail points to NULL*/yyval.nametylist = A_NametyList(yyvsp[0].namety, NULL);;
    break;}
case 21:
#line 118 "pascal.y"
{/*run into error*/ yyval.nametylist = yyvsp[0].nametylist;;
    break;}
case 22:
#line 119 "pascal.y"
{yyval.nametylist = NULL;;
    break;}
case 23:
#line 120 "pascal.y"
{/*type declaration*/yyval.namety =A_Namety(yyvsp[-3].sym, yyvsp[-1].ty);;
    break;}
case 24:
#line 121 "pascal.y"
{/*simple type*/ yyval.ty = yyvsp[0].ty;;
    break;}
case 25:
#line 122 "pascal.y"
{/*array type*/ yyval.ty = yyvsp[0].ty;;
    break;}
case 26:
#line 123 "pascal.y"
{/*record type*/ yyval.ty = yyvsp[0].ty;;
    break;}
case 27:
#line 124 "pascal.y"
{/*system defined type*/ yyval.ty = A_NameTy(EM_tokPos, yyvsp[0].sym);;
    break;}
case 28:
#line 125 "pascal.y"
{/*self define simple type*/ yyval.ty = A_NameTy(EM_tokPos, yyvsp[0].sym);;
    break;}
case 29:
#line 126 "pascal.y"
{/*enum type*/ yyval.ty = A_EnumType(EM_tokPos, yyvsp[-1].fieldlist);;
    break;}
case 30:
#line 127 "pascal.y"
{/*subrange type*/ yyval.ty = A_RangeTy(EM_tokPos, yyvsp[-2].exp, yyvsp[0].exp);;
    break;}
case 31:
#line 128 "pascal.y"
{/*subrange type*/ A_RangeTy(EM_tokPos, A_OpExp(EM_tokPos, A_minusOp, A_IntExp(EM_tokPos, 0), yyvsp[-2].exp), yyvsp[0].exp);;
    break;}
case 32:
#line 129 "pascal.y"
{/*subrange type*/ A_RangeTy(EM_tokPos, A_OpExp(EM_tokPos, A_minusOp, A_IntExp(EM_tokPos, 0), yyvsp[-3].exp), A_OpExp(EM_tokPos, A_minusOp, A_IntExp(EM_tokPos, 0), yyvsp[0].exp));;
    break;}
case 33:
#line 130 "pascal.y"
{/*subrange type*/ A_RangeTy(EM_tokPos, A_VarExp(EM_tokPos, A_SimpleVar(EM_tokPos, yyvsp[-2].sym)), A_VarExp(EM_tokPos, A_SimpleVar(EM_tokPos, yyvsp[0].sym)));;
    break;}
case 34:
#line 131 "pascal.y"
{/*array type, simple_type_dec is range of array, type_dec is actual type of array element*/ yyval.ty = A_ArrayTy(EM_tokPos, yyvsp[-3].ty, yyvsp[0].ty);;
    break;}
case 35:
#line 132 "pascal.y"
{/*record type*/ yyval.ty = A_RecordTy(EM_tokPos, yyvsp[-1].fieldlist);;
    break;}
case 36:
#line 134 "pascal.y"
{/*link parts of fieldlists*/ yyval.fieldlist = A_linkFieldList(yyvsp[-1].fieldlist, yyvsp[0].fieldlist); ;
    break;}
case 37:
#line 135 "pascal.y"
{yyval.fieldlist = yyvsp[0].fieldlist;;
    break;}
case 38:
#line 136 "pascal.y"
{ /*set type of namelist*/yyval.fieldlist = A_setFieldListType(yyvsp[-3].fieldlist, yyvsp[-1].ty);;
    break;}
case 39:
#line 137 "pascal.y"
{/*namelist is fieldlist of same unknown type*/ yyval.fieldlist = A_linkFieldList(yyvsp[-2].fieldlist, A_FieldList(A_Field(EM_tokPos, yyvsp[0].sym, NULL), NULL));;
    break;}
case 40:
#line 138 "pascal.y"
{yyval.fieldlist = A_FieldList(A_Field(EM_tokPos, yyvsp[0].sym, NULL), NULL);;
    break;}
case 41:
#line 141 "pascal.y"
{/*variable declaration part*/ yyval.declist = yyvsp[0].declist;;
    break;}
case 42:
#line 142 "pascal.y"
{/*no variable declaration*/ yyval.declist = NULL;;
    break;}
case 43:
#line 143 "pascal.y"
{/*variable declaration list*/ yyval.declist = A_linkDecList(yyvsp[-1].declist, yyvsp[0].declist);;
    break;}
case 44:
#line 144 "pascal.y"
{yyval.declist = yyvsp[0].declist;;
    break;}
case 45:
#line 145 "pascal.y"
{yyval.declist = yyvsp[0].declist;;
    break;}
case 46:
#line 146 "pascal.y"
{yyval.declist = NULL;;
    break;}
case 47:
#line 147 "pascal.y"
{/*change name_list to variable declaration list*/ yyval.declist = A_setDecListType(A_unDecList(yyvsp[-3].fieldlist), yyvsp[-1].ty);;
    break;}
case 48:
#line 150 "pascal.y"
{/*routine declaration part, new function*/ yyval.fundeclist = A_FundecList(yyvsp[-1].fundec, yyvsp[0].fundeclist);;
    break;}
case 49:
#line 151 "pascal.y"
{/*routine declaration part, new routine*/ yyval.fundeclist = A_FundecList(yyvsp[-1].fundec, yyvsp[0].fundeclist);;
    break;}
case 50:
#line 152 "pascal.y"
{yyval.fundeclist = NULL;;
    break;}
case 51:
#line 154 "pascal.y"
{/*set function body*/yyval.fundec = yyvsp[-3].fundec; yyval.fundec->body = yyvsp[-1].exp;;
    break;}
case 52:
#line 155 "pascal.y"
{/*declare function head*/yyval.fundec = A_Fundec(EM_tokPos, yyvsp[-3].sym, yyvsp[-2].fieldlist, yyvsp[0].ty->u.name, NULL);;
    break;}
case 53:
#line 156 "pascal.y"
{/*set procedure body*/ yyval.fundec = yyvsp[-3].fundec; yyval.fundec->body = yyvsp[-1].exp;;
    break;}
case 54:
#line 157 "pascal.y"
{/*declare procedure head, return type is NULL*/ yyval.fundec = A_Fundec(EM_tokPos, yyvsp[-1].sym, yyvsp[0].fieldlist, NULL, NULL);;
    break;}
case 55:
#line 158 "pascal.y"
{/*sub_routine in declaration*/yyval.exp = A_LetExp(EM_tokPos, yyvsp[-1].declist, yyvsp[0].exp);;
    break;}
case 56:
#line 159 "pascal.y"
{/*parameters declaration*/ yyval.fieldlist = yyvsp[-1].fieldlist;;
    break;}
case 57:
#line 160 "pascal.y"
{/*no parameters*/ yyval.fieldlist = NULL;;
    break;}
case 58:
#line 161 "pascal.y"
{/*represent parameter declaration as A_fieldList*/ yyval.fieldlist = A_linkFieldList(yyvsp[-2].fieldlist, yyvsp[0].fieldlist);;
    break;}
case 59:
#line 162 "pascal.y"
{yyval.fieldlist = yyvsp[0].fieldlist;;
    break;}
case 60:
#line 163 "pascal.y"
{ yyval.fieldlist = A_setFieldListType(yyvsp[-2].fieldlist, yyvsp[0].ty);;
    break;}
case 61:
#line 164 "pascal.y"
{ yyval.fieldlist = A_setFieldListType(yyvsp[-2].fieldlist, yyvsp[0].ty);;
    break;}
case 62:
#line 165 "pascal.y"
{yyval.fieldlist = yyvsp[0].fieldlist;;
    break;}
case 63:
#line 166 "pascal.y"
{yyval.fieldlist = yyvsp[0].fieldlist;;
    break;}
case 64:
#line 169 "pascal.y"
{/*set routine body as A_exp*/ yyval.exp = yyvsp[0].exp;;
    break;}
case 65:
#line 170 "pascal.y"
{ yyval.exp = A_SeqExp(EM_tokPos, yyvsp[-1].explist);;
    break;}
case 66:
#line 171 "pascal.y"
{ /*statement in routine body*/yyval.explist = A_ExpList(yyvsp[-2].exp, yyvsp[0].explist);;
    break;}
case 67:
#line 172 "pascal.y"
{yyval.explist = NULL;;
    break;}
case 68:
#line 173 "pascal.y"
{yyval.explist = yyvsp[0].explist;;
    break;}
case 69:
#line 174 "pascal.y"
{yyval.exp = yyvsp[0].exp;;
    break;}
case 70:
#line 175 "pascal.y"
{ yyval.exp = yyvsp[0].exp;;
    break;}
case 71:
#line 176 "pascal.y"
{ yyval.exp = yyvsp[0].exp;;
    break;}
case 72:
#line 177 "pascal.y"
{/*call function or procedure*/ yyval.exp = yyvsp[0].exp;;
    break;}
case 73:
#line 178 "pascal.y"
{yyval.exp = yyvsp[0].exp;;
    break;}
case 74:
#line 179 "pascal.y"
{yyval.exp = yyvsp[0].exp;;
    break;}
case 75:
#line 180 "pascal.y"
{  yyval.exp = yyvsp[0].exp;;
    break;}
case 76:
#line 181 "pascal.y"
{yyval.exp = yyvsp[0].exp;;
    break;}
case 77:
#line 182 "pascal.y"
{yyval.exp = yyvsp[0].exp;;
    break;}
case 78:
#line 183 "pascal.y"
{yyval.exp = yyvsp[0].exp;;
    break;}
case 79:
#line 184 "pascal.y"
{yyval.exp = yyvsp[0].exp;;
    break;}
case 80:
#line 185 "pascal.y"
{/*simple variable assignment*/ yyval.exp = A_AssignExp(EM_tokPos,A_SimpleVar(EM_tokPos, yyvsp[-2].sym), yyvsp[0].exp);;
    break;}
case 81:
#line 186 "pascal.y"
{/*subscript variable of array assignment*/ yyval.exp = A_AssignExp(EM_tokPos, A_SubscriptVar(EM_tokPos, A_SimpleVar(EM_tokPos, yyvsp[-5].sym), yyvsp[-3].exp),yyvsp[0].exp);;
    break;}
case 82:
#line 187 "pascal.y"
{/*field variable of record assignment*/yyval.exp = A_AssignExp(EM_tokPos, A_FieldVar(EM_tokPos, A_SimpleVar(EM_tokPos, yyvsp[-4].sym), yyvsp[-2].sym),yyvsp[0].exp);;
    break;}
case 83:
#line 188 "pascal.y"
{/*call function*/ yyval.exp = A_CallExp(EM_tokPos, yyvsp[0].sym, NULL);;
    break;}
case 84:
#line 189 "pascal.y"
{/*call function with arguments*/ yyval.exp = A_CallExp(EM_tokPos, yyvsp[-3].sym, yyvsp[-1].explist);;
    break;}
case 85:
#line 190 "pascal.y"
{/*call system procedure*/yyval.exp = A_CallExp(EM_tokPos, yyvsp[0].sym, NULL);;
    break;}
case 86:
#line 191 "pascal.y"
{/*call system procedure with arguments*/yyval.exp = A_CallExp(EM_tokPos, yyvsp[-3].sym, yyvsp[-1].explist);;
    break;}
case 87:
#line 192 "pascal.y"
{;
    break;}
case 88:
#line 193 "pascal.y"
{/*if statement*/ yyval.exp = A_IfExp(EM_tokPos, yyvsp[-3].exp, yyvsp[-1].exp, yyvsp[0].exp);;
    break;}
case 89:
#line 194 "pascal.y"
{/*with else clause*/ yyval.exp = yyvsp[0].exp;;
    break;}
case 90:
#line 195 "pascal.y"
{/*no else clause*/ yyval.exp = NULL;;
    break;}
case 91:
#line 196 "pascal.y"
{/*repeat statement*/ 
          yyval.exp = A_RepeatExp(EM_tokPos, yyvsp[-2].exp, yyvsp[0].exp);;
    break;}
case 92:
#line 198 "pascal.y"
{/*while statement*/ yyval.exp = A_WhileExp(EM_tokPos, yyvsp[-2].exp, yyvsp[0].exp);;
    break;}
case 93:
#line 199 "pascal.y"
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
case 94:
#line 209 "pascal.y"
{yyval.cval = 0;;
    break;}
case 95:
#line 210 "pascal.y"
{yyval.cval = 1;;
    break;}
case 96:
#line 211 "pascal.y"
{/*case statement, case_expr_list is all the possible value*/ yyval.exp = A_CaseExp(EM_tokPos, yyvsp[-3].exp, yyvsp[-1].explist);;
    break;}
case 97:
#line 212 "pascal.y"
{yyval.explist = A_ExpList(yyvsp[-1].exp, yyvsp[0].explist);;
    break;}
case 98:
#line 213 "pascal.y"
{yyval.explist = A_ExpList(yyvsp[0].exp, NULL);;
    break;}
case 99:
#line 214 "pascal.y"
{yyval.exp = A_CaseValExp(EM_tokPos, yyvsp[-3].exp, yyvsp[-1].exp);;
    break;}
case 100:
#line 215 "pascal.y"
{yyval.exp = A_CaseValExp(EM_tokPos, A_VarExp(EM_tokPos, A_SimpleVar(EM_tokPos, yyvsp[-3].sym)), yyvsp[-1].exp);;
    break;}
case 101:
#line 216 "pascal.y"
{/*goto statement*/ yyval.exp = A_GotoExp(EM_tokPos, A_IntExp(EM_tokPos, yyvsp[0].ival));;
    break;}
case 102:
#line 218 "pascal.y"
{ yyval.explist = A_ExpList(yyvsp[-2].exp, yyvsp[0].explist);;
    break;}
case 103:
#line 219 "pascal.y"
{yyval.explist = A_ExpList(yyvsp[0].exp, NULL);;
    break;}
case 104:
#line 220 "pascal.y"
{/*greater equal expression*/ yyval.exp = A_OpExp(EM_tokPos, A_geOp, yyvsp[-2].exp, yyvsp[0].exp);;
    break;}
case 105:
#line 221 "pascal.y"
{/*greater than expression*/ yyval.exp = A_OpExp(EM_tokPos, A_gtOp, yyvsp[-2].exp, yyvsp[0].exp);;
    break;}
case 106:
#line 222 "pascal.y"
{/*less equal expression*/ yyval.exp = A_OpExp(EM_tokPos, A_leOp, yyvsp[-2].exp, yyvsp[0].exp); ;
    break;}
case 107:
#line 223 "pascal.y"
{/*less than expression*/ yyval.exp = A_OpExp(EM_tokPos, A_ltOp, yyvsp[-2].exp, yyvsp[0].exp);;
    break;}
case 108:
#line 224 "pascal.y"
{/*equal expression*/ yyval.exp = A_OpExp(EM_tokPos, A_eqOp, yyvsp[-2].exp, yyvsp[0].exp);;
    break;}
case 109:
#line 225 "pascal.y"
{/*unequal expression*/ yyval.exp = A_OpExp(EM_tokPos, A_neqOp, yyvsp[-2].exp, yyvsp[0].exp);;
    break;}
case 110:
#line 226 "pascal.y"
{ yyval.exp = yyvsp[0].exp;;
    break;}
case 111:
#line 228 "pascal.y"
{yyval.exp = A_OpExp(EM_tokPos, A_plusOp, yyvsp[-2].exp, yyvsp[0].exp);;
    break;}
case 112:
#line 229 "pascal.y"
{yyval.exp = A_OpExp(EM_tokPos, A_minusOp, yyvsp[-2].exp, yyvsp[0].exp);;
    break;}
case 113:
#line 230 "pascal.y"
{/*bool operation or*/ yyval.exp = A_IfExp(EM_tokPos, yyvsp[-2].exp, A_IntExp(EM_tokPos, 1), yyvsp[0].exp);;
    break;}
case 114:
#line 231 "pascal.y"
{ yyval.exp = yyvsp[0].exp;;
    break;}
case 115:
#line 232 "pascal.y"
{ yyval.exp = A_OpExp(EM_tokPos, A_timesOp, yyvsp[-2].exp, yyvsp[0].exp);;
    break;}
case 116:
#line 233 "pascal.y"
{ /*intdiv operation*/ yyval.exp = A_OpExp(EM_tokPos, A_divideOp, yyvsp[-2].exp, yyvsp[0].exp); ;
    break;}
case 117:
#line 234 "pascal.y"
{ /*real div operaiton*/ yyval.exp = A_OpExp(EM_tokPos, A_realDivideOp, yyvsp[-2].exp, yyvsp[0].exp);;
    break;}
case 118:
#line 235 "pascal.y"
{ /*mod operation*/ yyval.exp = A_OpExp(EM_tokPos, A_modOp, yyvsp[-2].exp, yyvsp[0].exp);;
    break;}
case 119:
#line 236 "pascal.y"
{ /*bool operation and*/ yyval.exp = A_IfExp(EM_tokPos, yyvsp[-2].exp, yyvsp[0].exp, A_IntExp(EM_tokPos, 0));;
    break;}
case 120:
#line 237 "pascal.y"
{ yyval.exp = yyvsp[0].exp;;
    break;}
case 121:
#line 238 "pascal.y"
{yyval.exp = A_VarExp(EM_tokPos, A_SimpleVar(EM_tokPos, yyvsp[0].sym));;
    break;}
case 122:
#line 239 "pascal.y"
{/*call function*/yyval.exp = A_CallExp(EM_tokPos, yyvsp[-3].sym, yyvsp[-1].explist);;
    break;}
case 123:
#line 240 "pascal.y"
{/*call system function without argument*/yyval.exp = A_CallExp(EM_tokPos, yyvsp[0].sym, NULL);;
    break;}
case 124:
#line 241 "pascal.y"
{/*call system function with arguments*/yyval.exp = A_CallExp(EM_tokPos, yyvsp[-3].sym, yyvsp[-1].explist);;
    break;}
case 125:
#line 242 "pascal.y"
{/*const expression*/ yyval.exp = yyvsp[0].exp;;
    break;}
case 126:
#line 243 "pascal.y"
{ /*expression*/ yyval.exp = yyvsp[-1].exp;;
    break;}
case 127:
#line 244 "pascal.y"
{ /*bool operation, not*/ yyval.exp = A_IfExp(EM_tokPos, yyvsp[0].exp, A_IntExp(EM_tokPos, 0), A_IntExp(EM_tokPos,1));;
    break;}
case 128:
#line 245 "pascal.y"
{/*expression with negative value*/ yyval.exp = A_OpExp(EM_tokPos, A_minusOp, A_IntExp(EM_tokPos, 0), yyvsp[0].exp);;
    break;}
case 129:
#line 246 "pascal.y"
{ /*subscript variable expression*/ yyval.exp = A_VarExp(EM_tokPos,A_SubscriptVar(EM_tokPos, A_SimpleVar(EM_tokPos, yyvsp[-3].sym), yyvsp[-1].exp));;
    break;}
case 130:
#line 247 "pascal.y"
{ /*field variable expression*/ yyval.exp = A_VarExp(EM_tokPos, A_FieldVar(EM_tokPos, A_SimpleVar(EM_tokPos, yyvsp[-2].sym), yyvsp[0].sym));;
    break;}
case 131:
#line 248 "pascal.y"
{yyval.explist = yyvsp[-2].explist; yyvsp[-2].explist->tail = A_ExpList(yyvsp[0].exp, NULL);;
    break;}
case 132:
#line 249 "pascal.y"
{yyval.explist = A_ExpList(yyvsp[0].exp, NULL);;
    break;}
case 133:
#line 251 "pascal.y"
{yyval.sym = S_Symbol(yyvsp[0].sval);;
    break;}
case 134:
#line 252 "pascal.y"
{yyval.sym = S_Symbol(yyvsp[0].sval);;
    break;}
case 135:
#line 253 "pascal.y"
{yyval.sym = S_Symbol(yyvsp[0].sval);;
    break;}
case 136:
#line 254 "pascal.y"
{yyval.sym = S_Symbol(yyvsp[0].sval);;
    break;}
case 137:
#line 255 "pascal.y"
{yyval.sym = S_Symbol(yyvsp[0].sval);;
    break;}
case 138:
#line 257 "pascal.y"
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
#line 259 "pascal.y"

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
