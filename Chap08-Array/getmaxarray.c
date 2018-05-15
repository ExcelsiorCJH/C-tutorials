/*
8-1. 배열에서 최대값 구하기
*/

#include <stdio.h>

int main(void){

    int aList[5] = { 30, 40, 10, 50, 20 };
    int i = 0;

    // 여기에 코드 작성
    for(i = 1; i < 5; ++i)
        if(aList[0] < aList[i])
            aList[0] = aList[i];

    // 이하 코드는 수정하지 않는다.
    for(i = 0; i < 5; ++i)
        printf("%d\t", aList[i]);
    putchar('\n');

    printf("MAX: %d\n", aList[0]);
    return 0;
}