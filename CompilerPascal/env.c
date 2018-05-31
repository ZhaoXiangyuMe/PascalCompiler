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

S_table Base_varenv(void)					//���������⣬����Ӧ������ǰ�����ı������ͣ�����
{
	S_table base=S_empty();
	S_enter(base,S_Symbol("integer"),INT_type());
	S_enter(base,S_Symbol("string"),STRING_type());
	S_enter(base,S_Symbol("real"),REAL_type());
	
	//�¼�
	S_enter(base,S_Symbol("char"),CHAR_type());
	S_enter(base,S_Symbol("boolean"),BOOLEAN_type());
	return base;
}
S_table Base_funenv(void)									//��ʱ���䣬���Ժ���˵������
{
	S_table base=S_empty();
	S_enter(base,
    S_Symbol("print"),
	Newfunenv(Tr_outermost(),Temp_newlabel(),Newtypelist(STRING_type(),NULL),VOID_type())
	);  //void print(string)
	S_enter(base,S_Symbol("getchar"),
	Newfunenv(Tr_outermost(),Temp_newlabel(),NULL,VOID_type())
	);  //void getchcar(void)
	S_enter(base,S_Symbol("chr"),
	Newfunenv(Tr_outermost(),Temp_newlabel(),Newtypelist(INT_type(),NULL),STRING_type())
	); //string chr(int)
	S_enter(base,S_Symbol("size"),
	Newfunenv(Tr_outermost(),Temp_newlabel(),Newtypelist(STRING_type(),NULL),INT_type())
	); //int size(string)
	S_enter(base,S_Symbol("not"),
	Newfunenv(Tr_outermost(),Temp_newlabel(),Newtypelist(INT_type(),NULL),INT_type())
	); //int not(int)
	S_enter(base,S_Symbol("exit"),
	Newfunenv(Tr_outermost(),Temp_newlabel(),Newtypelist(INT_type(),NULL),VOID_type())
	); //void exit(int)
	S_enter(base,S_Symbol("substring"),
	Newfunenv(Tr_outermost(),Temp_newlabel(),Newtypelist(STRING_type(),
	Newtypelist(INT_type(),Newtypelist(INT_type(),NULL))),STRING_type())
	); //string substing(string,int start,int end)
	S_enter(base,S_Symbol("ord"),
	Newfunenv(Tr_outermost(),Temp_newlabel(),Newtypelist(STRING_type(),NULL),INT_type())
	); //int ord(string)
	S_enter(base,S_Symbol("concat"),
	Newfunenv(Tr_outermost(),Temp_newlabel(),Newtypelist(STRING_type(),
	Newtypelist(STRING_type(),NULL)),STRING_type())
	); //string concat(string1,string2)
	S_enter(base,S_Symbol("flush"),
	Newfunenv(Tr_outermost(),Temp_newlabel(),NULL,VOID_type())
	); //void flush(void)
	return base;
}