#include <stdio.h>

// Write a program that prints its input one word per line.
// A word is a sequence of characters that does not conaint a blank
// a tab or a new line.

int main() {
    int c, pc;

    pc = EOF; // nonblank character
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (pc != ' ' && pc != '\n' && pc != '\t')
                putchar('\n');
        }
        else
            putchar(c);
        pc = c;
    }
}
