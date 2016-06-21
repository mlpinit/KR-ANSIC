// Write a program detab that replaces numbers of tabs with the necessary empty
// strings. Assume a constant tab size (every n columns). Do not use extra
// space.

#include <stdio.h>

#define TABINC 8

int main() {
    int c, pos, spaces; // character, position, number of spaces left

    pos = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            spaces = TABINC - (pos % TABINC) - 1;
            while (spaces > 0) {
                putchar(' ');
                --spaces;
                ++pos;
            }
            putchar(' ');
            ++pos;
        }
        else if (c == '\n') {
            putchar('\n');
            pos = 0;
        }
        else {
            putchar(c);
            ++pos;
        }
    }

    return 0;
}
