// write a function htoi(s) that take a string and converts it to a hexadecimal
// number. Including the optional '0x' or '0X' prefix.

#include <stdio.h>
#include <ctype.h>

int htoi(char s[]);
int ltoi(int c);

int main() {
    char hexnr1[] = "0XFF2";
    char hexnr2[] = "0x8B2";
    char hexnr3[] = "8B2F";

    printf("hex: %s - to:%d\n", hexnr1, htoi(hexnr1));
    printf("hex: %s - to:%d\n", hexnr2, htoi(hexnr2));
    printf("hex: %s - to:%d\n", hexnr3, htoi(hexnr3));

    return 0;
}

int htoi(char s[]) {
    int i, nr;

    for (i = 0, nr = 0; s[i] != '\0'; ++i)
        nr = nr * 16 + ltoi(s[i]);

    return nr;
}

int ltoi(int c) {
    if (c >= 'a' && c <= 'f')
        return 10 + c - 'a';
    else if (c >= 'A' && c <= 'F')
        return 10 + c - 'A';
    else if (isdigit(c - '0'))
        return c - 0;
    else
        return 0;
}
