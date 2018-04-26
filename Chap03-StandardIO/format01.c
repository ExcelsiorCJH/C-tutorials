// format01.c
#include <stdio.h>

int main(void)
{
    printf("%d\n", 1234);
    printf("%d, %d\n", 1234, -5678);
    // 부호를 붙여서 출력
    printf("%+d, %+d\n", 1234, -5678);

    // 정수를 8자리로 맞추고 오른쪽 정렬해 출력한다.
    printf("%8d\n", 1234);
    // 왼쪽 빈 공간을 모두 0으로 채워서 출력한다.
    printf("%08d\n", 1234);

    return 0;
}