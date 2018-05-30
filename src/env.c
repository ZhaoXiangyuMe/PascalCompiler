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

Environments Newvarenv(Traccess acc,Type ty, int isConst)
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
Environments Newfunenv(Level l,Temp_label label,Typelist param,Type output)
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
	S_table base=S_empty();
	S_enter(base,
    S_Symbol("print"),
	Newfunenv(global(),Temp_newlabel(),Newtypelist(STRING_type(),NULL),VOID_type())
	);  //void print(string)
	S_enter(base,S_Symbol("getchar"),
	Newfunenv(global(),Temp_newlabel(),NULL,VOID_type())
	);  //void getchcar(void)
	S_enter(base,S_Symbol("chr"),
	Newfunenv(global(),Temp_newlabel(),Newtypelist(INT_type(),NULL),STRING_type())
	); //string chr(int)
	S_enter(base,S_Symbol("size"),
	Newfunenv(global(),Temp_newlabel(),Newtypelist(STRING_type(),NULL),INT_type())
	); //int size(string)
	S_enter(base,S_Symbol("not"),
	Newfunenv(global(),Temp_newlabel(),Newtypelist(INT_type(),NULL),INT_type())
	); //int not(int)
	S_enter(base,S_Symbol("exit"),
	Newfunenv(global(),Temp_newlabel(),Newtypelist(INT_type(),NULL),VOID_type())
	); //void exit(int)
	S_enter(base,S_Symbol("substring"),
	Newfunenv(global(),Temp_newlabel(),Newtypelist(STRING_type(),
	Newtypelist(INT_type(),Newtypelist(INT_type(),NULL))),STRING_type())
	); //string substing(string,int start,int end)
	S_enter(base,S_Symbol("ord"),
	Newfunenv(global(),Temp_newlabel(),Newtypelist(STRING_type(),NULL),INT_type())
	); //int ord(string)
	S_enter(base,S_Symbol("concat"),
	Newfunenv(global(),Temp_newlabel(),Newtypelist(STRING_type(),
	Newtypelist(STRING_type(),NULL)),STRING_type())
	); //string concat(string1,string2)
	S_enter(base,S_Symbol("flush"),
	Newfunenv(global(),Temp_newlabel(),NULL,VOID_type())
	); //void flush(void)
	return base;
}