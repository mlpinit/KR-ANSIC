// Write a program to print a histogram for the frequencey of different
// characters in its input.

#include <stdio.h>

#define MAX_CHARS 128 // representing ascii chars
#define MAX_HIST 20 // max allowed histogram size

int main() {
    int c, i, j, max_count, len;
    int chars[MAX_CHARS];

    // initialize empty array
    for (i = 0; i < MAX_CHARS; ++i)
        chars[i] = 0;

    while ((c = getchar()) != EOF)
        if (c < MAX_CHARS)
            ++chars[c];

    // find max count
    for (i = 0, max_count = 0; i < MAX_CHARS; ++i)
        if (max_count < chars[i])
            max_count = chars[i];

    for (i = 1; i < MAX_CHARS; ++i) {
        if (chars[i] > 0) {
            if ((len = chars[i] * MAX_HIST / max_count) <= 0)
                len = 1;
        } else
            len = 0;

        printf("char %c: ", i);
        for (j = 0; j <= len; ++j)
            putchar('#');
        putchar('\n');
    }
}
