// arrayerror01.c
#include <stdio.h>

int main(void) {

    int aList[5] = { 10, 20, 30, 40, 50};
    int aListNew[5] = { 0 };
    int i = 0;

    // 배열 전체 요소를 동시에 대입하려 시도한다.
    // error가 발생한다. 배열이름은 메모리 주소이기 때문이다.
    // 따라서, l-value가 아니다.
    aListNew = aList;

    for(int i=0; i < 5; ++i)
        printf("%d\t", aListNew[i]);
    putchar('\n');

    return 0;
}