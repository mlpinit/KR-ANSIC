// keyword counter
#include "getword.h"

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
