// funcrec01.c
#include <stdio.h>

int main(void){

    int nFact = 1;
    for(int i=5; i>=1; --i)
        nFact *= i;

    printf("5! == %d\n", nFact);
    return 0;
}

/* 출력결과
5! == 120
 */