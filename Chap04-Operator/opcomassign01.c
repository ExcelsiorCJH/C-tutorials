// opcomassign01.c
#include <stdio.h>

int main(void){
    int nResult = 0, nData = 10;

    nResult += 3;  // nResult = nResult + 3;
    printf("%d\n", nResult);

    nResult *= nData;  // nResult = nResult * nData;
    printf("%d\n", nResult);

    nResult /= 2;  // nResult = nResult / 2;
    printf("%d\n", nResult);

    nResult -= nData - 5;  // nResult = nReuslt - (nData - 5);
    printf("%d\n", nResult);

    nResult %= 3;  // nResult = nResult % 3;
    printf("%d\n", nResult);
    return 0;
}