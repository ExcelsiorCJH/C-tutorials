# Chap03 - 표준 입출력 도구



## 3.1 문자 입출력

영문 한 글자를 입출력하는데 사용하는 자료형은 `char`형이며, 8비트의 정수 형식이다. 



### 3.1.1 `getchar()`/`putchar()`함수

`int getchar(void);`

- 인자 : 없음
- 반환값 : 입력 문자 하나

`int putchar(int c);`

- 인자 : `c` - 출력할 문자 상수
- 반환값 : 출력 문자 하나



```c
// getchar01.c
#include <stdio.h>

int main(void)
{
    // 자료형이 char 형식이고 이름이 ch인 변수의 선언 및 정의
    char ch = 0;

    // getchar() 함수가 반환한 값을 ch 변수에 저장한다.
    ch = getchar();
    // 변수 ch에 담겨 있는 정보를 화면에 출력한다.
    putchar(ch);
    // 대문자 Z를 화면에 출력한다.
    putchar('Z');
    // 0을 반환하고 main() 함수가 반환한다. (프로그램 종료)
    return 0;
}
```



### 3.1.2 `_getch()`/`_getche()` 함수

`_getch(), _getche()` 함수는 위의 `getchar()`함수와 비슷하지만, **"아무 키나 눌려서 사용자 입력이 발생했음"** 을 감지하려는 목적으로 쓰인다.  `getchar()`와 다른점은 사용자가 입력한 정보가 버퍼를 거치지 않고 즉시 전달되는 **Non-buffered I/O**를 사용한다는 것이다. `_getch()`함수를 사용하려면 `conio.h` 헤더 파일을 `include` 해야한다.

```c
// getch01.c
#include <stdio.h>
// _getch() 함수를 사용하기 위한 헤더 파일 포함
#include <conio.h>

int main(void){
    char ch = 0;
    // 사용자에게 전달할 메시지(문자열) 출력
    printf("아무 키나 누르면 다음으로 넘어갑니다. \n");
    // 사용자로부터 키보드 입력을 한 번 받는다. 사용자가 입력한 값을 
    // _getch() 함수가 반환하면 이를 ch변수에 저장한다.
    ch = _getch();

    // 사용자가 입력한 문자를 출력한다.
    printf("입력한 키는 ");
    putchar(ch);
    printf("입니다.\n");
    return 0;
}
```





## 3.2 문자열 입출력

**문자열은 정확히 말해서 '문자의 배열'** 이다(2장 참고). 여기서 중요한 것은 문자를 다루는 것과 문자열을 다루는 것의 차이는 한 인스턴스(`char`)를 다루는 것과 여러 인스턴스(`char[n]`)를 묶어서 한꺼번에 다루는 것의 차이라 할 수 있다.

배열의 이름은 일반 변수의 이름과 달리 메모리의 주소에 부여한 식별자이다. 예를 들어, `char szName[32];` 은 배열을 이루는 각 요소의 자료형이 `char`이고 개수가 32인 배열을 의미한다.  그리고 그 배열을 대표하는 주소에 `szName`이라는 이름(식별자, identifier)를 부여한 것이다.

**배열의 이름은 주소** 이며, 이 주소를 저장하기 위한 전용 변수가 바로 포인터(pointer)이다.

- 주소는 집주소처럼 메모리의 위치를 표시하는 정보이다.
- 주소를 저장하기 위한 전용변수가 포인터이다.
- 배열의 이름은 주소다.
- 배열은 여럿이 한 데 모인 집합체이다.
- 배열의 이름은 포인터에 담을 수 있다. 



### 3.2.1 `gets()` / `puts()` 함수

`char *gets(char *buffer);`

- 인자 : buffer - 입력받은 문자열을 저장할 메모리의 주소
- 반환값 : 전달받은 메모리의 주소

`int puts(const char *string);`

- 인자 : string 출력할 문자열이 저장된 메모리의 주소
- 반환값 : 정상적이면 음수가 아닌 값을 반환


`gets()/puts()` 함수는 문자열을 입/출력 해주는 함수이며, 매개변수가 포인터다. 따라서, `gets(), puts()` 함수를 호출하려면 메모리의 주소를 적어야 한다.

```c
#include <stdio.h>

int main(void)
{
    // char 변수 32개가 한 덩어리로 묶인 배열 선언 및 정의
    char szName[32] = { 0 };
    
    // 사용자로 부터 이름(문자열)을 입력받는다.
    printf("이름을 입력하세요: ");
    // 사용자가 입력한 문자들을 문자 배열에 모두 저장한다.
    gets(szName);  // gets()는 보안 결함 문제가 있음

    // 배열에 저장된 이름을 화면에 출력한다.
    printf("당신의 이름은 ");
    puts(szName);
    puts("입니다.");
    return 0;
}
```



`gets()` 함수가 호출되면 키보드 입력 버퍼(buffer, 메모리)의 내용을 확인하고, 버퍼가 비어있으면 문자열을 입력받아 버퍼에 저장한다.

`puts()` 함수는 매개변수로 전달된 메모리의 주소에 저장된 문자정보를 읽어 화면에 출력한다.  

`gets()`함수는 보안 결함 문제가 있다.  따라서, `gets()` 는 사용하지 않는 것이 좋으며, `gets_s()/fgets()` 함수를 사용한다. 

```c
#include <stdio.h>

int main(void)
{
    char szName[32] = {0};

    printf("이름을 입력하세요 : ");
    
    // Windows: gets_s(szName, sizeof(szName));
    // Linux, UNIX : fgets(szName, sizeof(szName), stdin);
    fgets(szName, sizeof(szName), stdin);

    printf("당신의 이름은 ");
    puts(szName);
    puts("입니다.");
    return 0;
}
```





## 3.3 `printf()` 함수 

`printf()`함수는 문자, 숫자(정수, 실수), 문자열 등을 하나로 조합하여 출력할 수 있는 기능을 제공한다.

`int printf(const char *format [,argument]...)`

- 인자 : `format` - 형식 문자열이 저장된 메모리의 주소 , `argument` - 형식 문자열에 대응하는 가변인자들
- 반환값 : 출력할 문자열의 개수

출력해야할 매개변수의(argument) 개수는 형식 문자의 개수와 일치해야 한다. 



### 3.3.1 형식 문자와 이스케이프 시퀀스

#### 형식 문자

자주 사용하는 형식 문자들은 `%d, %f, %s` 이다.

| 형식 문자 | 자료형        | 출력 형식                        |
| :-------: | :------------ | :------------------------------- |
|   `%c`    | int(char)     | character. ASCII문자로 출력      |
|   `%d`    | int           | Decimal. 부호가 있는 10진수      |
|   `%o`    | int           | Octal. 8진수                     |
|   `%u`    | unsigned in   | Unsigned. 부호가 없는 10진수     |
| `%x, %X`  |               | Hexa. 16진수                     |
| `%e, %E`  | float, double | Exponent. 지수형 소수            |
|   `%f`    | double(float) | Float. 10진형 소수               |
|   `%g`    | double        | 지수형 소수나 10진형 소수로 출력 |
|   `%p`    | Pointer       | 16진수 주소                      |
|   `%s`    | String        | 문자열                           |



#### 이스케이프 시퀀스

가장 많이 사용되는 이스케이프 시퀀스는 `\n, \t, \\, \"` 이다.

| 문자 | 의미                  |  문자  | 의미        |
| :--: | --------------------- | :----: | ----------- |
| `\a` | 경고음 울림           |  `\\`  | Backslash   |
| `\b` | Backspace             |  `\?`  | 물음표      |
| `\f` | 인쇄시 종이 한장 넘김 |  `\'`  | 작은 따옴표 |
| `\n` | New line (개행)       |  `\"`  | 큰 따옴표   |
| `\r` | Carriage return       | `\ooo` | 8진수       |
| `\t` | Tab                   | `\xhh` | 16진수      |
| `\v` | Vertical tab          |        |             |



```c
// format01.c
#include <stdio.h>

int main(void)
{
    printf("%d\n", 1234);
    printf("%d, %d\n", 1234, -5678);
    // 부호를 붙여서 출력
    printf("%+d, %+d\n", 1234, -5678);

    // 정수를 8자리로 맞추고 오른쪽 정렬해 출력한다.
    printf("%8d\n", 1234);
    // 왼쪽 빈 공간을 모두 0으로 채워서 출력한다.
    printf("%08d\n", 1234);

    return 0;
}
```





## 3.4 `scanf()` 함수

`int scanf(const char *format [,argmument]...)`

- 인자 : `format`- 형식 문자열이 저장된 메모리 주소, `[,argument]`- 형식 문자열에 대응하는 가변인자들
- 반환값 : 입력할 문자열의 개수

`scanf()` 함수는 형식 문자열을 이용한 사용자의 입력을 지원한다. 



### 3.4.1 정수 입력

아래의 예제는 사용자로부터 나이(정수)를 입력받아 `printf()` 함수를 이용해 출력하는 예제이다. 입력받은 나이는 `int`형 변수인 `nAge`에 저장하는데, `scanf()`함수를 호출할때 `nAge`변수의 **주소**를 의미하는 `&nAge`를 인수로 사용해야 한다.

```c
// scanfint01.c
#include <stdio.h>

int main(void)
{
    int nAge = 0;

    printf("나이를 입력하세요. : ");
    // 사용자가 입력한 정보를 int 형식으로 해석하고 nAge변수에 저장한다.
    // 그리고 $ 기호는 주소 연산자이며
    // &nAge는 nAge변수의 주소라는 의미이다.
    scanf("%d", &nAge);

    printf("당신의 나이는 %d세 입니다.\n", nAge);
    return 0; 
}
```



`scanf()` 함수도 `gets()` 함수와 마찬가지로 보안 문제가 있어, `scanf()` 대신 `scanf_s()`를 사용하는 것이 좋다. 하지만, `scanf_s()`는 Windows 운영체제에서만 사용할 수 있는 함수며, `gcc`에서는 지원하지 않는다.