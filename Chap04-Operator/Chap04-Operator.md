# Chap04 - 연산자(기본)



연산자(operator)는 메모리가 아닌 CPU연산과 관련되는 문법이다. 

- **연산자** : 덧셈(`+`), 곱셈(`*`), 나눗셈(`/`) 등을 연산자라 한다.
- **피연산자** : `3 + 4`  에서 `3, 4` 를 덧셈(`+`) 연산자의 피연산자라 한다.



## 4.1 산술 연산자

산술 연산자는 우리가 기본적으로 알고 있는 수학 식을 C언어로 그대로 옮긴 문법이라 할 수 있다. 여기서 하나 알고 넘어가야할 중요한 개념은 **연산의 임시결과** 이다. 

연산의 임시결과는 산술연산이 여러개가 있을 경우, 우선순위가 나중에 수행될 연산의 피연산자 중 먼저 연산된 결과를 말한다. 예를 들어 `(a + b) * c` 의 계산식에서 `(a + b)` 의 임시결과가 `*`의 피연산자가 된다.



### 4.1.1 덧셈, 뺄셈 연산자

```c
// operator.c
#include <stdio.h>

int main(void){
    int nResult = 0;

    // 1. 3 + 4
    // 2. 7(임시결과) - 5
    // 3. nResult = 2
    nResult = 3 + 4 - 5;
    printf("nResult : %d\n", nResult);
    return 0;
}
```

위의 코드에서 `3 + 4` 는 덧셈연산의 임시결과가 된다. 그리고 이 임시결과에서 `5`를 빼주어 `2`라는 임시결과를 얻게된다. 그 다음 더이상 이어지는 연산이 없기 때문에 최종결과인 `2`가 출력된다.



### 4.1.2 이형자료 간의 연산 및 형승격

이형자료 간의 연산에 대해 알아보자. 먼저 소스코드를 보도록 하자.

```c
// TypePromotion.c
#include <stdio.h>

int main(void){
    char ch = 'A';

    // char를 %c로 출력
    printf("%c\n", ch);

    // 'char + int'는 int 형식이다.
    printf("%c\n", ch + 1);
    printf("%d\n", ch + 1);
    printf("%c\n", 'A' + 2);

    // 'double + int'는 double 형식이다.
    // 따라서 %d 형식으로 출력할 수 없음
    printf("%d\n", 5.0 + 2);
    printf("%f\n", 5.0 + 2);
    return 0;
}

/*
출력결과
    A
    B
    66
    C
    0
    7.000000
*/
```



위의 코드에서 `ch + 1` 과 `'A'+2`와 같이 서로 다른 자료형의 연산을 이형자료 간의 연산이라고 한다.  앞의 연산에 대한 임시결과의 자료형은 `int`형이 된다. 

이렇듯, **임시결과의 자료형은 연산에 참여한 피연산자 중 정보 표현 범위가 더 넓은 자료형** 이 된다. `char=1byte` 이고 `int=4byte` 이므로 `char`와 `int`간의 연산은 `int`형이 된다. 

위의 코드에서 `5.0 + 2`의 (임시)결과의 자료형은 `double + int` 이므로 표현범위가 더 넓은 `double`이 되어 `printf("%d\n", 5.0 + 2);`에서 형식문자 `%d`가 `int`를 출력하기 때문에 `0`이 출력된다.

이처럼 연산의 결과가 피연산자의 자료형보다 표현범위가 넓은 형식으로 변경되는 현상을 **형승격(type promotion)** 이라 한다. 



### 4.1.3 곱셈, 나눗셈 연산자

```c
// opdoubleint.c
#include <stdio.h>

int main(void){
    
    int x = 10;

    // int * int -> %d
    printf("x * 10 = %d\n", x * 10);
    // int * double -> %d (출력 불가능)
    printf("x * 10.0 = %d\n", x * 10.0);

    // int / int는 int 형식이다. 
    // 실수 형식이 아니라는 점에 주의!
    // 단, 소수점 이하는 절사된다.
    printf("x / 10 = %d\n", x / 10);

    // int / int는 int 형식이므로 %f 로 출력할 수 없다.
    printf("(int) : 5 / 2 = %d\n", 5 / 2);
    // 소수점 이하가 절사되므로 사실상 정수 2를 %f로 출력하는 것이다.
    printf("(double) : 5 / 2 = %f\n", 5 / 2);

    // double / int double 형식이다.
    printf("5.0 / 2 = %f\n", 5.0 / 2);
    return 0;
}

/*
출력결과
    x * 10 = 100
    x * 10.0 = 0
    x / 10 = 1
    (int) : 5 / 2 = 2
    (double) : 5 / 2 = 100.000000
    5.0 / 2 = 2.500000
*/
```



곱셈, 나눗셈 연산 또한 형승격(type promotion)이 일어난다.  

나눗넴 연산은 다음 두 가지에 대해 알고 있어야 한다.

- **정수(`int`)를 정수(`int`)로 나눈 결과는 정수**
- **절대 `0`으로 나눌 수 없음**




### 4.1.4 나머지 연산자

나머지 연산자는 나눗셈과 원리가 같으나, 몫이 아닌 나머지를 구한다. 나머지 연산자 기호는 `%`이다. 나머지 연산자의 피연산자로 **실수가 사용될 수 없다.**

```c
// operator04.c
#include <stdio.h>

int main(void){

    int x = 0;
    scanf("%d", &x);

    // int / int는 int 이므로 
    // 소수점 이하는 버려지고 출력된다.
    printf("몫 : %d\n", x / 3);
    // 몫은 버리고 나머지(int)만 출력한다.
    printf("나머지 : %d\n", x % 3);
    
    return 0;
}
```





## 4.2 대입 연산자

대입 연산자는 `=` 기호로 표시되는 연산자로, 오른쪽(우변) 피연산자에서 읽어서 왼쪽(좌변) 피연산자로 정보를 복사하는 연산을 수행한다. 쉽게 말해 좌변의 변수에 우변의 값을 대입해 준다고 보면 된다. 과정을 하나하나 살펴보면 다음과 같다.

1. 복사할 원본을 읽기
2. 복사
3. 덮어쓰기



### 4.2.1 단순 대입 연산자

가장 기본적인 대입 연산자이다.

```c
// opassign01.c
#include <stdio.h>

int main(void){
    int x = 0, nInput = 0;
    scanf("%d", &nInput);

    // nInput 변수에 저장된 사용자가 입력한 값을 x에 복사한다.
    // x에 들어있던 값은 Overwrite되고 사라진다.
    x = nInput;
    printf("%d\n", x);
    
    return 0;
}
```



#### 두 변수값 교환

```c
// opswap1.c

#include <stdio.h>

int main(void){
    // nTmp는 '교환'을 위해 필요한 변수이다.
    int x = 10, y = 20, nTmp = 0;
    printf("Before: %d, %d\n", x, y);

    // 두 변수 x와 y에 저장된 값을 서로 교환한다.
    nTmp = x; 
    x = y;
    y = nTmp;

    // 교환이 완료된 것을 확인하기 위해 출력한다.
    printf("After: %d, %d\n", x, y);
    return 0;
}
```



### 4.2.2 복합 대입 연산자

복합 대입 연산자는 기존의 단순 대입 연산자에 산술 연산자나 비트 연산자를 조합하여 새로운 연산자로 만드는 것이다. 즉, 두 개의 연산을 하나로 합친 연산이라 볼 수 있다.

```c
// opcomassign01.c
#include <stdio.h>

int main(void){
    int nResult = 0, nData = 10;

    nResult += 3;  // nResult = nResult + 3;
    printf("%d\n", nResult);

    nResult *= nData;  // nResult = nResult * nData;
    printf("%d\n", nResult);

    nResult /= 2;  // nResult = nResult / 2;
    printf("%d\n", nResult);

    nResult -= nData - 5;  // nResult = nReuslt - (nData - 5);
    printf("%d\n", nResult);

    nResult %= 3;  // nResult = nResult % 3;
    printf("%d\n", nResult);
    return 0;
}

/*
출력결과
	3
    30
    15
    10
    1
*/
```



#### 누적 연산 구현

복합 대입 연산자 중 `+=`연산자는 누적을 구현하는 데 자주 사용된다.

```c
// accumulate01.c
/*
사용자로부터 세 정수를 입력받아 총합을 출력
*/
#include <stdio.h>

int main(void){
    int nInput, nTotal = 0;

    scanf("%d", &nInput);
    nTotal += nInput;

    scanf("%d", &nInput);
    nTotal += nInput;

    scanf("%d", &nInput);
    nTotal += nInput;

    printf("Total = %d", nTotal);
    
    return 0;
}
```





## 4.3 형변환 연산자

형변환(type cast) 연산자 피연산자의 자료형을 새로운 자료형으로 변경하는 단항 연산자다. 위에서 알아본 연산자들 보다 **우선순위가 높기** 때문에, 산술 연산자와 형변환 연산자가 같이 나올 경우 형변환이 우선이다. 

```c
// opcast01.c

#include <stdio.h>

int main(void){
    int x = 5;

    printf("%d\n", 5/2);  // int / int -> int
    printf("%f\n", 5.0 / 2);  // double / int -> double
    printf("%f\n", 5 / 2.0);  // int / double -> double
    printf("%f\n", (double)5 / 2);  // double / int -> double
    printf("%f\n", (double)x / 2);  // double / int -> double
    printf("%f\n", x / (double)2);  // int / double -> double
    printf("%f\n", (double)(x / 2));  // double

    return 0;
}
/*
출력결과
    2
    2.500000
    2.500000
    2.500000
    2.500000
    2.500000
    2.000000
*/
```





## 4.4 단항 증감 연산자

단항 증감 연산자는 `++` 와 `--` 로 표시되는 연산자다.  이 연산자의 의미는 피연산자의 값을 1씩 증가(감소) 시킨다.

```c
// opinc01.c
#include <stdio.h>

int main(void){
    int x = 10;

    // 1. x에 저장된 값과 1을 더해 다시 x에 저장한다.
    x = x + 1;
    printf("%d\n", x);

    // 2. x에 저장되어 있는 값을 1을 누적한다.
    x += 1;
    printf("%d\n", x);

    // 3. x에 저장된 값을 1 증가시킨다.
    ++x;
    printf("%d\n", x);

    return 0;
}

/*
출력결과
    11
    12
    13
*/
```



단한 증감 연산자의 위치에 따라 우선순위가 달라진다. 위의 코드에서 `++x` (전위식 표기)일 경우에는 연산자 우선 순위가 높지만 `x++` (후위식 표기)이면 우선순위가 **최하위**가 된다. 아래의 예제 코드를 보자.

```c
// opinc02.c
#include <stdio.h>

int main(void){
    int x, nResult = 0;

    // x의 값을 1 증가시킨 후 출력한다.
    ++x;
    printf("%d\n", x);

    // x의 값을 1 증가 시킨 후 출력한다.
    x++;
    printf("%d\n", x);

    // x의 값을 1 증가시킨 후 단순 대입한다(전위식 표기).
    nResult = ++x;
    printf("%d, %d\n", nResult, x);

    // x의 값을 nResult에 대입한 후 x를 1 감소시킨다(후위식 표기).
    nResult = x--;
    printf("%d, %d\n", nResult, x);

    return 0;
}

/*
출력결과
	1
    2
    3, 3
    3, 2
*/
```



위의 코드 `nResult = x--;` 부분에서 단순 대입 연산과 단항 증가 연산이 같이 나왔다. 이 경우 단항 (증감) 연산을 먼저 수행하는 것이 아니라 **대입 연산을 먼저 수행** 한다. 