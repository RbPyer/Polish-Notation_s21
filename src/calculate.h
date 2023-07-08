#ifndef CALCULATE_H
#define CALCULATE_H

#include <math.h>
#include <stdlib.h>

#include "stack.h"

double calculate(char *postfix, double x, int *everything_is_fine);
int make_decision(char *postfix, double num1, double num2, double *result, double *nums, int *top);

#endif