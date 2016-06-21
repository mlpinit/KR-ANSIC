// Line folding (account for tabs)

#include <stdio.h>

#define MAX_LINE 20
#define TABINC 8

char line[MAX_LINE];

int extend_tab(int pos);
void print_line(int pos);
int last_space();
int shift_line(int pos);

int main() {
    int c, pos;

    pos = 0;
    while ((c = getchar()) != EOF) {
        line[pos] = c; // store character

        if (c == '\t')
            pos = extend_tab(pos);
        else if (c == '\n') {
            print_line(pos);
            pos = 0;
        }
        else if (++pos == MAX_LINE) {
            pos = last_space();
            print_line(pos);
            pos = shift_line(pos);
        }
    }
}

void print_line(int pos) {
    int i;

    for (i = 0; i < pos; ++i)
        putchar(line[i]);

    // make sure that we don't print an empty line
    if (pos > 0)
        putchar('\n');
}

int extend_tab(int pos) {
    line[pos] = ' '; // replace the tab character with a space

    // check if position is one after tabstop or greater then MAX_LINE
    while (++pos % TABINC != 0 && pos < MAX_LINE)
        line[pos] = ' ';

    if (pos == MAX_LINE) {
        print_line(pos);
        pos = 0;
    }

    return pos;
}

int last_space() {
    int i;

    i = MAX_LINE - 1;
    while (i > 0 && line[i] != ' ')
        --i;

    // if there are no spaces in the input we print the entire line
    if (i == 0)
        return MAX_LINE;
    // return position after the blank
    else
        return i + 1;
}

int shift_line(int pos) {
    int j, i;

    for (i = 0, j = pos; j < MAX_LINE; ++j)
        line[i++] = line[j];

    return i;
}
