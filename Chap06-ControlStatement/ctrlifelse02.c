// ctrlifelse02.c
#include <stdio.h>

int main (void){

    int nInput = 0, nSelect = 0;
    scanf("%d", &nInput);

    // 1차 분류
    if(nInput <= 10){
        // 2차 분류
        if(nInput < 0)
            nSelect = 0;  // 경우 1
        else
            nSelect = 10;  // 경우 2
    } else {
        nSelect = 20;  // 경우 3
    }
    
    printf("%d\n", nSelect);
    return 0;
}