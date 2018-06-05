// ptrmemcmp01.c

#include <stdio.h>
#include <string.h>

int main(void){

    char szBuffer[12] = {"TestString"};
    char *pszData = "TestString";

    // 두 메모리에 저장된 값이 같은 경우
    printf("%d\n", memcmp(szBuffer, pszData, 10));

    // 왼쪽("teststring")이 더 큰 경우
    printf("%d\n", memcmp("teststring", pszData, 10));

    // 오른쪽(pszData)이 더 큰 경우
    printf("%d\n", memcmp("DataString", pszData, 10));

    return 0;
}
/*출력결과
0
1
-1
*/