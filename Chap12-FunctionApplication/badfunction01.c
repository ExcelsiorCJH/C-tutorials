// badfunction01.c
#include <stdio.h>

int* TestFunc(void){

    int nData = 10;
    // 함수가 반환하면 소멸할 자동변수의 주소를 반환한다.
    return &nData;
}

int main(int argc, char* argv[]){

    int *pnResult = NULL;
    pnResult = TestFunc();

    // 포인터가 가리키는 대상 메모리는 유효하지 않은 메모리이다.
    printf("%d\n", *pnResult);
    return 0;
}

/* 출력결과
badfunction01.c:8:12: warning: function returns address of local variable 
 */