// Our binary search makes two tests inside the loop, when one would suffice (at
// the price of more tests outside). Write a version with only one test inside
// the loop and measure the difference in run-time.

#include <stdio.h>

int binsearch(int x, int nrs[], int n);

int main() {
    int nr, length, position;
    int nrs[] = {1, 5, 9, 20, 43, 57, 68};
    length = 7;

    nr = 20;
    position = binsearch(nr, nrs, length);
    printf("Nr %d is found at position %d\n", nr, position);

    nr = 57;
    position = binsearch(nr, nrs, length);
    printf("Nr %d is found at position %d\n", nr, position);

    nr = 43;
    position = binsearch(nr, nrs, length);
    printf("Nr %d is found at position %d\n", nr, position);

    nr = 1;
    position = binsearch(nr, nrs, length);
    printf("Nr %d is found at position %d\n", nr, position);

    nr = -9;
    position = binsearch(nr, nrs, length);
    printf("Nr %d is found at position %d\n", nr, position);

    nr = 21;
    position = binsearch(nr, nrs, length);
    printf("Nr %d is found at position %d\n", nr, position);

    return 0;
}

int binsearch(int x, int nrs[], int n) {
    int high, mid, low;

    low = 0;
    high = n - 1;
    mid = (high - low) / 2 + low;
    while (low <= high && nrs[mid] != x) {
        if (x < nrs[mid])
            high = mid - 1;
        else
            low = mid + 1;
        mid = (high - low) / 2 + low;
    }

    if (nrs[mid] == x)
        return mid;
    else
        return -1;
}
