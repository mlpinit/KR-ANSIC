#include <stdio.h>
#include <string.h>

#define MAX_LINE 1000

void itoa(int nr, char s[]);
void reverse(char s[]);

int main() {
    char str[MAX_LINE];

    itoa(-1231, str);
    printf("itoa: %s\n", str);
    return 0;
}

void itoa(int nr, char s[]) {
    int i, sign;

    if ((sign = nr) < 0)
        nr = -nr;

    i = 0;
    do {
        s[i++] = nr % 10 + '0';
    } while ((nr /= 10) > 0);

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]) {
    int i, j, c;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}
