#include <stdlib.h>
#include <string.h>

#include "calculate.h"
#include "draw.h"
#include "parse.h"

int main() {
    // read expression as a string
    char *expr = input_arr();
    if (expr != NULL) {
        int len = strlen(expr);
        // convert our expr to polish notation like string
        int everything_is_fine = 1;
        char *postfix = convert(expr, len, &everything_is_fine);
        if (postfix != NULL && everything_is_fine) {
#ifdef RENDER_STRING
            // write polish notation string
            printf("This is our polish notation string:\n");
            for (int i = 0; i < (int)strlen(postfix); i++) {
                printf("%c", postfix[i]);
            }
            printf("\n\n");
#endif
            // output our graphic
            draw_graph(postfix, &everything_is_fine);
            free(postfix);
        }
        free(expr);
    }

    return 0;
}