#include "edtab.h"

#define MAXTABS 100
#define TABINC 8

static int tints[MAXTABS]; // tabs integer list
static int tlength = 0; // tabs integer list length
static int tpos = 0; // tab position
static int mpos = 0;
static int npos = 0;

void settabs(int argc, char **argv) {
    char first;
    int current;
    static int previous = 0;

    while (tlength < argc && (!mpos || !npos)) {
        first = **argv; // first character to test for '-' or '+'
        current = atoi(*argv++); // get current and increment to next
        // get starting column if any
        if (first == '-') {
            mpos = -1 * current;
            continue;
        }
        // get increment integer if any
        if (first == '+') {
            npos = current;
            continue;
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
    int adjustment;

    if (tpos < tlength && (pos <= tints[tpos] || ++tpos < tlength))
        return tints[tpos];
    else if ((mpos && npos) && mpos <= pos) {
        adjustment = npos - (pos - mpos + 1) % npos;
        return (adjustment == npos) ? pos : pos + adjustment;
    }
    else
        return TABINC;
}

void resett(void) {
    tpos = 0;
}

void printall(void) {
    int i;

    printf("MPOS: %d\n", mpos);
    printf("NPOS: %d\n", npos);
    printf("TLENGTH: %d\n", tlength);

    for (i = 0; i < tlength; ++i)
        printf("%d ", tints[i]);
    putchar('\n');
}
