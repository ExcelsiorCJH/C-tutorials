// variable01.c

#include <stdio.h>

int main(int argc, char* argv[]){

    auto int aList[3] = {10, 20, 30};
    auto int i = 0;

    for(i=0; i<3; ++i)
        printf("%d\t", aList[i]);
    return 0;
}
/*  출력결과
10	20	30
 */