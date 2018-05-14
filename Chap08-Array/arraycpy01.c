// arraycpy01.c
#include <stdio.h>

int main(void){

    int aList[5] = { 10, 20, 30, 40, 50 };
    int aListNew[5] = { 0 };

    // aListNew = aList;와 같은 코드는 불가능하며,
    // 아래와 같이 반복문으로 하나씩 복사해야 한다. (혹은 메모리 복사)
    for(int i=0; i<5; ++i)
        aListNew[i] = aList[i];

    for (int i = 0; i < 5; ++i)
        printf("%d\t", aListNew[i]);
    putchar('\n');

    return 0;
}