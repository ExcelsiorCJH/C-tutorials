// operator.c
#include <stdio.h>

int main(void){
    int nResult = 0;

    // 1. 3 + 4
    // 2. 7(임시결과) - 5
    // 3. nResult = 2
    nResult = 3 + 4 - 5;
    printf("nResult : %d\n", nResult);
    return 0;
}