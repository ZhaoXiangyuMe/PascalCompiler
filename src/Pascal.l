%{
#include<stdio.h>
#include "util.h"
#include "errormsg.h"
#include "symbol.h"
#include "absyn.h"
#include "y.tab.h"

// update EM_tokPos
void updatePos(void);
int charPos;
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

"("                 {updatePos(); return LP;}
")"                 {updatePos(); return RP;}
"["                 {updatePos(); return LB;}
"]"                 {updatePos(); return RB;}
"."                 {updatePos(); return DOT;}
".."                {updatePos(); return DOTDOT;}
","                 {updatePos(); return COMMA; }               
":"                 {updatePos(); return COLON;}              //应该是：SEMI应该是；
";"                 {updatePos(); return SEMI;}                //name == id
"+"                 {updatePos(); return PLUS;}
"-"                 {updatePos(); return MINUS;}
"*"                 {updatePos(); return MUL;}
"/"                 {updatePos(); return REALDIV;}
{div}               {updatePos(); return INTDIV;}
{mod}               {updatePos(); return MOD; }
">="                {updatePos(); return GE;}
">"                 {updatePos(); return GT;}
"<="                {updatePos(); return LE;}
"<"                 {updatePos(); return LT;}
"="                 {updatePos(); return EQUAL;}
"<>"                {updatePos(); return UNEQUAL;}
":="                {updatePos(); return ASSIGN;}
{program}             {updatePos(); return PROGRAM;}
{const}               {updatePos(); return CONST;}
{type}                {updatePos(); return TYPE;}
{var}                 {updatePos(); return VAR;}
{array}               {updatePos(); return ARRAY;}
{of}                  {updatePos(); return OF;}
{record}              {updatePos(); return RECORD;}
{end}                 {updatePos(); return END;}
{function}            {updatePos(); return FUNCTION;}
{procedure}           {updatePos(); return PROCEDURE;}
{begin}               {updatePos(); return BEGIN_T;}
{read}                {updatePos(); return READ;}
{if}                  {updatePos(); return IF;}
{then}                {updatePos(); return THEN;}
{else}                {updatePos(); return ELSE;}
{repeat}              {updatePos(); return REPEAT;}
{until}               {updatePos(); return UNTIL;}
{while}               {updatePos(); return WHILE;}
{do}                  {updatePos(); return DO;}
{for}                 {updatePos(); return FOR;}
{to}                  {updatePos(); return TO;}
{downto}              {updatePos(); return DOWNTO;}
{case}                {updatePos(); return CASE;}
{goto}                {updatePos(); return GOTO;}
{and}                 {updatePos(); return AND;}
{or}                  {updatePos(); return OR;}
{not}                 {updatePos(); return NOT;}
[a-zA-Z][0-9a-zA-Z]*  {updatePos(); yylval.sval = yytext; return ID;}
{integer}         {
    updatePos();
    int getNum;
    sscanf(yytext, "%d", &getNum);
    yylval.ival = getNum;  
    return INTEGER;
}
{real}             {
    updatePos();
    double getNum;
    sscanf(yytext, "%lf", &getNum);
    yylval.rval = getNum;
    return REAL;
}
{char}                {updatePos(); yylval.cval = yytext[0]; return CHAR; }
{string}              {updatePos(); yylval.sval = yytext; return STRING; }
{sys_con}             {updatePos(); return SYS_CON;}
{sys_funct}           {updatePos(); return SYS_FUNCT;}
{sys_proc}            {updatePos(); return SYS_PROC;}
{sys_type}            {updatePos(); return SYS_TYPE;}
\n                    {updatePos(); EM_newline();}
\r\n                  {updatePos(); EM_newline();}
[ \t+]                {updatePos();}
.                     {updatePos(); char message[100]; sprintf(message, "illegal token:%s", yytext);EM_error(EM_tokPos, message);}      
%%
void updatePos(void) {
    EM_tokPos = charPos;
    charPos += yyleng;
}
int yywrap(){
    charPos = 1;
    return 1;
}