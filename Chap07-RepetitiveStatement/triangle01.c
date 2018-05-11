/*
7-5. 첫 번째 직각 삼각형 출력하기
*
*   *
*   *   *
*   *   *   *
*   *   *   *   *
*/
#include <stdio.h>

int main(void){
    for (int i = 0; i < 5; ++i){
        for (int j = 0; j <= i; ++j){
            printf("*\t");
        }
        printf("\n");
    }

    return 0;
}