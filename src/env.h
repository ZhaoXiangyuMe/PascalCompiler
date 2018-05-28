#ifndef ENV_H
#define ENV_H

#include "translate.h"

typedef struct environments *Environments;

struct environments
{
	enum { VAR, FUN, CONST } flag;
	union
	{
		struct { Tr_access acc; Type ty;} var;	
		struct { Tr_level lev; Temp_label label; Typelist param; Type output; } fun;
	} u;
};
Environments Newvarenv(Tr_access acc,Type ty,int isConst);
Environments Newfunenv(Tr_level l,Temp_label label,Typelist param,Type output);

S_table Base_varenv(void);
S_table Base_funenv(void);

#endif