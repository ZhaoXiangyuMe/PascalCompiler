#include <stdio.h>
#include "util.h"
#include "symbol.h"
#include "types.h"

static struct type st_NIL ={NIL};
static struct type st_INT ={INT};
static struct type st_BOOLEAN ={BOOLEAN};
static struct type st_REAL ={REAL};
static struct type st_CHAR ={CHAR};
static struct type st_STRING ={STRING};
static struct type st_VOID={VOID};
static char types[][7]=
{"RECORD","NIL","BOOLEAN","INT","CHAR","STRING","ARRAY","REAL","NAME","VOID","ENUM"};

Type NIL_type(void)
{return &st_NIL;}
Type BOOLEAN_type(void)
{return &st_BOOLEAN;}
Type INT_type(void)
{return &st_INT;}
Type REAL_type(void)
{return &st_REAL;}
Type CHAR_type(void)
{return &st_CHAR;}
Type STRING_type(void)
{return &st_STRING;}
Type VOID_type(void)
{return &st_VOID;}

Type RECORD_type(Fieldlist fields)
{
	Type ty=checked_malloc(sizeof(*ty));
	ty->flag=RECORD;
	ty->u.record=fields;
	return ty;
}

Type ARRAY_type(Array arrayInfo)
{
	Type tmp=checked_malloc(sizeof(*tmp));
	tmp->flag=ARRAY;
	tmp->u.array=arrayInfo;
	return tmp;
}

Type ENUM_type(EnumEveryList enumt)
{
	Type ty = checked_malloc(sizeof(*ty));
	ty->flag = ENUM;
	ty->u.enumt = enumt;
	return ty;
}

Type NAME_type(S_symbol sym, Type ty)
{
	Type tmp=checked_malloc(sizeof(*tmp));
	tmp->flag=NAME;
	tmp->u.name.sym=sym;
	tmp->u.name.ty=ty;
	return tmp;
}

Typelist Newtypelist(Type head,Typelist next)
{
	Typelist tmp=checked_malloc(sizeof(*tmp));
	tmp->head=head;
	tmp->next=next;
	return tmp;
}

Field Newfield(S_symbol name,Type ty)
{
	Field tmp=checked_malloc(sizeof(*tmp));
	tmp->name=name;
	tmp->ty=ty;
	return tmp;
}

Fieldlist Newfieldlist(Field head,Fieldlist next)
{
	Fieldlist tmp=checked_malloc(sizeof(*tmp));
	tmp->head=head;
	tmp->next=next;
	return tmp;
}

EnumEvery NewEnumEvery(S_symbol name){
	EnumEvery en = checked_malloc(sizeof(*en));
	en->name = name;
	return en;
}

EnumEveryList NewEnumEveryList(EnumEvery head, EnumEveryList next){
	EnumEveryList enl = checked_malloc(sizeof(*enl));
	enl->head = head;
	enl->next = next;
	return enl;
}

void Typeprint(Type ty)
{
	if(!ty)
		printf(" NULLTYPE ");
	else
	{
		printf(" %s ", types[ty->flag]);
		if (ty->flag == NAME)
		{
			printf(", %s ", S_name(ty->u.name.sym));
			Typeprint(ty->u.name.ty);
		}
	}
}

void Typelistprint(Typelist list)
{
	if(!list)
		printf("NULLLIST\n");
	else
	{
		printf("TYPELIST[");
		Typeprint(list->head);
		putchar(',');
		Typelistprint(list->next);
		printf("]\n");
	}
}