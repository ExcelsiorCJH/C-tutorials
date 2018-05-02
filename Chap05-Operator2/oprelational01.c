// oprelational01.c
#include <stdio.h>

int main(void){
    
    int x = 5, y = 10;

    printf("%d\n", x == y);
    printf("%d\n", x != y);
    printf("%d\n", x > 5);
    printf("%d\n", y < 5);
    printf("%d\n", y >= 10);

    // 산술연산은 관계연산보다 우선
    // 따라서 x + 5의 결과가 관계연산에 적용
    printf("%d\n", y <= x + 5);

    return 0;
}