// arraylookup01.c

#include <stdio.h>

int main(void){

    // 전체 경우에 대한 과금률 결과를 담은 배열의 선언 및 정의
    double aRate[10] = {
        0.0, 0.1, 0.25,  // 1~3세 0%, 10%, 25%
        0.5, 0.5,  // 4~5세
        0.6, 0.65,  // 6~7세
        0.8, 0.82, 0.97  // 8~10세
    };
    int nAge = 0, i = 0, nFee = 1000;

    // 요금표를 출력한다.
    printf("요금표\n");
    for(i = 1; i <= 10; ++i)
        printf("%d세 요금 : \t%d원\n", i, (int)(nFee * aRate[i - 1]));
    putchar('\n');

    // 나이를 입력받고 배열 인덱스 범위 내부로 값을 강제 조정한다.
    printf("나이를 입력하세요. : ");
    scanf("%d", &nAge);
    if(nAge < 1)
        nAge = 1;
    else if (nAge > 10)
        nAge = 10;

    // 나이에 맞는 배열요소를 선택하고 별다른 제어문 없이 즉시 값을 출력한다.
    printf("최종요금: %d원\n", (int)(nFee * aRate[nAge - 1]));
    putchar('\n');
    return 0;
}