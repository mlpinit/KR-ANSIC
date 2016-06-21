// Write a pogram to dispaly the conversion between fahrenheit and celsius using
// a function.

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20 

double celsius(int fahr) {
    return (5.0 / 9.0) * (fahr - 32);
}

int main() {
    int fahr;

    printf("Fahr Celsius\n");
    for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
        printf("%4d %7.1f\n", fahr, celsius(fahr)); 

    return 0;
}

