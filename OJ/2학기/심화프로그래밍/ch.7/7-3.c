/*32비트 정수 x, 시작 위치 pos, 길이 n을 입력받아
다음 세 가지 연속 비트 조작 결과를 각각 출력하시오.
Set → 지정 구간 비트를 1로 설정
Reset → 지정 구간 비트를 0으로 설정
Invert → 지정 구간 비트를 반전

입력형식
x
pos
n

[입력]
43981
4
3
[출력]
Set 결과: 0x0000ABFD
Reset 결과: 0x0000AB8D
Invert 결과: 0x0000ABBD*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

unsigned setBits(unsigned x, int pos, int n) {
    unsigned mask = ((1U << n) - 1) << pos; // 길이 n의 비트 마스크 생성. 1u는 0000...0001을, <<n은 n비트 왼쪽 이동, -1은 n비트가 1인 값 생성, <<pos는 pos 위치로 이동
    // 예: 1u = 0000..0000 0001 > n=3 -> 0000..0000 1000 -1 > 0000..0000 0111 << pos=4 -> 0000 0000 ... 0111 0000
    return x | mask; // OR 연산으로 지정 구간 비트를 1로 설정
}
unsigned resetBits(unsigned x, int pos, int n) {
    unsigned mask = ~(((1U << n) - 1) << pos); // 길이 n의 비트 마스크 생성 후 반전
    // setBits처럼 생성, 그 후 ~연산자로 반전 0000..0000 0111 0000 -> 1111..1111 1000 1111
    return x & mask; // AND 연산으로 지정 구간 비트를 0으로 설정
}
unsigned invertBits(unsigned x, int pos, int n) {
    unsigned mask = ((1U << n) - 1) << pos; // 길이 n의 비트 마스크 생성
    return x ^ mask; // XOR 연산으로 지정 구간 비트를 반전 (xor : 같으면 0, 다르면 1)
}

int main(){
    unsigned num;
    int pos, n;
    scanf("%u %d %d", &num, &pos, &n);
    unsigned setResult = setBits(num, pos, n);
    unsigned resetResult = resetBits(num, pos, n);
    unsigned invertResult = invertBits(num, pos, n);

    printf("Set 결과: 0x%08X\n", setResult);
    printf("Reset 결과: 0x%08X\n", resetResult);
    printf("Invert 결과: 0x%08X\n", invertResult);

    return 0;
}