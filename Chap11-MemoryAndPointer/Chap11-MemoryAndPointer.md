# Chap11 - 메모리와 포인터

드디어 C언어의 꽃인 포인터다. 

이번 장에서 실습을 제대로 하기 위해서는 몇가지 설정이 필요하다. 우선 나는 Chap02 ~ Chap10까지는 Linux, Mac OS에서 실습을 하여 [gcc](https://gcc.gnu.org/)로 컴파일하였다. 하지만, 이번 장에서 포인터에 대해 실습할 때는 Windows 환경에서 [Visual Studio 2017](https://www.visualstudio.com/ko/downloads/)을 이용하여 실습을 진행하였다. 

Visual Studio에서 새로운 프로젝트를 생성한 후 `Alt + F7` 를 눌러 프로젝트의 속성을 다음과 같이 수정해야 한다.

- [구성 속성] → [링커] → [고급] 에서 '임의 기준 주소' 옵션을 '**아니요(/DYNAMICBASE:NO)**' 로 설정해줘야 한다.
- 그 이유는 Windows7 이후 부터는 **ASLR**(Address Space Layout Randomization)을 지원하기 때문에 프로그램을 실행할 때마다 메모리 주소가 변경된다. 실습에서 메모리 주소를 고정해주기 위해 '아니요'로 설정한다.

![](./images/setting.png)





## 11.1 컴퓨터와 메모리

**변수의 본질은 메모리이며 모든 메모리는 자신의 위치를 식별하기 위한 근거로 고유번호(일련번호)를 갖는데, 이 번호를 메모리의 주소**라 한다. 32비트 응용프로그램에서 1바이트 단위 메모리에 부여된 일련번호는 부호가 없는 32비트 정수이며, 보통 16진수로 표기한다.

![](./images/cell.png)



주소로 메모리를 식별하는 것은 low-level 특성이며, high-level에서는 주소보다는 이름(식별자)으로 식별한다. 따라서, 변수의 선언 및 정의는 메모리 확보를 의미하며, 선언 시 부여한 이름으로 확보한 메모리를 식별한다.

변수를 이루는 세 가지 요소는 다음과 같다. 

- 이름이 부여된 메모리
- 그 안에 담긴 정보
- 메모리의 주소

![](./images/memory.png)



다음 예제코드는 단항 연산자인 **주소 번지 연산자**(주소 연산자)를 이용해 해당 변수의 이름 즉, **변수의 메모리 주소**를 출력하는 코드이다.

```c
// pointer01.c

#include <stdio.h>

int main(void){
    
    int nData = 10;
    printf("%s\n", "nData");

    // 변수 nData에 들어 있는 값을 출력
    printf("%d\n", nData);
    // 변수 nData의 메모리 주소를 출력
    printf("%p\n", &nData);  // %p: pointer, 16진수로 출력
    return 0;
}
/* 출력결과
nData
10
0061FF2C
*/
```



위의 코드를 요약하면 아래와 같다

> "변수명이 `nData`인 부호가 없는 32비트 정수형 메모리의 실제 주소는 `0x0061FF2c`이고, 그 안에 저장된 정보는 10진 정수인 `10`이다."



### 11.1.1 메모리의 종류

메모리는 용도에 따라 스택(stack), 힙(heap), 데이터 영역(data section), 텍스트 영역(text section)등으로 나눌 수 있다.

![](./images/memory_structure.png)

