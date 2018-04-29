// opinc01.c
#include <stdio.h>

int main(void){
    int x = 10;

    // 1. x에 저장된 값과 1을 더해 다시 x에 저장한다.
    x = x + 1;
    printf("%d\n", x);

    // 2. x에 저장되어 있는 값을 1을 누적한다.
    x += 1;
    printf("%d\n", x);

    // 3. x에 저장된 값을 1 증가시킨다.
    ++x;
    printf("%d\n", x);

    return 0;
}