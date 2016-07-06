// Write getfloat, the floating-point analog of getint. What types does getfloat
// return as its function value?

#include <stdio.h>
#include <ctype.h>

#define SIZE 100

int getfloat(float *pt);

int main(void) {
    int i, response;
    float nrs[SIZE];

    for (i = 0; i < SIZE && (response = getfloat(&nrs[i])) != EOF; ++i) {
        if (response == '-' || response == '+') {
            printf("error: '+ or -' not followed by a digit supplied\n");
            return -1;
        } else if (response == 0) {
            printf("error: non number provided\n");
            return -1;
        }
        printf("%g - ", nrs[i]);
    }
    

    return 0;
}

int getfloat(float *pt) {
    static int previous = 0;
    int c, sign;
    int power;

    if (previous) {
        c = previous;
        previous = 0;
    } else
        c = getchar();

    while (isspace(c))
         c = getchar();

    // not a number
    if (!isdigit(c) && c != '.' && c != EOF && c != '-' && c != '+') {
        previous = c;
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '-' || c == '+') {
        previous = c;
        if (!isdigit(c = getchar()))
            return previous;
    }


    for (*pt = 0; isdigit(c); c = getchar())
        *pt = *pt * 10 + (c - '0');

    if (c == '.') {
        power = 1;
        while (isdigit(c = getchar())) {
            *pt = *pt * 10 + (c - '0');
            power *= 10;
        }
        *pt /= power;
    }
    *pt *= sign;

    return c;
}
