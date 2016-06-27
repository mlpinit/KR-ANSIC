// Write the strindex(s, t) that finds the right most occurance of the t string
// within the s string.

#include <stdio.h>

int strindex(char s[], char t[]);

int main() {
    char pattern[] = "ould";
    char str[] = "I could dance or I could fly.\n";
    char str2[] = "I like to dance and I like fly.\n";

    printf("Right most position: %d\n", strindex(str, pattern));
    printf("Right most position: %d\n", strindex(str2, pattern));

    return 0;
}

int strindex(char s[], char t[]) {
    int i, j, k, p;

    p = -1;
    for (i = 0; s[i] != '\0'; ++i) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; ++j, ++k)
            ;
        if (k > 0 && t[k] == '\0')
            p = i;
    }

    return p;
}
