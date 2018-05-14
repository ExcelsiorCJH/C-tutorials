// array01.c

#include <stdio.h>

int main(void){

    // int 5개가 한 덩어리인 배열 선엄 및 0 초기화
    int aList[5] = { 0 };

    // 다섯 번 반복해 사용자 입력을 받고 순차적으로 인덱스를 
    // 증가시켜 각각의 배열요소에 저장한다. 
    for(int i=0; i < 5; ++i)
        scanf("%d", &aList[i]);

    // 배열에 담긴 내용을 요소 하나씩 꺼내서 출력한다.
    for (int i=0; i < 5; ++i)
        printf("%d\n", aList[i]);

    printf("aList = %d\n", aList);  // aList는 변수가 아니라 0번 요소의 주소이다.
    printf("&aList = %d\n", &aList);  // 즉 aList == aList[0]과 같다.

    return 0;
}