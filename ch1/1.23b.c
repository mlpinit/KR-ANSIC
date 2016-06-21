#include <stdio.h>

#define IN 1
#define OUT 0

void rmlcomment(void);
void rslcomment(void);
void pqcontent(void);

int main() {
    // character, next_character, previous_character
    int c, nc, pc;

    pc = '\0';

    while ((c = getchar()) != EOF) {
        if (pc != '\\' && pc != '\'' && c == '"') {
            putchar(c);
            pqcontent();
        } else if (pc != '\\' && pc != '\'' && c == '/' && (nc = getchar()) == '*')
            rmlcomment();
        else if (pc != '\\' && pc != '\'' && c == '/' && nc == '/')
            rslcomment();
        else if (pc != '\\' && pc != '\'' && c == '/') {
            putchar(c);
            putchar(nc);
        } else
            putchar(c);

        pc = c;
    }

    return 0;
}

// print multy line comment
void rmlcomment() {
    int c, d;

    c = getchar();
    d = getchar();
    while (c != '*' || d != '/') {
        c = d;
        d = getchar();
    }
}

// print single line comment
void rslcomment() {
    int c;

    while ((c = getchar()) != '\n')
        ;
    putchar(c);
}

// print quote content
void pqcontent(void) {
    int pc, c;

    pc = '\0';

    while ((c = getchar()) != '"' && pc != '\\') {
        putchar(c);
        pc = c;
    }
    putchar(c);
}
