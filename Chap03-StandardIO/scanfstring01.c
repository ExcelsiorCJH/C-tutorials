// scanfstring01.c
#include <stdio.h>

int main(void)
{
    // 문자열을 저장하기 위한 배열 선언 및 정의
    char szBuffer[32] = {0};

    // 사용자가 입력한 문자열을 배열에 저장하고 출력
    scanf("%s", szBuffer);
    printf("%s\n", szBuffer);
    return 0;
}