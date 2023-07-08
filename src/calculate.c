#include "calculate.h"

double calculate(char *postfix, double x, int *everythingIsFine) {
    double nums[80];
    int top = -1, isDouble = 0;
    double num1, num2, result;
    while (*postfix != '\0' && *everythingIsFine) {
        if (*postfix == 'x') {
            pushNum(nums, &top, x);
        } else if (*postfix >= '0' && *postfix <= '9') {
            double currentNum = 0;

            while (*postfix != 'x' && *postfix != ' ') {
                if (*postfix != '.' && !isDouble) {
                    currentNum = currentNum * 10 + (double)(*postfix - 48);
                    postfix++;
                } else if (*postfix == '.' && !isDouble) {
                    postfix++;
                    isDouble = 1;
                } else {
                    currentNum = currentNum + (double)(*postfix - 48) / pow(10, isDouble);
                    postfix++;
                    isDouble++;
                }
            }
            postfix--;
            isDouble = 0;
            pushNum(nums, &top, currentNum);
        } else if (*postfix != ' ') {
            num1 = popNum(nums, &top);
            num2 = popNum(nums, &top);
            *everythingIsFine = makeDecision(postfix, num1, num2, &result, nums, &top);
            pushNum(nums, &top, result);
        }
        postfix++;
    }
    return popNum(nums, &top);
}

int makeDecision(char *postfix, double num1, double num2, double *result, double *nums, int *top) {
    int res = 1;
    switch (*postfix) {
        case '+':
            *result = num2 + num1;
            break;
        case '-':
            *result = num2 - num1;
            break;
        case '*':
            *result = num2 * num1;
            break;
        case '/':
            *result = num2 / num1;
            break;
        case 's':
            *result = sin(num1);
            pushNum(nums, top, num2);
            break;
        case 'c':
            *result = cos(num1);
            pushNum(nums, top, num2);
            break;
        case 't':
            *result = tan(num1);
            pushNum(nums, top, num2);
            break;
        case 'g':
            *result = 1 / tan(num1);
            pushNum(nums, top, num2);
            break;
        case 'q':
            *result = sqrt(num1);
            pushNum(nums, top, num2);
            break;
        case 'l':
            *result = log(num1);
            pushNum(nums, top, num2);
            break;
        default:
            res = 0;
    }
    return res;
}