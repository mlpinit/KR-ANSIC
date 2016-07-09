// Write versions of the library functions strncpy, strncat, and strncmp, which
// operate on at most the first n characters of their argument strings. For
// example, strncpu(s,t,n) copies at most n characters of t to s.
//
// Unsafe to use this family of functions because they require manual null
// termination and because if the n provided is greater than the size of the
// destination string the behavior is undefined.

#include <stdio.h>

#define count_of(s) (sizeof(s)/sizeof(s[0]))

#define MAXVALUE 100

void mystrncpy(char *, char *, int n);
void mystrncat(char *, char *, int n);
int mystrncmp(char *, char *, int n);

int main(void) {
    int i;

    char dst[6];
    char str[MAXVALUE] = "Output: ";
    char str1[] = "Joy";
    char str2[] = "Hello";
    char str3[] = "Hello World";

    mystrncpy(dst, str3, count_of(dst) - 1);
    dst[count_of(dst) - 1] = '\0';
    printf("%s\n", dst);

    mystrncat(str, str3, count_of(str));
    printf("%s\n", str);

    printf("%d\n", mystrncmp(str1, str2, count_of(str1)));
    printf("%d\n", mystrncmp(str2, str3, count_of(str1)));
    printf("%d\n", mystrncmp(str3, str2, count_of(str1)));

    return 0;
}


void mystrncpy(char* dst, char* src, int n) {

    while (n-- && (*dst++ = *src++))
        ;

    for (; n-- > 0; *dst++ = '\0')
        ;
}


void mystrncat(char *dst, char *src, int n) {
    // go to end of destination string
    while (*dst)
        ++dst;
    while (n-- && *src)
        *dst++ = *src++;
    *dst = '\0';
}

int mystrncmp(char *str1, char *str2, int n) {
    while (--n && *str1) {
        // if null terminated break
        if (!str1)
            break;
        // if difference return unsinged 
        if (*str1 != *str2)
            return (unsigned char *) str1 - (unsigned char *) str2;
        --str1, --str2;
    }

    return 0;
}
