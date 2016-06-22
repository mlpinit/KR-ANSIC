#include <stdio.h>

#define LIM 10

enum loop { TRUE, FALSE };
enum loop loop_value = TRUE;

int main() {
    int i, c;
    char s[LIM];

    /* for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i) */
    /*     s[i] = c; */

    while (loop_value == TRUE) {
        if (i >= LIM - 1)
            loop_value = FALSE;
        else if ((c = getchar()) == '\n')
            loop_value = FALSE;
        else if (c == EOF)
            loop_value = FALSE;
        else {
            s[i] = c;
            ++i;
        }
    }

    s[i] = '\0';
    printf("%s\n", s);

}
