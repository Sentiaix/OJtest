/*2개의 숫자를 입력받아, 조건 연산자를 활용하여 최대값을 출력하는 프로그램을 작성해보자.
[ 조건 연산자: 조건식 ? 참일 경우 : 거짓일 경우 ]

# 입출력 예시
Input >> 10 2
Max is 10.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    int a, b, max;

    printf("Input >> ");
    scanf("%d %d", &a, &b);

    max = (a > b) ? a : b;

    printf("Max is %d.\n", max);

    return 0;
}