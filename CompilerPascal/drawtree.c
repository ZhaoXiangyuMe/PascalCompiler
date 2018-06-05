#include <stdio.h>
#include "util.h"
#include "symbol.h"
#include "temp.h"
#include "tree.h"
#include "drawtree.h"


/* local function prototype */
static void dr_tree_exp(FILE *out, T_exp exp);

static char bin_oper[][12] = {
   "PLUS", "MINUS", "TIMES", "DIVIDE", 
   "AND", "OR", "LSHIFT", "RSHIFT", "ARSHIFT", "XOR"};

static char rel_oper[][12] = {
  "EQ", "NE", "LT", "GT", "LE", "GE", "ULT", "ULE", "UGT", "UGE"};

// count of node 
// this will act as number of node 
static int count = 0;
 
static void dr_stm(FILE *out, T_stm stm)
{
    if (!stm)
        return;
    switch (stm->kind) {
        case T_SEQ: {
            count++;
            int n1 = count;
            fprintf(out, "node%d->", n1); 
            dr_stm(out, stm->u.SEQ.left);  
            fprintf(out, "node%d->", n1); 
            dr_stm(out, stm->u.SEQ.right); 
            fprintf(out, "node%d[label=\"SEQ\"];\n", n1);
            break;
        }
        case T_LABEL: {
            count++;
            int n1 = count;
            count++;
            int n2 = count;
            fprintf(out, "node%d->node%d;\n", n1, n2);
            fprintf(out, "node%d[label=\"LABEL\"];\n", n1);
            fprintf(out, "node%d[label=\"%s\"];\n", n2, S_name(stm->u.LABEL));
            break;
        }
        case T_JUMP: {
            count++;
            int n1 = count;
            fprintf(out, "node%d->", n1);
            dr_tree_exp(out, stm->u.JUMP.exp); 
            fprintf(out, "node%d[label=\"JUMP\"];\n", n1);
            break;
        }
        case T_CJUMP: {
            count++;
            int n1 = count;
            count++;
            int n2 = count;
            count++;
            int n3 = count;
            count++;
            int n4 = count;

            fprintf(out, "node%d->node%d;\n", n1, n2);
            fprintf(out, "node%d->", n1);
            dr_tree_exp(out, stm->u.CJUMP.left); 
            fprintf(out, "node%d->", n1);
            dr_tree_exp(out, stm->u.CJUMP.right);
            if (stm->u.CJUMP.true)
              fprintf(out, "node%d->node%d;\n", n1, n3); 
            if(stm->u.CJUMP.false) 
              fprintf(out, "node%d->node%d;\n", n1, n4); 
            fprintf(out, "node%d[label=\"CJUMP\"];\n", n1);
            fprintf(out, "node%d[label=\"%s\"];\n", n2, rel_oper[stm->u.CJUMP.op]);
            fprintf(out, "node%d[label=\"%s\"];\n", n3, S_name(stm->u.CJUMP.true));
            fprintf(out, "node%d[label=\"%s\"];\n", n4, S_name(stm->u.CJUMP.false));
            break;
        }
        case T_MOVE: {
            count++;
            int n1 = count;
            fprintf(out, "node%d->", n1);
            dr_tree_exp(out, stm->u.MOVE.dst); 
            fprintf(out, "node%d->", n1);
            dr_tree_exp(out, stm->u.MOVE.src); 
            fprintf(out, "node%d[label=\"MOVE\"];\n", n1);
            break;
        }
        case T_EXP: {
            count++;
            int n1 = count;
            fprintf(out, "node%d->", n1);
            dr_tree_exp(out, stm->u.EXP); 
            fprintf(out, "node%d[label=\"EXP\"];\n", n1);
            break;
        }
    
    }
}

static void dr_tree_exp(FILE *out, T_exp exp)
{
    if (!exp)
        return;
    switch (exp->kind) {
        case T_BINOP: {
            count++;
            int n1 = count;
            count++;
            int n2 = count;
            fprintf(out, "node%d->node%d;\n", n1, n2); 
            fprintf(out, "node%d->", n1); 
            dr_tree_exp(out,exp->u.BINOP.left);
            fprintf(out, "node%d->", n1); 
            dr_tree_exp(out,exp->u.BINOP.right);
            fprintf(out, "node%d[label=\"BINOP\"];\n", n1);
            fprintf(out, "node%d[label=\"%s\"];\n", n2, bin_oper[exp->u.BINOP.op]);
            break;
        }
        case T_MEM: {
            count++;
            int n1 = count;
            fprintf(out, "node%d->", n1);
            dr_tree_exp(out, exp->u.MEM.exp);
            fprintf(out, "node%d[label=\"MEM\"];\n", n1);
            break;
        }
        case T_TEMP: {
            count++;
            int n1 = count;
            count++;
            int n2 = count;
            fprintf(out, "node%d->node%d;\n", n1, n2);
            fprintf(out, "node%d[label=\"TEMP\"];\n", n1);
            fprintf(out, "node%d[label=\"t%s\"];\n", n2, Temp_look(Temp_name(), exp->u.TEMP));
            break;
        }
        case T_ESEQ: {
            count++;
            int n1 = count;
            fprintf(out, "node%d->", n1); 
            dr_stm(out, exp->u.ESEQ.stm);
            fprintf(out, "node%d->", n1); 
            dr_tree_exp(out, exp->u.ESEQ.exp);
            fprintf(out, "node%d[label=\"ESEQ\"];\n", n1);
            break;
        }
        case T_NAME: {
            count++;
            int n1 = count;
            count++;
            int n2 = count;
            fprintf(out, "node%d->node%d;\n", n1, n2);
            fprintf(out, "node%d[label=\"NAME\"];\n", n1);
            fprintf(out, "node%d[label=\"%s\"];\n", n2, S_name(exp->u.NAME));
            break;
        }
        case T_CONST: {
            count++;
            int n1 = count;
            count++;
            int n2 = count;
            fprintf(out, "node%d->node%d;\n", n1, n2);
            fprintf(out, "node%d[label=\"CONST\"];\n", n1);
            fprintf(out, "node%d[label=\"%d\"];\n", n2, exp->u.CONST);
            break;
        }
        case T_DOUBLE: {
            count++;
            int n1 = count;
            count++;
            int n2 = count;
            fprintf(out, "node%d->node%d;\n", n1, n2);
            fprintf(out, "node%d[label=\"DOUBLE\"];\n", n1);
            fprintf(out, "node%d[label=\"%lf\"];\n", n2, exp->u.DOUBLE);
            break;
        }
        case T_CHAR: {
            count++;
            int n1 = count;
            count++;
            int n2 = count;
            fprintf(out, "node%d->node%d;\n", n1, n2);
            fprintf(out, "node%d[label=\"CHAR\"];\n", n1);
            fprintf(out, "node%d[label=\"%c\"];\n", n2, exp->u.CHAR);
            break;
        }
        case T_CALL: {
            count++;
            int n1 = count;
            T_expList args = exp->u.CALL.args;
            fprintf(out, "node%d->", n1); 
            dr_tree_exp(out, exp->u.CALL.fun);
            for (;args; args=args->tail) {
              fprintf(out, "node%d->", n1); 
              dr_tree_exp(out, args->head);
            }
            fprintf(out, "node%d[label=\"CALL\"];\n", n1);
            break;
        }
    } /* end of switch */
}

void  drawStmList (FILE *out, T_stmList stmList) 
{
    // setting of graph 
    fprintf(out, "digraph g {\n");
    fprintf(out, "node[peripheries=2, style=filled;]\n");
    for (; stmList; stmList=stmList->tail) {
        dr_stm(out, stmList->head); 
    }
    fprintf(out, "}");
}