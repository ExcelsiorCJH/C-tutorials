// pointer01.c

#include <stdio.h>

int main(void){
    
    int nData = 10;
    printf("%s\n", "nData");

    // 변수 nData에 들어 있는 값을 출력
    printf("%d\n", nData);
    // 변수 nData의 메모리 주소를 출력
    printf("%p\n", &nData);  // %p: pointer, 16진수로 출력
    return 0;
}
/* 출력결과
nData
10
0061FF2C
*/