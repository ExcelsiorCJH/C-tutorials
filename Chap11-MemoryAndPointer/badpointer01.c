#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    char *pszBuffer = NULL;

    pszBuffer = (char*)malloc(12);
    gets(pszBuffer);
    puts(pszBuffer);

    // 오류 확인을 위해 의도적으로 해제하지 않음
    // free(pszBuffer);
    return 0;
}