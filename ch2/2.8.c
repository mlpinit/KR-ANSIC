// Write a function rightrot(x, n) that returns the value of the integer x
// rotated to the right by n bits positions.
//
// Note: I used char instead of integer for easier testing. 
//
// We don't know of sizeof yet. We could also compute the size of char by
// inverting 0 and right shifting and incrementing one at a time while greater
// then 0.
//
// unsinged char max = (unsigned) char ~0;

#include <stdio.h>

unsigned char rightrot(unsigned char x, short n);
unsigned char rightrot2(unsigned char x, short n);
int size(void);

int main() {
    printf("sizeof(int) * 8 - 3 => %lu\n", sizeof(char) * 8 - 3);
    printf("Rotating 44 to the right 3 positions should return 133 and it returns: %d\n", rightrot(44, 3));
    printf("Rotating 44 to the right 3 positions should return 133 and it returns: %d\n", rightrot2(44, 3));
    return 0;
}

unsigned char rightrot(unsigned char x, short n) {
    // sizeof returns size in bytes so we need to multiply by the number of bits
    return (x >> n) |
        (x & ~(~0 << n)) << (sizeof(char) * 8 - n);
}

unsigned char rightrot2(unsigned char x, short n) {
    return (x >> n) |
        (x & ~(~0 << n)) << (size() - n);
}

int size(void) {
    int counter;
    unsigned char max;
    
    for (counter = 0, max = (unsigned char) ~0; max != 0; ++counter)
        max >>= 1;

    return counter;
}
