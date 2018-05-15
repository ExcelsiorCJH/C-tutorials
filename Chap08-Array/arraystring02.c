// arraystring02.c
#include <stdio.h>

int main(void){

    char szBuffer[32] = { 0 };
    int nLength = 0;

    // 이름을 입력받아 배열에 저장한다.
    printf("Input your name : ");
    gets(szBuffer);

    // 배열의 시작부터 '\0'가 나올 때까지 계속 다음으로 넘기고 확인한다.
    while(szBuffer[nLength] != '\0')
        nLength++;

    // 이름과 문자열의 길이를 출력한다.
    printf("Your name is %s(%d).\n", szBuffer, nLength);
    return 0;
}