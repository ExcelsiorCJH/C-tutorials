// scanfage02.c
#include <stdio.h>

int main(void)
{
    int age;
    char name[10] = {0};

    printf("나이를 입력하세요. : ");
    scanf("%d", &age);

    printf("이름을 입력하세요. : ");
    // fgets() 입력이 그냥 넘어가는 오류 해결
    fflush(stdin);  // Windows
    // fpurge(stdin);  // Linux, Unix
    fgets(name, sizeof(name), stdin);

    printf("당신의 나이는 %d살이고, 이름은 %s입니다.\n", age, name);

    return 0;
}