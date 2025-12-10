/*
영문자와 숫자가 섞인 문자열에서
모든 정수를 추출하여 포인터로 배열에 저장하고, 그 정수들의 합을 출력하시오.
영문자와 숫자가 섞여 있는 문자열이 입력된다.
이 문자열에서 정수를 모두 추출하여 배열에 저장하고, 그 정수들의 합을 계산하여 출력하는 프로그램을 작성하시오.
규칙:
연속된 숫자는 하나의 정수로 간주한다.
숫자 앞의 '-' 문자는 음수 부호로 인정한다.
추출된 정수는 최대 100개까지 저장할 수 있다.
**모든 숫자 추출 및 배열 저장은 포인터 연산으로 수행해야 한다.**
atoi, strtol 등 문자열 변환 라이브러리 함수는 사용 금지.
[입력]
문자열 s

[출력]
sum = X
[입력예시]
a12b-3c45

[출력예시]
sum = 54
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strlen()
#include <ctype.h>  // isdigit() > 0~9의 값: 그대로 반환. / 숫자가 아니면 0 반환

// function declaration
void extractIntegers(char* str, int* arr, int* count);

int main() {
    int arr[100]; // 정수 저장 배열 
    int count = 0; // 추출된 정수 개수
    char str[256]; // 입력 문자열 저장 배열
    int sum = 0; // 정수 합계

    scanf("%s", str);
    extractIntegers(str, arr, &count);
    
    for (int i = 0; i < count; i++) {
        sum += arr[i];
    }

    printf("sum = %d\n", sum);
    
    return 0;
}

// define function
void extractIntegers(char* str, int* arr, int* count) {
    int sign = 0; // 부호 플래그 (0: 양수, 1: 음수)
    int index = 0; // arr 배열의 인덱스
    char* p = str; // 문자열 포인터
    
    while (*p != '\0') {
        if (*p == '-' && isdigit(*(p + 1))) {
            sign = 1; // 이 다음 숫자는 음수임.
            p++;
        }
        if (isdigit(*p)) {
            int num = 0;
            while (isdigit(*p)) {
                num = num * 10 + (*p - '0'); // 숫자 누적
                p++;
            }
            if (sign) {
                num = -num; // 음수로 변환
                sign = 0; // 부호 플래그 초기화
            }
                                  // arr[index] = num;
            *(arr + index) = num; // 포인터 연산으로 배열에 저장
            index++;
            (*count)++; // 추출된 정수 개수 증가
        } else {
            p++; // 숫자가 아니면 다음 문자로 이동
        }
    }

    /* while에서 다루는 case */
    /* 
    case 1. hyphen(-) 기호 다음에 숫자가 오는 경우
    case 2. 바로 숫자가 연속해서 오는 경우
    case 3. 숫자가 아닌 문자가 오는 경우
    */    
}