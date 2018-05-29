#include <stdio.h>

int main(void)
{

    // int 형식 변수 선언 및 정의
    int x = 10;
    // 변수 x를 가리키는 int 형식에 대한 포인터 변수 선언 및 정의
    int *pnData = &x;

    printf("x : %d\n", x);

    // pnData 포인터 변수가 가리키는 대상 메모리를 int 형 변수로
    // 간접지정하고 20을 대입한다.
    // 현재 가리키는 대상 메모리는 변수 x의 메모리이므로 x의 값이 20이 된다.
    *pnData = 20;
    printf("x : %d\n", x);

    // pnData를 출력해보자
    printf("pnData의 값 : %p\n", pnData);
    printf("x의 주소(&x) : %p\n", &x);

    /* 
    즉, pnData의 값은 x의 메모리 주소(&x)이므로 
    이것을 간접연산자 *를 통해 변수 x라고 식별하고
    여기에 *pnData = 20 이라고 해주는 것은
    x = 20이라는 것과 같은 것이 된다.
    */

    return 0;
}

/* 출력결과
x : 10
x : 20
pnData의 값 : 0061FF28
x의 주소(&x) : 0061FF28
*/