// In a two's complement number system, x &= (x-1) dlete the rightmost 1-bit in
// x. Explain why. Use this observation to write a faster version of bitcount.
//
// When we subtract one, all the bits right to the rightmost 1-bit become
// 1-bits and the bit itself becomes 0. However when we & the two different
// numbers we in fact perform the & operation on the inverses of the rightmost
// n bits. So the rightmost 1-bit becomes 0.

#include <stdio.h>

int bits(unsigned int n);

int main() {
    int x;

    x = 44;
    printf("The number of bits in %d should be 3 and our result is %d\n", x, bits(x));

    return 0;
}

int bits(unsigned int n) {
    int counter;

    for (counter = 0; n != 0; n &= n - 1)
        counter++;

    return counter;
}
