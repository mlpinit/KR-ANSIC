// itoa that handles largest number (2^(wordsize - 1))
// 128

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

#define LIMIT 1000

void itoa(int nr, char s[]);
void reverse(char s[]);

int main() {
    char s[LIMIT];

    printf("INT MAX: %d\n", INT_MAX);
    printf("INT MIN: %d\n", INT_MIN);
    itoa(INT_MIN, s);
    printf("STRING: %s\n", s);

    return 0;
}

void itoa(int nr, char s[]) {
    int i, sign;
    sign = nr;

    i = 0;
    do {
        s[i++] = abs(nr % 10) + '0';
    } while (nr /= 10);
    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);
}
void reverse(char s[]) {
    int i, j, c;

    for (i = 0, j = strlen(s) -1; i < j; ++i, --j)
        c = s[i], s[i] = s[j], s[j] = c;

}
