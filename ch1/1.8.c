#include <stdio.h>

// Write a program to count blanks, tabs and new lines

int main() {
    int c;
    int bc = 0, tc = 0, nc = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n')
            ++nc;
        else if (c == '\t')
            ++tc;
        else if (c == ' ')
            ++ bc;
    }

    printf("Blanks count: %d | Tabs count: %d | New lines count: %d\n", bc, tc, nc);
}
