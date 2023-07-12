#ifndef parseH
#define parseH

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

// блок констант
#define SIZE 50
#define SIN 's'
#define sinF 1
#define COS 'c'
#define cosF 2
#define TG 't'
#define tanF 3
#define CTG 'g'
#define ctgF 4
#define SQRT 'q'
#define sqrtF 5
#define LN 'l'
#define lnF 6
#define PLUS '+'
#define MINUS '-'
#define MUL '*'
#define DIV '/'
#define unaryMinusF 7
#define UMINUS '~'

void validateOpers(char *stack);

// reads our input via scanf string
char *inputArr(int *everythingIsFine);
// calculate operator weight depending on its state
int opWeight(char op);
// check if our char is operator
int isOp(char ch);
// make polish notation string
char *convert(char *input, int len, int *everythingIsFine);
// same but is func
int isFunc(const char *input, int i, int len);
// decomposize operators
void pushAllPossibleOp(int func, char stack[50], int *top, char *input, int *i);
int sCount(char *str);
int checkOpers(char *str);

#endif