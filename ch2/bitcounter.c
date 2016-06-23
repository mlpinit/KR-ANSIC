#include <stdio.h>

int bits(unsigned int n);

int main() {
    int n;

    n = 16;
    printf("nr of 1 bits in %d is %d and should be 1\n", n, bits(n));

    n = 15;
    printf("nr of 1 bits in %d is %d and should be 4\n", n, bits(n));

    return 0;
}

int bits(unsigned int n) {
    int counter;

    for (counter = 0; n != 0; n >>= 1)
        if (n & 1)
            ++counter;

    return counter;
}
