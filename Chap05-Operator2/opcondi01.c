// opcondi01.c
#include <stdio.h>

int main(void){

    int nInput = 0, nSelect = 0;
    scanf("%d", &nInput);

    // 조건식이 참이면 nSelect = 10이 되고
    // 거짓이면 nSelect = 20이 된다.
    nSelect = nInput <= 10 ? 10 : 20;
    printf("%d\n", nSelect);

    return 0;
}