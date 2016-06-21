#include <stdio.h>

int main() {
    int lower, upper, step;
    float fahr, celsius;

    lower = 0;
    upper = 300;
    step = 20;

    printf("Celsius\t\tFahr\n");
    for (celsius = 0; celsius <= upper; celsius += step) {
        fahr = (9.0 * celsius / 5.0) + 32;
        printf("%7.0f\t\t%4.1f\n", celsius, fahr);
    }

    return 0;
}
