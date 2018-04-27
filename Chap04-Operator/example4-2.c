/*
4-2. 초를 '시:분:초'로 변환하는 프로그램

사용자로부터 초(second)를 입력받아 '시:분:초' 형식으로 출력

입력 예: 4000
출력 예: 4000초는 01시간 06분 40초 입니다.
*/
#include <stdio.h>

int main(void){

    int nData = 0;
    int hour, minute, second = 0;
    printf("초를 입력해 주세요 : ");
    scanf("%d", &nData);

    hour = nData / 3600;
    minute = (nData % 3600) / 60;
    second = (nData % 3600) % 60;

    printf("%d초는 %02d시간 %02d분 %02d초 입니다.\n", 
            nData, hour, minute, second);

    return 0;
}