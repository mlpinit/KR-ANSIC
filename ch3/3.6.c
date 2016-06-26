// Write a version of itoa that accepts three arguments instead of two. The
// third argument is a minimum field width; the converted number must be padded
// with blanks on the left if necessary to make it wide enough.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LIMIT 1000

void itoa(int nr, char s[], int pad);
void reverse(char s[]);

int main(void) {
    char s[LIMIT];

    printf("Nr: %d\n", 20);
    itoa(20, s, 40);
    printf("String: %s\n", s);

    printf("Nr: %d\n", 33);
    itoa(33, s, 40);
    printf("String: %s\n", s);

    printf("Nr: %d\n", 33);
    itoa(47, s, 40);
    printf("String: %s\n", s);

    return 0;
}

void itoa(int nr, char s[], int pad) {
    int i, sign;

    sign = nr;

    i = 0;
    do {
        s[i++] = abs(nr % 10) + '0';
    } while (nr /= 10);
    if (sign < 0)
        s[i++] = '-';
    
    while (i < pad)
        s[i++] = ' ';
    s[i] = '\0';
    reverse(s);
}


void reverse(char s[]) {
    int i, j, c;

    for (i = 0, j = strlen(s) - 1; i < j; ++i, --j)
        c = s[i], s[i] = s[j], s[j] = c;
}
