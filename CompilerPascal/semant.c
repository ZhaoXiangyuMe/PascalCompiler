#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "errormsg.h"
#include "symbol.h"
#include "absyn.h"
#include "types.h"
#include "temp.h"
#include "tree.h"
#include "frame.h"
#include "env.h"
#include "semant.h"
#include "printtree.h"

extern bool anyErrors;
static A_fundec nowCheckFun = NULL;

F_fragList transProg(A_exp exp)
{
    struct expty exptype;
    S_table basefunenv=Base_funenv();
    S_table basevarenv=Base_varenv();
    exptype=transExp(Tr_outermost(),NULL,basefunenv,basevarenv,exp);
    printf("Expression with return type: %d\n",exptype.ty->flag);
	Tr_procEntryExit(Tr_outermost(), exptype.exp, NULL);
    F_fragList ret=Tr_getResult();

    return ret;
}

struct expty Newexpty(Tr_exp e, Type t) 
{
	struct expty et;
	et.exp = e;
	et.ty  = t;
	return et;
}
static U_boolList makeFormals(A_fieldList params)
{
	U_boolList head = NULL, tail = NULL;
	A_fieldList p = params;
	for (; p; p = p->tail) {
		if (head) {
			tail->tail = U_BoolList(p->head->escape, NULL);
			tail = tail->tail;
		}
		else {
			tail = head = U_BoolList(p->head->escape, NULL);
		}
		/*if (head) {
			tail->tail = U_BoolList(TRUE, NULL);
			tail = tail->tail;
		} else {
			head = U_BoolList(TRUE, NULL);
			tail = head;
		}*/
	}
	return head;
}
static Typelist gettypelist(S_table varenv,A_fieldList list)
{
    Typelist head=NULL;
    Typelist tail=NULL;
    A_fieldList ptr=list;
    Type tmpty;

    while(ptr)
    {
        tmpty=S_look(varenv,ptr->head->typ->u.name);
        if(!tmpty)
        {
            EM_error(ptr->head->pos,"Type %s undefined\n",S_name(ptr->head->typ->u.name));
            tmpty=INT_type();
        }
        if(!head)//head==NULL
            head=tail=Newtypelist(tmpty,NULL);
        else
        {
            tail->next=Newtypelist(tmpty,NULL);
            tail=tail->next;
        }
        ptr=ptr->tail;
    }
    return head;
}

Type gettype(Type ty)
{
    if(!ty)
        return NULL;
    else if(ty->flag==NAME)
        gettype(ty->u.name.ty);
    else
        return ty;
}

static Fieldlist getfieldlist(S_table varenv,A_fieldList list)
{
    Fieldlist head=NULL;
    Fieldlist tail=NULL;
    A_fieldList ptr=list;
    Type tmpty;
    Field tmpfd;

    while(ptr)
    {
        tmpty=S_look(varenv,ptr->head->typ->u.name);
        if(!tmpty)
            EM_error(ptr->head->pos,"Type %s undefined\n",S_name(ptr->head->typ->u.name));
        else
        {
            tmpfd=Newfield(ptr->head->name,tmpty);
            if(!head)
                head=tail=Newfieldlist(tmpfd,NULL);
            else
            {
                tail->next=Newfieldlist(tmpfd,NULL);
                tail=tail->next;
            }
        }
		ptr = ptr->tail;
    }
    return head;
}

int totalLen = 0;
static int getSize(Type ty)
{
	
		ty = gettype(ty);
		switch(ty->flag){
			case VOID: {return 0;}
			case BOOLEAN: return 1;
			case CHAR: return 1;
			case INT: return 4;
			case REAL: return 8;
			case STRING: return 255;
			case ARRAY: {
				int num;
				Type arrayTy = gettype(ty->u.arrayInfo->ty);
				if(arrayTy->flag == INT)
					num = ty->u.arrayInfo->u.intt.end-ty->u.arrayInfo->u.intt.start+1;
				else if(arrayTy->flag == CHAR)
					num = ty->u.arrayInfo->u.charr.end-ty->u.arrayInfo->u.charr.start+1;
				totalLen = num;
				return num*getSize(ty->u.arrayInfo->tyEle);
			}
			case RECORD:{
				Fieldlist re = ty->u.record;
				Field nowF;
				int num = 0;
				for(re; re!=NULL; re = re->next)
				{
						nowF = re->head;
						num+=getSize(nowF->ty);
				}
				return num;
			}
		}
}

static struct expty transVar(Tr_level l,Tr_exp e,S_table funenv,S_table varenv,A_var var)
{
    if(!var)
        return Newexpty(Tr_NoExp(), VOID_type());
    Environments env;
    struct expty pt1,pt2;
    Fieldlist tmpfl;
    Tr_exp trans;

    if(var->kind==A_simpleVar)
    {
        env= (Environments)S_look(funenv,var->u.simple);
        trans=Tr_NoExp();
        //µ±Ç°ÊÇ¼ì²éº¯ÊýµÄÊ±ºò,º¯ÊýÃû¶ÔÓ¦ÄÚÈÝÒ²Òª·µ»Ø
        if(env && (env->flag==VAR||env->flag == CONST))
        {	
            trans=Tr_SimpleVar(env->u.var.acc,l);			
            struct expty temExp = Newexpty(trans,gettype(env->u.var.ty));
            if(env->flag == CONST)		
            		temExp.isConst = 1;	
            else temExp.isConst = 0;
            return temExp;
        }
        //½öÓÃÓÚº¯Êý·µ»ØÖµÀàÐÍ¼ì²é
        else if(env&&env->flag == FUN&&nowCheckFun&&checkEqSymbol(nowCheckFun->name, var->u.simple))
        {
        		return Newexpty(NULL, gettype(env->u.fun.output));
        }
        else
        {
            EM_error(var->pos,"Variable %s undefined\n",S_name(var->u.simple));
            return Newexpty(trans,INT_type());
        }
    }
    else if(var->kind==A_fieldVar)
    {
    		//½«x.yÖÐµÄx°ü×°Ò»ÏÂ£¬x±»¶¨ÒåÎªsimpleVar£¬¿ÉÒÔ´Ó·ûºÅ±íÖÐ²éÕÒ³öfieldlist¡£
        pt1=transVar(l,e,funenv,varenv,var->u.field.var);
        trans=Tr_NoExp();
        if(pt1.ty->flag!=RECORD)
        {
            EM_error(var->pos,"Expected a record type\n");
            return Newexpty(trans,INT_type());
        }
        else
        {
            int i=0;
            for(tmpfl=pt1.ty->u.record;tmpfl;tmpfl=tmpfl->next,i++)
                if(tmpfl->head->name==var->u.field.sym)
                {
                		int size = getSize(tmpfl->head->ty);
//有点小问题，等会再查
                    trans=Tr_FieldVar(pt1.exp,i,size);
                    return Newexpty(trans,gettype(tmpfl->head->ty));
                }
            EM_error(var->pos,"Field %s not found\n",S_name(var->u.field.sym)); //not fount in record
            return Newexpty(trans,INT_type());
        }
    }
    else if(var->kind==A_subscriptVar)
    {
        pt1=transVar(l,e,funenv,varenv,var->u.subscript.var);
        trans=Tr_NoExp();
        if(pt1.ty->flag!=ARRAY)
        {
            EM_error(var->pos,"Expected an array type\n");
            return Newexpty(trans,INT_type());
        }
        else
        {
            pt2=transExp(l,e,funenv,varenv,var->u.subscript.exp);
            
            if(pt2.ty->flag==INT||pt2.ty->flag == CHAR)
            {
            	int size = getSize(pt1.ty);
				size /= totalLen;
				totalLen = 0;
                trans=Tr_SubscriptVar(pt1.exp,pt2.exp,size);
                return Newexpty(trans,gettype(pt1.ty->u.arrayInfo->ty));
            }
            else if(pt2.ty->flag == ENUM)
            {
            		//´¦ÀítransExpºóÔÙÐ´£¨ÐèÒª»ñÈ¡EnumµÄÀàÐÍ£¬»¹ÓÐµ±Ç°ÊÇµÚ¼¸¸ö£©
            }
            else
            {
                EM_error(var->pos,"Index must be an interger\n");
                return Newexpty(trans,INT_type());
            }
        }
    }
    //else ERROR
    printf("Transvar inner error!\n");
    exit(1);
}

static struct expty transExp(Tr_level l,Tr_exp e,S_table funenv,S_table varenv,A_exp exp)
{
    if(!exp)
        return Newexpty(Tr_NoExp(), VOID_type());
    if(exp->kind==A_varExp)
        return transVar(l,e,funenv,varenv,exp->u.var);
//有问题，最后在处理
//    else if(exp->kind==A_nilExp)
//        return Newexpty(nilExp(),NIL_type());
    else if(exp->kind==A_stringExp)
        return Newexpty(Tr_StringExp(255 ,exp->u.stringg),STRING_type());
    else if(exp->kind==A_intExp)
        return Newexpty(Tr_IntExp(exp->u.intt),INT_type());
    else if(exp->kind==A_realExp)
        return Newexpty(Tr_RealExp(exp->u.real),REAL_type());
    else if(exp->kind==A_charExp)
        return Newexpty(Tr_CharExp(exp->u.charr),CHAR_type());
    else if(exp->kind==A_recordExp)
    {
    		A_efieldList itemList =exp->u.record.fields;
    		int n = 0;
    		Tr_expList fields = NULL;
    		Type recordTy;
    		recordTy = gettype(S_look(varenv, exp->u.record.typ));
    		if(!recordTy)
            EM_error(exp->pos,"Type %s undefined\n",S_name(exp->u.record.typ));
        else{
        		if(recordTy->flag!=RECORD)
            {
                EM_error(exp->pos,"Record type expected, get %s\n",S_name(exp->u.record.typ));
                return Newexpty(Tr_NoExp(),RECORD_type(NULL));
            }
            Fieldlist fieldTyList = recordTy->u.record;
			U_intList itemSizeList = NULL;
		    		for(itemList; itemList; itemList = itemList->tail, fieldTyList = fieldTyList->next, n++){
		    				struct expty et = transExp(l, e, funenv, varenv, itemList->head->exp);
							if (itemList->head->name != fieldTyList->head->name) 
				              EM_error(exp->pos, "%s not a valid field name", itemList->head->name);
							if (!type_match(fieldTyList->head->ty, et.ty)) 
				              EM_error(itemList->head->exp->pos, "Type mismatch");
							itemSizeList = U_IntList(getSize(et.ty), itemSizeList);
				        //½«Tr_expÁ¬½ÓÆðÀ´
								// Tr_explistnewhead(et.exp, &fields);
                            fields = Tr_ExpList(et.exp, fields);
				        
		    		}
		    		return Newexpty(Tr_RecordExp(itemSizeList, fields), recordTy);
    		}
        return Newexpty(Tr_NoExp(),RECORD_type(NULL));
    }
    else if(exp->kind==A_boolExp)
        return Newexpty(Tr_BoolExp(exp->u.booll),BOOLEAN_type());
    else if(exp->kind==A_breakExp)
    {
        if(!e)
            return Newexpty(Tr_NoExp(),VOID_type());
        return Newexpty(Tr_BreakExp(e),VOID_type());
    }
    else if(exp->kind==A_callExp)
    {
        Environments callinfo;
        A_expList params=NULL;
        Tr_expList paramlist=NULL;
        Typelist fmls;
        callinfo=S_look(funenv,exp->u.call.func);
        Tr_exp trans=Tr_NoExp();
        if(callinfo && callinfo->flag==FUN)
        {
            fmls=callinfo->u.fun.param;
            //½«²ÎÊý´¦ÀíºÃºó·ÅÈëµ½Tr_explistÖÐ
            for(params=exp->u.call.args;params&&fmls;params=params->tail,fmls=fmls->next)
            {
                struct expty arg=transExp(l,e,funenv,varenv,params->head);
                if(!type_match(arg.ty,fmls->head))
                    EM_error(params->head->pos,"Function %s type mismatch\n",S_name(exp->u.call.func));
                paramlist = Tr_ExpList(arg.exp,paramlist);
            }
            
            if(!params&&fmls)
                EM_error(exp->pos,"Too few parameters");
            if(params&&!fmls)
                EM_error(exp->pos,"Too many parameters");
            
            //°ü×°³ÉT_expµÄÐÎÊ½
            trans=Tr_CallExp(callinfo->u.fun.label,callinfo->u.fun.lev,l,paramlist);
            return Newexpty(trans,gettype(callinfo->u.fun.output));
        }
				else
				{
					EM_error(exp->pos, "Function name %s undefined\n");
					return Newexpty(trans, INT_type());
				}
    }
    /*	²»ÐèÒªÕâÖÖÓï¾ä
    else if(exp->kind==A_recordExp)
    {
        Type rectp;
        rectp=gettype(S_look(varenv,exp->u.record.typ));
        if(!rectp)
            EM_error(exp->pos,"Type %s undefined\n",S_name(exp->u.record.typ));
        else
        {
            if(rectp->flag!=RECORD)
            {
                EM_error(exp->pos,"Record type expected, get %s\n",S_name(exp->u.record.typ));
                return Newexpty(Tr_NoExp(),RECORD_type(NULL));
            }
            Fieldlist fieldTys = rectp->u.record;
						A_efieldList recList;
						Tr_explist list = NULL;
						int n = 0;
						//±éÀúrecordÖÐµÄÃ¿Ò»¸öÔªËØ£¬recListÖÐ°üº¬Ã¿Ò»¸ö±äÁ¿Ãû¼°¸³Öµexp
						for (recList = exp->u.record.fields; recList; recList = recList->tail, fieldTys = fieldTys->next, n++) 
			      {
								struct expty et = transExp(l,e,funenv,varenv, recList->head->exp);
								if (recList->head->name != fieldTys->head->name) 
				              EM_error(exp->pos, "%s not a valid field name", recList->head->name);
								if (!type_match(fieldTys->head->ty, et.ty)) 
				              EM_error(recList->head->exp->pos, "Type mismatch");
				              
				        //½«Tr_expÁ¬½ÓÆðÀ´
								Tr_explistnewhead(et.exp, &list);
						}
						return Newexpty(recordExp(n, list), rectp);
        }
        return Newexpty(Tr_NoExp(),RECORD_type(NULL));
    }
    */
    //ÐèÒªÐÞ¸Ä£¬µÈabsynÐÞ¸ÄºÃÖ®ºó£¬ÔÙ´¦Àí
    /*不需要了
    else if(exp->kind==A_arrayExp)
    {
        Type artp;
				Type finaltp;
				artp = S_look(varenv, exp->u.array.typ);
				printf("\n");
				if (artp->flag == NAME)
					finaltp=artp->u.name.ty;
				else
					finaltp= artp;
				//finaltp = gettype(artp);
        if(!finaltp)
        {
            EM_error(exp->pos,"Array type %s undefined\n",S_name(exp->u.array.typ));
            return Newexpty(Tr_NoExp(),INT_type());
        }
        else if(finaltp->flag!=ARRAY)
        {
            EM_error(exp->pos,"Array type expected, get %s\n",S_name(exp->u.array.typ));
            return Newexpty(Tr_NoExp(),INT_type());
        }

        struct expty size, init;
        size = transExp(l,e, funenv, varenv, exp->u.array.size);
        init = transExp(l,e, funenv, varenv, exp->u.array.init);
        if(exp->u.array.size->kind == A_varExp&&size.isConst != 1)
        		EM_error(exp->pos,"Array %s size cannot be simple var\n",exp->u.array.typ);
        else if(size.ty->flag!=INT && size.ty->flag!=CHAR)
            EM_error(exp->pos,"Array %s size must be an interger or char.\n",exp->u.array.typ);
        else if(size->flag!=init->flag)
        		EM_error(exp->pos,"Array initation and final number's type are different\n");
        else if(!type_match(init.ty, finaltp))
            EM_error(exp->pos,"Array %s type mismatch\n",exp->u.array.typ);
        else
        {
        		int sizeEvery = getSize(exp);
        		
        		Tr_expList expList = Tr_ExpList(size.exp, NULL);
        		expList = Tr_expList(init.exp, expList);
        		
            return Newexpty(Tr_ArrayExp(sizeEvery, totalLen, expList),artp);
        }
        return Newexpty(Tr_NoExp(),INT_type());
    }
    */
    else if(exp->kind==A_seqExp)
    {
        Tr_expList lis=NULL;
        A_expList explist;
        struct expty seq;
        explist=exp->u.seq;
        if(!explist)
            return Newexpty(Tr_NoExp(),VOID_type());
        while(explist->head)
        {
            seq=transExp(l,e,funenv,varenv,explist->head);
						printf("\n");
            lis = Tr_ExpList(seq.exp,lis);
						if (explist->tail == NULL)
								break;
		        explist=explist->tail;
		     }
        return Newexpty(Tr_SeqExp(lis),seq.ty);
    }
    else if(exp->kind==A_whileExp)
    {
        struct expty cond;
        cond=transExp(l,e,funenv,varenv,exp->u.whilee.test);
        if(cond.ty->flag!=INT&&cond.ty->flag!=BOOLEAN)
        {
            EM_error(exp->pos,"Integer expected in while\n");
        		return Newexpty(Tr_NoExp(),INT_type());
        }
//        Tr_exp done=doneExp();
        struct expty body=transExp(l,e,funenv,varenv,exp->u.whilee.body);
        return Newexpty(Tr_WhileExp(cond.exp, body.exp),VOID_type());
    }
    else if(exp->kind==A_assignExp)
    {
        struct expty left,right;
        left=transVar(l,e,funenv,varenv,exp->u.assign.var);
        right=transExp(l,e,funenv,varenv,exp->u.assign.exp);
		if(right.ty->flag == CONST)
		{
			EM_error(exp->pos, "Cannot assign to the const\n");
		}
		else if(!type_match(left.ty,right.ty))
        {
        		if(left.exp == NULL){//ÓÃÓÚº¯Êý·µ»ØÖµÀàÐÍ¼ì²é
   							EM_error(nowCheckFun->pos, "incorrect return type in function '%s'", S_name(nowCheckFun->name));
   					}
   					else if(left.isConst)
   					{
   							EM_error(exp->pos, "Don't assign to the const\n");
   					}
   					else
            		EM_error(exp->pos,"Assign type mismatch\n");
        		return Newexpty(Tr_NoExp(),INT_type());
        }
        return Newexpty(Tr_AssignExp(left.exp, right.exp),VOID_type());
    }
		//Óï·¨·ÖÎö½«for×ª»¯Îªwhile£¬´Ë´¦²»ÐèÒª´¦Àí
    else if(exp->kind==A_forExp)
    {
		/*
        struct expty start,end,stm;
        start=transExp(l,e,funenv,varenv,exp->u.forr.lo);
        end=transExp(l,e,funenv,varenv,exp->u.forr.hi);
        if(start.ty!=INT||end.ty!=INT)
            EM_error(exp->pos,"Expected integer range type");
		Typeprint(start.ty);
		Typeprint(end.ty);
        S_beginScope(funenv);
        transDec(l,e,funenv,varenv,A_VarDec(exp->pos,exp->u.forr.var, S_Symbol("int"),exp->u.forr.lo));
        stm=transExp(l,e,funenv,varenv,exp->u.forr.body);
        S_endScope(funenv);
		*/
        return Newexpty(Tr_NoExp(),VOID_type());
    }
    else if(exp->kind==A_letExp)
    {
        A_decList declist;
        Tr_expList list = NULL;
        struct expty body;
        S_beginScope(funenv);
        S_beginScope(varenv);
      /*  for(declist=exp->u.let.decs;declist;declist=declist->tail)
            list = Tr_ExpList(transDec(l,e,funenv,varenv,declist->head),list);*/
		int count = 0;
		for (declist = exp->u.let.decs; declist; declist = declist->tail) {
			printf("%d", count++);
			transDec(l, e, funenv, varenv, declist->head);
		
		}

        body=transExp(l,e,funenv,varenv,exp->u.let.body);
        list = Tr_ExpList(body.exp, list);
        // Tr_explistnewhead(body.exp,&list);
        S_endScope(varenv);
        S_endScope(funenv);
        return Newexpty(Tr_SeqExp(list),body.ty);
    }
    
    else if(exp->kind==A_opExp)
    {
        struct expty left,right;
        A_oper oper;
        oper=exp->u.op.oper;
        left=transExp(l,e,funenv,varenv,exp->u.op.left);
        right=transExp(l,e,funenv,varenv,exp->u.op.right);
        //¼Ó¼õ³Ë³ý
        if(oper>=A_plusOp&&oper<= A_realDivideOp)
        {
            if(left.ty->flag!=INT&&left.ty->flag!=REAL)
                EM_error(exp->u.op.left->pos,"Expected Integer or double left operand\n");
            if(right.ty->flag!=INT&&right.ty->flag!=REAL)
                EM_error(exp->u.op.right->pos,"Expected Integer or double right operand\n");
            
            //³ý·¨È«²¿±äÎªdoubleÀàÐÍ
            if(left.ty->flag==INT&&right.ty->flag==INT&&oper!= A_realDivideOp)
                return Newexpty(Tr_OpExp(oper, left.exp, right.exp),INT_type());
            else
                return Newexpty(Tr_OpExp(oper, left.exp, right.exp),REAL_type());
        }
		else if (oper == A_divideOp||oper == A_modOp) {
			if (left.ty->flag != INT || right.ty->flag != INT)
			{
				EM_error(exp->u.op.right->pos, "Expected Integer or double right operand\n");
			}
			else
				return Newexpty(Tr_OpExp(oper, left.exp, right.exp), INT_type());
		}
        //µÈÓÚ²»µÈÓÚ£¬Ð¡ÓÚ£¬Ð¡ÓÚµÈÓÚ£¬´óÓÚ£¬´óÓÚµÈÓÚ
        else if(oper>=A_eqOp&&oper<=A_geOp)
        {
            Tr_exp trans=Tr_NoExp();
            if(oper==A_eqOp||oper==A_neqOp)
            {
                if(left.ty->flag==INT||left.ty->flag==REAL)
                {
                    if(right.ty->flag == INT || right.ty->flag == REAL) 
                        trans = Tr_RelExp(oper, left.exp, right.exp);
										else 
                        EM_error(exp->u.op.right->pos, "unexpected type in comparsion\n");
                }
                else if(left.ty->flag == CHAR)
                {
                		if(type_match(right.ty, left.ty))
                        trans = Tr_RelExp(oper, left.exp, right.exp);
										else 
                        EM_error(exp->u.op.right->pos, "unexpected type in comparsion\n");
                }
                else if(left.ty->flag == BOOLEAN)
                {
                		if(type_match(right.ty, left.ty))
                        trans = Tr_RelExp(oper, left.exp, right.exp);
										else 
                        EM_error(exp->u.op.right->pos, "unexpected type in comparsion\n");
                }
                else if(left.ty->flag==STRING)
                {
                    if(type_match(right.ty, left.ty))
                        trans = Tr_StringRelExp(oper, left.exp, right.exp);
										else 
                        EM_error(exp->u.op.right->pos, "unexpected type in comparsion\n");
                }
                /*
								else if (left.ty->flag == ARRAY)
                {
                    if(type_match(right.ty, left.ty))
                        trans = eqRef(oper, left.exp, right.exp);
										else 
                        EM_error(exp->u.op.right->pos, "unexpected type in comparsion\n");
                }
                else if(left.ty->flag==RECORD)
                {
                    if(type_match(right.ty, left.ty) || right.ty->flag == NIL)
                        trans = eqRef(oper, left.exp, right.exp);
										else 
                        EM_error(exp->u.op.right->pos, "unexpected type in comparsion\n");
                }
                */
                else 
                    EM_error(exp->u.op.right->pos, "unexpected expression in comparsion\n");
                return Newexpty(trans,BOOLEAN_type());
            }
            else
            {
                if(left.ty->flag==INT||left.ty->flag==REAL)
                {
                    if(right.ty->flag == INT || right.ty->flag == REAL)
                        trans = Tr_RelExp(oper, left.exp, right.exp);
										else 
                        EM_error(exp->u.op.right->pos, "unexpected type in comparsion\n");
                }
                else if(left.ty->flag==CHAR)
                {
                    if(right.ty->flag == CHAR)
                        trans = Tr_RelExp(oper, left.exp, right.exp);
										else 
                        EM_error(exp->u.op.right->pos, "unexpected type in comparsion\n");
                }
                else if(left.ty->flag==BOOLEAN)
                {
                    if(right.ty->flag == BOOLEAN)
                        trans = Tr_RelExp(oper, left.exp, right.exp);
										else 
                        EM_error(exp->u.op.right->pos, "unexpected type in comparsion\n");
                }
                else if(left.ty->flag==STRING)
                {
                    if(right.ty->flag == STRING)
                        trans = Tr_StringRelExp(oper, left.exp, right.exp);
										else 
                        EM_error(exp->u.op.right->pos, "unexpected type in comparsion\n");
                }
                else 
                    EM_error(exp->u.op.right->pos, "unexpected expression in comparsion\n");
                return Newexpty(trans,BOOLEAN_type());
            }
        }
        else
        {
            printf("TransExp inner error!\n");
            exit(3);
        }
    }
    /*
    ifÓï¾ä¿ÉÄÜ»áÓÐ·µ»ØÖµ£¬Ò²¿ÉÄÜÃ»ÓÐ
    */
    else if(exp->kind==A_ifExp)
    {
        struct expty condi,ybran,nbran;
        condi=transExp(l,e,funenv,varenv,exp->u.iff.test);
        ybran=transExp(l,e,funenv,varenv,exp->u.iff.then);
        nbran.ty=NULL;
        nbran.exp=NULL;
        if(exp->u.iff.elsee)
        {
            nbran=transExp(l,e,funenv,varenv,exp->u.iff.elsee);
            if(condi.ty->flag!=INT&&condi.ty->flag!=BOOLEAN)
                EM_error(exp->u.iff.test->pos,"Expected integer condition control\n");
            if(!type_match(ybran.ty,nbran.ty))
                EM_error(exp->pos,"Branches return type must correspond\n");
        }
        return Newexpty(Tr_IfExp(condi.exp, ybran.exp, nbran.exp),ybran.ty);
    }
    else if(exp->kind == A_gotoExp)
    {
    	  if(!e)
            return Newexpty(Tr_NoExp(),VOID_type());
        return Newexpty(Tr_GotoExp(e),VOID_type());
    }
    else if(exp->kind == A_repeatExp)
    {
    		struct expty num;
    		num = transExp(l, e, funenv, varenv, exp->u.repeatt.test);
    		if(num.ty->flag!=INT)
            EM_error(exp->pos,"Integer expected in repeat\n");
//        Tr_exp done=doneExp();
        struct expty body = transExp(l, e, funenv, varenv, exp->u.repeatt.body);
        return Newexpty(Tr_RepeatExp(body.exp, num.exp), VOID_type());
    }
    /*
    caseÓï¾äÃ»ÓÐ·µ»ØÖµ
    */
    else if(exp->kind == A_caseExp)
    {
    		
    		A_expList items = exp->u.casee.valList;
    		struct expty test = transExp(l, e, funenv, varenv, exp->u.casee.exp);
    		if(test.ty->flag!=INT && test.ty->flag!=CHAR&&
    			test.ty->flag!=STRING&&test.ty->flag!=BOOLEAN)
    				EM_error(exp->pos,"Integer, char, string or boolean expected in case\n");
    		Tr_exp elsee = NULL;
    		for(items; items; items = items->tail)
    		{
    				A_exp val = items->head->u.caseval.val;
    				A_exp action = items->head->u.caseval.action;
    				struct expty valItem = transExp(l, e, funenv, varenv, val);
    				struct expty actionItem = transExp(l, e, funenv, varenv, action);
    				elsee = Tr_IfExp(Tr_RelExp(A_eqOp, test.exp, valItem.exp), actionItem.exp, elsee);
    		}
    		return Newexpty(elsee, VOID_type());
    }
    else
    {
        printf("TransExp inner error!\n");
        exit(2);
    }
}
static Tr_exp transDec(Tr_level l,Tr_exp e,S_table funenv,S_table varenv,A_dec dec)
{
    if(dec->kind==A_varDec)
    {
        struct expty tmp;
        Type tmptp;
        Tr_access acc; 
        tmp=transExp(l,e,funenv,varenv,NULL);
        if(dec->u.var.typ)
        {
		        tmptp=transType(l, e, funenv, varenv, dec->u.var.typ);
				int size = getSize(tmptp);
				totalLen = 0;
				acc = Tr_allocLocal(l, dec->u.var.escape, size);
		        if(tmptp)
		        {
		        		if(!dec->u.var.init)
		        		{
		        				
								Environments temEnv = S_look(funenv, dec->u.var.var);
								if(!temEnv)
									S_enter(funenv,dec->u.var.var,Newvarenv(acc,tmptp, 0));
								else EM_error(dec->pos, "The var has been defined\n");
		        		}
//		            else if(type_match(tmptp,tmp.ty))
//		                S_enter(funenv,dec->u.var.var,Newvarenv(acc,tmptp, 0));               
		            else
		            {
		                EM_error(dec->pos,"Type %s mismatch\n",S_name(dec->u.var.typ->u.name));
		                //S_enter(funenv,dec->u.var.var,Newvarenv(acc,tmptp));
		            }
		        }
		        else
		            EM_error(dec->pos,"Type %s undefined\n",S_name(dec->u.var.typ->u.name));
        }
        else
        {
        	/*
            if(tmp.ty->flag==NIL||tmp.ty->flag==VOID)
            {
                EM_error(dec->pos,"Type %s initial must have a type\n",S_name(dec->u.var.var));
                //S_enter(funenv,dec->u.var.var,Newvarenv(acc,INT_type()));
            }
            else
                S_enter(funenv,dec->u.var.var,Newvarenv(acc,tmp.ty));
            */
            EM_error(dec->pos,"Type %s must be inited\n",S_name(dec->u.var.var));
        }
		return Tr_NoExp();
       // return Tr_AssignExp(Tr_SimpleVar(acc, l), tmp.exp);
    }
    else if(dec->kind == A_constDec)
    {
    		struct expty getExp;
    		Type tmpty;
    		Tr_access acc;
    		getExp = transExp(l,e,funenv, varenv, dec->u.constt.init);
    		acc = Tr_allocLocal(l, dec->u.constt.escape, getSize(getExp.ty));
    		if(!dec->u.var.init)
    		{
    				EM_error(dec->pos,"Const is not inited\n");
    		}
    		else if(dec->u.constt.init->kind!=A_intExp
    			&&	dec->u.constt.init->kind!=A_charExp
    			&&	dec->u.constt.init->kind!=A_realExp
    			&&	dec->u.constt.init->kind!=A_stringExp
    			&&	dec->u.constt.init->kind!=A_boolExp)
    		{
    				EM_error(dec->pos,"Const initialization error\n");
    		}
    		else
    		{
					Environments temEnv = S_look(funenv,dec->u.constt.constt);
					if (!temEnv) {
						initVar =  dec->u.constt.init;
						S_enter(funenv, dec->u.constt.constt, Newvarenv(acc, getExp.ty, 1));
						initVar = NULL;
					}
					else EM_error(dec->pos, "The var has been defined\n");	
    		}
    		return Tr_AssignExp(Tr_SimpleVar(acc, l), getExp.exp);
    }
    else if(dec->kind==A_functionDec)
    {
        struct expty final;
        A_fundecList fcl;
        A_fieldList list;
        Type resTy;
        Typelist formalTys;
        A_fundec f;
        Environments fun;
        Typelist s;
        for (fcl = dec->u.function; fcl; fcl = fcl->tail)
        {
			if (fcl->head->result)
            {
				resTy = S_look(varenv, fcl->head->result);
				if (!resTy)
                {
						EM_error(fcl->head->pos, "undefined type for return type");
						resTy = VOID_type();
				}
			}
            else
				resTy = VOID_type();
			formalTys = gettypelist(varenv, fcl->head->params);
			Temp_label funLabel = Temp_newlabel();
			U_intList paramSizeList = NULL;
			for (Typelist ty = formalTys; ty; ty = ty->next)
			{
				paramSizeList = U_IntList(getSize(ty->head), paramSizeList);
			}
			Tr_level lev = Tr_newLevel(l, funLabel, makeFormals(fcl->head->params), paramSizeList);/* create a new level */
			Environments value = Newfunenv(lev, funLabel, formalTys, resTy);
			S_enter(funenv, fcl->head->name, value);
		}
		//»ñÈ¡·ûºÅ£¬½«·ûºÅ£¬¼ÓÈëµ½»·¾³ÖÐ
		for (fcl = dec->u.function; fcl; fcl = fcl->tail)
		{
				f = fcl->head;
				Environments funEntry = (Environments)S_look(funenv, f->name); /*get fun-info*/
				S_beginScope(funenv);							//ÊµÏÖÄÚ²ãº¯Êý·ÃÎÊÍâ²ã±äÁ¿
				formalTys = funEntry->u.fun.param;
				Tr_accessList acls = Tr_formals(funEntry->u.fun.lev);
				for (list = f->params, s = formalTys; list && s && acls; list = list->tail, s = s->next, acls = acls->tail)
					S_enter(funenv, list->head->name, Newvarenv(acls->head, s->head, 0));
				nowCheckFun = f;
				final = transExp(funEntry->u.fun.lev, e, funenv, varenv, f->body);
				nowCheckFun = NULL;
				Tr_procEntryExit(funEntry->u.fun.lev, final.exp, acls);
				S_endScope(funenv);
		}
		return Tr_NoExp();
    }
    else if(dec->kind==A_typeDec)
    {
        A_nametyList nl;
        Type resTy;
        Type namety;
        bool iscyl;
        for (nl = dec->u.type; nl; nl = nl->tail) 
					S_enter(varenv, nl->head->name, NAME_type(nl->head->name, nl->head->ty));
				iscyl = TRUE;
				for (nl = dec->u.type; nl; nl = nl->tail) {//ËùÓÐµÄ¶¼ÏòÉÏ²éÕÒÒ»¸ö£¬×îºóÒ»¸ö»á²éÕÒµ½Êµ¼ÊÀàÐÍ
					resTy = transType(l, e, funenv, varenv, nl->head->ty);
					if (iscyl)
						if (resTy->flag != NAME)
							iscyl = FALSE;
					namety = S_look(varenv, nl->head->name);
					namety->u.name.ty = resTy;
				}
				if (iscyl) EM_error(dec->pos,"illegal type cycle: cycle must contain record, array");
				return Tr_NoExp();
		}
		else
		{
		    printf("TransDec inner error!\n");
		    exit(4);
		}
}
static Type transType(Tr_level l,Tr_exp e,S_table funenv,S_table varenv,A_ty ty)
{
    Type tmptp=NULL;
    Fieldlist list=NULL;

    if(ty->kind==A_nameTy)
    {
        tmptp=S_look(varenv,ty->u.name);
        if(tmptp)
            return tmptp;
        else
        {
            EM_error(ty->pos,"Type %s undefined\n",S_name(ty->u.name));
            return INT_type();
        }
    }
    else if(ty->kind==A_recordTy)
    {
        list=getfieldlist(varenv,ty->u.record);
        return RECORD_type(list);
    }
    else if(ty->kind==A_arrayTy)
    {
        tmptp=transType(l, e, funenv, varenv, ty->u.arrayy.element);//S_look(varenv,ty->u.arrayy.element);
        if(!tmptp)
        	EM_error(ty->pos,"Type %s undefined\n",S_name(ty->u.arrayy.element->u.name));
        struct array *temArrayInfo = checked_malloc(sizeof(*temArrayInfo));
        temArrayInfo->tyEle = tmptp;
        struct expty low, high;
        low = transExp(l, e, funenv, varenv, ty->u.arrayy.range->u.rangee.lo);
        high = transExp(l,e,funenv, varenv, ty->u.arrayy.range->u.rangee.hi);

        if(!(low.ty->flag == INT || low.ty->flag == CHAR)
        	||!(high.ty->flag == INT || high.ty->flag == CHAR))
        	EM_error(ty->pos,"Array index type should be integer, char or const char, const integer.\n");
        else 
        if(low.ty->flag!=high.ty->flag)
        	EM_error(ty->pos,"Array index type is inconsistent.\n");
        else if(ty->u.arrayy.range->u.rangee.lo->kind == A_intExp){
			temArrayInfo->ty = low.ty;
        	temArrayInfo->u.intt.start = ty->u.arrayy.range->u.rangee.lo->u.intt;
		      temArrayInfo->u.intt.end = ty->u.arrayy.range->u.rangee.hi->u.intt;
        }
        else if(ty->u.arrayy.range->u.rangee.lo->kind == A_charExp){
			temArrayInfo->ty = low.ty;
        	temArrayInfo->u.charr.start = ty->u.arrayy.range->u.rangee.lo->u.charr;
		      temArrayInfo->u.charr.end = ty->u.arrayy.range->u.rangee.hi->u.charr;
        }
        else if(ty->u.rangee.lo->kind == A_varExp){
        	Environments getLoEnv = S_look(funenv, ty->u.arrayy.range->u.rangee.lo->u.var->u.simple);
        	Environments getHiEnv = S_look(funenv, ty->u.arrayy.range->u.rangee.hi->u.var->u.simple);
        	if(getLoEnv&&getHiEnv)
        	{
        			if(getLoEnv->flag == CONST&&getHiEnv->flag == CONST)
        			{
        					if(low.ty->flag == INT){
								temArrayInfo->ty = INT_type();;
        						temArrayInfo->u.intt.start = getLoEnv->u.var.init->u.intt;
		      					temArrayInfo->u.intt.end = getHiEnv->u.var.init->u.intt;
        					}
        					else if(low.ty->flag == CHAR){
								temArrayInfo->ty = CHAR_type();
        						temArrayInfo->u.charr.start = getLoEnv->u.var.init->u.charr;
		      					temArrayInfo->u.charr.end = getHiEnv->u.var.init->u.charr;
        					}
        			}
        			else EM_error(ty->pos,"The var at the array index should be const.\n");
        	}
        	else
        		EM_error(ty->pos,"The var at the array index are not defined.\n");
        }
		return ARRAY_type(temArrayInfo);
    }

    else
    {
        printf("TransType inner error!\n");
        exit(5);
    }
}
static bool type_match(Type ty1,Type ty2)
{
    Type t1=gettype(ty1);
    Type t2=gettype(ty2);
    return (((t1->flag == RECORD || t1->flag == ARRAY) && t1 == t2) ||
			 (t1->flag == RECORD && t2->flag == NIL) ||
			 (t2->flag == RECORD && t1->flag == NIL) ||
			 (t1->flag != RECORD && t1->flag != ARRAY && t1->flag == t2->flag));
}