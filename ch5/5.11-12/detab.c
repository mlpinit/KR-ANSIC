// Write a program detab that replaces numbers of tabs with the necessary empty
// strings. Assume a constant tab size (every n columns). Do not use extra
// space and allow tab positions to be passed in as arguments.

#include "edtab.h"

int main(int argc, char *argv[]) {
    int c, pos, spaces, currentt;

    settabs(argc - 1, ++argv);

    pos = spaces = currentt = 0;
    while ((c = getchar()) != EOF) {
        ++pos;
        currentt = gettab(pos);
        if (c == '\t') {
            spaces = 1;
            // we don't need to increment the position when we're at the tab
            // position
            if (pos % currentt) {
                spaces += currentt - (pos % currentt);
                pos += spaces - 1;
            }
            while (spaces-- > 0)
                putchar(' ');
        }
        else if (c == '\n') {
            putchar('\n');
            pos = 0;
            resett();
        }
        else
            putchar(c);
    }

    return 0;
}
