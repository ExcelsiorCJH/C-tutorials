// oprelational02.c
#include <stdio.h>
#include <string.h>

int main(void){

    char ch1[5] = {"ABCD"};

    // memcmp(*str1, *str2, n)
    // n: the number of bytes to be compared.
    printf("%d\n", memcmp(ch1, "ABCD", 5));

    // strcmp(*str1, *str2)
    printf("%d\n", strcmp(ch1, "AEFG"));

    return 0;
}