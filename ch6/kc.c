// keyword counter

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof(struct key))

struct key {
    char *word;
    int count;
} keytab[] = {
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    "else", 0,
    "exit", 0,
    "for", 0,
    "go", 0,
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0
};


int getword(char *, int);
int binsearch(char *, struct key *, int);

int main(void) {
    int n;
    char word[MAXWORD];

    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            if ((n = binsearch(word, keytab, NKEYS)) >= 0)
                keytab[n].count++;
    for (n = 0; n < NKEYS; n++)
        if (keytab[n].count >0)
            printf("%4d %s\n", keytab[n].count, keytab[n].word);

    return 0;
}

int binsearch(char *word, struct key * pairs, int size) {
    int low, mid, high, cond;

    low = 0, high = size - 1;
    while (low <= high) {
        mid = low + (high - low) / 2;
        cond = strcmp(word, pairs[mid].word);
        if (cond < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }

    return -1;
}

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

#define STACKMAX 100

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
