#include "frame.h"
#include "util.h"

const int F_wordSize = 4;
Temp_map F_tempMap = NULL;
static Temp_temp F_fp = NULL;
static Temp_temp F_sp = NULL;
static Temp_temp F_rv = NULL;
static Temp_temp F_ra = NULL;

struct  F_access_ {
    enum {inFrame, inReg} kind;
    union {
		struct { int offset; int size; } frame;/*in frame, offset from fp, occupy size in memory*/
        Temp_temp reg; /*in reg, reg number*/
    } u;
};

struct F_frame_ {
    Temp_label name;
    F_accessList formals;
    F_accessList formalsTail;
    int ptrPos; /*local variables allocated in frame so far*/ 
};

// in frame
static F_access InFrame(int offset, int size) {
    F_access access = checked_malloc(sizeof(*access));
    access->kind = inFrame;
    access->u.frame.offset = offset;
    access->u.frame.size = size;
    return access;
}

// in register 
static F_access InReg(Temp_temp reg) {
    F_access access = checked_malloc(sizeof(*access));
    access->kind = inReg;
    access->u.reg = reg;
    return access;
}

F_accessList F_AccessList(F_access head, F_accessList tail) {
    F_accessList accessList = checked_malloc(sizeof(*accessList));
    accessList->head = head;
    accessList->tail = tail;
    return accessList;
}


F_frame F_newFrame(Temp_label name, U_boolList formals, U_intList formalsSizes) {
    F_frame f = checked_malloc(sizeof(*f));
    f->name = name;
    f->formalsTail = f->formals = NULL;
	
    for (;formals, formalsSizes;formals = formals->tail, formalsSizes = formalsSizes->tail) {
        F_allocLocal(f, formals->head, formalsSizes->head);
    }

	return f;
}

Temp_label F_name(F_frame f) {
    return f->name;
}

F_accessList F_formals(F_frame f) {
    // should implement view shift 
    return f->formals;
}

F_access F_allocLocal(F_frame f, bool escape, int size) {
	// only calculate num of variables in frame 
    if (escape||size > 4) {
        // allocate in frame
        f->ptrPos -= size;
        F_access frameLocal = InFrame(f->ptrPos, size);
        if (!(f->formals)) {
            f->formalsTail = f->formals = F_AccessList(frameLocal, NULL);
        } else {
            f->formalsTail->tail = F_AccessList(frameLocal, NULL);
            f->formalsTail = f->formalsTail->tail;
        }
		
        return frameLocal;
    }   
    else {
        // allocate in register
        F_access regLocal = InReg(Temp_newtemp());
        if (!(f->formals)) {
            f->formalsTail = f->formals = F_AccessList(regLocal,NULL);
        } else {
            f->formalsTail->tail = F_AccessList(regLocal, NULL);
            f->formalsTail = f->formalsTail->tail;
        }

        return regLocal;
    }
}

Temp_temp F_Fp(void) {
    if (F_fp) {
        return F_fp;
    } 

    F_fp = Temp_newtemp();
   // Temp_enter(F_tempMap, F_fp, "eax");

    return F_fp;
}

Temp_temp F_Sp(void) {
    if (F_sp) {
        return F_sp;
    } 

    F_sp = Temp_newtemp();
    Temp_enter(F_tempMap, F_sp, "ebx");

    return F_sp;
}

Temp_temp F_Rv(void) {
    if (F_rv) {
        return F_rv;
    } 

    F_rv = Temp_newtemp();
    Temp_enter(F_tempMap, F_rv, "ebx");

    return F_rv;
}

Temp_temp F_Ra(void) {
    if (F_ra) {
        return F_ra;
    } 

    F_ra = Temp_newtemp();
    Temp_enter(F_tempMap, F_ra, "ebx");

    return F_ra;
}

T_exp F_Exp(F_access access, T_exp framePtr) {
    if (access->kind == inFrame) 
        // in frame, return T_mem  
        return T_Mem(T_Binop(T_plus, framePtr, T_Const(access->u.frame.offset)), access->u.frame.size);
    else  
        // in register, return T_temp
        return T_Temp(access->u.reg);
}

T_stm F_procEntryExi1(F_frame frame, T_stm stm) {
    return NULL;
}

F_frag F_StringFrag(Temp_label label, string str) {}

F_frag F_ProcFrag(T_stm body, F_frame frame) {
    F_frag frag = checked_malloc(sizeof(*frag));
    frag->kind = F_procFrag;
    frag->u.proc.body = body;
    frag->u.proc.frame = frame;

    return frag;
}

F_fragList F_FragList(F_frag head, F_fragList tail) {
    F_fragList fragList = checked_malloc(sizeof(*fragList));
    fragList->head = head;
    fragList->tail = tail;

    return fragList;
}