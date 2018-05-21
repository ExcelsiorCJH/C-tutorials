// functionerror.c

#include <stdio.h>

int Add(int a, int b){
    int nData = 0, a;
    nData = a + b;
    a = b = 10;
    return nData;
}
/* 출력결과
error: redefinition of 'a'
*/