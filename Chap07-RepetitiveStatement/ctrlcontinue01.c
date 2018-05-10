// ctrlcontinue01.c

#include <stdio.h>

int main(void){

    int i = 0;
    // for문은 i가 9가 될 때까지 반복된다.
    for (i = 0; i < 10; ++i){
        // i 값이 5가 되면 break문이 실행되고 for문을 벗어난다.
        if(i > 4)
            continue;

        printf("%dth\n", i);
    }
    // break문이 적용된 순간의 계수(count)값을 출력한다.
    printf("END: i == %d\n", i);
    return 0;
}