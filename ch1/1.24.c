// Write a program that checks for rudimentary syntax errors.
// - unbalanced parantheses, brackets and braces
// - quotes (single and double)
// - escape sequences
// - comments

#include <stdio.h>

#define IN 1
#define OUT 0

int par, brak, brac;

void in_quotes(int c);
void in_comment(int c);
void search(int c);

int main() {
    int c, nc;

    par = brak = brac = nc = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\'' || c == '"')
            in_quotes(c);
        else if (c == '/' && ((nc = getchar()) == '*' || nc == '/'))
            in_comment(nc);
        else {
            search(c);
            search(nc);
        }
        nc = 0;
    }

    if (par != 0)
        printf("Warning: Unbalanced parantheses.");

    if (brak != 0)
        printf("Warning: Unbalanced brackets.");

    if (brac != 0)
        printf("Warning: Unbalanced braces.");

    return 0;
}


void in_quotes(int c) {
    // character
    int d;
    
    while ((d = getchar()) != c)
        if (d == '\\')
            getchar(); // ignore escape seq
}


void in_comment(int c) {
    // previous character, character
    int pc, cc;

    pc = 0;
    if (c == '*') {
        pc = getchar();
        cc = getchar();
        while (pc != '*' || cc != '/') {
            pc = cc;
            cc = getchar();
        }
    }
    else {
        while ((cc = getchar()) != '\n')
           ;
    }
}

void search(int c) {
    if (c == '(')
        ++par;
    if (c == '[')
        ++brak;
    if (c == '{')
        ++brac;
    if (c == ')')
        --par;
    if (c == ']')
        --brak;
    if (c == '}')
        --brac;

    if (par < 0) {
        printf("Warning: Closing parantheses before opening parantheses is not allowed.\n");
        par = 0;
    }

    if (brak < 0) {
        printf("Warning: Closing brackets before opening brackets is not allowed.\n");
        brak = 0;
    }

    if (brac < 0) {
        printf("Warning: Closing braces before opening brace is not allowed.\n");
        brac = 0;
    }
}
