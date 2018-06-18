// variable02.c
#include <stdio.h>

int TestFunc(void){

    // 접근성은 TestFunc() 내부로 제한된 지역변수이나
    // 기억부류는 스택이 아니라 데이터 영역인 '정적'변수 선언 및 정의
    // 정의는 이 함수가 여러번 호출 되더라도 단 한번만 적용된다.
    static int nData = 10;

    // nData의 값이 변경됐다.
    // 정적변수이므로 이 변경된 값은 함수가 반환하더라도 유지된다.
    ++nData;
    return nData;
}

int main(int argc, char* argv[]){
    // TestFunc() 함수를 호출할 때마다 다른 nData 값을 반환 받는다.
    printf("%d\n", TestFunc());
    printf("%d\n", TestFunc());
    printf("%d\n", TestFunc());
    return 0;
}
/* 출력결과
11
12
13
 */