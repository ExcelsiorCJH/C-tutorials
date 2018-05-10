// ctrlnestedloop01.c
#include <stdio.h>

int main(void){

    int i = 0, j = 0;

    i = 2;  // 카운팅 변수(계수) i 초기화
    while(i <= 9){
        j = 1;
        while(j <= 9){  // 계수 j 초기화
            printf("%d * %d = %d\n", i, j, i*j);
            ++j;
        }
        putchar('\n');
        ++i;
    }

    return 0;
}