// Write a program entab to turn spaces into tabs.

#include <stdio.h>

#define TABINC 8

int main() {
    int c, spaces, pos;
    
    pos = 1;
    spaces = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++spaces;
            if (pos % TABINC == 0) {
                spaces = 0;
                putchar('\t');
            }
        } else if (c == '\t') {
            pos += TABINC - (pos % TABINC);
            spaces = 0;
            putchar('\t');
        } else if (c == '\n') {
            while (spaces != 0) {
                --spaces;
                putchar(' ');
            }
            putchar(c);
            pos = 0;
        } else {
            while (spaces != 0) {
                --spaces;
                putchar(' ');
            }
            putchar(c);
        }
        ++pos;
    }

    return 0;
}
