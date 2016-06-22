// Write an alternate version of squeeze(s1, s2) that deletes each character in
// s1 that matches any character in s2.

#include <stdio.h>

void squeeze(char s1[], char s2[]);
int present(char s[], char c);

int main() {
    char s1[] = "right string";
    char s2[] = "ring";

    squeeze(s1, s2);
    printf("%s\n", s1);
}

void squeeze(char s1[], char s2[]) {
    int i, j;

    for (i = 0, j = 0; s1[i] != '\0'; ++i)
        if (!present(s2, s1[i]))
            s1[j++] = s1[i];
    s1[j] = '\0';
}

int present(char s[], char c) {
    int i, presence;

    for (i = 0, presence = 0; s[i] != '\0'; ++i)
        if (s[i] == c)
            return 1;
    return 0;
}
