/*
getchar() 함수를 호출하여 영문 네 글자 이상을 입력받고,
그 중에서 두 번째 글자만 화면에 출력
입력: Test
출력: e
*/
#include <stdio.h>

int main(void){
    char ch = 0;
    char ch2 = 0;
    ch = getchar();
    ch2 = getchar();
    putchar(ch2);

    return 0;
}