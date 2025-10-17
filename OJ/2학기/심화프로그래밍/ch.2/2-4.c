/*## 문제 설명
[문제 2-11]과 비슷하게 정숫값 2개를 읽어 들여
앞의 값이 뒤의 값의 몇 %인가를 실수로 출력하는 프로그램을 작성하라.
** 소수점 아래 8번째 자리까지 출력한다

## 입력 예시
2개의 정수를 입력하세요.
정수 a : 48
정수 b : 87

## 출력 예시
a값은 b의 55.17241379%입니다.*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    int a, b;
    double ratio;

    printf("2개의 정수를 입력하세요.\n");
    printf("정수 a : ");
    scanf("%d", &a);
    printf("정수 b : ");
    scanf("%d", &b);

    ratio = (double)a / b * 100.0;

    printf("a값은 b의 %.8f%%입니다.\n", ratio);

    return 0;
}