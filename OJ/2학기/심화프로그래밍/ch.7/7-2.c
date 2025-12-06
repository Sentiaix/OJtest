/*정수 x와 회전 거리 n을 입력받아, x의 비트를 오른쪽으로 n비트 순환 회전시킨 결과를 16진수로 출력하시오.

[입력]
43981
4

[출력]
회전 결과: 0xD0000ABC*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

unsigned rotateRight(unsigned x, int n) {
    int bits = sizeof(x) * 8; // 정수의 비트 수 (32비트)
    n = n % bits; // 회전 거리가 비트 수보다 클 경우를 대비

    return (x >> n) | (x << (bits - n)); // 오른쪽으로 n비트 이동 후, 왼쪽으로 (bits - n)비트 이동한 값을 합침
}

int main(){
    unsigned num;
    int n;
    scanf("%u %d", &num, &n);

    unsigned rotated = rotateRight(num, n);
    printf("회전 결과: 0x%X\n", rotated);

    return 0;
}