#include "stack.h"

void pushOp(char *stack, int *top, char x) {
    *top = *top + 1;
    stack[*top] = x;
}

char popOp(const char *stack, int *top) {
    char x = stack[*top];
    *top = *top - 1;
    return x;
}

void pushNum(double *stack, int *top, double x) {
    *top = *top + 1;
    stack[*top] = x;
}

double popNum(const double *stack, int *top) {
    double x = stack[*top];
    *top = *top - 1;
    return x;
}