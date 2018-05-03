// opcondi02.c
#include <stdio.h>

int main(void){

    int nInput = 0, nSelect = 0;
    scanf("%d", &nInput);

    // 조건식이 참이면 nSelect = 10이 되고
    // 거짓이면 nSelect = 20이 된다.
    // 연산식을 쓰려면 괄호로 묶어야 한다.
    nSelect = nInput <= 10 ? (nSelect = 10) : (nSelect = 20);
    printf("%d\n", nSelect);

    return 0;
}