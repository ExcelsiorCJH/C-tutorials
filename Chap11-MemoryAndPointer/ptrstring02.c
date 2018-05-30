// ptrstring02.c

#include <stdio.h>

int main(void){
    char szBuffer[16] = { "Hello" };
    char *pszData = szBuffer;

    // 문자열의 길이를 측정하기 위해 NULL 문자가 저장된 위치를 찾아낸다.
    while(*pszData != '\0')
        pszData++;

    // NULL 문자가 저장된 위치(주소)에서 시작 위치(주소)를 빼면
    // 문자열의 길이를 알 수 있다.
    printf("&pszData : %p, &szBuffer : %p\n", pszData, szBuffer);
    printf("Length : %d\n", pszData - szBuffer);
    return 0;
}