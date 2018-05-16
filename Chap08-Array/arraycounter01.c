// arraycounter01.c
#include <stdio.h>

int main(void){

    int aList[3][4] = { 0 };
    int i = 0, j = 0, nCounter = 0;

    // 3행 4열 배열의 각 요소를 순차적으로 1씩 증가하는 카운터로 채운다.
    // 행 단위의 바깥쪽 반복문
    for(i = 0; i < 3; ++i){
        // 한 행의 전체 열을 채우는 안쪽 반복문
        for(j = 0; j < 4; ++j){
            aList[i][j] = ++nCounter;
        }
    }

    for(i = 0; i < 3; ++i){
        for(j = 0; j < 4; ++j)
            printf("%d\t", aList[i][j]);
        putchar('\n');
    }

    return 0;
}
/*출력결과
1	2	3	4	
5	6	7	8	
9	10	11	12	
*/