#include "stack.h"

void push_op(char *stack, int *top, char x) {
    *top = *top + 1;
    stack[*top] = x;
}

char pop_op(const char *stack, int *top) {
    char x = stack[*top];
    *top = *top - 1;
    return x;
}

void push_num(double *stack, int *top, double x) {
    *top = *top + 1;
    stack[*top] = x;
}

double pop_num(const double *stack, int *top) {
    double x = stack[*top];
    *top = *top - 1;
    return x;
}