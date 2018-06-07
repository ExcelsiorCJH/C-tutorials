// ptrnarray02.c

#include <stdio.h>
#include <string.h>

int main(void){

    char szBuffer[32] = { "You are a girl." };

    // 배열의 첫 번째(0번) 요소의 값을 %c 형식으로 출력한다.
    printf("%c\n", szBuffer[0]);
    // 0번 요소에 대한 주소인 배열의 이름(주소)에 대해 간접지정 연산을
    // 수행하고 그 안에 담긴 정보를 출력한다.
    printf("%c\n", *szBuffer);
    // 0을 더하더라도 주소는 달라지지 않는다.
    printf("%c\n", *(szBuffer + 0));
    
    // 배열 연산자는 '기준주소 + 인덱스' 연산결과로 얻은 주소를
    // 간접지정한 것과 같다.
    printf("%c\n", szBuffer[5]);
    printf("%c\n", *(szBuffer + 5));

    // 주소연산(&)은 간접지정 연산과 상반된다.szBuffer
    // 그러므로 아래 세줄의 코드는 모두 같다.
    printf("%s\n", &szBuffer[4]);
    printf("%s\n", &*(szBuffer + 4));
    printf("%s\n", szBuffer + 4);
    printf("%p\n", szBuffer + 4);

    return 0;
}
/* 출력결과
Y
Y
Y
r
r
are a girl.
are a girl.
are a girl.
0061FF14
*/