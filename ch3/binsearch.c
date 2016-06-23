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

    nr = 21;
    position = binsearch(nr, nrs, length);
    printf("Nr %d is found at position %d\n", nr, position);

    return 0;
}

int binsearch(int x, int nrs[], int n) {
    int high, low, mid;

    high = n - 1;
    low = 0;

    while (low <= high) {
        mid = (high - low) / 2 + low;
        if (x < nrs[mid])
            high = mid - 1;
        else if (nrs[mid] < x)
            low = mid + 1;
        else
            return mid;
    }

    // if not found return - 1
    return -1;
}
