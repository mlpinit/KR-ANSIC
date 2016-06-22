// Write a function any(s1, s2), which returns the first  location in the string
// s1 where any character from the string s2 occurs, or -1 is s1 contains no
// characters from s2.

#include <stdio.h>

int any(char s1[], char s2[]);

int main() {
    char s1[] = "string";
    char s2[] = "ri";
    char s3[] = "z";

    printf("First character from %s also found in %s at position %d\n", s2, s1, any(s1, s2));
    printf("First character from %s also found in %s at position %d\n", s3, s1, any(s1, s3));

    return 0;
}

int any(char s1[], char s2[]) {
    int i, j;

    for (i = 0; s1[i] != '\0'; ++i)
        for (j = 0; s2[j] != '\0'; ++j)
            if (s1[i] == s2[j])
                return i;

    return -1;
}
