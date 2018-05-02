# Chap05 - 연산자(응용)



## 5.1 `sizeof` 연산자

`sizeof` 연산자는 **피연산자의 자료형에 대한 크기** 를 구하는 연산이다. 따라서, `sizeof(5)` 라는 연산은 `size(int)` 연산과 같으며 결과는 `int`형의 크기인 `4`가 된다.

```c
// opsize01.c
#include <stdio.h>

int main(void){
    int nData = 10;

    // sizeof 연산자의 피연산자는 자료형이다.
    printf("%d, %d, %d\n", sizeof(5), sizeof(nData), sizeof(int));
    printf("%d, %d\n", sizeof('A'), sizeof(char));
    printf("%d, %d\n", sizeof(123.45F), sizeof(123.45));

    // 연산식 결과값의 자료형의 크기를 측정한다.
    printf("%d, %d\n", sizeof(nData +10), sizeof(++nData));
    printf("%d\n", nData);

    return 0;
}
/*
출력결과
    4, 4, 4
    4, 1
    4, 8
    4, 4
    10
*/
```

 `sizeof` 연산자는 프로그램을 빌드하고 CPU가 실행하는 런타임 연산자가 아니라 컴파일러가 컴파일타임에 수행하는 연산자이기 때문에 CPU를 사용하지 않는다.



## 5.2 관계 연산자

관계 연산자는 상등/부등, 비교 연산자로 분류할 수 있으며, **두 피연산자의 값을 비교해 참(`True, 1`) 또는 거짓(`False, 0`)의 결과를 내는 연산자**다.

|  연산식  | 분류      | 의미                   |
| :------: | :-------- | ---------------------- |
| `A == B` | 상등연산  | A는 B와 같다.          |
| `A != B` | 부등연산  | A는 B와 같지 않다.     |
| `A > B`  | 비교 연산 | A는 B보다 크다.        |
| `A < B`  | "         | A는 B보다 작다.        |
| `A >= B` | "         | A는 B보다 크거나 같다. |
| `A <= B` | "         | A는 B보다 작거나 같다. |

```c
// oprelational01.c
#include <stdio.h>

int main(void){
    
    int x = 5, y = 10;

    printf("%d\n", x == y);
    printf("%d\n", x != y);
    printf("%d\n", x > 5);
    printf("%d\n", y < 5);
    printf("%d\n", y >= 10);

    // 산술연산은 관계연산보다 우선
    // 따라서 x + 5의 결과가 관계연산에 적용
    printf("%d\n", y <= x + 5);

    return 0;
}
/* 
출력결과
    0
    1
    0
    0
    1
    1
*/
```



만약 문자열과 같이 배열형태의 피연산자에 대해 관계 연산을 수행하려고 한다면 각 요소 하나하나를 일일이 비교해야 하는 번거로움이 있다. 따라서, 이런 비교를 위한 전용 함수가 따로 있다. 대표적으로 `memcmp()`와 `strcmp()`이다. 이 **두 함수는 서로 일치한다면 `0`을 반환**한다.

```c
// oprelational02.c
#include <stdio.h>
#include <string.h>

int main(void){

    char ch1[5] = {"ABCD"};

    // memcmp(*str1, *str2, n)
    // n: the number of bytes to be compared.
    printf("%d\n", memcmp(ch1, "ABCD", 5));

    // strcmp(*str1, *str2)
    printf("%d\n", strcmp(ch1, "AEFG"));

    return 0;
}
/*
출력결과
    0
    -1
*/
```





## 5.3 논리 연산자

논리 연산자는 참/거짓으로 결론 내릴 수 있는 두 대상을 피연산자로 사용한다. 이러한 논리식을 보통 **조건식**이라고 한다.



### 5.3.1 논리합(OR)과 논리곱(AND)

C 언어에서 **논리합(OR)** 연산자는 `||` 이다. **OR** 연산은 **여러 관계식들 중 하나만 만족하면 전체 논리식의 결과는 참**이 된다. 다음 예제 코드는 사용자가 입력한 값이 `4`미만이거나(OR) `60`이상이면 `1`을 출력하고, 그렇지 않으면 `0`을 출력하는 예제이다.

```c
// oplogical01.c
#include <stdio.h>

int main(void){

    int nInput = 0, bResult = 0;

    scanf("%d", &nInput);
    bResult = nInput < 4 || nInput >= 60;
    
    printf("Result: %d (1: True, 0: False)\n", bResult);
    return 0;
}
```



**논리곱(AND)** 을 의미하는 연산자는 `&&`이다. 논리합(OR) 연산과는 다르게 **모든 조건(논리식)이 다 참이어야 최종결과도 참**이 된다. 

```c
// oplogical02.c
#include <stdio.h>

int main(void){

    int nInput = 0, bResult = 0;

    scanf("%d", &nInput);
    bResult = nInput > 3 && nInput < 20;

    printf("Result: %d (1: True, 0: False)\n", bResult);
    return 0;
}
```



### 5.3.2 부정

**부정(NOT)** 을 의미하는 연산자는 `!` 이다. AND와 OR 연산자와 달리 부정(NOT)은 단항 연산자이므로 우선순위가 높다.

```c
// oplogicalnot01.c
#include <stdio.h>

int main(void){

    int nInput = 0, bResult = 0;

    scanf("%d", &nInput);
    // 사용자가 입력한 값이 0이 아니면 참
    // 원래라면 사용자가 0을 입력하면 거짓이나
    // ! 연산을 수행해 참이된다.
    // 반대로 0 외의 값을 입력하면 원래는 참이나
    // ! 연산을 통해 거짓이 된다.
    bResult = !nInput;
    printf("Result: %d (1: True, 0: False)\n", bResult);
    return 0;
}
```



### 5.3.3. 쇼트서킷

**쇼트서킷(Short Circuit)**은 컴파일 시 **불필요한 (논리)연산을 생략해 논리 연산식의 효율을 높이는 것**이다. 

1. 논리 연산식은 무조건 왼쪽에서 오른쪽으로 수행한다.
2. `OR(||)` 논리식은 하나라도 조건에 만족하면 이후 연산을 생략한다.
3. `AND(&&)` 논리식은 하나라도 조건에 만족하지 않으면 이후 연산은 생략한다.



```c
// opshortcircuit01.c
#include <stdio.h>

int main(void){

    int nAge = 0, nHeight = 0;

    printf("나이를 입력하세요. : ");
    scanf("%d", &nAge);
    printf("키를 입력하세요. : ");
    scanf("%d", &nHeight);

    // 모든 논리 연산은 왼쪽에서 오른쪽으로 진행한다.
    // 만일 논리적으로 더 수행할 필요가 없다고 결정되면
    // 수행하지 않은 나머지 연산들과 상관없이 최종 결론을 내린다.
    printf("결과 : %d (1:합격, 0:불합격)\n",
        nAge >= 20 && nAge <=30 && nHeight >= 150);

    return 0;
}
```

