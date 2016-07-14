#include "edtab.h"

#define MAXTABS 100
#define TABINC 8

static int tints[MAXTABS]; // tabs integer list
static int tlength = 0; // tabs integer list length
static int tpos = 0; // tab position

void settabs(int argc, char **argv) {
    int current;
    static int previous = 0;

    while (tlength < argc) {
        current = atoi(*argv++);
        if (current <= previous) {
            printf("error: invalid list of increasing integers provided; \
                    using default tabstops of %d", TABINC);
            // setting tlength to 0 indicates that we should use default value
            tlength = 0;
            return;
        }
        tints[tlength++] = current;
        previous = current;
    }
}

// condition:
// - if we didn't run out of tabs &&
//   - the current position is not greater than the tab position ||
//   - the next position is not out of bounds
//
// Note:
// - the out of bounds position being greater than the current position is
// implicit
int gettab(int pos) {
    if (tpos < tlength && (pos <= tints[tpos] || ++tpos < tlength))
        return tints[tpos];
    else
        return TABINC;
}

void resett(void) {
    tpos = 0;
}
