# Chap12 함수 응용



## 12.1 매개변수 전달 방법

`A`함수 내부에서 `B`함수를 호출하는 코드가 있으면, `A`는 호출자(caller)이고, `B`는 피호출자(callee)이다. 이렇게 두 함수가 호출/피호출 관계로 묶이는 것을 **바인딩(binding)**이라고 한다. 이 두 함수가 서로 연결되는 인터페이스는 매개변수(parameter)와 반환 자료(return)이다.

호출자 함수는 피호출자 함수 매개변수의 초기값을 지정해줘야 하며, 함수호출 과정에서 매개변수로 전달되는 정보가 무엇이냐에 따라 **매개변수 전달방법**이 달라진다. 매개변수 전달방법으로는 정보가 값인지 주소인지에 따라 **Call by value**, **Call by reference**로 나뉜다.



### 12.1.1 Call by value

다음의 예제는 `Add()`함수로 `int`형 값을 전달하여 두 수의 덧셈 결과를 반환하는 Call by value 예제이다.

```c
// funccallbyval01.c
#include <stdio.h>

int Add(int a, int b){
    return a + b;
}

int main(int argc, char* argv[]){
    printf("%d\n", Add(3, 4));
    return 0;
}
/* 출력결과
7
*/
```



### 12.1.2 Call by reference

다음 예제는 위의 `funccallbyval01.c` 에서 `Add()` 함수를 Call by reference 형식으로 바꾼 것이다. **Call by reference의 핵심은 매개변수가 포인터**이기 때문에, 호출자는 반드시 메모리의 **주소를 인자**로 넘겨야 한다.

```c
// funccallbyref01.c
#include <stdio.h>

int Add(int *a, int *b){
    return *a + *b;
}

int main(void){
    int x = 3, y = 4;

    // Add() 함수를 호출할 때 지역변수의 주소를 실인수로 기술
    printf("%d\n", Add(&x, &y));
    return 0;
}
/* 출력결과
7
*/
```



Call-by-reference 방식이 Call-by-value와 가장 큰 차이점은 **주소를 통해 호출자 메모리에 접근**할 수 있다는 것이다. Call-by-reference의 장점은 **배열처럼 덩치가 큰 메모리를 매개변수로 전달**할 수 있다.

```c
// funcgetname01.c
#include <stdio.h>

// 주소를 매개변수로 받을 때는 대상 메모리의 크기를 함께 받는 것이 좋다.
void GetName(char *pszName, int nSize){
    printf("이름을 입력하세요. : ");
    // 매개변수로 전달받은 주소를 다시 fgets() 함수의 인자로 넘긴다.
    fgets(pszName, nSize, stdin);
}

int main(int argc, char* argv[]){
    char szName[32] = { 0 };

    // 배열(주소)과 배열의 크기를 함수의 매개변수로 전달한다.
    GetName(szName, sizeof(szName));
    printf("당신의 이름은 %s 입니다.\n", szName);
    return 0;
}
```



**포인터의 가장 큰 문제는 가리키는 대상의 실제 크기를 포인터 자체만으로는 알 수가 없다**는 것이다. 따라서, 피호출함수의 매개변수가 포인터인 경우 반드시 대상 메모리의 크기를 함께 매개변수로 받아야 한다. 위에서 `void GetName(char *pszName, int nSize)` 부분을 `void GetName(char pszName[], int nSize)`로 표현해도 의미는 둘다 포인터로 같으며, 두 번째 방법이 "매개변수로 배열의 이름이 전달"된다고 추론할 수 있으므로 가독성이 좋다고 할 수 있다.

다음 예제는 Call-by-reference가 필요한 가장 대표적인 상황을 설명하는 예제로,  두 변수간의 '교환'(swap)을 함수로 구현한 것이다.  아래의 코드에서 `Swap()` 함수는 `int` 에 대한 포인터 변수를 간접지정해서 **대상 메모리에 대해 교환을 수행**한다. 

```c
// funcswap01.c
#include <stdio.h>

// 매개변수로 주소를 받는다.
void Swap(int *pLeft, int *pRight){

    // 주소가 가리키는 대상의 메모리의 값을 교환한다.
    int nTmp = *pLeft;
    *pLeft = *pRight;
    *pRight = nTmp;
}

int main(void){

    int x = 10, y = 20;
    printf("x=%d, y=%d\n", x, y);
    // 호출자 함수에 선언된 지역변수의 주소를 전달한다.
    // 따라서 함수가 반환한 후 x와 y의 값은 서로 교환된다.
    Swap(&x, &y);
    printf("x=%d, y=%d\n", x, y);
    return 0;
}

/* 출력결과
x=10, y=20
x=20, y=10
*/
```



다음 예제는 **문자열의 길이를 측정하는 기능을 함수로 구현**한 예제이다. 

```c
// funcstrlen01.c
#include <stdio.h>

// 매개변수로 전달된 문자열의 길이를 반환하는함수
int GetLength(const char *pszParam){

    int nLength = 0;
    while(pszParam[nLength] != '\0')
        nLength++;

    return nLength;
}

int main(int argc, char* argv[]){

    char *pszData = "Hello";

    printf("%d\n", GetLength("Hi"));
    printf("%d\n", GetLength(pszData));
    return 0;
}
/* 출력결과
2
5
*/
```





#### 잘못된 주소 전달

Call-by-reference 방식은 함수의 매개변수(포인터)로 주소를 받는 방법이다. 피호출자 함수가 포인터(주소)를 반환하는 경우에는 반환한 주소가 가리키는 대상 메모리는 반드시 유효한 것이어야한다. 따라서, **운영체제에 반환했거나 곧 사라질 메모리에 대한 주소를 반환하는 일은 없어야 한다.** 

```c
// badfunction01.c
#include <stdio.h>

int* TestFunc(void){

    int nData = 10;
    // 함수가 반환하면 소멸할 자동변수의 주소를 반환한다.
    return &nData;
}

int main(int argc, char* argv[]){

    int *pnResult = NULL;
    pnResult = TestFunc();

    // 포인터가 가리키는 대상 메모리는 유효하지 않은 메모리이다.
    printf("%d\n", *pnResult);
    return 0;
}

/* 출력결과
badfunction01.c:8:12: warning: function returns address of local variable 
 */
```



위의 코드에서의 문제는 **함수 내부에 선언된 자동변수의 주소를 반환하는 것**이다.  `nData`는 `TestFunc()`의 지역변수이므로, 이러한 자동변수는 메모리 중 **스택 영역**을 사용한다. **스택은 스코프가 닫히면 그 내부에 선엉된 것들이 사라진다.**  따라서, 이러한 변수의 주소를 반환하기 때문에 출력결과에서 처럼 `warning` 메시지가 나타나게 된다.



## 12.2 스택 프레임 그리는 방법

자동변수는 스택 영역 메모리를 사용한다. C언어에서 자동변수는 `auto`라는 기억부류 지정자(storage-class specifier)로 선언할 수 있는데, 별도로 지정하지 않을 경우 자동으로 `auto`로 지정이 된다. 함수의 매개변수는 자동변수이며, 지역변수이다. 따라서, **함수 내부에 선언된 변수와 매개변수는 기본적으로 '스택'을 사용**한다.

스택(stack) 영역은 시스템이 관리하므로, 따로 메모리 지정/해제를 관리할 필요가 없다. 하지만, C언어의 전문가가 되려면 이러한 스택이 어떠한 형식으로 관리되는지 알아야할 필요가 있다고 한다. 따라서, 스택의 관리 형식인 **스택 프레임(Stack frame)**을 구성하는 것을 코드 및 그림으로 알아보도록 하자.

스택은 늘어날 수 있는 최대 크기가 처음부터 결정 되어 있는데, 그 이유는 스택은 일정 크기의 주소에서 주소가 증가하는 방향이 아닌 역으로 **감소하는 방향**으로 가기 때문이다.



> - 스택과 메모리의 주소는 반대방향으로 그린다
> - 지역 변수는 선언된 순서대로 그린다.
> - 포인터 변수는 별도로 표시한다.
> - 배열의 인덱스는 아래로 증가하게 그린다.
> - 동적 할당된 메모리는 따로 표시한다.
> - 매개변수는 오른쪽부터 스택에 그리며 새 스코프는 기존 스택 위에 그린다.
> - 스코프가 닫히면 그림에서 지운다.
> - 정적변수, 전역변수는 별도로 표시한다.



##  12.3 재귀호출

재귀호출(recursive function call)은 **함수가 내부에서 다시 자기 자신을 호출하는 것**을 말한다.  

아래의 예제코드는 계승(factorial)을 계산하는 프로그램을 반복문을 사용한 방법과 재귀호출을 이용한 방법을 나타낸 코드이다.

먼저, 반복문을 사용해 계승을 계산하는 코드를 살펴보자.

```c
// funcrec01.c
#include <stdio.h>

int main(void){

    int nFact = 1;
    for(int i=5; i>=1; --i)
        nFact *= i;

    printf("5! == %d\n", nFact);
    return 0;
}

/* 출력결과
5! == 120
 */
```



이번에는 재귀함수를 이용해 동일한 계승을 계산하는 코드를 살펴보자.

```c
// funcrec02.c
#include <stdio.h>

// 계승을 계산하고 결과를 반환하는 함수
int GetFactorial(int nParam){

    int nResult = 0;
    // 재귀호출을 띁내기 위한 조건식! 반복문의 조건식과 같다.
    if (nParam == 1) return 1;

    // 매개변수의 값을 1 감소시켜 자기 자신을 다시 호출한다.
    // 이는 반복문의 계수기와 같다.
    nResult = nParam * GetFactorial(nParam - 1);
    printf("nResult = %d\n", nResult);
    return nResult;
}

int main(void){

    printf("5! == %d\n", GetFactorial(5));
    return 0;
}

/* 출력결과
nResult = 2
nResult = 6
nResult = 24
nResult = 120
5! == 120
 */
```

