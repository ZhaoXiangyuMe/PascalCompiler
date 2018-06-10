// tree root from paring 
#include "absyn.h"
#include "prabsyn.h"
#include "errormsg.h"
#include "semant.h"
#include "printtree.h"
#include "drawtree.h"
#include "canon.h"
#include "escape.h"
#include <stdio.h>

extern A_exp A_synTreeRoot;
extern int yyparse(void);

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
		parse("test/3.pas");
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
        if (!head) {
            tail = head = T_StmList(fragList->head->u.proc.body, NULL);
        } else {
            tail->tail = T_StmList(fragList->head->u.proc.body, NULL);
            tail = tail->tail;
        }
    }

     /* T_stmList stmList = C_linearize(fragList->head->u.proc.body);
    printStmList(stdout, stmList);

    stmList = C_traceSchedule(C_basicBlocks(stmList));*/
    fprintf(stdout, "\n------\n");
    printStmList(stdout, head); 
    FILE* fileout = fopen("IRTree.dot", "w");
    if (!fileout) 
        return 0;
    fprintf(stdout, "\n------\n");
    drawStmList(fileout, head);
    fclose(fileout);
	
	while (1) {
		int r = 1;
	}
	return 0;
}