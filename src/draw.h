#ifndef DRAW_H
#define DRAW_H

// step between our Y axis
#define WIDTH 80
#define HEIGHT 25

#define STEP (double)(2.0 / HEIGHT)
// our range to correct our function output
#define INFELICITY STEP / 2.0

#include <math.h>
#include <stdio.h>

#include "calculate.h"

void draw_graph(char *postfix, int *everything_is_fine);

#endif