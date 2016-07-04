// Define a macro swap(t,x,y) that interchanges two arguments of type t.
// Block structure will help.

#include <stdio.h>

#define swap(t,x,y) { t temp; temp = x, x = y, y = temp; }

int main(void) {
    char m, p;
    int a, b;

    a = 4, b = 6;
    m = 'm', p = 'p';

    /* swap(int, a, b); */
    swap(char, m, p);

    /* printf("a was 4 and now it's %d and b was 6 and now it's %d\n", a, b); */
    printf("m was 'm' and now it's '%c' and p was 'p' and now it's '%c'\n", m, p);

    return 0;
}
