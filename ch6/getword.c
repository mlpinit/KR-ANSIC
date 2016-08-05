#include "getword.h"

#define STACKMAX 100

void skip_quote(char c);
void skip_comment(char c);
void skip_line(void);

int getch(void);
void ungetch(int);

int getword(char *word, int lim) {
    int c;
    char *w = word;

    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (c == '#') {
        skip_line();
        return c;
    }
    if (c == '"' || c == '\'') {
        skip_quote(c);
        return c;
    }
    if (c == '/' && ((c = getch()) == '*' || c == '/')) {
        skip_comment(c);
        return c;
    }

    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++)
        if (!isalnum(*w = getch()) && *w != '_') {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}

void skip_quote(char type) {
    char prev, current;

    prev = type;
    current = '\0';
    while ((prev == '\\' || current != type) && prev != current) {
        prev = current;
        current = getch();
    }
}

void skip_comment(char c) {
    char prev;

    prev = '\0';
    if (c == '/')
        skip_line();
    else if (c == '*')
        while (prev != '*' && (c = getch()) != '/')
            prev = c;
}

void skip_line(void) {
    char c;

    while ((c = getch()) != '\n')
        ;
}

int cstack[STACKMAX];
int sp = 0;

int getch(void) {
    return (sp > 0) ? cstack[--sp] : getchar();
}

void ungetch(int c) {
    if (sp < STACKMAX)
        cstack[sp++] = c;
    else
        printf("error: stack is full\n");
}
