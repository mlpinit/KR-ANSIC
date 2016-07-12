#include <stdio.h>
#include <stdlib.h>

#define MAXVALUE 100

void push(double);
double pop(void);

int main(int argc, char *argv[]) {
    double op;

    if (argc < 2) {
        printf("Pass in expression 2 3 4 + *\n");
        return 0;
    }

    while (--argc > 0) {
        // operator
        if ((op = atof(*++argv)) != 0.0 || *argv[0] == '0')
            push(op);
        // operand
        else {
            switch (*argv[0]) {
                case '+':
                    push(pop() + pop());
                    break;
                case '-':
                    op = pop();
                    push(pop() - op);
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '/':
                    op = pop();
                    if (op != 0.0)
                        push(pop() / op);
                    else
                        printf("error: division by zero\n");
                    break;
                default:
                    printf("error: unrecognized command '%c'\n", *argv[0]);
            }
        }
    }

    printf("\t%.8g\n", pop());

    return 0;
}

static double stack[MAXVALUE];
static int sp = 0;

void push(double f) {
    if (sp < MAXVALUE)
        stack[sp++] = f;
    else
        printf("error: stack full\n");
}

double pop(void) {
    if (sp > 0)
        return stack[--sp];
    else {
        printf("error: no elements on stack\n");
        return 0.0;
    }
}
