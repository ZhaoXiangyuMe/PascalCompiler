#ifndef FRAME_H
#define FRAME_H
#include "util.h"
#include "temp.h"
#include "tree.h"

typedef struct F_access_ *F_access;
typedef struct F_accessList_ *F_accessList;
typedef struct F_frame_ *F_frame;

struct F_accessList_ {
    F_access head;
    F_accessList tail;
};

typedef struct T_exp_ * T_exp;

typedef struct F_frag_ *F_frag;
struct F_frag_ {
    enum {F_stringFrag, F_procFrag} kind;
    union {
        struct {
            Temp_label label;
            string str;
        } stringg;
        struct {
            T_stm body;
            F_frame frame;
        } proc;
    } u;
};

typedef struct F_fragList_ *F_fragList;
struct F_fragList_ {
    F_frag head;
    F_fragList tail;
};


Temp_temp F_Fp(void);
extern const int F_wordSize;	

F_accessList F_AccessList(F_access head, F_accessList tail);
F_frame F_newFrame(Temp_label name, U_boolList formals, U_intList formalsSizes);
Temp_label F_name(F_frame f);
F_accessList F_formals(F_frame f);
F_access F_allocLocal(F_frame f, bool escape, int size);

// return address of access 
// T_exp is address of stack frame 
T_exp F_Exp(F_access access, T_exp framePtr);

// save and restore callee-save registers
// and part of view shift 
// in entry and exit of procedure 
T_stm F_procEntryExi1(F_frame frame, T_stm stm);

F_frag F_StringFrag(Temp_label label, string str);
F_frag F_ProcFrag(T_stm body, F_frame frame);

F_fragList F_FragList(F_frag head, F_fragList tail);
#endif