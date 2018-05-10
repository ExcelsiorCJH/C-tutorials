/*
7-3: 1에서 10까지의 총합 구하기
: while문을 사용
*/
#include <stdio.h>

int main(void){

    int i = 1, nSum = 0;
    
    while(i <= 10){
        nSum += i;
        ++i;
    } 
    printf("Total : %d", nSum);

    return 0;
}