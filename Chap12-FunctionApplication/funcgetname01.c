// funcgetname01.c
#include <stdio.h>

// 주소를 매개변수로 받을 때는 대상 메모리의 크기를 함께 받는 것이 좋다.
void GetName(char *pszName, int nSize){
    printf("이름을 입력하세요. : ");
    // 매개변수로 전달받은 주소를 다시 fgets() 함수의 인자로 넘긴다.
    fgets(pszName, nSize, stdin);
}

int main(int argc, char* argv[]){
    char szName[32] = { 0 };

    // 배열(주소)과 배열의 크기를 함수의 매개변수로 전달한다.
    GetName(szName, sizeof(szName));
    printf("당신의 이름은 %s 입니다.\n", szName);
    return 0;
}