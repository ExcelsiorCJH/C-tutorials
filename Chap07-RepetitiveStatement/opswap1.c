// opswap1.c

#include <stdio.h>

int main(void){

    char ch = 0;

    // 한 글자를 입력받아 ch에 저장한 후 이를 '\n'과 비교
    while((ch = getchar()) != '\n'){
        // 조건이 맞는 경우
        putchar(ch);
    }

    // '\n'이 등장해 조건을 만족하지 못해 반복문이 끝남
    return 0;
}