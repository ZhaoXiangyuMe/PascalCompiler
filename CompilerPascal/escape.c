#include "escape.h"
#include "symbol.h"
#include "util.h"
#include "absyn.h"

typedef struct escapeEntry_ *escapeEntry;
struct escapeEntry_ {
    int depth;
    bool* escape;
};
static escapeEntry EscapeEntry(int depth, bool *escape) {
    escapeEntry entry = checked_malloc(sizeof(*entry));
    entry->depth = depth;
    entry->escape = escape;
    *escape = FALSE;
	return entry;
}

static S_table escapeEnv;

static void traverseExp(S_table env, int depth, A_exp e);
static void traverseDec(S_table env, int depth, A_dec d);
static void traverseVar(S_table env, int depth, A_var v);

// static functions 
static void traverseExp(S_table env, int depth, A_exp e) {
    // endpoint of recursing 
    if (!e) {
        return;
    }
    switch (e->kind) {
        case A_varExp:
            traverseVar(env, depth, e->u.var);
            break;
        case A_intExp:
        case A_realExp:
        case A_charExp:
        case A_boolExp:
        case A_stringExp:
            break;
        case A_callExp:
            for (A_expList args = e->u.call.args;args;args = args->tail) {
                traverseExp(env, depth, args->head);
            }
            break;
        case A_opExp:
            traverseExp(env, depth, e->u.op.left);
            traverseExp(env, depth, e->u.op.right);
            break;
        case A_recordExp:
            for (A_efieldList fields = e->u.record.fields;fields;fields = fields->tail) {
                traverseExp(env, depth, fields->head->exp);
            }
            break;
        case A_seqExp:
            for (A_expList list = e->u.seq;list;list = list->tail) {
                traverseExp(env, depth, list->head);
            }
            break;
        case A_assignExp:
            traverseVar(env, depth, e->u.assign.var);
            traverseExp(env, depth, e->u.assign.exp);
            break;
        case A_ifExp:
            traverseExp(env, depth, e->u.iff.test);
            traverseExp(env, depth, e->u.iff.then);
            traverseExp(env, depth, e->u.iff.elsee);
            break;
        case A_whileExp:
            traverseExp(env, depth, e->u.whilee.test);
            traverseExp(env, depth, e->u.whilee.body);
            break;
        case A_repeatExp:
            traverseExp(env, depth, e->u.repeatt.body);
            traverseExp(env, depth, e->u.repeatt.test);
            break;
        case A_caseExp:
            traverseExp(env, depth, e->u.casee.exp);
            for (A_expList list = e->u.casee.valList;list;list = list->tail) {
                traverseExp(env, depth, list->head);
            }
            break;
        case A_caseValExp:
            traverseExp(env, depth, e->u.caseval.val);
            traverseExp(env, depth, e->u.caseval.action);
            break;
        case A_gotoExp:
            traverseExp(env, depth, e->u.gotoo.label);
            break;
        case A_letExp:
            S_beginScope(env);
            for (A_decList decs = e->u.let.decs;decs;decs = decs->tail) {
                traverseDec(env, depth, decs->head);
            }
            traverseExp(env, depth, e->u.let.body);
            S_endScope(env,3);
            break;
        case A_arrayExp:
            traverseExp(env, depth, e->u.array.size);
            traverseExp(env, depth, e->u.array.init);
            break;
        default:
            assert(0);
    }   
}

static void traverseDec(S_table env, int depth, A_dec d) {
    if (!d) 
        return;
    A_fundec func;
    switch (d->kind) {
        case A_functionDec: {
            A_fundecList funcList = d->u.function;
            for (;funcList;funcList = funcList->tail) {
                func = funcList->head; 
                // go deepper in depth 
                depth++;
                S_beginScope(env);
                // check for params 
                A_fieldList params = func->params;
                for (;params;params = params->tail) {
                    A_field param = params->head;
                    S_enter(env, param->name, EscapeEntry(depth, &(param->escape)));
                }
                traverseExp(env, depth, func->body);
                S_endScope(env, 3);
                depth--;
            }
            break;
        }
        case A_constDec:
            S_enter(env, d->u.constt.constt, EscapeEntry(depth, &(d->u.constt.escape)));
            break;
        case A_varDec:
            S_enter(env, d->u.var.var, EscapeEntry(depth, &(d->u.var.escape)));
            traverseExp(env, depth, d->u.var.init);
            break;
        case A_typeDec:
            // don't care about escape
            break;
        default:
            // can't get here 
            assert(0);
    }

    return;
}

static void traverseVar(S_table env, int depth, A_var v) {
    if (!v)
        return;
    switch (v->kind) {
        case A_simpleVar: {
            // look up in table 
            escapeEntry entry = (escapeEntry)S_look(env, v->u.simple);
            // used at depth > decalaration depth 
            // set escape to true 
            if (entry&&depth>entry->depth) {
                *(entry->escape) = TRUE;
            }
            break;
        }
        case A_fieldVar:
            traverseVar(env, depth, v->u.field.var);
            break;
        case A_subscriptVar:
            traverseVar(env, depth, v->u.subscript.var);
            traverseExp(env, depth, v->u.subscript.exp);
            break;
        default:
            assert(0);
    }
}

void Esc_findEscape(A_exp exp) {
    int depth = 0;
    escapeEnv = S_empty();
    traverseExp(escapeEnv, depth, exp);
}