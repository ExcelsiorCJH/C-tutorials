/*
세 정수 중에서 가장 큰 수 구하기
    - 사용자로부터 입력받은 세 정수 중 가장 큰 수를 출력
    - scanf() 한번만 사용하여 세 정수를 모두 입력 받음
    - 입력 예:
        10 20 30
    - 출력 예:
        MAX : 30

<토너먼트 방식>
    1. A와 B를 비교하여 둘 중 더 큰 수 하나를 선택
    2. 1번 과정에서 선택한 값과 C를 비교하여 더 큰 수 하나를 선택
    3. 2번 과정에서 선택한 값을 최대값으로 확정
*/

#include <stdio.h>

int main(void){

    int nMax = 0;
    int a, b, c;

    scanf("%d%d%d", &a, &b, &c);

    nMax = a > b ? a : b;
    nMax = nMax > c ? nMax : c;

    printf("MAX : %d\n", nMax);
    return 0;
}