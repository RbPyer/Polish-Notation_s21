#include "parse.h"

void validateOpers(char *stack) {
    int type = 1;
    for (int i = 0; stack[i] != '\0'; i++) {
        if (isOp(stack[i])) {
            if (type && stack[i] == MINUS) {
                stack[i] = UMINUS;
            }
            type = 1;
        }
        if (stack[i] == 'x' || (stack[i] >= '0' && stack[i] <= '9')) {
            type = 0;
        }
    }
}

char *inputArr(int *everythingIsFine) {
    char *input = malloc(sizeof(char) * SIZE);
    char iter = '_';
    int ind = 0;
    while (iter != '\n' && *everythingIsFine) {
        if (ind > SIZE) {
            *everythingIsFine = 0;
        } else {
            iter = getc(stdin);
            if (iter != ' ' && iter != '\n') {
                input[ind++] = iter;
            }
        }
    }
    input[ind] = '\0';
    validateOpers(input);
    return input;
}

// приоритет операций
int opWeight(char op) {
    int result = -1;
    switch (op) {
        case PLUS:
        case MINUS:
            result = 1;
            break;
        case MUL:
        case DIV:
            result = 2;
            break;
        case SIN:   // sin
        case COS:   // cos
        case TG:    // tan
        case CTG:   // ctg
        case SQRT:  // sqrt
        case LN:    // ln
        case UMINUS:
            result = 3;
            break;
    }
    return result;
}

// проверка на оператор
int isOp(char ch) { return ch == PLUS || ch == MINUS || ch == MUL || ch == DIV; }

// проверка на функцию
int isFunc(const char *input, int i, int len) {
    int result = 0;

    if (i + 2 < len && input[i] == 's' && input[i + 1] == 'i' && input[i + 2] == 'n') result = sinF;
    if (i + 2 < len && input[i] == 'c' && input[i + 1] == 'o' && input[i + 2] == 's') result = cosF;
    if (i + 2 < len && input[i] == 't' && input[i + 1] == 'a' && input[i + 2] == 'n') result = tanF;
    if (i + 2 < len && input[i] == 'c' && input[i + 1] == 't' && input[i + 2] == 'g') result = ctgF;
    if (i + 3 < len && input[i] == 's' && input[i + 1] == 'q' && input[i + 2] == 'r' && input[i + 3] == 't')
        result = sqrtF;
    if (i + 1 < len && input[i] == 'l' && input[i + 1] == 'n') result = lnF;
    if (i < len && input[i] == '~') result = unaryMinusF;
    return result;
}

// make polish notation string
char *convert(char *input, int len, int *everythingIsFine) {
    char *result = malloc((len * 2) * sizeof(char)), stack[50];
    int top = -1, j, i, flag = 0;
    for (i = 0, j = 0; i < len && *(everythingIsFine); i++) {
        if ((input[i] >= '0' && input[i] <= '9') || input[i] == 'x') {
            while ((input[i] >= '0' && (int)input[i] <= '9') || input[i] == '.' || (input[i] == 'x')) {
                result[j++] = input[i];
                flag = 1;
                i++;
            }
            i--;
        } else if (input[i] == '(') {
            pushOp(stack, &top, input[i]);
        } else if (input[i] == ')') {
            while (top > -1 && stack[top] != '(') {
                result[j++] = popOp(stack, &top);
                result[j++] = ' ';
            }
            if (top > -1 && stack[top] != '(')
                *(everythingIsFine) = 0;
            else
                top--;
        } else if (isOp(input[i]) || isFunc(input, i, len)) {
            int func = isFunc(input, i, len);
            while (!func && top > -1 && opWeight(stack[top]) >= opWeight(input[i])) {
                result[j++] = popOp(stack, &top);
                result[j++] = ' ';
            }
            pushAllPossibleOp(func, stack, &top, input, &i);
        } else
            *(everythingIsFine) = 0;
        if (flag) {
            result[j++] = ' ';
            flag = 0;
        }
    }
    while (top > -1) {
        result[j++] = popOp(stack, &top);
        result[j++] = ' ';
    }
    result[j] = '\0';
    return result;
}

// обработка операций и их пуш
void pushAllPossibleOp(int func, char stack[50], int *top, char *input, int *i) {
    switch (func) {
        case 0:
            pushOp(stack, top, input[*i]);
            break;
        case 1:
            pushOp(stack, top, SIN);
            *i += 2;
            break;
        case 2:
            pushOp(stack, top, COS);
            *i += 2;
            break;
        case 3:
            pushOp(stack, top, TG);
            *i += 2;
            break;
        case 4:
            pushOp(stack, top, CTG);
            *i += 2;
            break;
        case 5:
            pushOp(stack, top, SQRT);
            *i += 3;
            break;
        case 6:
            pushOp(stack, top, LN);
            *i += 1;
            break;
        case 7:
            pushOp(stack, top, UMINUS);
            break;
    }
}

int sCount(char *str) {
    int flag = 1;
    int lcount = 0, rcount = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') {
            lcount++;
        } else if (str[i] == ')') {
            rcount++;
            if (str[i + 1] == '(') {
                flag = 0;
            }
        }
    }
    return flag && lcount == rcount;
}

int checkOpers(char *str) {
    int flag = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isOp(str[i]) == 1 || str[i] == '~') {
            if (isOp(str[i + 1]) == 1 || str[i + 1] == '~') {
                flag = 0;
                break;
            }
        }
    }
    return flag;
}
