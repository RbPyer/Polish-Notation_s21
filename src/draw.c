#include "draw.h"

#define dyLimit -1  // нижний предел отрисовки по Y исходя из области значений
#define uyLimit 1  // верхний предел отрисовки по Y исходя из области значений

void drawGraph(char *postfix, int *everythingIsFine) {
    double coords[WIDTH];
    int count = 0;
    for (double x = 0.0; x < 4.0 * M_PI && everythingIsFine; x += 4.0 * M_PI / WIDTH) {
        coords[count++] = calculate(postfix, x, everythingIsFine);
    }
    if (*everythingIsFine) {
        for (double y = dyLimit; y <= uyLimit; y += STEP) {
            for (int x = 0; x < WIDTH; x++) {
                if (coords[x] <= y + INFELICITY && coords[x] >= y - INFELICITY) {
                    putchar('*');
                } else {
                    putchar('.');
                }
            }
            putchar('\n');
        }
    } else {
        printf("n/a");
    }
}

void delimiter() { printf("\n\nDELIMITER\n\n"); }