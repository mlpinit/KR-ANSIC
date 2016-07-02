// Exercise:
// 4.3 negative numbers + modulus
// 4.4 commands for print top of stack, duplicate it, swap top 2 elements
// 4.5 add support for sin, cos, exp and pow 
// 4.6 add commands for handling variables + last variable

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'
#define NAME 'N'
#define VARIABLE 'V'
#define VARSMAX 26
#define LASTVAR 'L'
#define CLEAR 'C'
#define SWAP 'S'
#define DUPLICATE 'D'
#define PTOP 'P'

void push(double);
double pop();
int getop(char s[]);
void print_top(void);
void duplicate_top(void);
void swap_top_two(void);
void clear(void);
void mathfnc(char s[]);

int main(void) {
    int type, i;
    double op2, last_var;
    char s[MAXOP];
    double variables[VARSMAX];
    int last_referenced_variable = '\0';

    for (i = 0; i < VARSMAX; ++i)
        variables[i] = '\0';
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case NAME:
                mathfnc(s);
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
                last_var = pop();
                printf("\t%.8g\n", last_var);
                break;
            case '=':
                if (variables[last_referenced_variable - 'a']) {
                    variables[last_referenced_variable - 'a'] = pop();
                    pop();
                } else
                    variables[last_referenced_variable - 'a'] = pop();
                last_referenced_variable = '\0';
                break;
            case VARIABLE:
                last_referenced_variable = s[0];
                if (variables[last_referenced_variable])
                    push(variables[last_referenced_variable - 'a']);
                break;
            case PTOP:
                print_top();
                break;
            case DUPLICATE:
                duplicate_top();
                break;
            case SWAP:
                swap_top_two();
                break;
            case CLEAR:
                clear();
                break;
            case LASTVAR:
                push(last_var);
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
char current_variable = '\0';

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

void print_top(void) {
    printf("Top of stack: \t%.8g\n", val[sp - 1]);
}

void duplicate_top(void) {
    push(val[sp - 1]);
}

void swap_top_two(void) {
    double one, two;
    one = pop();
    two = pop();
    push(one);
    push(two);
}

void mathfnc(char s[]) {
    double op2;

    if (strcmp(s, "sin") == 0)
        push(sin(pop()));
    else if (strcmp(s, "cos") == 0)
        push(cos(pop()));
    else if (strcmp(s, "exp") == 0)
        push(exp(pop()));
    else if (strcmp(s, "pow") == 0) {
        op2 = pop();
        push(pow(pop(), op2));
    } else
        printf("error: name '%s' not recognized\n", s);
}

void clear(void) {
    sp = 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);
void ungetcs(char []);

int getop(char s[]) {
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    i = 0;
    if (islower(c)) {
        while (islower(s[++i] = c = getch()))
            ;
        if (c != EOF)
            ungetch(c);
        s[i] = '\0';

        if (strlen(s) > 1)
            return NAME;
        else if ('a' <= s[0] && s[0] <= 'z')
            return VARIABLE;
        else
            return c;
    }
    s[1] = '\0';
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

void ungetcs(char s[]) {
    int len;
    
    len = strlen(s);
    while (len > 0)
        ungetch(s[--len]);
}
