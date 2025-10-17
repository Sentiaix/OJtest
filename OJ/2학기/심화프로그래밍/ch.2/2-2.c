/*## 문제 설명
[문제 2-6]과 비슷하게 
2개의 정숫값의 평균값 부호를 반전한 값이 출력되는 프로그램을 작성하자.

## 입력 예시
2개의 정숫값을 입력하세요.
정수 x: 55
정수 y: 64

## 출력 예시
평균값의 부호를 반전한 값은 -59.5입니다.*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    int x, y;
    double avg;

    printf("2개의 정숫값을 입력하세요.\n");
    printf("정수 x: "); scanf("%d", &x);
    printf("정수 y: "); scanf("%d", &y);

    avg = (x + y) / 2.0;



    printf("평균값의 부호를 반전한 값은 %.1f입니다.\n", -1.0f * avg); 

    return 0;
}