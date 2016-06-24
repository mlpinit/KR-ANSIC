// Write a function expand(s1,s2) that expands shorthand notations like a-z in
// the string s1 into the equivalent complete list in abc...xyz in s2. Allow for
// letters of either case and digits, and be prepared to handle cases like a-b-c
// and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literally.
//
// This solution handles ascending and descending scenarios for digits, lower
// case and uppper case letters.

#include <stdio.h>
#include <ctype.h>

#define MAX_LINE 1000

int is_lower_letter(char c);
int is_upper_letter(char c);
void expand(char s[], char t[]);
int valid_range(char c, char d);

int main() {
    char str[] = "-This -is Mike from a-z bling d-a and a-b-c. 0-9 in -5 seconds.\n"
        "Capital letters from D-G and this doesn't work D-z. Numbers down 4-1.\n"
        "And one last scenario: -a-z and a-z0-8 BAM! 2-8";
    char t[MAX_LINE];

    expand(str, t);

    printf("Regular: %s\n", str);
    printf("Expanded: %s\n", t);

    return 0;
}

void expand(char s[], char t[]) {
    int i, j, c, d;

    t[0] = s[0];
    for (i = 1, j = 1; s[i] != '\0'; ++i) {
        c = s[i - 1], d = s[i + 1];
        if (s[i] == '-' && valid_range(c, d)) {
            if (c < d) {
                while (++c < d)
                    t[j++] = c;
            } else {
                while (--c > d)
                    t[j++] = c;
            }
        } else
            t[j++] = s[i];
    }
    t[j] = s[i];
}

int is_lower_letter(char c) {
    return c >= 'a' && c <= 'z';
}

int is_upper_letter(char c) {
    return c >= 'A' && c <= 'Z';
}

int valid_range(char c, char d) {
    // if they are only one apart we don't expand
    if (c - d == 1 || d - c == 1)
        return 0;
    // they both have to be lower case letters to expand
    if (is_lower_letter(c) && is_lower_letter(d))
        return 1;
    // they both have to be upper case letters to expand
    if (is_upper_letter(c) && is_upper_letter(d))
        return 1;
    // they both have to be digits to expand
    if (isdigit(c) && isdigit(d))
        return 1;
    // if not digits or letters, it's not a valid range
    return 0;
}
