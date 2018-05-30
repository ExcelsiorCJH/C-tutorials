// ptrnarray01.c

#include <stdio.h>

int main(void){
    // int 배열 선언 및 정의. 배열의 이름은 연속된 각 요소들 중
    // 전체를 대표하는 0번째 요소에 대한 '주소 상수'이다.
    int aList[5] = { 0 };
    // int에 대한 포인터 변수를 배열의 이름으로 정의한다.
    int *pnData = aList;  // => int *pnData = &aList[0];

    // 배열의 0번 요소의 값을 출력한다.
    printf("aList[0] : %d\n", aList[0]);

    // 포인터가 가리키고 있는 배열의 0번 요소의 값을 변경하고 출력한다.
    *pnData = 20;
    printf("aList[0] : %d\n", aList[0]);
    printf("pnData[0] : %d\n", pnData[0]);

    return 0;
}

/* 출력결과
aList[0] : 0
aList[0] : 20
pnData[0] : 20
*/