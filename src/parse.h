#ifndef PARSE_H
#define PARSE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

// блок констант
#define SIZE 200
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

// reads our input via scanf string
char *input_arr();
// calculate operator weight depending on its state
int op_weigth(char op);
// check if our char is operator
int is_op(char ch);
// make polish notation string
char *convert(char *input, int len, int *everything_is_fine);
// same but is func
int is_func(const char *input, int i, int len);
// decomposize operators
void push_all_possible_op(int func, char stack[50], int *top, char *input, int *i);

#endif