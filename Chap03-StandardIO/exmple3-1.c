/*
나이와 이름을 입력받아 
한 행으로 출력하는 프로그램
*/
#include <stdio.h>

int main(void)
{
    int age;
    char name[10] = {0};

    printf("나이를 입력하세요. : ");
    scanf("%d", &age);

    printf("이름을 입력하세요. : ");
    fflush(stdin);  // fgets() 입력이 그냥 넘어가는 오류 해결
    fgets(name, sizeof(name), stdin);

    printf("당신의 나이는 %d살이고, 이름은 %s입니다.", age, name);

    return 0;
}