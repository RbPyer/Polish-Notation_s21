#include "parse.h"

// reads our input via scanf string
char *input_arr() {
    char *input = malloc(sizeof(char) * SIZE);
    scanf("%200s", input);  // считываем 200 символов
    return input;
}

// calculate operator weight depending on its state
int op_weigth(char op) {
    int result = -1;
    switch (op) {
        case '+':
        case '-':
            result = 1;
            break;
        case '*':
        case '/':
            result = 2;
            break;
        case 's':  // sin
        case 'c':  // cos
        case 't':  // tan
        case 'g':  // ctg
        case 'q':  // sqrt
        case 'l':  // ln
            result = 3;
            break;
    }
    return result;
}

// check if our char is a operator
int is_op(char ch) { return (ch == PLUS || ch == MINUS || ch == MUL || ch == DIV); }

// same but is a func
int is_func(const char *input, int i, int len) {
    int result = 0;
    // reading further than just a symbol if it matches our pattern below
    if (i + 2 < len && input[i] == 's' && input[i + 1] == 'i' && input[i + 2] == 'n') result = sinF;
    if (i + 2 < len && input[i] == 'c' && input[i + 1] == 'o' && input[i + 2] == 's') result = cosF;
    if (i + 2 < len && input[i] == 't' && input[i + 1] == 'a' && input[i + 2] == 'n') result = tanF;
    if (i + 2 < len && input[i] == 'c' && input[i + 1] == 't' && input[i + 2] == 'g') result = ctgF;
    if (i + 3 < len && input[i] == 's' && input[i + 1] == 'q' && input[i + 2] == 'r' && input[i + 3] == 't')
        result = sqrtF;
    if (i + 1 < len && input[i] == 'l' && input[i + 1] == 'n') result = lnF;
    return result;
}

// make polish notation string
char *convert(char *input, int len, int *everything_is_fine) {
    char *result = malloc((len * 2) * sizeof(char));
    char stack[50];
    // top is counting nodes after head. -1 is empty stack
    int top = -1, j, i, flag = 0;
    for (i = 0, j = 0; i < len && *(everything_is_fine); i++) {
        // range 48-57 our nums, 120 is x
        if ((input[i] >= '0' && input[i] <= '9') || input[i] == 'x') {
            // '.' is for double check
            while ((input[i] >= '0' && (int)input[i] <= '9') || input[i] == '.' || (input[i] == 'x')) {
                result[j++] = input[i];
                flag = 1;
                i++;
            }
            i--;
        } else if (input[i] == '(')
            push_op(stack, &top, input[i]);
        else if (input[i] == ')') {
            while (top > -1 && stack[top] != '(') {
                result[j++] = pop_op(stack, &top);
                result[j++] = ' ';
            }
            if (top > -1 && stack[top] != '(')
                *(everything_is_fine) = 0;
            else
                top--;
            // check if our symbol is a operator or a func
        } else if (is_op(input[i]) || is_func(input, i, len)) {
            int func = is_func(input, i, len);
            while (!func && top > -1 && op_weigth(stack[top]) >= op_weigth(input[i])) {
                result[j++] = pop_op(stack, &top);
                result[j++] = ' ';
            }
            push_all_possible_op(func, stack, &top, input, &i);
        } else
            *(everything_is_fine) = 0;
        if (flag) {
            result[j++] = ' ';
            flag = 0;
        }
    }

    while (top > -1) {
        result[j++] = pop_op(stack, &top);
        result[j++] = ' ';
    }
    result[j] = '\0';

    return result;
}

//
// refactor and gather all push ops in one function
void push_all_possible_op(int func, char stack[50], int *top, char *input, int *i) {
    switch (func) {
        case 0:
            push_op(stack, top, input[*i]);
            break;
        case 1:
            push_op(stack, top, SIN);
            *i += 2;
            break;
        case 2:
            push_op(stack, top, COS);
            *i += 2;
            break;
        case 3:
            push_op(stack, top, TG);
            *i += 2;
            break;
        case 4:
            push_op(stack, top, CTG);
            *i += 2;
            break;
        case 5:
            push_op(stack, top, SQRT);
            *i += 3;
            break;
        case 6:
            push_op(stack, top, LN);
            *i += 1;
            break;
    }
}