// Exercise 4.3, 4.4

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'

void push(double);
double pop();
int getop(char s[]);

int main(void) {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
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
                    printf("error: Division by zero.\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push(fmod(pop(), op2));
                else
                    printf("error: Division by zero.\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: Unrecognized command '%s'\n", s);
                break;
        }
    }

    return 0;
}

#define MAXVALUE 100

int sp = 0;
double val[MAXVALUE];

void push(double f) {
    if (sp < MAXVALUE)
        val[sp++] = f;
    else
        printf("error: Stack full.\n");
}

double pop() {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: No elements in stack.\n");
        return 0.0;
    }
}

#include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[]) {
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    i = 0;
    if (!isdigit(c) && c != '.' && c != '-')
        return c;

    if (c == '-') {
        if (isdigit(c = getch()) || c == '.')
            s[++i] = c;
        else {
            if (c != EOF)
                ungetch(c);
            return '-';
        }
    }
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';

    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

int buf[BUFSIZE];
int bufp = 0;

int getch() {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("error: Not enough buffer space.\n");
    else
        buf[bufp++] = c;
}
