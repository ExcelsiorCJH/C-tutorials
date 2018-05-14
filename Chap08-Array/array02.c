// array02.c

#include <stdio.h>

int main(void){

    // 요소가 5개인 int형 배열의 선언 및 정의
    // int aList[] = { 10, 20, 30, 40, 50 };
    int aList[5] = { 10, 20, 30, 40, 50 };
    
    // 전체 요소의 값을 화면에 출력
    for(int i=0; i < 5; ++i)
        printf("%d\t", aList[i]);
    putchar('\n');

    // 일부 배열 요소의 값을 변경
    aList[0] = 100;
    aList[3] = 200;

    for(int i=0; i < 5; ++i)
        printf("%d\t", aList[i]);
    putchar('\n');

    return 0;
}