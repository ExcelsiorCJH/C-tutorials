// variable03.c

#include <stdio.h>

int main(int argc, char* argv[]){
    
    register int i = 0;
    printf("%d\n", i);
    printf("%p\n", &i);  // <- 레지스터 변수는 주소가 없으므로 에러가 남
    return 0;
}