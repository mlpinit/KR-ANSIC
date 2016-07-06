#include <stdio.h>
#include <ctype.h>

#define SIZE 100

int n, array[SIZE], getint(int *);

int main(void) {
    int response;

    for (n = 0; n < SIZE && (response = getint(&array[n])) != EOF; ++n) {
        if (response == '-' || response == '+') {
            printf("error: '+ or -' not followed by a digit supplied\n");
            return -1;
        } else if (response == 0) {
            printf("error: non number provided\n");
            return -1;
        }
        printf("%d - ", array[n]);
    }
    putchar('\n');

    return 0;
}

void ungetch(int ch);
char getch(void);

int getint(int *pn) {
    int c, sign, previous;

    while (isspace(c = getch()))
        ;

    if (!isdigit(c) && c != EOF && c != '-' && c != '+') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if ((c == '-' || c == '+')) {
        previous = c;
        if (!isdigit(c = getch())) {
            if (c != EOF)
                ungetch(c);
            ungetch(previous);
            return previous;
        }
    }

    for (*pn = 0; isdigit(c); c = getch())
        *pn = *pn * 10 + (c - '0');
    *pn *= sign;

    if (c != EOF)
        ungetch(c);

    return c;
}

#define BUFSIZE 100

static char buf[BUFSIZE];
static int bufp = 0;

char getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp < BUFSIZE)
        buf[bufp++] = c;
    else
        printf("error: stack full\n");
}
