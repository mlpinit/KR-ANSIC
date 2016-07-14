// Write a program detab that replaces numbers of tabs with the necessary empty
// strings. Assume a constant tab size (every n columns). Do not use extra
// space and allow tab positions to be passed in as arguments.

#include "edtab.h"

int main(int argc, char *argv[]) {
    int c, pos, spaces, currentt;

    settabs(argc - 1, ++argv);

    pos = spaces = currentt = 0;
    while ((c = getchar()) != EOF) {
        currentt = gettab(pos);
        if (c == '\t') {
            spaces = currentt - (pos % currentt) - 1;
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
            resett();
        }
        else {
            putchar(c);
            ++pos;
        }
    }

    return 0;
}
