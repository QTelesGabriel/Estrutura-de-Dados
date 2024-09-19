#include <stdio.h>

int main() {
    
    char s[] = "Maria";
    char *ptr = s;

    printf("%c, %c\n", s[0], *ptr);
    printf("%c, %c\n", s[1], *(ptr + 1));
    printf("%c, %c\n", s[2], *(ptr + 2));
    printf("%c, %c\n", s[3], *(ptr + 3));
    printf("%c, %c\n", s[4], *(ptr + 4));

    return 0;
}