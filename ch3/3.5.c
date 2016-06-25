// Write a function itob(n,s,b) that converts the integer n into a base b
// character representation in the string s. In particular, itob(n,s,16) formats
// n as a hexadecimal integer in s.

#include <stdio.h>
#include <string.h>

#define MAX_LINE 1000

void itob(int i, int base, char str[]);
void reverse(char str[]);

int main() {
    int nr, base;
    char str[MAX_LINE];

    nr = 9;
    base = 2;
    itob(nr, base, str);
    printf("Base %d representation of %d nr is %s\n", base, nr, str);

    nr = 56;
    base = 3;
    itob(nr, base, str);
    printf("Base %d representation of %d nr is %s\n", base, nr, str);

    nr = 15;
    base = 16;
    itob(nr, base, str);
    printf("Base %d representation of %d nr is %s\n", base, nr, str);


    nr = 31;
    base = 16;
    itob(nr, base, str);
    printf("Base %d representation of %d nr is %s\n", base, nr, str);
    

    nr = 31;
    base = 32;
    itob(nr, base, str);
    printf("Base %d representation of %d nr is %s\n", base, nr, str);

    nr = -8;
    base = 32;
    itob(nr, base, str);
    printf("Base %d representation of %d nr is %s\n", base, nr, str);

    nr = -23;
    base = 32;
    itob(nr, base, str);
    printf("Base %d representation of %d nr is %s\n", base, nr, str);
    
    return 0;
}

void itob(int nr, int base, char str[]) {
    int i, digit, sign;

    if ((sign = nr) < 0)
        nr = -nr;

    i = 0;
    do {
        if ((digit = nr % base) <= 9)
            str[i] = digit + '0';
        else
            str[i] = 'A' - 10 + digit;
        ++i;
    } while ((nr /= base) != 0);
    if (sign < 0)
        str[i++] = '-';
    str[i] = '\0';
        
    reverse(str);
}

void reverse(char str[]) {
    int i, j, c;

    for(i = 0, j = strlen(str) - 1; i < j; ++i, --j)
        c = str[i], str[i] = str[j], str[j] = c;
}
