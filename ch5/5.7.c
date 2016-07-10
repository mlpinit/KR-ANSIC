#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXSTORE 10000

int readlines(char *[], int nlines, char *);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

int main(void) {
    char *lineptr[MAXLINES];
    char linestore[MAXSTORE];

    int nlines;

    if ((nlines = readlines(lineptr, MAXLINES, linestore)) >= 0) {
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

int readlines(char *lineptr[], int maxlines, char *linestore) {
    int len, nlines;
    char line[MAXLEN];
    char *p = linestore;
    char *linestop = linestore + MAXSTORE;

    nlines = 0;
    while ((len = gline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || p + len > linestop)
            return -1;
        else {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
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
