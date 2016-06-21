// Write a program to remove all comments from a c program.

#include <stdio.h>

#define IN 1
#define OUT 0

#define OUT_OF_CYCLE -1

int main() {
    // previous character, character, state, state of quotes
    int pc, c, comments_state, quotes_state, single_line_comment_state;
    int ago; // one cycle to not print the last comment delimiter of multy line comments

    single_line_comment_state = OUT;
    comments_state = OUT;
    quotes_state = OUT;
    pc = '\0'; // null character
    ago = -1;
    while ((c = getchar()) != EOF) {
        // mark inside or outside of quotes
        if (comments_state == OUT && single_line_comment_state == OUT && c == '"' && pc != '\'' && pc != '\\') {
            if (quotes_state == OUT)
                quotes_state = IN;
            else
                quotes_state = OUT;
        }
        // mark inside of multy line comment
        if (quotes_state == OUT && comments_state == OUT && single_line_comment_state == OUT && pc == '/' && c == '*')
            comments_state = IN;
        // mark inside of single line comment
        if (quotes_state == OUT && comments_state == OUT && single_line_comment_state == OUT && pc == '/' && c == '/')
            single_line_comment_state = IN;
        // cray cray
        if (ago == OUT)
            ago = IN;
        // print previous character if not inside of a line
        if (pc && comments_state == OUT && single_line_comment_state == OUT && ago != IN)
            putchar(pc);
        if (ago == IN)
            ago = OUT_OF_CYCLE;
        // mark outside of multy line comment
        if (quotes_state == OUT && comments_state == IN && single_line_comment_state == OUT && pc == '*' && c == '/') {
            ago = OUT;
            comments_state = OUT;
        }
        // mark outside of single line comment
        if (single_line_comment_state == IN && c == '\n')
            single_line_comment_state = OUT;
        // set previous character
        pc = c;
    }
    if (pc && comments_state == OUT && single_line_comment_state == OUT)
        putchar(pc);

    return 0;
}
