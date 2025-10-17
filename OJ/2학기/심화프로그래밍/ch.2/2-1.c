/*## 문제 설명
[문제 2-3]과 비슷하게 읽어들인 정숫값 2개의 비율을 백분율로 출력하는 프로그램을 작성하자.

## 입력 예시
2개의 정숫값을 입력하세요.
정수 x: 10
정수 y: 25

## 출력 예시
x 값은 y 값의 40%입니다.*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    int x, y;

    printf("2개의 정숫값을 입력하세요.\n");
    printf("정수 x: "); scanf("%d", &x);
    printf("정수 y: "); scanf("%d", &y);

    printf("x 값은 y 값의 %d%%입니다.\n", 100 * x / y);

    return 0;
}