// Write a program detab that replaces numbers of tabs with the necessary empty
// strings. Assume a constant tab size (every n columns).

#include <stdio.h>

#define MAX_SIZE 1000
#define TABINC 8

int gline(char s[], int len);
void detab(char from[], char to[]);

int main() {
    int len;
    char tabbed_line[MAX_SIZE];
    char detabbed_line[MAX_SIZE];

    while ((len = gline(tabbed_line, MAX_SIZE)) != 0) {
        detab(tabbed_line, detabbed_line);
        printf("%s", detabbed_line);
    }

    return 0;
}

int gline(char s[], int len) {
    int c, i;

    for (i = 0; i < len - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';

    return i;
}

void detab(char from[], char to[]) {
    int i, j, spaces;

    for (i = 0, j = 0; from[i] != '\n'; ++i, ++j) {
        if (from[i] == '\t') {
            to[j] = ' ';
            spaces = TABINC - (j % TABINC) - 1;
            while (spaces > 0) {
                to[++j] = ' ';
                --spaces;
            }
        }
        else
            to[j] = from[i];
    }
    to[j++] = '\n';
    to[j] = '\0';
}
