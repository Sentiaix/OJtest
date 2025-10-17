/*## 문제 설명
[문제2-7]과 비슷하게 실숫값을 읽어 들여 그 값을 
반지름으로 하는 원의 넓이를 구해서 출력하는 프로그램을 작성해보자.

이때, 파이는 3.14로 계산한다.

## 입력 예시
반지름은 : 6.8

## 출력 예시
원의 넓이는 145.1936입니다.
*/

#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14
#include <stdio.h>

int main(){
    double r, area;

    printf("반지름은 : ");
    scanf("%lf", &r);

    area = r * r * PI;

    printf("원의 넓이는 %.4f입니다.\n", area);

    return 0;
}