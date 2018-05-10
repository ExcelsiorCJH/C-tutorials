/*
7-4: 구구단에서 한 단만 출력하기
*/

#include <stdio.h>

int main(void){

    int nInput = 0, i = 1;

    printf("2 ~ 9 사이의 정수를 입력하세요. : ");
    scanf("%d", &nInput);

    if(nInput >=2 && nInput <= 9){
        while (i <= 9)
        {
            printf("%d * %d = %d\n", nInput, i, nInput*i);
            ++i;
        }
    } else {
        printf("ERROR");
    }
    
    return 0;
}