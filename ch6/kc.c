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

int getword(char *word, int lim) {
    int c, getch(void);
    void ungetch(int);

    char *w = word;

    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++)
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
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
