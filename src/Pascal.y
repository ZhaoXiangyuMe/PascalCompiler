%{

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

%}
%token  LP RP LB RB DOT COMMA COLON SEMI
        PLUS MINUS MUL REALDIV INTDIV MOD AND OR NOT
        GE GT LE LT EQUAL UNEQUAL
        ASSIGN PROGRAM FUNCTION PROCEDURE BEGIN_T END  
        TYPE ARRAY OF RECORD VAR 
        IF THEN ELSE
        REPEAT TO DOWNTO UNTIL WHILE DO FOR
        CASE GOTO 
        READ
        CONST DOTDOT
%union {
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
}
%token<ival> INTEGER 
%token<rval> REAL
%token<cval> CHAR 
%token<sval> ID STRING SYS_CON SYS_FUNCT SYS_PROC SYS_TYPE

%type <cval> direction
%type <exp> program routine sub_routine routine_body const_value stmt compound_stmt non_label_stmt assign_stmt proc_stmt if_stmt else_clause repeat_stmt while_stmt for_stmt case_stmt case_expr goto_stmt expression expr term factor 
%type <declist> routine_head label_part const_part const_expr_list type_part var_part var_decl_list var_decl 
%type <fundec> function_decl function_head procedure_decl procedure_head
%type <fundeclist> routine_part
%type <namety> type_definition
%type <nametylist> type_decl_list 
%type <explist> stmt_list expression_list args_list case_expr_list
%type <sym> id sys_con sys_funct sys_proc sys_type
%type <ty> type_decl simple_type_decl array_type_decl record_type_decl
%type <fieldlist> field_decl_list field_decl name_list parameters para_type_list para_decl_list var_para_list val_para_list
%type <cval> stat;

%start program

%%
program : program_head routine DOT {/*set root for abstract syntax tree*/ A_synTreeRoot = $2; /*printf("Program parsed.\n");*/}
program_head : PROGRAM id SEMI {/*printf("Program head.\n");*/}
routine : routine_head routine_body {/*head:declaration with type A_decList,  body:expression with type A_exp*/ $$ = A_LetExp(EM_tokPos, $1, $2);}
routine_head    : label_part const_part type_part var_part routine_part { 
        /* placeholder*/
        A_decList decList = A_DecList(A_TypeDec(0, NULL), NULL);
        if ($2) 
            A_linkDecList(decList, $2);
        if ($3)
            A_linkDecList(decList, $3);
        if ($4) 
            A_linkDecList(decList, $4);
        if ($5)
            A_linkDecList(decList, A_DecList(A_FunctionDec(EM_tokPos, $5), NULL));
        $$ = decList->tail;
    }

label_part  : {/*label part is empty in pascal*/ $$ = NULL;}


const_part  : CONST const_expr_list {/*const declaration part*/ $$ = $2;}
            |  {/*no const declaration*/ $$ = NULL;}
const_expr_list : id EQUAL const_value SEMI const_expr_list  {/*const declaration list*/ $$ = A_DecList(A_ConstDec(EM_tokPos, $1, $3),$5);}
                | id EQUAL const_value SEMI {/*first one in list*/ $$ = A_DecList(A_ConstDec(EM_tokPos, $1, $3), NULL);}
const_value : INTEGER {/*integer value*/ $$ = A_IntExp(EM_tokPos, $1);}
            | REAL{/*real value*/ $$ = A_RealExp(EM_tokPos, $1);}
            | CHAR{/*char value*/ $$ = A_CharExp(EM_tokPos, $1);}
            | STRING {/*string value*/ $$ = A_StringExp(EM_tokPos, $1);}
            | sys_con {/*system const value*/ /*$$ = A_SysConstExp(EM_tokPos, $1);*/}

                
type_part   : TYPE type_decl_list {/*type declaration part*/ $$ = A_DecList(A_TypeDec(EM_tokPos, $2), NULL);}
            | {/*no type declaration*/ $$ = NULL;}
type_decl_list  : type_definition type_decl_list   {/*type declaration list*/ $$ = A_NametyList($1, $2);}
                | type_definition {/*last type definition, tail points to NULL*/$$ = A_NametyList($1, NULL);}
type_definition : id  EQUAL  type_decl  SEMI {/*type declaration*/$$ =A_Namety($1, $3);}
type_decl   :  simple_type_decl  {/*simple type*/ $$ = $1;}
            |  array_type_decl  {/*array type*/ $$ = $1;}
            |  record_type_decl {/*record type*/ $$ = $1;}
simple_type_decl    :  sys_type {/*system defined type*/ $$ = A_NameTy(EM_tokPos, $1);}
                    |  id  {/*self define simple type*/ $$ = A_NameTy(EM_tokPos, $1);}
                    |  LP  name_list  RP  {/*enum type*/ $$ = A_EnumType(EM_tokPos, $2);}
                    |  const_value  DOTDOT  const_value  {/*subrange type*/ $$ = A_RangeTy(EM_tokPos, $1, $3);}
                    |  MINUS  const_value  DOTDOT  const_value {/*subrange type*/ A_RangeTy(EM_tokPos, A_OpExp(EM_tokPos, A_minusOp, A_IntExp(EM_tokPos, 0), $2), $4);}
                    |  MINUS  const_value  DOTDOT  MINUS  const_value {/*subrange type*/ A_RangeTy(EM_tokPos, A_OpExp(EM_tokPos, A_minusOp, A_IntExp(EM_tokPos, 0), $2), A_OpExp(EM_tokPos, A_minusOp, A_IntExp(EM_tokPos, 0), $5));}                    
                    |  id  DOTDOT  id {/*subrange type*/ A_RangeTy(EM_tokPos, A_VarExp(EM_tokPos, A_SimpleVar(EM_tokPos, $1)), A_VarExp(EM_tokPos, A_SimpleVar(EM_tokPos, $3)));}
array_type_decl : ARRAY  LB  simple_type_decl  RB  OF  type_decl {/*array type, simple_type_dec is range of array, type_dec is actual type of array element*/ $$ = A_ArrayTy(EM_tokPos, $3, $6->u.name);}
record_type_decl    : RECORD  field_decl_list  END {/*record type*/ $$ = A_RecordTy(EM_tokPos, $2);}

field_decl_list : field_decl  field_decl_list   {/*link parts of fieldlists*/ $$ = A_linkFieldList($1, $2); }
                | field_decl{$$ = $1;}
field_decl  : name_list  COLON  type_decl  SEMI { /*set type of namelist*/$$ = A_setFieldListType($1, $3);}
name_list   : name_list  COMMA  id  {/*namelist is fieldlist of same unknown type*/ $$ = A_linkFieldList($1, A_FieldList(A_Field(EM_tokPos, $3, NULL), NULL));}
            |  id {$$ = A_FieldList(A_Field(EM_tokPos, $1, NULL), NULL);}


var_part    : VAR  var_decl_list {/*variable declaration part*/ $$ = $2;}
            |  {/*no variable declaration*/ $$ = NULL;}
var_decl_list   : var_decl var_decl_list  {/*variable declaration list*/ $$ = A_linkDecList($1, $2);} 
                | var_decl {$$ = $1;}
var_decl :  name_list  COLON  type_decl  SEMI {/*change name_list to variable declaration list*/ $$ = A_setDecListType(A_unDecList($1), $3);}


routine_part: function_decl  routine_part {/*routine declaration part, new function*/ $$ = A_FundecList($1, $2);}
            |  procedure_decl routine_part  {/*routine declaration part, new routine*/ $$ = A_FundecList($1, $2);}
            |  {$$ = NULL;}
    
function_decl : function_head  SEMI  sub_routine  SEMI {/*set function body*/$$ = $1; $$->body = $3;}
function_head :  FUNCTION  id  parameters  COLON  simple_type_decl {/*declare function head*/$$ = A_Fundec(EM_tokPos, $2, $3, $5->u.name, NULL);}
procedure_decl :  procedure_head  SEMI  sub_routine  SEMI {/*set procedure body*/ $$ = $1; $$->body = $3;}
procedure_head :  PROCEDURE id parameters {/*declare procedure head, return type is NULL*/ $$ = A_Fundec(EM_tokPos, $2, $3, NULL, NULL);}
sub_routine : routine_head routine_body {/*sub_routine in declaration*/$$ = A_LetExp(EM_tokPos, $1, $2);}
parameters : LP  para_decl_list  RP  {/*parameters declaration*/ $$ = $2;}
            | {/*no parameters*/ $$ = NULL;}
para_decl_list : para_decl_list  SEMI  para_type_list {/*represent parameter declaration as A_fieldList*/ $$ = A_linkFieldList($1, $3);}
                | para_type_list {$$ = $1;}
para_type_list : var_para_list COLON  simple_type_decl  { $$ = A_setFieldListType($1, $3);}
                |  val_para_list  COLON  simple_type_decl { $$ = A_setFieldListType($1, $3);}
var_para_list : VAR  name_list {$$ = $2;}
val_para_list : name_list {$$ = $1;}


routine_body : compound_stmt {/*set routine body as A_exp*/ $$ = $1;}
compound_stmt : BEGIN_T  stmt_list  END { $$ = A_SeqExp(EM_tokPos, $2);}
stmt_list : stmt  SEMI stmt_list { /*statement in routine body*/$$ = A_ExpList($1, $3);}
            | {$$ = NULL;}
            | stat {$$ = NULL;}
stmt : INTEGER  COLON  non_label_stmt  {$$ = $3;}
        |  non_label_stmt { $$ = $1;}
non_label_stmt  : assign_stmt { $$ = $1;}
                | proc_stmt {/*call function or procedure*/ $$ = $1;}
                | compound_stmt {$$ = $1;}
                | if_stmt {$$ = $1;}
                | repeat_stmt {  $$ = $1;}
                | while_stmt {$$ = $1;}
                | for_stmt {$$ = $1;}
                | case_stmt {$$ = $1;}
                | goto_stmt {$$ = $1;}
assign_stmt : id  ASSIGN  expression {/*simple variable assignment*/ $$ = A_AssignExp(EM_tokPos,A_SimpleVar(EM_tokPos, $1), $3);}
            | id LB expression RB ASSIGN expression {/*subscript variable of array assignment*/ $$ = A_AssignExp(EM_tokPos, A_SubscriptVar(EM_tokPos, A_SimpleVar(EM_tokPos, $1), $3),$6);}
            | id  DOT  id  ASSIGN  expression {/*field variable of record assignment*/$$ = A_AssignExp(EM_tokPos, A_FieldVar(EM_tokPos, A_SimpleVar(EM_tokPos, $1), $3),$5);}
proc_stmt :  id {/*call function*/ $$ = A_CallExp(EM_tokPos, $1, NULL);}
          |  id LP  args_list  RP {/*call function with arguments*/ $$ = A_CallExp(EM_tokPos, $1, $3);} 
          |  sys_proc {/*call system procedure*/$$ = A_CallExp(EM_tokPos, $1, NULL);}
          |  sys_proc  LP  expression_list  RP {/*call system procedure with arguments*/$$ = A_CallExp(EM_tokPos, $1, $3);}
          |  READ  LP  factor  RP {}
if_stmt : IF  expression  THEN  stmt  else_clause {/*if statement*/ $$ = A_IfExp(EM_tokPos, $2, $4, $5);}
else_clause : ELSE stmt {/*with else clause*/ $$ = $2;}
            |  {/*no else clause*/ $$ = NULL;}
repeat_stmt : REPEAT  stmt  UNTIL  expression {/*repeat statement*/ 
          $$ = A_RepeatExp(EM_tokPos, $2, $4);} 
while_stmt : WHILE  expression  DO stmt {/*while statement*/ $$ = A_WhileExp(EM_tokPos, $2, $4);}
for_stmt : FOR  id  ASSIGN  expression  direction  expression  DO stmt {/*for statement*/
    A_var var =  A_SimpleVar(EM_tokPos, $2);
    if (!($5)) {
        // to 
        $$ = A_SeqExp(EM_tokPos, A_ExpList(A_AssignExp(EM_tokPos, var, $4), A_ExpList(A_WhileExp(EM_tokPos, A_OpExp(EM_tokPos, A_ltOp, A_VarExp(EM_tokPos, var), $6), $8), NULL )));
    } else {
        // downto 
        $$ = A_SeqExp(EM_tokPos, A_ExpList(A_AssignExp(EM_tokPos, var, $4), A_ExpList(A_WhileExp(EM_tokPos, A_OpExp(EM_tokPos, A_gtOp, A_VarExp(EM_tokPos ,var), $6), $8), NULL )));
    }  
}
direction   : TO {$$ = 0;}
            | DOWNTO {$$ = 1;}
case_stmt : CASE expression OF case_expr_list  END {/*case statement, case_expr_list is all the possible value*/ $$ = A_CaseExp(EM_tokPos, $2, $4);}
case_expr_list : case_expr case_expr_list   {$$ = A_ExpList($1, $2);}  
                |  case_expr {$$ = A_ExpList($1, NULL);}
case_expr : const_value  COLON  stmt  SEMI {$$ = A_CaseValExp(EM_tokPos, $1, $3);}
          |  id  COLON  stmt  SEMI {$$ = A_CaseValExp(EM_tokPos, A_VarExp(EM_tokPos, A_SimpleVar(EM_tokPos, $1)), $3);}
goto_stmt : GOTO  INTEGER {/*goto statement*/ $$ = A_GotoExp(EM_tokPos, A_IntExp(EM_tokPos, $2));}

expression_list : expression COMMA   expression_list { $$ = A_ExpList($1, $3);}  
                | expression {$$ = A_ExpList($1, NULL);}
expression  :  expression  GE  expr  {/*greater equal expression*/ $$ = A_OpExp(EM_tokPos, A_geOp, $1, $3);}
            |  expression  GT  expr  {/*greater than expression*/ $$ = A_OpExp(EM_tokPos, A_gtOp, $1, $3);}
            |  expression  LE  expr {/*less equal expression*/ $$ = A_OpExp(EM_tokPos, A_leOp, $1, $3); }
            |  expression  LT  expr  {/*less than expression*/ $$ = A_OpExp(EM_tokPos, A_ltOp, $1, $3);}
            |  expression  EQUAL  expr  {/*equal expression*/ $$ = A_OpExp(EM_tokPos, A_eqOp, $1, $3);}
            |  expression  UNEQUAL  expr  {/*unequal expression*/ $$ = A_OpExp(EM_tokPos, A_neqOp, $1, $3);}
            |  expr{ $$ = $1;}

expr    :  expr  PLUS  term {$$ = A_OpExp(EM_tokPos, A_plusOp, $1, $3);} 
        |  expr  MINUS  term  {$$ = A_OpExp(EM_tokPos, A_minusOp, $1, $3);} 
        |  expr  OR  term  {/*bool operation or*/ $$ = A_IfExp(EM_tokPos, $1, A_IntExp(EM_tokPos, 1), $3);} 
        |  term { $$ = $1;}
term    :  term  MUL  factor { $$ = A_OpExp(EM_tokPos, A_timesOp, $1, $3);} 
        |  term  INTDIV  factor  { /*intdiv operation*/ $$ = A_OpExp(EM_tokPos, A_divideOp, $1, $3); }
        |  term REALDIV factor { /*real div operaiton*/ $$ = A_OpExp(EM_tokPos, A_realDivideOp, $1, $3);}
        |  term  MOD  factor { /*mod operation*/ $$ = A_OpExp(EM_tokPos, A_modOp, $1, $3);}
        |  term  AND  factor  { /*bool operation and*/ $$ = A_IfExp(EM_tokPos, $1, $3, A_IntExp(EM_tokPos, 0));}
        |  factor { $$ = $1;}
factor  :  id {$$ = A_VarExp(EM_tokPos, A_SimpleVar(EM_tokPos, $1));}
        |  id LP  args_list  RP {/*call function*/$$ = A_CallExp(EM_tokPos, $1, $3);}
        |  sys_funct {/*call system function without argument*/$$ = A_CallExp(EM_tokPos, $1, NULL);}
        |  sys_funct  LP  args_list  RP  {/*call system function with arguments*/$$ = A_CallExp(EM_tokPos, $1, $3);}
        |  const_value  {/*const expression*/ $$ = $1;}
        |  LP  expression  RP { /*expression*/ $$ = $2;}
        |  NOT  factor  { /*bool operation, not*/ $$ = A_IfExp(EM_tokPos, $2, A_IntExp(EM_tokPos, 0), A_IntExp(EM_tokPos,1));} 
        |  MINUS  factor {/*expression with negative value*/ $$ = A_OpExp(EM_tokPos, A_minusOp, A_IntExp(EM_tokPos, 0), $2);}
        |  id  LB  expression  RB { /*subscript variable expression*/ $$ = A_VarExp(EM_tokPos,A_SubscriptVar(EM_tokPos, A_SimpleVar(EM_tokPos, $1), $3));}
        |  id  DOT  id { /*field variable expression*/ $$ = A_VarExp(EM_tokPos, A_FieldVar(EM_tokPos, A_SimpleVar(EM_tokPos, $1), $3));}
args_list   :  args_list  COMMA  expression  {$$ = $1; $1->tail = A_ExpList($3, NULL);}
            |  expression {$$ = A_ExpList($1, NULL);}

id      : ID {$$ = S_Symbol($1);}
sys_con  : SYS_CON {$$ = S_Symbol($1);}
sys_funct: SYS_FUNCT {$$ = S_Symbol($1);}
sys_proc: SYS_PROC {$$ = S_Symbol($1);}
sys_type: SYS_TYPE {$$ = S_Symbol($1);} 

stat: error SEMI {/*jump to next semi after error */}

%%
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
