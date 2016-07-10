#include <stdio.h>

int date_to_days(int, int, int);
void day_to_date(int, int, int*, int*);

int main(void) {
    int day;
    int month;

    printf("%d\n", date_to_days(2016, 7, 10));
    printf("%d\n", date_to_days(2016, 7, 32));
    printf("%d\n", date_to_days(2016, 2, 30));
    printf("%d\n", date_to_days(2016, 13, 30));

    day_to_date(2016, 192, &day, &month);
    printf("%d-%d-%d\n", 2016, day, month);

    day_to_date(2016, 427, &day, &month);
    printf("%d-%d-%d\n", 2016, day, month);

    return 0;
}

static char daytab[2][13] = {
    { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
    { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

int date_to_days(int year, int month, int day) {
    int leap;
    char *p;

    leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    // check valid month
    if (month > 12 || month < 1) {
        printf("error: month '%d' is not an accepted value\n", month);
        return 0;
    }
    // check valid day
    if (daytab[leap][month] < day) {
        printf("error: day '%d' must be smaller or equal than %d\n", day, daytab[leap][month]);
        return 0;
    }

    p = daytab[leap];
    while (--month)
        day += *++p;

    return day;
}

void day_to_date(int year, int days, int* day, int* month) {
    int leap;

    leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    if (days - leap > 366) {
        printf("error: There are only %d days in this year\n", leap ? 366 : 365);
        *month = 0, *day = 0;
        return;
    }

    for (*month = 1, *day = days; *day > daytab[leap][*month]; *day -= daytab[leap][*month])
        ++*month;
}
