// Write a program to remove trailing tabs and blanks and to completely remove
// empty lines.
#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 100

int gline(char s[], int limit);
int strip(char s[], int length);

int main() {
    int len;
    char string[MAX_SIZE];

    while ((len = gline(string, MAX_SIZE)) != 0)
        if (strip(string, len) > 0)
            printf("%d: %s", len, string);

    return 0;
}


int gline(char s[], int limit) {
    int i, c;

    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';

    return i;
}

int strip(char s[], int length) {
    // skip new line and end of string delimiter
    length -= 2;

    while (length >= 0 && isblank(s[length]))
        --length;
    if (length >= 0) {
        length++;
        s[length++] = '\n';
        s[length] = '\0';
    }

    return length;
}
