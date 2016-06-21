#include <stdio.h>

// Write a program to copy its input to its output and replace one or more
// blanks with one blank.

int main() {
    // character, previous character
    int c, pc;

    pc = EOF; // non blank character
    while ((c = getchar()) != EOF) {
        if (c != ' ' || c != pc)
            putchar(c);
        pc = c;
    }
}
