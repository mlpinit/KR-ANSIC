// ./pattern match -xn
//
// options:
//  -x that doesn't contain the pattern
//  -n with a line number printed in front

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int gline(char *, int);

int main(int argc, char *argv[]) {
    char line[MAXLINE];
    long lineno = 0;
    int c, found = 0, except = 0, number = 0;

    while (--argc > 0 && (*++argv)[0] == '-')
        while ((c = *++argv[0]))
            switch (c) {
                case 'x':
                    except = 1;
                    break;
                case 'n':
                    number = 1;
                    break;
                default:
                    printf("find: illegal option %c\n", c);
                    argc = 0;
                    found = -1;
                    break;
            }

    if (argc != 1)
        printf("Usage: find -x - n pattern\n");
    else
        while (gline(line, MAXLINE) > 0) {
            lineno++;
            if ((strstr(line, *argv) != NULL) != except) {
                if (number)
                    printf("%ld:", lineno);
                printf("%s", line);
                found++;
            }
        }
    return found;
}

int gline(char *line, int max) {
    int c, len;

    for (len = 0; --max > 1 && (c = getchar()) != EOF && c != '\n'; ++len)
        *line++ = c;
    if (c == '\n')
       *line++ = c;
    *line = '\0';

    return len;
}
