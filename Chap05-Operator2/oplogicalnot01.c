// oplogicalnot01.c
#include <stdio.h>

int main(void){

    int nInput = 0, bResult = 0;

    scanf("%d", &nInput);
    // 사용자가 입력한 값이 0이 아니면 참
    // 원래라면 사용자가 0을 입력하면 거짓이나
    // ! 연산을 수행해 참이된다.
    // 반대로 0 외의 값을 입력하면 원래는 참이나
    // ! 연산을 통해 거짓이 된다.
    bResult = !nInput;
    printf("Result: %d (1: True, 0: False)\n", bResult);
    return 0;
}