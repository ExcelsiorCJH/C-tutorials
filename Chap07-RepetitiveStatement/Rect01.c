/*
5행 5열의 사각형 출력하기
*/
#include <stdio.h>

int main(void){

    int i = 0;

    while(i < 5){
        int j = 0;
        while(j < 5){
            printf("*\t");
            ++j;
        }
        putchar('\n');
        ++i;
    }

    return 0;
}