// ctrlbranch02.c
#include <stdio.h>

int main(void){

    int nAge = 0;

    printf("나이를 입력하세요. : ");
    scanf("%d", &nAge);

    // if문의 시작
    if(nAge >= 20) {
        // 조건식을 만족했을 때 실행할 구문들
        // 여러 구문을 실행해야 한다면 반드시 블록 스코프로 묶는다.
        printf("처리 전, 당신의 나이는 %d세 입니다.\n", nAge);
        nAge = 20;
    }  // if 문 끝

    printf("당신의 나이는 %d세 입니다.\n", nAge);
    return 0;
}