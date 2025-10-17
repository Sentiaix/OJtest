/*## 문제 설명
매달 입금하는 금액과 저축하는 년수를 정수를 입력하여, 
저축되는 총액을 출력하는 프로그램을 작성해보자. 
단, 이자는 무시하며, 한달에 입금할 수 있는 금액은 최대 500만원, 
년수는 30년으로 합니다.

## 입력 예시
100000 10

## 출력 예시
12000000
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    int month_money, year; // 한달에 입금하는 금액, 년수
    int total_money; // 총 저축액

    // 1. 입력
    scanf("%d %d", &month_money, &year);

    // 2. 계산
    total_money = month_money * year * 12;

    // 3. 출력
    printf("%d\n", total_money);

    return 0;
}