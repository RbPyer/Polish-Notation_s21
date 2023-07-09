#ifndef drawH
#define drawH

// step between our Y axis
#define WIDTH 80
#define HEIGHT 25

#define STEP (double)(2.0 / HEIGHT)
// our range to correct our function output
#define INFELICITY STEP / 2.0

#include <math.h>
#include <stdio.h>

#include "calculate.h"

void drawGraph(char *postfix, int *everythingIsFine);
void delimiter();

#endif