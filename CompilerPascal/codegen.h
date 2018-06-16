#ifndef CODEGEN_H_
#define CODEGEN_H_
#include "assem.h"
#include "frame.h"
#include "tree.h"

AS_instrList F_codegen(F_frame frame, T_stmList stmList);
static Temp_temp munchExp(T_exp e);
static void munchStm(T_stm s);
static Temp_tempList munchArgs(int i, T_expList args);
#endif