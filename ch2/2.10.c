// Rewrite the function lower, which converts upper case letters to lover case,
// with a conditional expression insted of if-else.
//
// (coverting strings instead of letters)

#include <stdio.h>

void lower(char s[]);

int main() {
    char s[] = "LoWeR";

    lower(s);
    printf("apply lower function to LoWeR -> %s\n", s);
    return 0;
}

void lower(char s[]) {
    int i;

    i = 0;
    while (s[i] != '\0') {
        s[i] = (s[i] >= 'A' && s[i] <= 'Z') ? (s[i] - 'A' + 'a') : s[i];
        ++i;
    }

}
