#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void myqsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);

int main(int argc, char *argv[]) {
    int nlines;
    int numeric = 0;
    
    if (argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric = 1;
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        myqsort((void **) lineptr, 0, nlines-1,
                (int (*)(void *, void *))(numeric ? numcmp :strcmp));
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }
}

void myqsort(void *v[], int left, int right, int (*comp)(void *, void *)) {
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    myqsort(v, left, last - 1, comp);
    myqsort(v, last + 1, right, comp);
}

#define MAXLINESIZE 100

int gline(char *, int);
char *alloc(int len);

int readlines(char *lineptr[], int max) {
    char line[MAXLINESIZE];
    int n, len;
    char *p;
    
    for (n = 0; n < max && (len = gline(line, MAXLINESIZE)) != EOF; ++n) {
        p = alloc(len);
        if (p) {
            strncpy(p, line, MAXLINESIZE);
            *lineptr++ = p;
        } else
            printf("error: out of memory\n");
    }

    return n;
}

int gline(char *line, int lim) {
    int len, c;

    for (len = 1; len < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++len)
        *line++ = c;
    if (c == '\n') {
        ++len;
        *line++ = c;
    }
    *line++ = '\0';

    if (c == EOF)
        return c;
    else
        return len;
}

void writelines(char *lineptr[], int nlines) {
    while (nlines--)
        printf("%s", *lineptr++);
}

int numcmp(char *s1, char *s2) {
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

void swap(void *v[], int i, int j) {
    void *temp;
    
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

#define MAXBUFFER 10000

static char buffer[MAXBUFFER];
static char *allocp = buffer;

char* alloc(int len) {
    if (allocp + len <= buffer + MAXBUFFER) {
        allocp += len;
        return allocp - len;
    }
    else
        return NULL;
}
