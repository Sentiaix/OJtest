#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int x, count = 0;

    scanf("%d", &x);

    if (x < 100 || x > 1000) { //x가 100~1000 범위에 해당하지 않으면 종료
        return 0;
    }

    for (int i = 1; i <= x; i++) {
        int temp = i;
        while (temp > 0) {
            if (temp % 10 == 3) {
                count++; // 숫자의 각 자리에 3이 있을 때마다 누적
            }
            temp /= 10; // temp = temp/10; 즉, temp를 나눠 한자릿수 줄임
        }
    }

    printf("%d\n", count);

    return 0;
}