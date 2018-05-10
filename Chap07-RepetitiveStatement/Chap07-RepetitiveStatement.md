# Chap07 - 반복문



반복문(Repetitive Statement)은 **일정구간의 코드를 연속적으로 반복해 실행하는 제어문**이다.



## 7.1 `while` - 조건 기반 반복문

while문은 아래의 그림에서도 확인할 수 있듯이 `if`문과 차이가 없다. 괄호 속에 조건식을 기술하는 문법이나 여러 구문을 스코프(`{}`)로 묶는 것이 동일하다. 

![](./images/while-loop.png)



하지만, `while`문은 `if`문과 달리 반복문이다. **내부 구문이 끝나면 그다음으로 그냥 넘어가는 것이 아니라 다시 구문의 처음으로 돌아가 조건식을 확인**한 후 조건이 참이면 계속해서 구문을 돌고, 거짓이면 반복이 끝나게 된다.



### 7.1.1 기본구조 조건에 의한 제어

다음 예제코드는 `getchar()`를 이용해 사용자로부터 문자 혹은 문자열을 입력받은 후, `putchar()`로 출력하는 코드다. 

```c
// opswap1.c
#include <stdio.h>

int main(void){

    char ch = 0;

    // 한 글자를 입력받아 ch에 저장한 후 이를 '\n'과 비교
    while((ch = getchar()) != '\n'){
        // 조건이 맞는 경우
        putchar(ch);
    }

    // '\n'이 등장해 조건을 만족하지 못해 반복문이 끝남
    return 0;
}
```



### 7.1.2 무한루프

반복문에서 가장 많이 범하는 오류 중 하나가 바로 '무한루프'이다. 반복문에서 가장 주의해야 할 부분은 **반복을 멈추기 위한 조건**이고, 그 조건에 **영향을 줄 수 있는 연산이 반복문 내부에 포함**되어야 한다.

다음 예제는 반복문 내부 구문에 반복을 멈추기 위한 조건에 도달하지 못하여 무한루프에 빠지게 되는 코드이다. 이 코드를 종료하려면 `Ctrl + c`를 눌러 강제 종료해야 한다.

```c
// ctrlendless01.c
#include <stdio.h>

int main(void){

    int nIndex = 0;

    // nIndex 변수는 반복조건에 직접 영향을 준다.
    while (nIndex >= 0){
        // 반복구간 내부 연산을 수행하더라도 nIndex는
        // 달라지지 않는다. 따라서 반복이 끝날 수 없다.
        nIndex + 1; 
    }

    printf("%d\n", nIndex);
    return 0;
}
```



### 7.1.3 반복문 내부에 선언한 자동변수

반복문 내부에 변수를 선언하는 것은 바람직하지 않다. 그 이유는 반복문이 계속 반복(Iteration)될때 마다 변수가 선언되어 초기화 되기 때문이다. 다음 예제 코드를 통해 변수를 반복문 내에서 선언할 경우 어떠한 문제가 발생하는지 보도록 하자. 문자열을 입력받아 인덱스와 함께 화면에 출력하는 예제이다.

```c
// ctrlwhilevariable.c
#include <stdio.h>

int main(void){
    
    char ch = 0;

    while((ch = getchar()) != '\n'){
        // nIndex 변수가 생성되고 초기화 된다.
        int nIndex = 0;
        printf("%02d\t%c\n", nIndex, ch);

        // 변수의 값을 증가시키지만 논리적으로 소용이 없다.
        ++nIndex;

        // 여기서 nIndex는 소멸하고 사라지기 때문이다.
    }

    return 0;
}

/*출력 결과
Hello
00      H
00      e
00      l
00      l
00      o
*/
```



### 7.1.4 반복문의 중첩

`if`문 내부에 또 다른 `if`문을 중첩할 수 있는 것처럼, `while`문 내부에 또 다른 `while`문을 중첩할 수 있다. 

```c
while(조건식) {  // 바깥쪽 반복문
    
    while (조건식) {  // 안쪽 반복문
        ......
    }
}
```

 

다음 예제는 중첩 반복문을 이용해 구구단을 출력하는 코드다.

```c
// ctrlnestedloop01.c
#include <stdio.h>

int main(void){

    int i = 0, j = 0;

    i = 2;  // 카운팅 변수(계수) i 초기화
    while(i <= 9){
        j = 1;
        while(j <= 9){  // 계수 j 초기화
            printf("%d * %d = %d\n", i, j, i*j);
            ++j;
        }
        putchar('\n');
        ++i;
    }

    return 0;
}
```





## 7.2 `for`, 계수(count) 기반 반복문

`for`문과 `while`문은 반복문이라는 점에서 같지만, `while`문은 조건에 기반을 둔 측면이 강하고 **`for`문은 계수(count)에 기반을 둔 측면이 강하다**.

![](./images/for_loop.jpg)



`for`문에서는 반복횟수에 영향을 주는 **계수(count) 초기화, 조건식, 계수 증감**을 아래의 구조처럼 한 행에 기술하도록 한다. 

```c
for ( init; condition; increment ) {
   statement(s);
}
```



다음 예제 코드는 `for`문을 이용하여 5회 반복 수행하는 코드다.

```c
// ctrlfor01.c
#include <stdio.h>

int main(void){

    // 계수 초기화; 조건식; 계수 증가
    for(int i = 0; i < 5; ++i){
        printf("%dth\n", i);
        // 제어의 흐름이 반복될 때 ++i를 실행하고 조건을 비교한다.
    }

    return 0;
}
/*출력결과
0th
1th
2th
3th
4th
*/
```



