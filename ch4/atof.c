#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

int main() {
    char s[] = "     -243.1234   ";
    char t[] = " 443.1234   ";
    char z[] = " 443   ";

    printf("%f\n", atof(s));
    printf("%f\n", atof(t));
    printf("%f\n", atof(z));
}

double atof(char s[]) {
    int i, sign;
    double power, val;

    // skip spaces
    for (i = 0; isspace(s[i]); ++i)
        ;

    sign = 1;
    if (s[i] == '-' || s[i] == '+')
        sign = (s[i++] == '-') ? -1 : 1;

    // store part before dot
    val = 0.0;
    for (; isdigit(s[i]); ++i)
        val = val * 10.0 + (s[i] - '0');
    // skip dot
    if (s[i] == '.')
        ++i;
    power = 1;
    for (; isdigit(s[i]); ++i) {
        power *= 10.0;
        val = val * 10.0 + (s[i] - '0');
    }

    return sign * val/power;
}
