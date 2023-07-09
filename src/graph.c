#include <stdlib.h>
#include <string.h>

#include "draw.h"
#include "parse.h"

int main() {
    // считываем выражение для преобразования в нужный вид для польской нотации
    char *expr = inputArr();
    if (expr != NULL) {
        int len = strlen(expr);
        // конвертируем наше выражение в польскую нотацию
        int everythingIsFine = 1;
        char *postfix = convert(expr, len, &everythingIsFine);
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
        }
        free(expr);
    }

    return 0;
}