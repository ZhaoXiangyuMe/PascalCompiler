/*
 * table.c - Functions to manipulate generic tables.
 * Copyright (c) 1997 Andrew W. Appel.
 */

#include <stdio.h>
#include "util.h"
#include "table.h"
#include "env.h"

#define TABSIZE 127

typedef struct binder_ *binder;
struct binder_ {void *key; void *value; binder next; void *prevtop;};
struct TAB_table_ {
  binder table[TABSIZE];
  void *top;
};


static binder Binder(void *key, void *value, binder next, void *prevtop)
{binder b = checked_malloc(sizeof(*b));
 b->key = key; b->value=value; b->next=next; b->prevtop = prevtop; 
 return b;
}

TAB_table TAB_empty(void)
{ 
 TAB_table t = checked_malloc(sizeof(*t));
 int i;
 t->top = NULL;
 for (i = 0; i < TABSIZE; i++)
   t->table[i] = NULL;
 return t;
}

/* The cast from pointer to integer in the expression
 *   ((unsigned)key) % TABSIZE
 * may lead to a warning message.  However, the code is safe,
 * and will still operate correctly.  This line is just hashing
 * a pointer value into an integer value, and no matter how the
 * conversion is done, as long as it is done consistently, a
 * reasonable and repeatable index into the table will result.
 */

void TAB_enter(TAB_table t, void *key, void *value)
{int index;
 assert(t && key);
 index = ((unsigned)key) % TABSIZE;
 t->table[index] = Binder(key, value,t->table[index], t->top);
 t->top = key;
}

void *TAB_look(TAB_table t, void *key)
{int index;
 binder b;
 assert(t && key);
 index=((unsigned)key) % TABSIZE;
 for(b=t->table[index]; b; b=b->next)
   if (b->key==key) return b->value;
 return NULL;
}
char * printType(Type ty) {
	char *nameTy;
	switch (ty->flag) {
	case RECORD:	nameTy = "RECORD";	break;
	case NIL:		nameTy = "NIL";		break;
	case BOOLEAN:	nameTy = "BOOLEAN"; break;
	case INT:		nameTy = "INT";		break;
	case CHAR:		nameTy = "CHAR";	break;
	case STRING:	nameTy = "STRING";	break;
	case ARRAY:		nameTy = "ARRAY";	break;
	case REAL:		nameTy = "REAL";	break;
	case NAME:		nameTy = "NAME";	break;
	case VOID:		nameTy = "VOID";	break;
	case ENUM:		nameTy = "ENUM";	break;
	}
	return nameTy;
}
char * printVar(Environments en) {
	char * nameEn;
	switch (en->flag)
	{
	case VAR: nameEn = "VAR"; break;
	case FUN: nameEn = "FUN"; break;
	case CONST: nameEn = "CONST"; break;
	default:
		break;
	}
	return nameEn;
}
void *TAB_pop(TAB_table t, int type, int cont) {
  void *k; binder b; int index;
  assert (t);
  k = t->top;
  assert (k);
  index = ((unsigned)k) % TABSIZE;
  b = t->table[index];
  assert(b);
  t->table[index] = b->next;
  t->top=b->prevtop;
  
  if (type != 3&&b->value) {
	  char tem[80];
	  sprintf(tem, "%s%d%s", "symbol", cont, ".txt");
	  FILE* fwrite = fopen(tem, "ab");

	  fprintf(fwrite, "%s\t", S_name(b->key));
	  //打印类型名
	  char * nameTy;
	  if (type == 0)
	  {
		  nameTy = printType((Type)(b->value));
		  fprintf(fwrite, "%s\n", nameTy);
	  }
	  else {
		  char * nameEn = printVar((Environments)b->value);
		  fprintf(fwrite, "%s\t", nameEn);
		  if (((Environments)b->value)->flag == FUN)
		  {
			  Typelist list = ((Environments)b->value)->u.fun.param;
			  while (list)
			  {
				  nameTy = printType(list->head);
				  fprintf(fwrite, "%s\t", nameTy);
				  list = list->next;
			  }
			  nameTy = printType(((Environments)b->value)->u.fun.output);
			  fprintf(fwrite, "%s\n", nameTy);
		  }
		  else
		  {
			  nameTy = printType(((Environments)b->value)->u.var.ty);
			  fprintf(fwrite, "%s\n", nameTy);
		  }
	  }
	  fclose(fwrite);
  }
  return b->key;
}

void TAB_dump(TAB_table t, void (*show)(void *key, void *value)) {
  void *k = t->top;
  int index = ((unsigned)k) % TABSIZE;
  binder b = t->table[index];
  if (b==NULL) return;
  t->table[index]=b->next;
  t->top=b->prevtop;
  show(b->key,b->value);
  TAB_dump(t,show);
  assert(t->top == b->prevtop && t->table[index]==b->next);
  t->top=k;
  t->table[index]=b;
}
