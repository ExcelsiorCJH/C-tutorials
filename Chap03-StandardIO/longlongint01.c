// longlongint.c
#include <stdio.h>

int main(void)
{
    // 부호가 있는 64비트 정수형 변수 선언 및 정의
    long long int lldData = 4294967295LL;

    // 64비트 정보를 32비트 형식 문자로 출력한다.
    printf("%d\n", lldData);
    printf("%u\n", lldData);

    // 32비트로는 표현할 수 없는 범위의 정보를 출력해본다.
    printf("%u\n", lldData + 1);
    printf("%u\n", lldData + 2);
    printf("%u\n", lldData + 3);

    // 64비트 정보를 64비트 형식 문자(%lld)로 출력한다.
    printf("%lld\n", lldData + 1);
    printf("%lld\n", lldData + 2);
    printf("%lld\n", lldData + 3);

    return 0;
}
