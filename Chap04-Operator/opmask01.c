// opmask01.c

#include <stdio.h>

int main(void){
    
    int nData = 0x11223344;

    printf("%08X\n", nData & 0xFFFF0000);
    printf("%08X\n", nData & 0x00FF0000);
    printf("%08X\n", nData & 0x0000FFFF);
    printf("%08X\n", nData & 0xFF0000FF);

    return 0;
}