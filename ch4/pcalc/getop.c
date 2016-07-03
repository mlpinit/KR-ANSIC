#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(char s[]) {
    int i, c;

    // skip empty chars
    while ((s[0] = c = getch()) == ' ' || s[0] == '\t')
        ;
    s[1] = '\0';

    if (!isdigit(c))
        return c;

    i = 0;
    while (isdigit(s[++i] = c = getchar()))
        ;
    if (c == '.')
        while (isdigit(s[++i] = c = getchar()))
            ;
    s[i] = '\0';

    if (c != EOF)
        ungetch(c);

    return NUMBER;
}
