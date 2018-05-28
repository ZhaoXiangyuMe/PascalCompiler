#ifndef SEMANT_H
#define SEMANT_H
#include "translate.h"
//typedef void *Tr_exp;

struct expty
{
	bool isConst = FALSE;
	Tr_exp exp;
	Type ty;
};

F_fragList transProg(A_exp exp);
static U_boolList makeFormals(A_fieldList params);
static struct expty transVar(Tr_level l,Tr_exp e,S_table funenv,S_table varenv,A_var var);
static struct expty transExp(Tr_level l,Tr_exp e,S_table funenv,S_table varenv,A_exp exp);
static Tr_exp transDec(Tr_level l,Tr_exp exp,S_table funenv,S_table varenv,A_dec dec);
static Type transType(S_table varenv,A_ty ty);
static Typelist gettypelist(S_table varenv,A_fieldList list);
static Type gettype(Type ty);
static Fieldlist getfieldlist(S_table varenv,A_fieldList list);
static bool type_match(Type ty1,Type ty2);
#endif