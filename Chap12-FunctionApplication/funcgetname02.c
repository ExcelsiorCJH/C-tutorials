// funcgetname02.c
#include <stdio.h>
#include <stdlib.h>

// 주소를 반환하는 사용자 정의 함수 선언 및 정의
char* GetName(void){
    
    char *pszName = NULL;

    // 메모리를 동적 할당한다.
    pszName = (char*)calloc(32, sizeof(char));
    printf("이름을 입력하세요 : ");

    // 동적 할당한 메모리에 사용자가 입력한 문자열을 저장한다.
    fgets(pszName, sizeof(char)*32, stdin);
    // 동적 할당한 메모리의 주소를 호출자 함수에 반환한다.
    return pszName;
}

int main(int argc, char* argv[]){

    char *pszName = NULL;

    // 이름이 저장된 동적 할당된 메모리의 주소를 반환한다.
    pszName = GetName();
    printf("당신의 이름은 %s입니다.\n", pszName);

    // 호출자 함수가 메모리를 해제해야 한다.
    free(pszName);
    return 0;
}