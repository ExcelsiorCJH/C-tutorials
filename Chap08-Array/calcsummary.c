/* 
8-3. 2차원 배열의 행과 열의 총합 계산하기
*/
#include <stdio.h>

int main(void){

    int aList[3][4] = {
        {10, 20, 30},
        {40, 50, 60}
    };
    int i = 0, j = 0;

    // 여기에 들어갈 코드를 작성
    for(i = 0; i < 2; ++i){
        int colSum = 0;
        for(j = 0; j < 4; ++j){
            colSum += aList[i][j];
            if(j == 3)
                aList[i][j] = colSum;
        }
    }

    for(j = 0; j < 4; ++j){
        int rowSum = 0;
        for(i = 0; i < 3; ++i){
            rowSum += aList[i][j];
            if(i == 2)
                aList[i][j] = rowSum;
        }
        
    }

    for(i = 0; i < 3; ++i){
        for(j = 0; j < 4; ++j)
            printf("%d\t", aList[i][j]);
        
        putchar('\n');
    }
    return 0;
}