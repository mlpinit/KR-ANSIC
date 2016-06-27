// Extend atof to handle extended scientific notation of the form 123.45e-6 or
// 123.45E+6 or 122.45e2 or 123.45E-6. (optionally signed exponent)

#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

int main(void) {
    char s[] = "    -1234.67  ";
    char s1[] = "    -1234.67E6  ";
    char s2[] = "    -1234.67e6  ";
    char s3[] = "    -1234.67E+6  ";
    char s4[] = "    -1234.67E-6  ";
    char s5[] = "    -1234.67e+6  ";
    char s6[] = "    -1234.67e-6  ";

    printf("%f\n", atof(s));
    printf("%f\n", atof(s1));
    printf("%f\n", atof(s2));
    printf("%f\n", atof(s3));
    printf("%f\n", atof(s4));
    printf("%f\n", atof(s5));
    printf("%f\n", atof(s6));

    return 0;
}

double atof(char s[]) {
    int i, sign, exponent;
    double power, val;

    // ignore white space
    for (i = 0; isspace(s[i]); ++i)
        ;

    sign = 1;
    if (s[i] == '-' || s[i] == '+')
        sign = (s[i++] == '-') ? -1 : 1;

    // get whole part
    val = 0.0;
    for (; isdigit(s[i]); ++i)
        val = val * 10.0 + s[i] - '0';

    // skip dot
    if (s[i] == '.')
        ++i;

    power = 1;
    for (; isdigit(s[i]); ++i) {
        val = val * 10.0 + s[i] - '0';
        power *= 10.0;
    }

    val = sign * val / power;

    if (s[i] == 'e' || s[i] == 'E') {
        sign = 1;
        if (s[++i] == '+' || s[i] == '-')
            sign = (s[i++] == '-') ? -1 : 1;
        for (exponent = 0; isdigit(s[i]); ++i)
            exponent = exponent * 10 + s[i] - '0';
        power = 1;
        for (i = 0; i < exponent; ++i)
            power *= 10;
        if (sign == -1)
            val /= power;
        else
            val *= power;
    }

    return val;
}
