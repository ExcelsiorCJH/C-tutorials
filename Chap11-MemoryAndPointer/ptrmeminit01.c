// ptrmeminit01.c
#include <stdio.h>
// malloc(), calloc() 함수를 위한 헤더 포함
#include <stdlib.h>
// memset() 함수를 위한 헤더 포함
#include <string.h>

int main(void){
    int *pList = NULL, *pNewList = NULL;

    // A. int형 3개 배열 선언 및 정의(0 초기화)
    int aList[3] = { 0 };

    // B. int형 3개를 담을 수 있는 크기의 메모리를 동적으로 할당한 후
    // 메모리를 모두 0으로 초기화
    pList = (int*)malloc(sizeof(int) * 3);
    memset(pList, 0, sizeof(int) * 3);

    // C. int형 3개를 담을 수 있는 메모리를 0으로 초기화한 후 할당받음
    pNewList = (int*)calloc(3, sizeof(int));

    for(int i=0; i<3; ++i)
        printf("pList[%d]의 값 : %d\n", i, pList[i]);

    for (int i = 0; i < 3; ++i)
        printf("pNewList[%d]의 값 : %d\n", i, pNewList[i]);

    // 동적 할당한 메모리들을 해제
    free(pList);
    free(pNewList);
    return 0;
}
/* 출력결과
pList[0]의 값 : 0
pList[1]의 값 : 0
pList[2]의 값 : 0
pNewList[0]의 값 : 0
pNewList[1]의 값 : 0
pNewList[2]의 값 : 0
*/