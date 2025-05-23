#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// <문제>: 복소수의 입력을 받고 합을 출력하여라. 구조체 사용 필수.
// a+bi c+di >> (a+c)+(b+d)i
// -1.0+2.4i -0.9-2.3i >> -0.1+0.1i

// 문제 해결 과정
// 1. 일단 main함수에서 문자를 char로 받고 float으로 변환을 테스트.
// 2. main함수에서 로직을 완성시키기 (실수와 허수 분리 등)
// 3. 구조체와 함수로 main함수에 있던 로직들을 모듈화하기

int main(){
    // 복소수 입력
    char sik1[100];
    char sik2[100];

    scanf("%s %s", sik1, sik2);

    float p = (float)(*sik1);

    printf("%f\n", p);

    // printf("%f %f\n", sik1 , sik2);

    return 0;
}