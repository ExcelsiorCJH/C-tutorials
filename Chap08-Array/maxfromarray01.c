// maxfromarray01.c
#include <stdio.h>

int main(void){

    int aList[5] = { 30, 10, 40, 20, 50 };
    // 배열의 첫 번째 요소를 최대값으로 설정한다.
    int i = 0, nMax = aList[0];

    // 이후 두 번째 요소부터 마지막 요소까지 비교한다.
    for(i = 0; i < 5; ++i)
        if(aList[i] > nMax)
            nMax = aList[i];

    // 전체 요소 및 최대값을 출력한다.
    for(i = 0; i < 5; ++i)
        printf("%d\t", aList[i]);
    putchar('\n');
    printf("MAX: %d\n", nMax);
    return 0;
}