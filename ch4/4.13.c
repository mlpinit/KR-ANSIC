// write a recursive version of the function reverse(s), which reverses the
// string s in place.

#include <stdio.h>
#include <string.h>

void reverse(char [], int, int);

int main(void) {
    char s[]  = "some string";

    reverse(s, 0, strlen(s) - 1);
    printf("%s\n", s);

    return 0;
}

void reverse(char s[], int i, int j) {
    char temp;

    if (i < j)
        reverse(s, i + 1, j - 1);
    temp = s[i], s[i] = s[j], s[j] = temp;
}
