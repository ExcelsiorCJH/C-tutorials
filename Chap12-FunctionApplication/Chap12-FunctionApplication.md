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

