/* 
지그재그로 2차원 배열 채우기
*/
#include <stdio.h>

int main(void){

    int aList[5][5] = {0};
    int i = 0, j = 0, cnt = 0;
    
    for(i = 0; i < 5; i=i+2){
        for(j = 0; j < 5; ++j)
            aList[i][j] = (5 * i) + (j + 1);
    }
    for(i = 1; i < 5; i=i+2){
        ++cnt;
        for(j = 4; j >= 0; --j)
            aList[i][j] = (10 * cnt) - j;
    }

    for(i = 0; i < 5; ++i){
        for (j = 0; j < 5; ++j)
            printf("%d\t", aList[i][j]);
        putchar('\n');
    }
        
    return 0;
}