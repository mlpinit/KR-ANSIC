#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int);
void writelines(char *lineptr[], int, int);

void myqsort(void *lineptr[], int, int, int (*comp)(void *, void *));
int numcmp(char *, char *);
int foldcmp(char *s1, char *s2);

int main(int argc, char *argv[]) {
    int nlines;
    int numeric, reverse, fold;
    char *pos;
    int (*function)(void *, void *);

    numeric = reverse = fold = 0;
    
    argv++;
    while (argc-- > 1) {
        pos = *argv++;
        while (*pos++) {
            if (*pos == 'n')
                numeric = 1;
            if (*pos == 'r')
                reverse = 1;
            if (*pos == 'f')
                fold = 1;
        }
    }

    if (numeric)
        function = numcmp;
    else if (fold)
        function = foldcmp;
    else
        function = strcmp;

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        myqsort((void **) lineptr, 0, nlines-1, function);
        writelines(lineptr, nlines, reverse);
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

void writelines(char *lineptr[], int nlines, int reverse) {
    if (reverse) {
        lineptr += nlines;
        while (nlines--)
            printf("%s", *--lineptr);
    }
    else
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

int foldcmp(char *s1, char *s2) {
    char tmp1, tmp2;

    while (*s1 && *s2) {
        tmp1 = (*s1 >= 'a' && *s1 <= 'z') ? *s1 - ('a' - 'A') : *s1 ;
        tmp2 = (*s2 >= 'a' && *s2 <= 'z') ? *s2 - ('a' - 'A') : *s2 ;

        if (tmp1 != tmp2)
            return (tmp1 < tmp2) ? -1 : 1;
        else if (tmp1 == '\0')
            return 0;
        ++s1, ++s2;
    }

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
