/*
6-2. 버스요금 계산 프로그램
버스의 기본요금을 1,000원이라고 가정하고 
나이가 20세 미만인 경우 25%할인 해주는 프로그램
*/

#include <stdio.h>

int main(void){

    int nAge = 0;
    int busFee = 1000;

    printf("나이를 입력하세요. : ");
    scanf("%d", &nAge);

    if(nAge < 20)
        busFee = (int) (0.75 * 1000);

    printf("최종요금 : %d원", busFee);
    return 0; 
}