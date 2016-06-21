// Write a program to determine the ranges of char, short, int, long variables
// both signed and unsigned. Print direct values from standard headers or
// compute the values. Determine the ranges of the various floating point types.

#include <stdio.h>
#include <limits.h>

int main() {

    putchar('\n');
    printf("From <limits.h>:\n\n");
    printf("Signed char min value: %d\n", CHAR_MIN);
    printf("Signed char max value: %d\n", CHAR_MAX);
    printf("Unsigned char max value: %u\n", UCHAR_MAX);
    printf("Signed short min value: %d\n", SHRT_MIN);
    printf("Signed short max value: %d\n", SHRT_MAX);
    printf("Unsigned short max value: %u\n", USHRT_MAX);
    printf("Signed int min value: %d\n", INT_MIN);
    printf("Signed int max value: %d\n", INT_MAX);
    printf("Unsigned int max value: %u\n", UINT_MAX);
    printf("Signed long min value: %ld\n", LONG_MIN);
    printf("Signed long max value: %ld\n", LONG_MAX);
    printf("Unsigned long max value: %lu\n\n", ULONG_MAX);

    printf("Computed:\n\n");
    printf("Signed char min value: %d\n", ~(char)((unsigned char) ~0 >> 1));
    printf("Signed char max value: %d\n", (char)(unsigned char) ~0 >> 1);
    printf("Unsigned char max value: %u\n", (unsigned char) ~0);
    printf("Signed short min value: %d\n", ~(short)((unsigned short) ~0 >> 1));
    printf("Signed short max value: %d\n", (short)((unsigned short) ~0 >> 1));
    printf("Unsigned short max value: %u\n", (unsigned short) ~0);
    printf("Signed int min value: %d\n", ~(int)((unsigned int) ~0 >> 1));
    printf("Signed int max value: %d\n", (int)((unsigned int) ~0 >> 1));
    printf("Unsigned int max value: %u\n", (unsigned int) ~0);
    printf("Signed long min value: %ld\n", ~(long)((unsigned long) ~0 >> 1));
    printf("Signed long max value: %ld\n", (long)((unsigned long) ~0 >> 1));
    printf("Unsigned long max value: %lu\n\n", (unsigned long) ~0);

    return 0;
}
