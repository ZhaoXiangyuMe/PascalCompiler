#ifndef UTIL_H_
#define UTIL_H_
#include <assert.h>

typedef char *string;
typedef char bool;

#define TRUE 1
#define FALSE 0

void *checked_malloc(int);
string String(char *);

typedef struct U_boolList_ *U_boolList;
struct U_boolList_ {bool head; U_boolList tail;};
U_boolList U_BoolList(bool head, U_boolList tail);

typedef struct U_intList_ *U_intList;
struct U_intList_ {int head; U_intList tail;};
U_intList U_IntList(int head, U_intList tail);
#endif
