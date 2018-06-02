#include "translate.h"
#include "tree.h"
#include <string.h>

// static global variable 
static Tr_level outermost = NULL;
static F_fragList procFragList = NULL;

struct Tr_level_ {
	Tr_level parent;
	// name of current level 
	Temp_label name;
	// frame of current level 
	F_frame frame;
};
 
struct patchList_ {
	Temp_label* head;
	patchList tail;
};

struct Cx {
	patchList trues;
	patchList falses;
	T_stm stm;
};

struct  Tr_exp_ {	
	enum {Tr_ex, Tr_nx, Tr_cx} kind;
	union {
		T_exp ex;
		T_stm nx;
		struct Cx cx;
	} u;
};

struct Tr_expList_ {
	Tr_exp head;
	Tr_expList tail;	
};


// constructors
Tr_access Tr_Access(Tr_level level, F_access access) {
	Tr_access trAccess = checked_malloc(sizeof(*trAccess));
	trAccess->level = level;
	trAccess->access = access;

	return trAccess;
}

Tr_accessList Tr_AccessList(Tr_access head, Tr_accessList tail) {
	Tr_accessList accessList = checked_malloc(sizeof(*accessList));
	accessList->head = head;
	accessList->tail = tail;

	return accessList;
}

static Tr_exp Tr_Ex(T_exp ex) {
	Tr_exp trEx = checked_malloc(sizeof(*trEx));
	trEx->kind = Tr_ex;
	trEx->u.ex = ex;

	return trEx;
}

static Tr_exp Tr_Nx(T_stm nx) {
	Tr_exp trNx = checked_malloc(sizeof(*trNx));
	trNx->kind = Tr_nx;
	trNx->u.nx = nx;

	return trNx;
}

static Tr_exp Tr_Cx(patchList trues, patchList falses, T_stm stm) {
	Tr_exp trCx = checked_malloc(sizeof(*trCx));
	trCx->kind = Tr_cx;
	trCx->u.cx.trues = trues;
	trCx->u.cx.falses = falses;
	trCx->u.cx.stm = stm;

	return trCx;
}

static patchList PatchList(Temp_label *head, patchList tail) {
	patchList list = checked_malloc(sizeof(*list));
	list->head = head;
	list->tail = tail;

	return list;
}


// outermost level  
Tr_level Tr_outermost(void) {
	// need to create outermost layer 
	if (!outermost) {
		// parent should be null 
		outermost = Tr_newLevel(NULL, Temp_newlabel(), NULL);
	}

	return outermost;
}

// create a new level 
Tr_level Tr_newLevel(Tr_level parent, Temp_label name, U_boolList formals) {
	Tr_level level = checked_malloc(sizeof(*level));
	level->parent = parent;
	level->name = name;
	// add static link 
	level->frame = F_newFrame(name, U_BoolList(TRUE, formals));

	return level;
}

// formals of given level
// static link not included 
Tr_accessList Tr_formals(Tr_level level) {
	Tr_accessList head, tail;
	tail = head = NULL;
	F_accessList fList = F_formals(level->frame);
	if (!fList)
		return NULL;

	// bypass static link 
	fList = fList->tail;

	while(fList) {
		if (!head) {
			// init head and tail 
			head = tail = Tr_AccessList(Tr_Access(level, fList->head), NULL);
		} else {
			// update tail 
			tail->tail = Tr_AccessList(Tr_Access(level, fList->head), NULL);
			tail = tail->tail;
		}
		fList = fList->tail;
	}

	return head;
}

Tr_access Tr_allocLocal(Tr_level level, bool escape) {
	Tr_access access = Tr_Access(level, F_allocLocal(level->frame, escape));

	return access;
}

// do patch for pathclist 
void doPatch(patchList	tList, Temp_label label) {
	for (;tList;tList = tList->tail) {
		*(tList->head) = label;
	}
}

patchList joinPatch(patchList first, patchList second) {
	if (!first) {
		return second;
	}

	// goto end of list 
	for (;first->tail;first = first->tail);
	return first;
}

// get T_exp out of Tr_exp 
static T_exp unEx(Tr_exp e) {
	switch (e->kind) {
		case Tr_ex:
				return	e->u.ex;
		// exp = 1 if stm is true, else exp = 0
		case Tr_cx: {
			Temp_temp r = Temp_newtemp();
			// create label for true and false
			Temp_label t = Temp_newlabel(), f = Temp_newlabel();
			doPatch(e->u.cx.trues, t);
			doPatch(e->u.cx.falses, f);

			return	T_Eseq(T_Move(T_Temp(r), T_Const(1)), 
							T_Eseq(e->u.cx.stm, 
								T_Eseq(T_Label(f),
									T_Eseq(T_Move(T_Temp(r), T_Const(0)),
										T_Eseq(T_Label(t), 
											T_Temp(r))))));


		}
		// Tr_nx return no value,
		// and unEx excutes statement and return 0
        case Tr_nx: 
        	return T_Eseq(e->u.nx, T_Const(0));
	}

	// can't get here 
	assert(0);
}
	
// get T_stm out of Tr_exp 						
static T_stm unNx(Tr_exp e) {
	switch (e->kind) {
		case Tr_nx:
			return e->u.nx;
		// convert T_exp to T_stm 
    	case Tr_ex: 
        	return T_Exp(e->u.ex);
		// first translate to ex, then convert to nx 
		case Tr_cx: {
			Temp_temp r = Temp_newtemp();
			// create label for true and false
			Temp_label t = Temp_newlabel(), f = Temp_newlabel();
			doPatch(e->u.cx.trues, t);
			doPatch(e->u.cx.falses, f);

			return	T_Exp(unEx(e));
		}
	}

	// can't get here
	assert(0);
}

// get struct Cx out of Tr_exp 
static struct Cx unCx(Tr_exp e) {
	switch (e->kind) {
		case Tr_cx:
			return	e->u.cx;
		
    	case Tr_ex: {
    		struct Cx condCx;
    		condCx.trues = NULL;
    		condCx.falses = NULL;
    		// treat the cases of CONST 0 and CONST 1 specially 
    		if (e->u.ex->kind == T_CONST) {
    			condCx.stm = T_Cjump(T_gt, e->u.ex, T_Const(0), NULL, NULL);
    			condCx.trues = PatchList(&(condCx.stm)->u.CJUMP.true, NULL);
    			condCx.falses = PatchList(&(condCx.stm)->u.CJUMP.false, NULL);
    		} else {
    			condCx.stm = T_Exp(e->u.ex);
    		}

    		return condCx;
    	}
		// can't get here 
		case Tr_nx: 
			assert(0);
	}

	// can't get here 
	assert(0);
}

static T_expList unExpList(Tr_expList list) {
	T_expList head, tail;
	head = tail = NULL;
	while (list) {
		if (!head) {
			head = tail = T_ExpList(unEx(list->head), NULL);
			list = list->tail;
		} else {
			tail->tail = T_ExpList(unEx(list->head), NULL);
			tail = tail->tail;
			list = list->tail;
		}
	}

	return head;
}

T_exp Tr_getStaticLink(Tr_level call, Tr_level def) {
	// current frame pointer
	T_exp framePtr = T_Temp(F_Fp());
	// along static link 
	while(call->parent&&call != def) {
		// static link of current level 
		F_access temp = F_formals(call->frame)->head;
		// update frame pointer and level 
		framePtr = F_Exp(temp, framePtr);
		call = call->parent;
	}

	return framePtr;
}


// variables
Tr_exp Tr_SimpleVar(Tr_access access, Tr_level level) {
	// should go along static links 
	return Tr_Ex(F_Exp(access->access, Tr_getStaticLink(level, access->level)));
}

Tr_exp Tr_FieldVar(Tr_exp addr, int offset, int size) {
	return Tr_Ex(T_Mem(T_Binop(T_plus, unEx(addr), T_Const(offset*F_wordSize)), size));
}

Tr_exp Tr_SubscriptVar(Tr_exp addr, Tr_exp index, int size) {
	return Tr_Ex(T_Mem(T_Binop(T_plus, unEx(addr), T_Binop(T_mul, unEx(index), T_Const(size))), size));
}


// expressions 
Tr_exp Tr_NoExp() {
	return Tr_Ex(T_Const(0));
}

Tr_exp Tr_BoolExp(bool b) {
	return Tr_Ex(T_Char(b));
}

Tr_exp Tr_IntExp(int i) {
	return Tr_Ex(T_Const(i));
}

Tr_exp Tr_RealExp(double r) {
	return Tr_Ex(T_Double(r));
}

Tr_exp Tr_CharExp(char c) {
	return Tr_Ex(T_Char(c));
}

// string is translated into array
// default size is 255 
Tr_exp Tr_StringExp(int size, string str) {
	// set length
	Tr_expList init, tail;
	init = tail = Tr_ExpList(Tr_IntExp(size), NULL);
	// move string into array 
	for (int i = 0;i < strlen(str);i++) {
		tail->tail = Tr_ExpList(Tr_CharExp(str[i]), NULL);
		tail = tail->tail;
	}

	// return array after initialization 
	return Tr_ArrayExp(1, size, init);
}

Tr_exp Tr_CallExp(Temp_label label, Tr_level call, Tr_level dec, Tr_expList args) {
	// get static link 
	T_exp staticLink = Tr_getStaticLink(call, dec);
	// tatic link is 1st formal 
	T_expList tArgs = T_ExpList(staticLink, unExpList(args));
	
	return Tr_Ex(T_Call(T_Name(label), tArgs));
}

Tr_exp Tr_OpExp(A_oper op, Tr_exp left, Tr_exp right) {
	T_binOp tOp;
	if (op == A_plusOp) 
		tOp = T_plus;
	else if (op = A_minusOp)
		tOp = T_minus;
	else if (op == A_timesOp)
		tOp = T_mul;
	else if (op == A_divideOp)
		tOp = T_div;

	return Tr_Ex(T_Binop(tOp, unEx(left), unEx(right)));
}

Tr_exp Tr_RecordExp(int* sizes, Tr_expList fields) {
	// start address of record 
	Temp_temp addrTemp = Temp_newtemp();
	int offset = 0;

	T_stm seq = T_Seq(T_Move(T_Mem(T_Binop(T_plus, T_Temp(addrTemp), T_Const(0)), sizes[0]), unEx(fields->head)), NULL);
	offset += sizes[0];

	T_stm tail = seq;

	int i = 1;
	for (fields = fields->tail;fields;fields = fields->tail,i++) {
		tail->u.SEQ.right = T_Seq(T_Move(T_Mem(T_Binop(T_plus, T_Temp(addrTemp), T_Const(offset)), sizes[i]), unEx(fields->head)), NULL);
		tail = tail->u.SEQ.right;
		offset += sizes[i];
	}

	T_stm alloc = T_Move(T_Temp(addrTemp), T_Call(T_Name(Temp_namedlabel("malloc")), 
												T_ExpList(T_Const(offset), NULL)));

	return Tr_Ex(T_Eseq(T_Seq(alloc, seq), T_Temp(addrTemp)));
}

Tr_exp Tr_ArrayExp(int size, int totalLen, Tr_expList initList) {
	// init contents of array 
	Temp_temp addrTemp = Temp_newtemp();
	T_stm alloc = T_Move(T_Temp(addrTemp), T_Call(T_Name(Temp_namedlabel("malloc")), 
												T_ExpList(T_Const(totalLen*size), NULL)));

	T_stm seq = T_Seq(T_Move(T_Mem(T_Binop(T_plus, T_Temp(addrTemp), T_Const(0)), size), unEx(initList->head)), NULL);

	T_stm tail = seq;

	int i = 1;
	for (initList = initList->tail;initList;initList = initList->tail,i++) {
		tail->u.SEQ.right = T_Seq(T_Move(T_Mem(T_Binop(T_plus, T_Temp(addrTemp), T_Const(i*size)), size), unEx(initList->head)), NULL);
		tail = tail->u.SEQ.right;
	}

	return Tr_Ex(T_Eseq(T_Seq(alloc, seq), T_Temp(addrTemp)));
}

Tr_exp Tr_AssignExp(Tr_exp left, Tr_exp right) {
	return Tr_Nx(T_Move(unEx(left), unEx(right)));
}

Tr_exp Tr_SeqExp(Tr_expList list) {
	if (!list)
		return NULL;

	/*T_stm seq, tail;
	seq = tail = T_Seq (unNx(list->head), NULL);

	for (list = list->tail;list;list = list->tail) {
		tail->u.SEQ.right = unNx(list->head);
		tail = tail->u.SEQ.right;
	}*/
	T_stm seq = unNx(list->head);
	for (list = list->tail; list; list = list->tail) {
		seq = T_Seq(unNx(list->head), seq);
	}

	return Tr_Nx(seq);
}

Tr_exp Tr_IfExp(Tr_exp test, Tr_exp then, Tr_exp elsee) {
	Temp_label tLabel = Temp_newlabel();
	Temp_label fLabel = Temp_newlabel();

	T_stm thenStm = NULL;
	T_stm elseStm = NULL;
	struct Cx condition = unCx(test);

	doPatch(condition.trues, tLabel);
	doPatch(condition.falses, fLabel);

	switch(then->kind) {
		case Tr_ex: 
			thenStm = T_Exp(then->u.ex);
			break;
		case Tr_nx:
			thenStm = then->u.nx;
			break;
		case Tr_cx:
			thenStm = then->u.cx.stm;
			break;
	}

	// with no else block 
	if (!elsee) {
		return Tr_Nx(T_Seq(condition.stm, 
						T_Seq(T_Label(tLabel),
							T_Seq(thenStm, T_Label(fLabel)))));	
	} else {
		// jump to outer after executing true statement 
		Temp_label jLabel = Temp_newlabel();
		T_stm jumpStm = T_Jump(T_Name(jLabel), Temp_LabelList(jLabel, NULL));

		switch(elsee->kind) {
			case Tr_ex: 
				elseStm = T_Exp(elsee->u.ex);
				break;
			case Tr_nx:
				elseStm = elsee->u.nx;
				break;
			case Tr_cx:
				elseStm = elsee->u.cx.stm;
				break;
		}

		return Tr_Nx(T_Seq(condition.stm,
						T_Seq(T_Label(tLabel),
							T_Seq(thenStm, 
								T_Seq(jumpStm, 
									T_Seq(T_Label(fLabel),
										T_Seq(elseStm,
											T_Label(jLabel))))))));
	}
	
}

Tr_exp Tr_WhileExp(Tr_exp test, Tr_exp body) {
	Temp_label testLabel = Temp_newlabel();
	Temp_label bodyLabel = Temp_newlabel();
	Temp_label doneLabel = Temp_newlabel();

	return Tr_Ex(T_Eseq(T_Label(testLabel), 
					T_Eseq(T_Cjump(T_eq, unEx(test), T_Const(0), doneLabel, bodyLabel),
						T_Eseq(T_Label(bodyLabel),
							T_Eseq(unNx(body),
								T_Eseq(T_Jump(T_Name(testLabel), Temp_LabelList(testLabel, NULL)),
									T_Eseq(T_Label(doneLabel), T_Const(0))))))));
}

Tr_exp Tr_RepeatExp(Tr_exp body, Tr_exp test) {
	Temp_label testLabel = Temp_newlabel();
	Temp_label bodyLabel = Temp_newlabel();
	Temp_label doneLabel = Temp_newlabel();

	return Tr_Ex(T_Eseq(T_Label(bodyLabel),
					T_Eseq(unNx(body),
						T_Eseq(T_Cjump(T_eq, unEx(test), T_Const(0), bodyLabel, doneLabel),
							T_Eseq(T_Label(doneLabel), T_Const(0))))));

}

Tr_exp Tr_RelExp(A_oper op, Tr_exp left, Tr_exp right) {
	T_relOp tOp;
	if (op == A_eqOp) 
		tOp = T_eq;
	else if (op == A_neqOp) 
		tOp = T_ne;
	else if (op == A_ltOp)
		tOp = T_lt;
	else if (op == A_leOp)
		tOp = T_le;
	else if (op == A_gtOp)
		tOp = T_gt;
	else if (op == A_geOp)
		tOp = T_ge;

	T_stm stm = T_Cjump(tOp, unEx(left), unEx(right), NULL, NULL);

	patchList t = PatchList(&stm->u.CJUMP.true, NULL);
	patchList f = PatchList(&stm->u.CJUMP.false, NULL);

	return Tr_Cx(t, f, stm);
}

Tr_exp Tr_StringRelExp(A_oper op, Tr_exp left, Tr_exp right) {
	int n = 255;
	T_exp ret = T_Call(T_Name(Temp_namedlabel("stringEqual")), 
												T_ExpList(T_Const((n-1)*F_wordSize), NULL));
	int retVal = (op == A_eqOp&&!ret->u.CONST)||(op == A_neqOp&&ret->u.CONST)
				||(op == A_ltOp&&ret->u.CONST<0)||(op == A_leOp&&ret->u.CONST<=0)
				||(op == A_gtOp&&ret->u.CONST>0)||(op == A_geOp&&ret->u.CONST>=0);

	return Tr_Ex(T_Const(retVal));
}

Tr_exp Tr_GotoExp(Tr_exp pos) {
	Temp_label name = unEx(pos)->u.NAME;
	return Tr_Nx(T_Jump(T_Name(name), Temp_LabelList(name, NULL)));
}

Tr_exp Tr_BreakExp(Tr_exp pos) {
	Temp_label name = unEx(pos)->u.NAME;
	return Tr_Nx(T_Jump(T_Name(name), Temp_LabelList(name, NULL)));
}	

Tr_expList Tr_ExpList(Tr_exp head, Tr_expList tail) {
	Tr_expList list = checked_malloc(sizeof(*list));
	list->head = head;
	list->tail = tail;
	return list;
}

void Tr_procEntryExit(Tr_level level, Tr_exp body, Tr_accessList formals) {
	F_frag procFrag = F_ProcFrag(unNx(body), level->frame);
	procFragList = F_FragList(procFrag, procFragList);
}

F_fragList Tr_getResult() {
	return procFragList;
}