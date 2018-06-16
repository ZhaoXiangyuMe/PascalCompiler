// tree root from paring 
#include "absyn.h"
#include "prabsyn.h"
#include "errormsg.h"
#include "semant.h"
#include "printtree.h"
#include "drawtree.h"
#include "canon.h"
#include "escape.h"
#include "frame.h"
#include "assem.h"
#include <stdio.h>

extern A_exp A_synTreeRoot;
extern Temp_map F_tempMap;
extern int yyparse(void);
static void doProc(FILE* out, F_frame frame, T_stm body) {
    // linearize and trace schedule 
    T_stmList stmList = C_linearize(body);
    stmList = C_traceSchedule(C_basicBlocks(stmList));

    fprintf(stdout, "\n------\n");
    printStmList(stdout, stmList); 
    FILE* fileout = fopen("IRTree.dot", "w+");
    if (!fileout) 
        return 0;
    fprintf(stdout, "\n------\n");
    drawStmList(fileout, stmList);
    fclose(fileout);

    AS_proc proc;
    AS_instrList iList;
    iList = F_codegen(frame, stmList);

    fprintf(out, "BEGIN %s\n", Temp_labelstring(F_name(frame)));
    AS_printInstrList(out, iList, Temp_layerMap(F_tempMap,Temp_name()));
    fprintf(out, "END %s\n\n", Temp_labelstring(F_name(frame)));
}

int parse(string fname) {
    // reset filename and line number 
    // open given file in the same time 
    EM_reset(fname);
    int res = yyparse();
    if (!res) {
    } else {
        printf("Syntax not passed! Please check your syntax.\n");
    }
    // restore stdin
    fclose(stdin);
    return res;
}

int main(int argc, char* argv[]) {
    FILE* out = stdout;
	if (argc < 2)
		parse("test/1.pas");
	else 
	    parse(argv[1]);
    fprintf(out, "\n---Abstract Syntax Tree---\n");
    pr_exp(out, A_synTreeRoot, 0);
    // find escape of variables 
    Esc_findEscape(A_synTreeRoot);

    fprintf(out, "\n---IR Tree---\n");
    F_fragList fragList = transProg(A_synTreeRoot);
    T_stmList head = NULL, tail = NULL;

    for (;fragList;fragList = fragList->tail) {
        doProc(out, fragList->head->u.proc.frame, fragList->head->u.proc.body);
    }
   
	
	while (1) {
		int r = 1;
	}
	return 0;
}