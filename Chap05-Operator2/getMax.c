/*
세 정수 중에서 가장 큰 수 구하기 <서바이벌 방식>
*/
#include <stdio.h>

int main(void){

    int nMax = -9999, nInput = 0;

    scanf("%d", &nInput);
    nMax = nInput;

    scanf("%d", &nInput);
    nMax = nInput > nMax ? nInput : nMax;

    scanf("%d", &nInput);
    nMax = nInput > nMax ? nInput : nMax;

    printf("MAX : %d\n", nMax);
    return 0;
}