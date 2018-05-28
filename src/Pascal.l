%{
#include<stdio.h>
#include "util.h"
#include "errormsg.h"
#include "symbol.h"
#include "absyn.h"
#include "y.tab.h"
%}
div             [dD][iI][vV]                         
mod             [mM][oO][dD]
integer         [0-9]+
real            [0-9]+\.[0-9]+
char            [A-za-z\_\'\.\"]
string          \"char+\"
program         [pP][rR][oO][gG][rR][aA][mM]
const           [cC][oO][nN][sS][tT]
type            [tT][yY][pP][eE]
var             [vV][aA][rR]
array           [aA][rR][rR][aA][yY]
of              [oO][fF]
record          [rR][eE][cC][oO][rR][dD]
end             [eE][nN][dD]
function        [fF][uU][nN][cC][tT][iI][oO][nN]
procedure       [pP][rR][oO][cC][eE][dD][uU][rR][eE]
begin           [bB][eE][gG][iI][nN]
read            [rR][eE][aA][dD]
if              [iI][fF]
then            [tT][hH][eE][nN]
else            [eE][lL][sS][eE]
repeat          [rR][eE][pP][eE][aA][tT]
until           [uU][nN][tT][iI][lL]
while           [wW][hH][iI][lL][eE]
do              [dD][oO]
for             [fF][oO][rR]
to              [tT][oO]
downto          [dD][oO][wW][nN][tT][oO]
case            [cC][aA][sS][eE]
goto            [gG][oO][tT][oO]
and             [aA][nN][dD]
or              [oO][rR]
not             [nN][oO][tT]
false           [fF][aA][lL][sS][eE]
maxint          [mM][aA][xX][iI][nN][tT]
true            [tT][rR][uU][eE]
sys_con         false|maxint|true
abs             [aA][bB][sS]
chr             [cC][hH][rR]
odd             [oO][dD][dD]
ord             [oO][rR][dD]
pred            [pP][rR][eE][dD]
sqr             [sS][qQ][rR]
sqrt            [sS][qQ][rR][tT]
succ            [sS][uU[cC][cC]
sys_funct       abs|chr|odd|ord|pred|sqr|sqrt|succ
write           [wW][rR][iI][tT][eE]
writeln         [wW][rR][iI][tT][eE][lL][nN]
sys_proc        write|writeln
boolt           [bB][oO][oO][lL][eE][aA][nN]
cht             [cC][hH][aA][rR]
intt            [iI][nN][tT][eE][gG][eE][rR]
realt           [rR][eE][aA][lL]
sys_type        boolt|cht|intt|realt
%%

"("                 { return LP;}
")"                 { return RP;}
"["                 { return LB;}
"]"                 { return RB;}
"."                 { return DOT;}
".."                { return DOTDOT;}
","                 { return COMMA; }               
":"                 return COLON;               //应该是：SEMI应该是；
";"                 return SEMI;                //name == id
"+"                 return PLUS;
"-"                 return MINUS;
"*"                 return MUL;
"/"                 return REALDIV;
{div}               { return INTDIV;}
{mod}               return MOD;
">="                return GE;
">"                 return GT;
"<="                return LE;
"<"                 return LT;
"="                 { return EQUAL;}
"<>"                { return UNEQUAL;}
":="                return ASSIGN;
{program}             { return PROGRAM;}
{const}               { return CONST;}
{type}                { return TYPE;}
{var}                 return VAR;
{array}               { return ARRAY;}
{of}                  return OF;
{record}              return RECORD;
{end}                 return END;
{function}            return FUNCTION;
{procedure}           return PROCEDURE;
{begin}               { return BEGIN_T;}
{read}                return READ;
{if}                  return IF;
{then}                return THEN;
{else}                return ELSE;
{repeat}              {return REPEAT;}
{until}               {return UNTIL;}
{while}               return WHILE;
{do}                  return DO;
{for}                 return FOR;
{to}                  return TO;
{downto}              return DOWNTO;
{case}                return CASE;
{goto}                return GOTO;
{and}                 return AND;
{or}                  return OR;
{not}                 return NOT;
[a-zA-Z][0-9a-zA-Z]*  { /*printf("id %s\n", yytext);*/ yylval.sval = yytext; return ID;}
{integer}         {
    int getNum;
    sscanf(yytext, "%d", &getNum);
    yylval.ival = getNum;  
    return INTEGER;
}
{real}             {
    double getNum;
    sscanf(yytext, "%lf", &getNum);
    yylval.rval = getNum;
    return REAL;
}
{char}                { yylval.cval = yytext[0]; return CHAR; }
{string}              { /*printf("This is string \n");*/ yylval.sval = yytext; return STRING; }
{sys_con}             return SYS_CON;
{sys_funct}           return SYS_FUNCT;
{sys_proc}            return SYS_PROC;
{sys_type}            return SYS_TYPE;
.                     {}      
%%
int yywrap(){
    return 1;
}