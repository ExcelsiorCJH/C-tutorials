// array05.c
#include <stdio.h>

int main(void){

    int aList[4][2][3] = { 0 };
    int i = 0, j = 0, k = 0, nCounter = 0;

    for(i = 0; i < 4; ++i){
        // 면
        printf("Plane number : %d\n", i);
        for(j = 0; j < 2; ++j){
            // 행
            for(k = 0; k < 3; ++k){
                // 열
                aList[i][j][k] = ++nCounter;
                printf("%d\t", aList[i][j][k]);
            }
            putchar('\n');
        }
        printf("\n\n");
    }
    return 0;
}