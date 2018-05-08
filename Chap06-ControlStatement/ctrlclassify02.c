// ctrlclassify02.c

#include <stdio.h>

int main(void){

    int nInput = 0;
    // 일단 A학점으로 설정한다.
    char ch = 'A';
    printf("점수를 입력하세요. : ");
    scanf("%d", &nInput);

    // 첫 번째 조건(A학점)에 맞는지 확인한다.
    if (nInput >= 90) 
        ch = 'A';

    // 아니라면 그 다음 수준에 맞는지 확인한다.
    else if (nInput >= 80)
        ch = 'B';

    // 같은 논리를 반복한다.
    else if (nInput >= 70)
        ch = 'C';
    else if (nInput >= 60)
        ch = 'D';
    // 앞선 조건에 부합하는 것이 하나도 없는 경우
    else
        ch = 'F';

    printf("점수 : %d, 학점: %c\n", nInput, ch);
    return 0;
}