// arraystring01.c
#include <stdio.h>

int main(void){

    // 배열 각 요소의 값을 하나씩 기술하는 방식으로 초기화
    int aList[5] = { 30, 40, 10, 50, 20 };
    char szBuffer[6] = { 'H', 'e', 'l', 'l', 'o', '\0' };

    // 문자열 형태로 문자집합을 기술하는 방식으로 배열 초기화
    char szData[8] = { "Hello" };

    // 문자열 상수를 가리키는 포인터 변수 선언 및 초기화
    char *pszBuffer = "Hello";

    // 문자열은 모두 같은 방식으로 출력
    puts(szBuffer);
    puts(szData);
    puts(pszBuffer);

    return 0;
}