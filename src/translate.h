#ifndef TRANSLATE_H_
#define TRANSLATE_H_
#include "temp.h"
#include "frame.h"
#include "absyn.h"

typedef struct Tr_access_ *Tr_access;
typedef struct Tr_accessList_ *Tr_accessList;
typedef struct Tr_level_ *Tr_level;

typedef struct Tr_exp_ *Tr_exp;
typedef struct Tr_expList_ *Tr_expList;

typedef struct patchList_ *patchList;

// constructor
Tr_access Tr_Access(Tr_level level, F_access access);
Tr_accessList Tr_AccessList(Tr_access head, Tr_accessList tail);

Tr_expList Tr_ExpList(Tr_exp head, Tr_expList tail);


// level dependent 

// outermost level, contain library functions
// parent of main function 
Tr_level Tr_outermost(void);
// create a new level for given function 
Tr_level Tr_newLevel(Tr_level parent, Temp_label name, U_boolList formals);

Tr_accessList Tr_formals(Tr_level level);
Tr_access Tr_allocLocal(Tr_level level, bool escape);

T_exp Tr_getStaticLink(Tr_level call, Tr_level def);

Tr_exp Tr_SimpleVar(Tr_access access, Tr_level level);
// size: size of field in record
Tr_exp Tr_FieldVar(Tr_exp addr, int offset, int size);
// size: size of element in array 
Tr_exp Tr_SubscriptVar(Tr_exp addr, Tr_exp offset, int size);

Tr_exp Tr_NoExp();
Tr_exp Tr_BoolExp(bool b);
Tr_exp Tr_IntExp(int i);
Tr_exp Tr_RealExp(double r);
Tr_exp Tr_CharExp(char c);
Tr_exp Tr_StringExp(int size, string str);
// sizes: size of each field in record 
Tr_exp Tr_RecordExp(int* sizes, Tr_expList fields);
// size: size of element in array
Tr_exp Tr_ArrayExp(int size, int totalLen, Tr_expList initList);

Tr_exp Tr_CallExp(Temp_label label, Tr_level call, Tr_level def, Tr_expList args);
Tr_exp Tr_OpExp(A_oper op, Tr_exp left, Tr_exp right);
Tr_exp Tr_RelExp(A_oper op, Tr_exp left, Tr_exp right);
Tr_exp Tr_StringRelExp(A_oper op, Tr_exp left, Tr_exp right);
Tr_exp Tr_AssignExp(Tr_exp left, Tr_exp right);
Tr_exp Tr_SeqExp(Tr_expList list);
Tr_exp Tr_IfExp(Tr_exp test, Tr_exp then, Tr_exp elsee);
Tr_exp Tr_WhileExp(Tr_exp test, Tr_exp body);
Tr_exp Tr_RepeatExp(Tr_exp body, Tr_exp test);
Tr_exp Tr_GotoExp(Tr_exp pos);
// for should be converted into while from abstract syntax 
// Tr_exp Tr_ForExp(A_pos pos, S_symbol var, A_exp lo, A_exp hi, A_exp body);
Tr_exp Tr_BreakExp(Tr_exp pos);

void Tr_procEntryExit(Tr_level level, Tr_exp body, Tr_accessList formals);
F_fragList Tr_getResult();

#endif