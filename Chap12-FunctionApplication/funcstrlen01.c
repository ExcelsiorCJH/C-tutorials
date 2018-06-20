// funcstrlen01.c
#include <stdio.h>

// 매개변수로 전달된 문자열의 길이를 반환하는함수
int GetLength(const char *pszParam){

    int nLength = 0;
    while(pszParam[nLength] != '\0')
        nLength++;

    return nLength;
}

int main(int argc, char* argv[]){

    char *pszData = "Hello";

    printf("%d\n", GetLength("Hi"));
    printf("%d\n", GetLength(pszData));
    return 0;
}
/* 출력결과
2
5
*/