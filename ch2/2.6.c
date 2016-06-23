// Write a function setbits(x,p,n,y) that returns x with the n bits that begin
// at position p set to the rightmost n bits of y, leavnig the other bits
// unchanged.

#include <stdio.h>

unsigned setbits(unsigned x, short p, short n, unsigned y);

int main() {
    int x, p, n, y;

    x = 32, p = 1, n = 2, y = 2;
    printf("%d: Applied at position %d, %d right most characters from %d to turn into %u\n", x, p, n, y, setbits(x, p, n, y));

    x = 32, p = 1, n = 2, y = 3;
    printf("%d: Applied at position %d, %d right most characters from %d to turn into %u\n", x, p, n, y, setbits(x, p, n, y));

    x = 32, p = 4, n = 5, y = 16;
    printf("%d: Applied at position %d, %d right most characters from %d to turn into %u\n", x, p, n, y, setbits(x, p, n, y));

    x = 32, p = 4, n = 1, y = 1;
    printf("%d: Applied at position %d, %d right most characters from %d to turn into %u\n", x, p, n, y, setbits(x, p, n, y));

    x = 32, p = 4, n = 1, y = 2;
    printf("%d: Applied at position %d, %d right most characters from %d to turn into %u\n", x, p, n, y, setbits(x, p, n, y));

    x = 32, p = 4, n = 3, y = 4;
    printf("%d: Applied at position %d, %d right most characters from %d to turn into %u\n", x, p, n, y, setbits(x, p, n, y));

    x = 32, p = 4, n = 3, y = 7;
    printf("%d: Applied at position %d, %d right most characters from %d to turn into %u\n", x, p, n, y, setbits(x, p, n, y));

    x = 63, p = 4, n = 3, y = 0;
    printf("%d: Applied at position %d, %d right most characters from %d to turn into %u\n", x, p, n, y, setbits(x, p, n, y));

    return 0;
}

unsigned setbits(unsigned x, short p, short n, unsigned y) {
    return (x & ~(~(~0 << n) << (p - n + 1))) |
        (y & ~(~0 << n)) << (p - n + 1);
}
