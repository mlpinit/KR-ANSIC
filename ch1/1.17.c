// Write a program to print all input lines that are longe then MIN_SIZE characters

#include <stdio.h>

#define MAX_SIZE 40
#define MIN_SIZE 5

int gline(char s[], int limit);

int main() {
    int length;
    char string[MAX_SIZE];

    while ((length = gline(string, MAX_SIZE)) != 0) {
        if (length > MIN_SIZE)
            printf("String with length %d > %d -> %s", length, MIN_SIZE, string);
        if (length >= MAX_SIZE)
            putchar('\n');
    }


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
