#include <stdlib.h>
#include <string.h>

#include "draw.h"
#include "parse.h"

int main() {
    // read expression as a string
    char *expr = inputArr();
    if (expr != NULL) {
        int len = strlen(expr);
        // convert our expr to polish notation like string
        int everythingIsFine = 1;
        char *postfix = convert(expr, len, &everythingIsFine);
        if (postfix != NULL && everythingIsFine) {
#ifdef renderString
            // write polish notation string
            printf("This is our polish notation string:\n");
            for (int i = 0; i < (int)strlen(postfix); i++) {
                printf("%c", postfix[i]);
            }
            printf("\n\n");
#endif
            // output our graphic
            drawGraph(postfix, &everythingIsFine);
            free(postfix);
        }
        free(expr);
    }

    return 0;
}