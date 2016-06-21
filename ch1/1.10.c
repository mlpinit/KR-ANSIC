#include <stdio.h>

// Write a program to output its inputs replacing all tabs with \t, backspaces
// with \b and backslashes with \\.

int main() {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            printf("\\t");
        } else if (c == '\b') {
            printf("\\b");
        } else if (c == '\\') {
            printf("\\\\");
        } else {
            putchar(c);
        }
    }
}
