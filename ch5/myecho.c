#include <stdio.h>

int main(int argc, char *argv[]) {

    printf("Program name: %s\n", *argv);

    while (--argc > 0)
        printf(argc > 1 ? "%s " : "%s\n", *++argv);

    return 0;
}
