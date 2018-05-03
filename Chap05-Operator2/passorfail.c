/*
합격자와 불합격자를 분류하는 방법
 - 삼항 연산자를 사용해 150cm 이상이면 합격 아니면 불합격

 - 입력 예 : 
    키를 입력하세요. : 160
 - 출력 예 :
    결과 : 합격
*/

#include <stdio.h>

int main(void){

    int nInput = 0;
    printf("키를 입력 하세요. :");
    scanf("%d", &nInput);

    printf("결과 : %s", nInput >= 150 ? "합격" : "불합격");

    return 0;
}
