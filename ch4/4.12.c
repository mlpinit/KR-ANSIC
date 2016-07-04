// write a recursive implementation of itoa

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAXSIZE 100

void itoa(char [], int);

int main(void) {
    char s[MAXSIZE];

    itoa(s, 127);
    printf("%s\n", s);
    itoa(s, -127);
    printf("%s\n", s);

    return 0;
}

void itoa(char s[], int nr) {
    static int position;

    if (nr / 10)
        itoa(s, nr / 10);
    else {
        position = 0;
        if (nr < 0) {
            s[position++] = '-';
            nr = -nr;
        }
    }
    s[position++] = abs(nr) % 10 + '0';
    s[position] = '\0';
}
