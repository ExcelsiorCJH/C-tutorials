/*
7-6. 두 번째 직각 삼각형 출력하기
                 *
             *   *
        *    *   *
    *   *    *   *
*   *   *    *   *
*/

#include <stdio.h>

int main(void){

    // for (int i = 0; i < 5; ++i){
    //     for (int j = 0; j < 4-i; ++j){
    //         printf("\t");
    //     }
    //     for (int j = 0; j <= i; ++j){
    //         printf("\t*");
    //     }
    //     printf("\n");
    // }

    for (int i = 0; i < 5; ++i){
        for (int j = 0 ; j < 5; ++j){
            if (i + j >= 4)
                printf("*\t");
            else
                putchar('\t');
        }
        putchar('\n');
    }

    return 0;
}