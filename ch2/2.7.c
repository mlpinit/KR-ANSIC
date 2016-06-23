// Write a function invert(x,p,n) hat returns x with the n bits that begin at
// position p inverted, leaving the others unchanged.

#include <stdio.h>

unsigned invert(unsigned x, short p, short n);

int main() {
    printf("Inverting %d starting at position %d, %d positions should return 50 and it returns %u\n", 44, 4, 4, invert(44, 4, 4));

    return 0;
}

unsigned invert(unsigned x, short p, short n) {
    return ~(~0 << n) << (p + 1 - n) ^ x;
}
