#ifndef stackH
#define stackH

void pushOp(char *stack, int *top, char x);
char popOp(const char *stack, int *top);
void pushNum(double *stack, int *top, double x);
double popNum(const double *stack, int *top);

#endif