/* 
10-1. 사용자가 입력한 값에서 최대값 구하기 코드와 분할
*/

#include <stdio.h>

// 코드 분할
int GetData(void){
    int nInput = 0;
    printf("정수를 입력하세요. : ");
    scanf("%d", &nInput);

    return nInput;
}

int GetMax(int num1, int num2, int num3){
    int nMax = num1;

    if(num2 > nMax) nMax = num2;
    if(num3 > nMax) nMax = num3;

    return nMax;
}

void PrintData(int num1, int num2, int num3, int nMax){
    printf("%d, %d, %d 중 가장 큰 수는 %d 입니다.\n",
           num1, num2, num3, nMax);
}

int main(void){
    int aList[3] = {0};
    int nMax = -9999, i = 0;
    // 입력
    for (i = 0; i < 3; ++i)
        aList[i] = GetData();
    
    // 최대값 계산
    nMax = GetMax(aList[0], aList[1], aList[2]);

    // 출력
    PrintData(aList[0], aList[1], aList[2], nMax);
    return 0;

}

// 원래 코드
/* int main(void){
    int aList[3] = { 0 };
    int nMax = -9999, i = 0;
    // 입력
    for(i = 0; i < 3; ++i){
        printf("정수를 입력하세요. : ");
        scanf("%d", &aList[i]);
    }

    // 최대값 계산
    nMax = aList[0];
    for(i = 1; i < 3; ++i)
        if(aList[i] > nMax)
            nMax = aList[i];

    // 출력
    printf("%d, %d, %d 중 가장 큰 수는 %d 입니다.\n", 
        aList[0], aList[1], aList[2], nMax);
    return 0;
} */
