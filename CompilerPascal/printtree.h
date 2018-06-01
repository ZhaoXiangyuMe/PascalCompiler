#ifndef PRINT_TREE_H
#define PRINT_TREE_H
#include <stdio.h>
#include <stdlib.h>
#include "translate.h"
/* function prototype from printtree.c */
void printStmList (FILE *out, T_stmList stmList) ;
void pr_tr_exp(FILE *out, Tr_exp exp);
#endif 
