#include "codegen.h"
#include <stdlib.h>

static AS_instrList iList = NULL, last = NULL;
extern Temp_map F_tempMap;


static void emit(AS_instr instr) {
    if (last != NULL) {
        last = last->tail = AS_InstrList(instr, NULL);
    } else {
        last = iList = AS_InstrList(instr, NULL);
    }
}

AS_instrList F_codegen(F_frame frame, T_stmList stmList) {
    AS_instrList ret = NULL;
    T_stmList sl = stmList;
    for(;sl;sl = sl->tail) 
        munchStm(sl->head);
    ret = iList;
    iList = last = NULL;
    return ret;
}

static Temp_temp munchExp(T_exp e) {
    char buffer[80];
    Temp_temp ret = Temp_newtemp(); 
    switch(e->kind) {
        case T_TEMP: {
            ret = e->u.TEMP;
            break;
        }
        case T_ESEQ: {
            munchStm(e->u.ESEQ.stm);
            ret = munchExp(e->u.ESEQ.exp);
            break;
        }
        case T_NAME: {
           Temp_enter(F_TEMPMAP, ret, Temp_labelstring(e->u.NAME));
            break;
        }
        case T_CONST: {
            sprintf(buffer, "%d", e->u.CONST);
            emit(AS_Move(String(buffer), Temp_TempList(ret, NULL), NULL));
            break;
        }
        case T_CALL: {
            ret = munchExp(e->u.CALL.fun);
            emit(AS_Oper(String("call `s0"), NULL, Temp_TempList(ret, munchArgs(0, e->u.CALL.args)), NULL));
            break;
        }
        case T_BINOP: {
            char *oper=NULL;
            char *sign=NULL;
            T_exp left=e->u.BINOP.left;
            T_exp right=e->u.BINOP.right;
            if(e->u.BINOP.op==T_plus)
            {
                oper="add";
                sign="+";
            }
            else if(e->u.BINOP.op==T_minus)
            {
                oper="sub";
                sign="-";
            }
            else if(e->u.BINOP.op==T_mul)
            {
                oper="mul";
                sign="*";
            }
            else if(e->u.BINOP.op==T_div)
            {
                oper="div";
                sign="/";
            }
            else
            {
                printf("Invalid operator\n");
                exit(15);
            }
            if (left->kind == T_CONST) 
            { /* BINOP(op, CONST, e) */
                sprintf(buffer, "%s $%x, `d0", oper, left->u.CONST);
                emit(AS_Oper(String(buffer), Temp_TempList(ret = munchExp(right), NULL), NULL, NULL));
            } 
            else if (right->kind == T_CONST) 
            { /* BINOP(op, e, CONST) */
                sprintf(buffer,"%s $%x, `d0", oper, right->u.CONST);
                emit(AS_Oper(String(buffer), Temp_TempList(ret = munchExp(left), NULL), NULL, NULL));
            } 
            else 
            { /* BINOP(op, e, e) */
                sprintf(buffer,"%s `s0, `d0",oper);
                emit(AS_Oper(String(buffer), Temp_TempList(ret = munchExp(right), NULL), Temp_TempList(munchExp(left), NULL), NULL));
            }
            break;
        }
        case T_MEM: {
            T_exp mem = e->u.MEM.exp;
            if (mem->kind == T_BINOP && mem->u.BINOP.op == T_plus)
            {
                T_exp left=mem->u.BINOP.left;
                T_exp right=mem->u.BINOP.right;
                if (left->kind == T_CONST)
                { /* MEM(BINOP(+, CONST, e)) */
                    sprintf(buffer,"mov %d(`s0), `d0",left->u.CONST);
                    emit(AS_Move(String(buffer), Temp_TempList(ret, NULL), Temp_TempList(munchExp(right), NULL)));
                } 
                else if (right->kind == T_CONST)
                { /*MEM(BINOP(+, e, CONST)) */
                    sprintf(buffer,"mov %d(`s0), `d0",right->u.CONST);
                    emit(AS_Move(String(buffer), Temp_TempList(ret, NULL), Temp_TempList(munchExp(left), NULL)));
                }
                else
                {
                    printf("MEM(BINOP) error\n");
                    exit(16);
                }
            }
            break;
        }
        default: {
            printf("T_exp error!\n");
            exit(14);
        }

    }

}

static void munchStm(T_stm s) {
    if (!s)
        return;
    char buffer[80];

    switch(s->kind) {
        case T_EXP: {
            munchExp(s->u.EXP); 
            break;    
        }
        case T_SEQ: {
            munchStm(s->u.SEQ.left);
            munchStm(s->u.SEQ.right);
            break;
        }
        case T_MOVE: {
            T_exp dst=s->u.MOVE.dst;
            T_exp src=s->u.MOVE.src;
            if(dst->kind==T_TEMP) {
                if (src->kind == T_CONST) {
                    sprintf(buffer, "addi `d0, $0, %d", src->u.CONST);
                    emit(AS_Move(String(buffer), Temp_TempList(munchExp(dst), NULL), NULL, NULL));      
                } else {
                     emit(AS_Move(String("addi `d0, `s0, 0"), Temp_TempList(munchExp(dst), NULL), Temp_TempList(munchExp(src), NULL)));  
                }
            }
            else if (dst->kind = T_MEM) {
                if(dst->u.MEM.exp->kind == T_BINOP && dst->u.MEM.exp->u.BINOP.op == T_plus) 
                {
                    if(dst->u.MEM.exp->u.BINOP.right->kind == T_CONST)  /* MOVE (MEM(BINOP(+, e, CONST)), e) */
                    {
                         sprintf(buffer, "sw `s1, %d(`s0)", dst->u.MEM.exp->u.BINOP.right->u.CONST);
                         emit(AS_Move(String(buffer), NULL, Temp_TempList(munchExp(dst->u.MEM.exp->u.BINOP.left), Temp_TempList(munchExp(src), NULL))));
                    }
                    if(dst->u.MEM.exp->u.BINOP.left->kind == T_CONST)  /* MOVE (MEM(BINOP(+, CONST, e)), e) */
                    {
                        sprintf(buffer, "mov `s1, %d(`s0)", dst->u.MEM.exp->u.BINOP.left->u.CONST);
                        emit(AS_Move(String(buffer), NULL, Temp_TempList(munchExp(dst->u.MEM.exp->u.BINOP.right), Temp_TempList(munchExp(src), NULL))));
                    }
                } 
                else if(dst->u.MEM.exp->kind == T_CONST) 
                { /* MOVE(MEM(CONST), e) */
                    sprintf(buffer, "sw `s0, %d($0)", dst->u.MEM.exp->u.CONST);
                    emit(AS_Move(String(buffer), NULL, Temp_TempList(munchExp(src), NULL)));
                }
                else if(src->kind == T_MEM)  /* MOVE(MEM(e), MEM(e)) */
                    emit(AS_Move("mov `s1, (`s0)", NULL, Temp_TempList(munchExp(dst->u.MEM.exp), Temp_TempList(munchExp(src->u.MEM.exp), NULL))));

            }
            break;
        }
        case T_LABEL: {
            sprintf(buffer, "%s:", Temp_labelstring(s->u.LABEL));        
            emit(AS_Label(String(buffer), s->u.LABEL));
            break;
        }
        case T_JUMP: {
            Temp_temp exp = munchExp(s->u.JUMP.exp);
            emit(AS_Oper(String("jump `d0"), Temp_TempList(exp, NULL), NULL, AS_Targets(s->u.JUMP.jumps)));
            break;
        }
        case T_CJUMP: {
            char * cmp;
            Temp_temp left = munchExp(s->u.CJUMP.left);
            Temp_temp right = munchExp(s->u.CJUMP.right);
            emit(AS_Oper(String("cmp `s0, `s1"), NULL, Temp_TempList(left, Temp_TempList(right, NULL)), NULL));
            if(s->u.CJUMP.op==T_eq) //==
                cmp="beq";
            else if(s->u.CJUMP.op==T_ne) //<>
                cmp="bne";
            else
            {
                printf("Invalid compare sign!\n");
                exit(12);
            }
            sprintf(buffer, "%s `j0", cmp);        
            emit(AS_Oper(String(buffer), NULL, NULL, AS_Targets(Temp_LabelList(s->u.CJUMP.true, NULL))));  
            break;
        }
        default: {
            printf("T_stm Error!\n");
        }

    }
}

static Temp_tempList munchArgs(int i, T_expList args) {
    if (!args) 
        return NULL;
   
    char buffer[80];
    Temp_tempList list = munchArgs(i+1,args->tail);
    Temp_temp regArg = munchExp(args->head);
    emit(AS_Oper(String("push `s0"), NULL, Temp_TempList(regArg, NULL), NULL));
    return (regArg,list);
}
