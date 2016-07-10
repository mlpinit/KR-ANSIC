#include <stdio.h>
#include <string.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

int main(void) {
    int nlines;

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too bug to sort\n");
        return 1;
    }
}

#define MAXLEN 1000

int gline(char *, int);
char* alloc(int);

int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = gline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

int gline(char* line, int lim) {
    int c;
    char* t = line;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *line++ = c;
    if (c == '\n')
        *line++ = c;
    *line = '\0';

    return line - t;
}

void writelines(char *lineptr[], int nlines) {
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

void qsort(char *v[], int left, int right) {
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right)
        return;
    swap(v, left, (right - left) / 2 + left);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last + 1, right);
}

void swap(char *v[], int i, int j) {
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

#define ALLOCSIZE 50000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char* alloc(int size) {
    char *p;

    // memory is cast to integer on comparison to integer
    if (allocbuf + ALLOCSIZE - allocp >= size) {
        allocp += size;
        return allocp - size;
    } else
        return NULL;
}

