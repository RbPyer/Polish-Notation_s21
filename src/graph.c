#include <stdlib.h>
#include <string.h>

#include "calculate.h"
#include "draw.h"
#include "parse.h"

int sCount(char* str) {
    int lcount = 0, rcount = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') {
            lcount++;
        } else if (str[i] == ')') {
            rcount++;
        }
    }
    return lcount == rcount;
}

int checkOpers(char* str) {
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

int main() {
    // считываем выражение для преобразования в нужный вид для польской нотации
    char* expression = inputArr();
    if (expression != NULL) {
        int len = strlen(expression);
        // конвертируем наше выражение в польскую нотацию
        int everythingIsFine = !sCount(expression) || !checkOpers(expression) ? 0 : 1;
        char* postfix = convert(expression, len, &everythingIsFine);
        if (postfix != NULL && everythingIsFine) {
#ifdef renderString
            // опционально: вывод выражения в виде польской нотации (юзалось для отладки)
            delimiter();
            printf("This is our polish notation string:\n");
            for (int i = 0; i < (int)strlen(postfix); i++) {
                printf("%c", postfix[i]);
            }
            putchar('\n');
            delimiter();
#endif
            // рендер графика
            drawGraph(postfix, &everythingIsFine);
            free(postfix);
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
    if (expression != NULL) {
        free(expression);
    }
    return 0;
}
