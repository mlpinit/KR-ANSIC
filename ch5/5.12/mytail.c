#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10 // default value of last n lines
#define MAXN 20 // max lines allowed to be displayed
#define ERROR -2

int readlines(char **);
void printnlines(int, char **);

int main(int argc, char *argv[]) {
    int n, error;
    char* lines[MAXN] = { NULL };

    n = N; // setting the default
    if (argc == 3 && **++argv == '-' && *(*argv + 1) == 'n' && (n = atoi(*++argv)))
        ;
    else if (argc > 1) {
        printf("error: not a valid format. Use ./mytail -n <nr>\n");
        return -1;
    }

    if (n > MAXN || n < 0) {
        printf("error: can't print more than %d lines\n", MAXN);
        return -1;
    }

    error = readlines(lines);
    if (!error)
        printnlines(n, lines);

    return 0;
}

void printnlines(int n, char **lines) {
    lines += n;
    while (n-- > 0)
        printf("%s", *(--lines));
}

#define MAXLINESIZE 1000

char* alloc(int);
int gline(char *, int);
void shift(char **, int);

int readlines(char **lines) {
    int len;
    char line[MAXLINESIZE];
    char *p;

    while ((len = gline(line, MAXLINESIZE)) != EOF) {
        if (len == ERROR) {
            printf("error: input line is too long.\n");
            return ERROR;
        }

        p = alloc(len); // allocate memory

        if (!p) {
            printf("error: out of memory.\n");
            return ERROR;
        }

        strncpy(p, line, MAXLINESIZE);
        shift(lines, MAXN);
        *lines = p;
    }

    return 0;
}

int gline(char* s, int limit) {
    char c;
    int len;

    for(len = 2; --limit > 1 && (c = getchar()) != EOF && c != '\n'; ++len)
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';

    // if c is a new line that means the string is within the specified
    // boundaries.
    if (c == '\n')
        return len;
    else
        return (c == EOF) ? EOF : ERROR;
}

void shift(char **lines, int lim) {
    int i;
    char *temp;
    char *startp = *lines;

    // navigate to the last line that doesn't point to null or the last line
    for (i = 0; i < lim && *lines; ++i)
        lines++;

    // shift pointers to the right
    while (*lines != startp) {
        *lines = *(lines - 1);
        lines--;
    }
}

#define MAXBUFFER 5000

char buffer[MAXBUFFER];
char* allocp = buffer;

char* alloc(int len) {
    if (allocp + len <= buffer + MAXBUFFER) {
        allocp += len;
        return allocp - len;
    }
    else
        return NULL;
}

