// Write a function escape(s,t) that converts characters like newline and tab
// into visible escape sequences like \n and \t as it copies the string t to s.
// Use a switch. Write a function for the other direction as well, converting
// escape sequences into the real characters.

#include <stdio.h>

#define MAX_LINE 1000

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main() {
    char s[MAX_LINE] = "Hello this is \t\t a test.\n One more.\n";
    char t[MAX_LINE];

    escape(s, t);
    printf("%s\n", s);
    printf("%s\n", t);

    printf("------------------------------------------------\n");

    unescape(t, s);
    printf("%s\n", t);
    printf("%s\n", s);

    return 0;
}

void escape(char s[], char t[]) {
    int i, j;
    
    for (i = j = 0; s[i] != '\0'; ++i, ++j) {
        switch (s[i]) {
            case '\n':
                t[j++] = '\\';
                t[j] = 'n';
                break;
            case '\t': 
                t[j++] = '\\';
                t[j] = 't';
                break;
            default: 
                t[j] = s[i];
        }
    }
    t[j] = s[i];
}

void unescape(char s[], char t[]) {
    int i, j;

    for (i = j = 0; s[i] != '\0'; ++i, ++j) {
        if (s[i] == '\\')
            switch (s[++i]) {
                case 'n':
                    t[j] = '\n';
                    break;
                case 't':
                    t[j] = '\t';
                    break;
            }
        else
            t[j] = s[i];
    }
}
