#include <stdio.h>

int main(void){

    // char* [3] 배열을 각각의 문자열로 초기화
    char *astrList[3] = { "Hello", "World", "String" };

    // 배열의 요소가 char* 이므로 %s로 출력하는 것이 맞다.
    printf("%s\n", astrList[0]);
    printf("%s\n", astrList[1]);
    printf("%s\n", astrList[2]);

    // 배열의 0번 요소에는 첫 글자가 저장된 메모리의 주소가 들어있다.
    // 여기에 정수를 더해 '상대주소'를 계산한다.
    printf("%s\n", astrList[0] + 1);
    printf("%s\n", astrList[1] + 2);
    printf("%s\n", astrList[2] + 3);

    // char*의 배열은 논리적으로 char의 2차원 배열과 같다.
    printf("%c\n", astrList[0][3]);
    printf("%c\n", astrList[1][3]);
    printf("%c\n", astrList[2][3]);

    return 0;
}
/* 출력결과 
Hello
World
String
ello
rld
ing
l
l
i
*/