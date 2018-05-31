// tree root from paring 
#include "absyn.h"
#include "prabsyn.h"
#include "errormsg.h"
#include "semant.h"
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
		parse("test/2.pas");
	else 
	    parse(argv[1]);
    fprintf(out, "\n---Abstract Syntax Tree---\n");
    pr_exp(out, A_synTreeRoot, 0);

    fprintf(out, "\n---IR Tree---\n");
    F_fragList fragList = transProg(A_synTreeRoot);


}