// write getline (ch<1,4>), atoi, itoa (ch<2,3,4>) reverse (ch3), strindex and
// getop (ch4)

#include <stdio.h>
#include <string.h>

#define LIMIT 100

int gline(char *, int lim);
int atoi(char *);
void itoa(int nr, char *str);
void reverse(char *);

int main(void) {
    int count;
    char nr[] = "2345";
    char line[LIMIT];
    char str[LIMIT];


    printf("%d\n", atoi(nr));

    itoa(423, str);
    printf("%s\n", str);

    while ((count = gline(line, LIMIT)))
        printf("count(%d): %s", count, line);

    return 0;
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

int atoi(char *array) {
    int nr;

    nr = 0;
    while (*array)
        nr = nr * 10 + (*array++ - '0');

    return nr;
}

void itoa(int nr, char *str) {
    char* start = str;
    do {
        *str++ = nr % 10 + '0';
    } while (nr /= 10);
    *str = '\0';
    reverse(start);
}

void reverse(char *str) {
    char temp;
    char* t = str + strlen(str) - 1;

    while (str < t) {
        temp = *str;
        *str++ = *t;
        *t-- = temp;
    }
}
