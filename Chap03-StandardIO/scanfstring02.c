// scanfstring02.c
#include <stdio.h>

int main(void)
{
    char szBufferLeft[32] = {0};
    char szBufferRight[32] = {0};

    scanf("%s%s", szBufferLeft, szBufferRight);
    printf("%s %s \n", szBufferLeft, szBufferRight);
    return 0;
}