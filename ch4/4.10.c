// Use getline to process calculator input. This makes ungetch and getch
// superfluous.
//
// line string
// name or variable or number string
// doubles array
// int array for variables
//
// while line is not EOF move through line
//      if digit collect number
//      if lowercase letter collect name for sin, cos .. or variable  

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_LINE_SIZE 1000
#define NUMBER '0'

char getop(char [], char []);
double pop();
void push(double);

int gline(char [], int);

int lp = 0; // line position

int main(void) {
    char type;
    int size;
    double op2;
    char line[MAX_LINE_SIZE];
    char s[MAX_LINE_SIZE];

    while ((size = gline(line, MAX_LINE_SIZE))) {
        if (size >= MAX_LINE_SIZE)
            printf("error: line provided is too long\n");
        else {
            while ((type = getop(s, line)) != '\n') {
                switch (type) {
                    case NUMBER:
                        push(atof(s));
                        break;
                    case '+':
                        push(pop() + pop());
                        break;
                    case '*':
                        push(pop() * pop());
                        break;
                    case '-':
                        op2 = pop();
                        push(pop() - op2);
                        break;
                    case '/':
                        op2 = pop();
                        if (op2 != 0.0)
                            push(pop() / op2);
                        else
                            printf("error: Division with 0\n");
                        break;
                    default:
                        printf("error: unknown command\n");
                        break;
                }
            }
            printf("\t%.8g\n", pop());
            lp = 0;
        }
    }

    return 0;
}

// gline returns -1 when 
//
// handle scenario when over line size limit
int gline(char s[], int lim) {
    int i, c;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';

    if (c != '\n')
        while ((c = getchar()) != '\n' && c != EOF)
            ++i;

    return i;
}

#include <ctype.h>

#define VALSIZE 100

double values[VALSIZE];
int sp = 0; // stack position

char getop(char s[], char line[]) {
    int i;

    while ((s[0] = line[lp++]) == ' ' || s[0] == '\t')
        ;
    s[1] = '\0';

    if (!isdigit(s[0]) && s[0] != '.' && s[0] != '-')
        return s[0];
    i = 0;
    // return - or continue collecting the rest of the number
    if (s[0] == '-' && !isdigit(s[++i] = line[lp++]) && s[i] != '.')
        return '-';

    if (isdigit(s[i]))
        while (isdigit(s[++i] = line[lp++]))
            ;
    if (s[i] == '.')
        while (isdigit(s[++i] = line[lp++]))
            ;
    s[i] = '\0';
    --lp;

    return NUMBER;
}

double pop() {
    if (sp > 0)
        return values[--sp];
    else {
        printf("error: no values on stack\n");
        return 0.0;
    }
}

void push(double f) {
    if (sp < VALSIZE)
        values[sp++] = f;
    else
        printf("error: stack full; can't add values\n");
}
