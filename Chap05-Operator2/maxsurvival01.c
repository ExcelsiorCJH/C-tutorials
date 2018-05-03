/*
세 정수 중에서 가장 큰 수 구하기
    - 사용자로부터 입력받은 세 정수 중 가장 큰 수를 출력
    - 매번 입력할때마다 최대값을 구함 -> <서바이벌 방식>
*/

#include <stdio.h>

int main(void){

    int nMax = 0, nInput = 0;

    // 처음 입력받은 값은 일단 최대값이다.
    scanf("%d", &nInput);
    nMax = nInput;

    // 현재까지 확인한 최대값과 사용자가 입력한 값을 비교하고
    // 새로운 최대값을 결정한다.
    scanf("%d", &nInput);
    nMax = nInput > nMax ? nInput : nMax;

    // 현재까지 확인한 최대값과 사용자가 입력한 값을 비교하고
    // 새로운 최대값을 결정한다.
    scanf("%d", &nInput);
    nMax = nInput > nMax ? nInput : nMax;

    printf("MAX : %d\n", nMax);
    return 0;
}