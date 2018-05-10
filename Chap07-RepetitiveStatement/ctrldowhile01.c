// ctrldowhile01.c

#include <stdio.h>

int main(void){

    char ch = 0;

    do {
        // 조건을 나중에 비교하므로
        // 일단 한 번은 무조건 실행된다.
        ch = getchar();
        putchar(ch);
    
    // 조건식 오른쪽 끝에 ;이 있다는 점에 주의한다. 
    } while (ch != '\n');

    return 0;
}