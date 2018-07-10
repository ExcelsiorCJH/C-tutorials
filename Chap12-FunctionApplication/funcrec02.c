// funcrec02.c
#include <stdio.h>

// 계승을 계산하고 결과를 반환하는 함수
int GetFactorial(int nParam){

    int nResult = 0;
    // 재귀호출을 띁내기 위한 조건식! 반복문의 조건식과 같다.
    if (nParam == 1) return 1;

    // 매개변수의 값을 1 감소시켜 자기 자신을 다시 호출한다.
    // 이는 반복문의 계수기와 같다.
    nResult = nParam * GetFactorial(nParam - 1);
    printf("nResult = %d\n", nResult);
    return nResult;
}

int main(void){

    printf("5! == %d\n", GetFactorial(5));
    return 0;
}

/* 출력결과
nResult = 2
nResult = 6
nResult = 24
nResult = 120
5! == 120
 */