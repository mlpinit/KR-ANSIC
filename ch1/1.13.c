#include <stdio.h>

// Write a program to print a program of the lenght of words in ints inpus.
// Print both a vertical and a horizontal historgram.

#define MAX_LENGTH_OF_WORD 51

int main() {
    int i, j, c, counter, max_counter, max_word;
    int lengths[MAX_LENGTH_OF_WORD];

    for (i = 0; i < MAX_LENGTH_OF_WORD; ++i)
        lengths[i] = 0;

    counter = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (counter < MAX_LENGTH_OF_WORD)
                ++lengths[counter];
            else if (counter != 0)
                // storying words longer than 50 characters in the unused position at index 0
                ++lengths[0]; 
            counter = 0;
        } else
            ++counter;
    }

    // find maximum histogram value
    // find longest word
    for (i = 1, max_counter = 0, max_word = 0; i < MAX_LENGTH_OF_WORD; ++i) {
        if (lengths[i] > max_counter)
            max_counter = lengths[i];
        if (lengths[i] > 0)
            max_word = i;
    }

    // print vertical
    for (i = 1; i <= max_word; ++i) {
        if (i < 10)
            putchar(' ');
        printf("%d: ", i);
        for (j = 0; j < lengths[i]; ++j)
            putchar('#');
        putchar('\n');
    }
    
    // print histograms separator
    printf("--------------------------------------------------------------------------------------------------------\n");

    // print horizontal
    for (i = max_counter; i > 0; --i) {
        for (j = 1; j <= max_word; ++j) {
            putchar(' ');
            putchar(' ');
            if (lengths[j] >= i)
                putchar('#');
            else
                putchar(' ');
        }
        putchar('\n');
    }
    for (i = 1; i <= max_word; ++i) {
        putchar(' ');
        if (i < 10)
            putchar(' ');
        printf("%d", i);
    }
    putchar('\n');

    // print separator
    printf("--------------------------------------------------------------------------------------------------------\n");
    if (lengths[0] > 0)
        printf("There (were/was) %d word(s) with more letters than %d.\n", lengths[0], MAX_LENGTH_OF_WORD - 1);
}
