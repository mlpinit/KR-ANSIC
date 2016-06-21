// Folding: Write a program to break long input lines into shorter lines at the
// last space right before the n-th column. Do something smart with lines that
// have no spaces.

#include <stdio.h>

#define MAX_LINE_SIZE 3

void empty_buffer(char buffer[], int length);

int main() {
    int i, c, buffer_length, line_length;
    char buffer[MAX_LINE_SIZE + 1];

    buffer_length = line_length = i = 0;
    while ((c = getchar()) != EOF)
        if (line_length + buffer_length == MAX_LINE_SIZE) {
            if (line_length == 0) {
                empty_buffer(buffer, buffer_length);
                buffer_length = 0;
            }
            putchar('\n');
            line_length = 0;
            // Store character in buffer as long as it's not a new line or a
            // space. We don't want new lines or spaces at the beginning of a
            // new line.
            if (c != '\n' && c != ' ') {
                buffer[buffer_length++] = c;
            }
        } else if (c == '\n') {
            empty_buffer(buffer, buffer_length);
            putchar('\n');
            buffer_length = 0;
            line_length = 0;
        } else {
            buffer[buffer_length++] = c;
            if (c == ' ') {
                // don't allow spaces at the beginning of the line
                if (buffer_length == 1)
                    --buffer_length;
                empty_buffer(buffer, buffer_length);
                line_length += buffer_length;
                buffer_length = 0;
            }
        }

    return 0;
}

void empty_buffer(char buffer[], int length) {
    int i;
    buffer[length] = '\0';
    printf("%s", buffer);
}
