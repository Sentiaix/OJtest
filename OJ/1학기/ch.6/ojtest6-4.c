#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a, b;

    while (1) {
        scanf("%d %d", &a, &b);

        if (a < 2 || a > 9 || b < 2 || b > 9) { // 범위 밖이라면 다시 시도하기
            printf("Try again\n");
            continue;
        }
        break;
    }

    for (int i = 1; i <= 100; i++) {
        if (i % a == 0 && i % b == 0) { // 1~100 중에 a의 배수이면서, b의 배수인 i 출력
            printf("%d ", i);
        }
    }

    printf("\n");

    return 0;
}