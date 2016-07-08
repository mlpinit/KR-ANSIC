// write a version of strcat(s,t) that concatenates the string t to the end of
// string s

#include <stdio.h>
#include <string.h>

#define MAXVALUE 100

void mystrcat(char*, char*);

int main(void) {

    char str1[MAXVALUE] = "Hello";
    char str2[MAXVALUE] = " world!";

    mystrcat(str1, str2);
    printf("%s\n", str1);

    return 0;
}

void mystrcat(char* s, char* t) {
    while (*s)
        ++s;
    while ((*s++ = *t++))
        ;
}
