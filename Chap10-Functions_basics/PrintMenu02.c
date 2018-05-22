// Printmenu02.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // sleep()을 사용하기 위함


// 나이를 매개변수로 받고 요금을 반환하는 기능을 제공
int GetFee(int nAge){
    int nFee = 1000;
    if(nAge < 20) nFee /= 2;
    return nFee;
}

// 메뉴를 출력하고 사용자로부터 선택을 입력받는 인터페이스
int PrintMenu(void){
    int nInput = 0;

    sleep(1);  // Linux & Mac에서는 화면이 바로 지워지는 문제로 인해 sleep() 추가
    system("clear");
    printf("[1]New\t[2]Search\t[3]Print\t[4]Remove\t[0]Exit\n");
    scanf("%d", &nInput);
    return nInput;
}

// 사용자로부터 나이를 입력받는 인터페이스
int GetAge(void){
    int nAge = 0;
    printf("나이를 입력하세요. : ");
    scanf("%d", &nAge);
    return nAge;
}

// 프로그램의 전체 흐름
int main(void){
    int nMenu = 0, nAge = 0;

    // 간단히 구현한 이벤트 루프    
    while((nMenu = PrintMenu()) != 0){
        if(nMenu == 1){
            nAge = GetAge();
            printf("요금은 %d원 입니다.\n", GetFee(nAge));
            getchar();
        }
    }
    puts("Bye~!");
    return 0;
}

/* 출력결과
[1]New	[2]Search	[3]Print	[4]Remove	[0]Exit
1
나이를 입력하세요. : 19
요금은 500원 입니다.

[1]New	[2]Search	[3]Print	[4]Remove	[0]Exit
0
Bye~!
*/