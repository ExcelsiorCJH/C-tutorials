// opdoubleint.c
#include <stdio.h>

int main(void){
    
    int x = 10;

    // int * int -> %d
    printf("x * 10 = %d\n", x * 10);
    // int * double -> %d (출력 불가능)
    printf("x * 10.0 = %d\n", x * 10.0);

    // int / int는 int 형식이다. 
    // 실수 형식이 아니라는 점에 주의!
    // 단, 소수점 이하는 절사된다.
    printf("x / 10 = %d\n", x / 10);

    // int / int는 int 형식이므로 %f 로 출력할 수 없다.
    printf("(int) : 5 / 2 = %d\n", 5 / 2);
    // 소수점 이하가 절사되므로 사실상 정수 2를 %f로 출력하는 것이다.
    printf("(double) : 5 / 2 = %f\n", 5 / 2);

    // double / int double 형식이다.
    printf("5.0 / 2 = %f\n", 5.0 / 2);
    return 0;
}

/*
출력결과
    x * 10 = 100
    x * 10.0 = 0
    x / 10 = 1
    (int) : 5 / 2 = 2
    (double) : 5 / 2 = 100.000000
    5.0 / 2 = 2.500000
*/