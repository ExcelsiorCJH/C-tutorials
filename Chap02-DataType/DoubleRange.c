#include <stdio.h>

#include <float.h>

int main(void){
    double dData = 123.456;

    printf("%f\n", dData);  
    printf("%E - %E\n", DBL_MIN, DBL_MAX);
    return 0;
}