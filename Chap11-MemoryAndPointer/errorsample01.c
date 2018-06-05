/* 
11-01. 중대한 두 가지 오류
    - 다음 코드에서 두 가지 결함을 찾고 수정하기
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    
    char szBuffer[12] = {"HelloWorld"};
    char *pszData = NULL;

    pszData = (char*)malloc(sizeof(char) * 12);
    
    // pszData = szBuffer;  
    strcpy(pszData, szBuffer);
    puts(pszData);
    
    free(pszData);
    return 0;
}