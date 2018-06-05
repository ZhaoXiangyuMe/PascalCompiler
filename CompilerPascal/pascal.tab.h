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


extern YYSTYPE yylval;
