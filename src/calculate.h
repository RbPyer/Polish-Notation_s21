#ifndef calculateH
#define calculateH

#include <math.h>
#include <stdlib.h>

#include "parse.h"
#include "stack.h"

double calculate(char *postfix, double x, int *everythingIsFine);
int makeSolution(char *postfix, double num1, double num2, double *result, double *nums, int *top);

#endif