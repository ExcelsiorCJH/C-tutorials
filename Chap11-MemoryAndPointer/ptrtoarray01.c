// ptrtoarray01.c
#include <stdio.h>

int main(int argc, char* argv[]){

    char astrList[2][12] = {"Hello", "World"};

    // char* *ptrList = astrList;
    char (*pstrList)[12] = astrList;

    puts(astrList[0]);
    puts(astrList[1]);

    return 0;
}
/* 출력결과
Hello
World
 */