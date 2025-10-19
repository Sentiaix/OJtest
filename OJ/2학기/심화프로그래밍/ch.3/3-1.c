/*5개의 숫자를 입력받아, 크기가 큰 순서대로 출력하는 프로그램을 작성해보자.
(단, 배열 사용하지 않는다.) 이거 진짜 미치겟네 아오 심지어 input>>까지 출력인게 말이안됨

# 입출력 예시
Input >> 4 6 1 7 9
9 7 6 4 1*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    int a, b, c, d, e, temp;

    printf("Input >> ");
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

    // a~e를 직접 비교해서 swap
    if (a < b) { temp = a; a = b; b = temp; }
    if (a < c) { temp = a; a = c; c = temp; }
    if (a < d) { temp = a; a = d; d = temp; }
    if (a < e) { temp = a; a = e; e = temp; }

    if (b < c) { temp = b; b = c; c = temp; }
    if (b < d) { temp = b; b = d; d = temp; }
    if (b < e) { temp = b; b = e; e = temp; }

    if (c < d) { temp = c; c = d; d = temp; }
    if (c < e) { temp = c; c = e; e = temp; }

    if (d < e) { temp = d; d = e; e = temp; }

    printf("%d %d %d %d %d\n", a, b, c, d, e);
    return 0;
}