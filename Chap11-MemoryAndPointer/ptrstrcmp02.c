// ptrstrcmp02.c

#include <stdio.h>
#include <string.h>

int main(void)
{

    char szBuffer[12] = {"TestString"};
    char *pszData = "TestString";

    // 다음 코드들은 두 문자열이 같은지 비교하는 것이 아니라
    // 문자열이 저장된 메모리의 위치가 같은지 비교하는 것이다.
    printf("%d\n", strcmp(szBuffer, pszData));
    printf("%d\n", strcmp("TestString", pszData));
    printf("%d\n", strcmp("Test", "TestString"));
    return 0;
}
/* 출력결과
0
0
-1
*/