// ptrmemcpy01.c
#include <stdio.h>
// memcpy() 함수를 위한 헤더포함
#include <string.h>

int main(void){
    char szBuffer[12] = { "HelloWorld" };
    char szNewBuffer[12] = { 0 };

    // 원본에서 4 바이트만 대상 메모리로 복사
    memcpy(szNewBuffer, szBuffer, 4);
    puts(szNewBuffer);

    // 원본에서 6 바이트만 대상 메모리로 복사
    memcpy(szNewBuffer, szBuffer, 6);
    puts(szNewBuffer);

    // 원본 메모리 전체를 대상 메모리로 복사
    memcpy(szNewBuffer, szBuffer, sizeof(szBuffer));
    puts(szNewBuffer);
    return 0;
}
/* 출력결과
Hell
HelloW
HelloWorld
*/