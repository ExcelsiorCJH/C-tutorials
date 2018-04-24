#include <stdio.h>

int main(void)
{
    char ch = 'A';
    wchar_t wch = L'A';
    short sData = 10;
    int nData = 10;
    long lData = 10L;
    long int lnData = 10L;
    long long int llnData = 10LL;

    // 부호비트가 없는 자료형
    unsigned char byNewData = 0;
    unsigned short sNewData = 65535U;
    unsigned long int ulNewData = 1UL;
    unsigned long long int ullNewData = 1ULL;
    return 0;
}