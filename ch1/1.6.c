// verify that the expression getchar() != EOF is 0 or 1

#include <stdio.h>

int main() {
    int c;

    while(getchar() != EOF) {
        printf("This is not the end of file. Expression evaluates to 1.\n");
    }
    printf("This is the end of file. Expression evaluates to 0.\n");
}
