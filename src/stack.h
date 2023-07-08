#ifndef STACK_H
#define STACK_H

void push_op(char *stack, int *top, char x);
char pop_op(const char *stack, int *top);
void push_num(double *stack, int *top, double x);
double pop_num(const double *stack, int *top);

#endif