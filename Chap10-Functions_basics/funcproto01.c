// funcproto01.c
#include <stdio.h>

// Add()란 함수가 있다는 사실을 컴파일러에 우선 알린다.(선언)
int Add(int, int);

int main(void){
    // Add() 함수가 존재한다는 사실을 컴파일러가 알고 있으므로
    // 컴파일 오류는 발생하지 안ㅅ는다. 
    printf("%d\n", Add(3, 4));
    return 0;
}

// 원형 선언에 이어진 함수 정의
int Add(int x, int y){
    return x + y;
}