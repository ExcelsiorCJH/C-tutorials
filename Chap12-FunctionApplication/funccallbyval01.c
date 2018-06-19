// funccallbyval01.c
#include <stdio.h>

int Add(int a, int b){
    return a + b;
}

int main(int argc, char* argv[]){
    printf("%d\n", Add(3, 4));
    return 0;
}
/* 출력결과
7
*/