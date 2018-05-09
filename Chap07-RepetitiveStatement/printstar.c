/*
7-1. 사용자가 입력한 숫자만큼 '*' 출력하기
사용자로 부터 1~9 범위의 정수를 입력받아 그 수만큼 '*'를 출력
입력이 -1인 경우 1로, 12를 입력했다면 9로 보정한 후 출력

ex. 
3 : ***
-1 : *
*/
#include <stdio.h>

int main(void){

    int nInput = 0, cnt = 0;

    printf("숫자를 입력하세요. : ");
    scanf("%d", &nInput);

    if (nInput < 0)
        nInput = 1;
    else if (nInput > 9)
        nInput = 9;

    while (cnt < nInput){
        putchar('*');
        cnt++;
    }

    return 0;
}