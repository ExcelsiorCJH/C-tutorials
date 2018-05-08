/*
나이에 따른 문류 및 요금 계산

0~3세   영유아  할인율 100%(무료)
4~13세  어린이  할인율 50%
14~19세 청소년  할인율 25%
20세이상    성인    할인율 0%

- if else 문을 두 번 중첩
- 요금 계산
*/

#include <stdio.h>

int main(void){

    int nAge = 0; 
    double nRate = 1.0; 
    int fee = 1000;

    printf("나이를 입력 하세요. : ");
    scanf("%d", &nAge);

    if (nAge < 20) {
        if (nAge >= 14 && nAge <= 19) {
            printf("나이(14~19): %d\n", nAge);
            nRate = 0.75; 
        } else {
            if (nAge >= 4 && nAge <=13) {
                printf("나이(4~13): %d\n", nAge);
                nRate = 0.5; 
            } else { 
                printf("나이(0~3): %d\n", nAge);
                nRate = 0; 
            }
        }
    }

    printf("최종요금 : %d\n", (int) (nRate * fee));
    return 0;
}
