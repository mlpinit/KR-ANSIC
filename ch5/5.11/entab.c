// Write a program entab to turn spaces into tabs. Allow passing in a list ot
// integers that indicate if there should be a tab at a given position.

#include "edtab.h"

int main(int argc, char *argv[]) {
    int c, spaces, pos, currentt;

    settabs(argc - 1, ++argv);

    pos = spaces = currentt = 0;
    while ((c = getchar()) != EOF) {
        ++pos;
        currentt = gettab(pos);
        /* printf("currentt: %d\n", currentt); */
        if (c == ' ') {
            ++spaces;
            if (pos % currentt == 0) {
                spaces = 0;
                putchar('\t');
            }
        } else if (c == '\t') {
            pos += pos % currentt;
            spaces = 0;
            putchar('\t');
        } else {
            while (spaces != 0) {
                --spaces;
                putchar(' ');
            }
            putchar(c);
            if (c == '\n') {
                pos = 0;
                resett();
            }
        }
    }

    return 0;
}
