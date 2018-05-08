// ctrlswitchcase01.c

#include <stdio.h>

int main(void){

    char cOperator = 0;
    int x = 0, y = 0, nResult = 0;

    // 사용자로부터 산술식을 입력받는다.
    scanf("%d%c%d", &x, &cOperator, &y);

    // 연산자가 무엇인지 선택한다.
    switch (cOperator){
        // cOperator == '+' 연산과 같다.
        case '+':
            nResult = x + y;
            // 다음 행으로 넘어가지 않고 switch-case 블록을 벗어난다.
            break;
        
        case '-':
            nResult = x - y;
            break;
        
        case '*':
            nResult = x * y;
            break;

        case '/':
            nResult = x / y;
            break;

        // 앞의 네 가지 경우에 해당하지 않는 나머지 경우
        default:
            puts("ERROR: 알 수 없는 산술 연산입니다.");
    }

    printf("Result: %d\n", nResult);
    return 0;
}