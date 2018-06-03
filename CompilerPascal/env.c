#include <stdio.h>
#include "util.h"
#include "symbol.h"
#include "absyn.h"
#include "types.h"
#include "temp.h"
#include "tree.h"
#include "frame.h"
#include "translate.h"
#include "env.h"

Environments Newvarenv(Tr_access acc,Type ty,int isConst)
{
	Environments tmp=checked_malloc(sizeof(*tmp));
	if(isConst)
		tmp->flag = CONST;
	else
		tmp->flag=VAR;
	tmp->u.var.init = initVar;
	tmp->u.var.ty=ty;
	tmp->u.var.acc=acc;
	return tmp;
}
Environments Newfunenv(Tr_level l,Temp_label label,Typelist param,Type output)
{
	Environments tmp=checked_malloc(sizeof(*tmp));
	tmp->flag=FUN;
	tmp->u.fun.param=param;
	tmp->u.fun.output=output;
	tmp->u.fun.lev=l;
	tmp->u.fun.label=label;
	return tmp;
}

S_table Base_varenv(void)					//定义有问题，这里应该是提前给定的变量类型！！！
{
	S_table base=S_empty();
	S_enter(base,S_Symbol("integer"),INT_type());
	S_enter(base,S_Symbol("string"),STRING_type());
	S_enter(base,S_Symbol("real"),REAL_type());
	
	//新加
	S_enter(base,S_Symbol("char"),CHAR_type());
	S_enter(base,S_Symbol("boolean"),BOOLEAN_type());
	return base;
}
S_table Base_funenv(void)									//暂时不变，等以后再说！！！
{
	S_table base = S_empty();
	S_enter(base,
		S_Symbol("write"),
		Newfunenv(Tr_outermost(), Temp_newlabel(), Newtypelist(STRING_type(), NULL), VOID_type())
	);  //void write(string)
	S_enter(base,
		S_Symbol("writeln"),
		Newfunenv(Tr_outermost(), Temp_newlabel(), Newtypelist(STRING_type(), NULL), VOID_type())
	);  //void writeln(string)
	S_enter(base, S_Symbol("abs"),
		Newfunenv(Tr_outermost(), Temp_newlabel(), Newtypelist(INT_type(), NULL), INT_type())
	); //int abs(int)
	S_enter(base, S_Symbol("chr"),
		Newfunenv(Tr_outermost(), Temp_newlabel(), Newtypelist(INT_type(), NULL), STRING_type())
	); //string chr(int)
	S_enter(base, S_Symbol("odd"),
		Newfunenv(Tr_outermost(), Temp_newlabel(), Newtypelist(INT_type(), NULL), BOOLEAN_type())
	); //boolean odd(int)
	S_enter(base, S_Symbol("ord"),
		Newfunenv(Tr_outermost(), Temp_newlabel(), Newtypelist(CHAR_type(), NULL), INT_type())
	); //int ord(char)
	S_enter(base, S_Symbol("pred"),
		Newfunenv(Tr_outermost(), Temp_newlabel(), Newtypelist(INT_type(), NULL), INT_type())
	); //int pred(int)
	S_enter(base, S_Symbol("succ"),
		Newfunenv(Tr_outermost(), Temp_newlabel(), Newtypelist(INT_type(), NULL), INT_type())
	); //int succ(int)
	S_enter(base, S_Symbol("sqr"),
		Newfunenv(Tr_outermost(), Temp_newlabel(), Newtypelist(INT_type(), NULL), INT_type())
	); //int sqr(int)
	S_enter(base, S_Symbol("sqr"),
		Newfunenv(Tr_outermost(), Temp_newlabel(), Newtypelist(INT_type(), NULL), REAL_type())
	); //real sqrt(int)
	return base;
}