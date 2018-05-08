// ctrlclassifybin01.c

#include <stdio.h>

int main(void){

    int nInput = 0;
    char ch = 'A';

    printf("점수를 입력하세요. : ");
    scanf("%d", &nInput);

    // 1차 분류: 전체 경우 중 중간 정도의 값으로 분류한다.
    if (nInput >= 80) {
        // 2차 상세 분류 A ~ B
        if (nInput >= 90) ch = 'A';
        else ch = 'B';
    } else {
        // 2차 상세 분류 C ~ F
        if (nInput >= 70) ch = 'C';
        else {
            // 3차 분류 D ~ F
            // 일단 D라고 확정한 후
            ch = 'D';
            // 60점 미만이면 F로 수정한다.
            if (nInput < 60) ch = 'F';
        }
    }

    printf("%c\n", ch);
    return 0;
}