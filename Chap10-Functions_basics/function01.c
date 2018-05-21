// function01.c
#include <stdio.h>

// 사용자 정의 함수의 선언 및 정의
// int 형식 자료 둘을 매개변수로 받아 합산결과를 반환
int Add(int a, int b){
    // Add() 함수의 지역변수 선언 및 정의
    int nData = 0;
    nData = a + b;

    // 합산 결과를 호출자 함수에 반환한다.
    return nData;
}

int main(void){

    int nResult = 0;

    // Add() 함수를 실인수 3과 4로 확정해 호출하고 결과를
    // 반환받아 nResult에 저장한다.
    nResult = Add(3, 4);
    printf("Result: %d\n", nResult);
    return 0;
}