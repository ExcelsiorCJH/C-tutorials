// opsize01.c
#include <stdio.h>

int main(void){
    int nData = 10;

    // sizeof 연산자의 피연산자는 자료형이다.
    printf("%d, %d, %d\n", sizeof(5), sizeof(nData), sizeof(int));
    printf("%d, %d\n", sizeof('A'), sizeof(char));
    printf("%d, %d\n", sizeof(123.45F), sizeof(123.45));

    // 연산식 결과값의 자료형의 크기를 측정한다.
    printf("%d, %d\n", sizeof(nData +10), sizeof(++nData));
    printf("%d\n", nData);

    return 0;
}