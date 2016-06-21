// Revise the main routine of the longest line program so it will correctly
// print the length of arbitrarily long input lines, and as much as possible of
// the text.

#include <stdio.h>

#define MAX_STRING 5

int gline(char s[], int limit);
void copy(char from[], char to[]);

int main() {
    int length, max;
    char longest[MAX_STRING];
    char string[MAX_STRING];

    max = 0;
    while ((length = gline(string, MAX_STRING)) != 0)
        if (length > max) {
            max = length;
            copy(string, longest);
            printf("%s |||| %s\n", string, longest);
        }

    printf("Max length is %d: %s\n", max, longest);
    return 0;
}

int gline(char s[], int limit) {
    int i, c;

    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';

    if (s[i - 1] != '\n')
        while ((c = getchar()) != EOF && c != '\n')
            ++i;

    return i;
}

void copy(char from[], char to[]) {
    int i = 0;
    while ((from[i] = to[i]) != '\0')
        ++i;
}
