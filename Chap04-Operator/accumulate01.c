// accumulate01.c
/*
사용자로부터 세 정수를 입력받아 총합을 출력
*/
#include <stdio.h>

int main(void){
    int nInput, nTotal = 0;

    scanf("%d", &nInput);
    nTotal += nInput;

    scanf("%d", &nInput);
    nTotal += nInput;

    scanf("%d", &nInput);
    nTotal += nInput;

    printf("Total = %d", nTotal);
    
    return 0;
}