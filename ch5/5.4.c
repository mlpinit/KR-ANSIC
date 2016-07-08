// write the function strend(s,t), which return 1 if the string t ocurs at the
// end of the string s, and 0 otherwise.

#include <stdio.h>
#include <string.h>

int strend(char *, char *);

int main(void) {
    char s[] = "hello";
    char r[] = "llo";
    char v[] = "o";
    char z[] = "llt";
    char d[] = "zlt";
    char b[] = "asldkfa";

    printf("%d\n", strend(s, s));
    printf("%d\n", strend(s, r));
    printf("%d\n", strend(s, v));
    printf("%d\n", strend(s, z));
    printf("%d\n", strend(s, d));
    printf("%d\n", strend(s, b));

    return 0;
}

int strend(char* s, char* t) {
    int ssize, tsize;

    ssize = strlen(s), tsize = strlen(t);

    if (ssize < tsize)
        return 0;

    s += ssize - tsize;
    while (*s && *s == *t)
        ++s, ++t;
    return *s ? 0 : 1;
}
