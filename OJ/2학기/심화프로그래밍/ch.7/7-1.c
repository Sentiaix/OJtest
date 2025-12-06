/*32비트 정수 x를 입력받아, 1로 설정된 비트(세트 비트)의 개수를 출력하시오.

[입력]
43981
[출력]
1비트의 개수: 10*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int countSetBits(int n){
    int count = 0;
    while (n) {
        count += n & 1; // 현재 비트가 1인지 확인. 1비트면 and 연산 > 1, 아니면 0을 count에 추가
        n >>= 1;        // 다음 비트로 이동
    }
    return count;
}

int main() {
    int num;
    scanf("%d", &num);

    int bit1 = countSetBits(num);
    printf("1비트의 개수: %d\n", bit1);

    return 0;
}