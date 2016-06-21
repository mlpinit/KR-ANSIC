#include <stdio.h>

// fahrenheit to celsius table in reverse order.

int main() {
    int fahr;

    printf("Fahr Celsius\n");
    for (fahr = 300; fahr >= 0; fahr -= 20)
        printf("%4d %7.1f\n", fahr, (5.0 / 9.0) + (fahr - 32));
}
