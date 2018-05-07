# Chap06 - 기본 제어문 (Control Statement)

## 6.1 `if` 문

`if`문은 분기문(branching statement)라고도 하며, 조건식을 기준으로 구문들의 절차상 흐름을 변경한다. 



### 6.1.1 기본 구조

`if`문의 구조는 아래의 그림과 같다. 

![](./images/if.png)



다음 예제코드를 통해`if`문의 사용법에 대해 알아보자. 아래의 코드는 사용자가 입력한 나이가 20 이상인지 비교한다. 결과가 참(`true`)이면 `if`문에 속한 나머지 구문을 수행하고 `false`이면 `if`문을 생략한다. 

```c
// ctrlbranch01.c

#include <stdio.h>

int main(void){

    int nAge = 0;

    printf("나이를 입력하세요. : ");
    scanf("%d", &nAge);

    // if문 시작
    if(nAge >= 20)
        // 조건식을 만족한 경우에만 실행하는 구문
        printf("당신의 나이는 %d세 입니다.\n", nAge);
    
    // if문 끝
    
    puts("End");

    return 0;
}
```



### 6.1.2 제어문과 스코프

만약`if`문에서 조건식을 만족할 때 수행할 구문이 여러 개면, 반드시 **스코프(Scope)**로 묶어야 한다. 위의 예제 코드에서는 수행할 구문이 하나이므로 스코프를 생략해도 된다.  아래의 예제코드는 사용자로부터 나이를 입력받고 `20`이상이면 사용자가 입력한 값을 `20`으로 바꿔주는 예제이다.

```c
// ctrlbranch02.c
#include <stdio.h>

int main(void){

    int nAge = 0;

    printf("나이를 입력하세요. : ");
    scanf("%d", &nAge);

    // if문의 시작
    if(nAge >= 20) {
        // 조건식을 만족했을 때 실행할 구문들
        // 여러 구문을 실행해야 한다면 반드시 블록 스코프로 묶는다.
        printf("처리 전, 당신의 나이는 %d세 입니다.\n", nAge);
        nAge = 20;
    }  // if 문 끝

    printf("당신의 나이는 %d세 입니다.\n", nAge);
    return 0;
}
```





## 6.2 `if else` 문

### 6.2.1 기본구조

`if else` 문은 조건을 만족하는 경우와 그렇지 않은 경우 모두를 처리할 수 있는 제어문이다.  [5장 - 연산자(응용)](https://github.com/ExcelsiorCJH/C-tutorials/tree/master/Chap05-Operator2) 에서 삼항연산자와 같은 방식이다. 아래의 예제 코드는 사용자가 입력한 값이 10 이하면 10으로, 그렇지 않으면 20으로 바꿔주는 예제이다.  코드에서 볼 수 있듯이 `else`문의 오른쪽에는 조건식을 쓰지 않는다.

```c
// ctrlifels01.c
#include <stdio.h>

int main(void){

    int nInput = 0, nSelect = 0;
    scanf("%d", &nInput);

    // nSelect = nInput <= 10 ? 10 : 20;
    // 삼항 연산자를 이용한 것과 동일한 구조의 if else 문
    if(nInput <= 10)
        nSelect = 10;  // true인 경우
    else
        nSelect = 20;  // false인 경우

    printf("%d\n", nSelect);
    return 0;
}
```

