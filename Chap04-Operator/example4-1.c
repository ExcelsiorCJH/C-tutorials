/*
4-1. 두 정수를 입력받아 평균을 계산해
출력하는 프로그램

입력 예: 10 20
출력 예: AVG : 15.00 (반드시 소수점 둘째 자리까지만 표시)
*/
#include <stdio.h>

int main(void){

    int num1, num2 = 0;
    printf("두 정수를 입력하세요 : ");
    scanf("%d%d", &num1, &num2);

    printf("AVG : %.2f\n", (double)(num1 + num2)/2);
    
    return 0;
}