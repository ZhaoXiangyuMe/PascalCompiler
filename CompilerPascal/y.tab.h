/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 39 "Pascal.y" /* yacc.c:1909  */

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

#line 196 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
