// opbit01.c

#include <stdio.h>

int main(void){
    int nData = 0x11223344;

    printf("%d\n", nData);
    printf("%08X\n", nData & 0x00FFFF00);  // AND
    printf("%08X\n", nData | 0x00FFFF00);  // OR
    printf("%08X\n", nData ^ 0x00FFFF00);  // XOR
    printf("%08X\n", ~nData);  // NOT
    printf("%08X\n", nData >> 8); // Shift Right
    printf("%08X\n", nData << 8); // Shift Left

    return 0;
}