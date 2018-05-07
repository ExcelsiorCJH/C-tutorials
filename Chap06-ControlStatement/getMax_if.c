/*
6-1. if문을 이용한 최대값 구하기
사용자로부터 세 정수를 입력받아 그 중 가장 큰 수를 출력하는 프로그램
if문을 사용하여 작성
*/

#include <stdio.h>

int main(void){

    int nInput, nMax = 0;

    printf("정수를 입력하세요. : ");
    scanf("%d", &nInput);
    nMax = nInput;

    printf("정수를 입력하세요. : ");
    scanf("%d", &nInput);
    if(nMax < nInput)
        nMax = nInput;

    printf("정수를 입력하세요. : ");
    scanf("%d", &nInput);
    if(nMax < nInput)
        nMax = nInput;

    printf("MAX : %d", nMax);

    return 0;
}