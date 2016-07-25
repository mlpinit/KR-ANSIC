#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINES 5000
#define NUMERIC 1
#define REVERSE 2
#define FOLD 4
#define DIRECTORY 8

char *lineptr[MAXLINES];
int options = 0;
int pos1 = 0; // field begining at pos1
int pos2 = 0; // field ending just before pos2

int readlines(char *lineptr[], int);
void writelines(char *lineptr[], int, int);

void myqsort(void *lineptr[], int, int, int (*comp)(void *, void *));
int numcmp(char *, char *);
int charcmp(char *s1, char *s2);
int readargs(int argc, char *argv[]);

int main(int argc, char *argv[]) {
    int nlines;
    int valid_args;

    valid_args = readargs(argc, argv);
    if (valid_args) {
        if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
            myqsort((void **) lineptr, 0, nlines-1, (options & NUMERIC) ? numcmp : charcmp);
            writelines(lineptr, nlines, options & REVERSE);
            return 0;
        } else {
            printf("input too big to sort\n");
            return 1;
        }
    }
}

int readargs(int argc, char *argv[]) {
    argv++;
    for (; argc > 1; --argc, ++argv) {
        if (**argv == '-' && isalpha(*(*argv + 1)))
            for (; **argv; ++*argv) {
                if (**argv == 'n')
                    options |= NUMERIC;
                if (**argv == 'r')
                    options |= REVERSE;
                if (**argv == 'f')
                    options |= FOLD;
                if (**argv == 'd')
                    options |= DIRECTORY;
            }
        else if (**argv == '-' || **argv == '+') {
            if (*argv[0]++ == '-') {
                pos1 = atof(*argv);
                pos2 += pos1;
            }
            else 
                pos2 += atof(*argv);
        }
        else if (**argv != '\0') {
            printf("ussage ./sort -nrfd -20 +10\n");
            return 0;
        }
    }

    return 1;
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

int charcmp(char *s1, char *s2) {
    int directory, fold;
    char tmp1, tmp2;

    fold = options & FOLD;
    directory = options & DIRECTORY;

    while (*s1 && *s2) {
        tmp1 = (islower(*s1) && fold) ? toupper(*s1) : *s1 ;
        tmp2 = (islower(*s2) && fold) ? toupper(*s2) : *s2 ;

        // change non alphanumeric, space or null characters
        if (!(isalnum(tmp1) || tmp1 == ' ' || tmp1 == '\0') && directory)
            tmp1 = 1;
        if (!(isalnum(tmp2) || tmp2 == ' ' || tmp2 == '\0') && directory)
            tmp2 = 1;

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
