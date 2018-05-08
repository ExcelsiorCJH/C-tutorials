/*
단계별 분류에 따른 버스요금 계산

0~3세   영유아  할인율 100%(무료)
4~13세  어린이  할인율 50%
14~19세 청소년  할인율 25%
20세이상    성인    할인율 0%
65세이상    어르신  할인율 100%
*/
#include <stdio.h>

int main(void){

    int nAge = 0, fee = 1000;
    double rate = 0.0;

    printf("나이를 입력하세요. : ");
    scanf("%d", &nAge);

    if (nAge >= 20 && nAge < 65)
        rate = 1.0;
    else if (nAge >= 14 && nAge <= 19)
        rate = 0.75;
    else if (nAge >= 4 && nAge <= 13)
        rate = 0.5;

    printf("최종요금 : %d원", (int)(rate * fee));
    return 0;
}