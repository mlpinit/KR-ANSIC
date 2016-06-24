#include <stdio.h>
#include <ctype.h>

int atoi(char s[]);

int main() {
    char s[] = "      -1234";

    printf("String: %s\n", s);
    printf("Integer: %d\n", atoi(s));

    return 0;
}

int atoi(char s[]) {
    int i, nr, sign;

    for (i = 0; isspace(s[i]); ++i)
        ;

    sign = (s[i] == '-') ? -1 : 1;

    // skip sign
    if (s[i] == '-' || s[i] == '+')
        ++i;

    for (nr = 0; isdigit(s[i]); ++i)
        nr = nr * 10 + s[i] - '0';

    return nr * sign;
}
