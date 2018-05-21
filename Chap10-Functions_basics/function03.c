// function03.c

#include <stdio.h>

// 정수 셋을 매개변수로 받고 최대값을 반환하는 함수 선언 및 정의
int GetMax(int a, int b, int c){
    // GetMax() 함수의 지역변수 선언 및 정의
    int nMax = a;
    if (b > nMax) nMax = b;
    if (c > nMax) nMax = c;

    return nMax;
}

int main(void){

    int nResult = 0;

    // 함수가 반환한 값을 %d 형식으로 출력한다.
    printf("MAX: %d\n", GetMax(1, 2, 3));
    // 함수가 반환한 값에 *2 연산을 수행하고 %d 형식으로 출력한다.
    printf("MAX: %d\n", GetMax(2, 3, 1) * 2);

    // 함수가 반환한 값을 nResult 변수에 저장한 후
    // nResult에 저장된 값을 %d 형식으로 출력한다.
    printf("MAX: %d\n", nResult = GetMax(3, 1, 2));
    return 0;
}
/* 출력결과
MAX: 3
MAX: 6
MAX: 3
*/