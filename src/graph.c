#include <stdlib.h>
#include <string.h>

#include "calculate.h"
#include "draw.h"
#include "parse.h"

int main() {
    // считываем выражение для преобразования в нужный вид для польской нотации
    int everythingIsFine = 1;
    char* expression = inputArr(&everythingIsFine);
    if (expression != NULL && everythingIsFine) {
        int len = strlen(expression);
        // конвертируем наше выражение в польскую нотацию
        everythingIsFine = !sCount(expression) || !checkOpers(expression) ? 0 : 1;
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
            if (postfix != NULL) {
                free(postfix);
            }
        }
    } else {
        printf("n/a");
    }
    if (expression != NULL) {
        free(expression);
    }
    return 0;
}
