/*# 문제 설명 

1보다 큰 입력 정수가 넓이인 모든 직각삼각형의 밑변과 높이의 길이(정수)를
나열하는 프로그램을 작성한다.
단, 밑변의 길이는 높이의 길이보다 크지 않다.

# 입력 예시 1
18

# 출력 예시 1
1 x 36
2 x 18
3 x 12
4 x 9
6 x 6

# 입력 예시 2
15

# 출력 예시 2
1 x 30
2 x 15
3 x 10
5 x 6

# 입력 예시 3
2

# 출력 예시 3
1 x 4
2 x 2
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int s;
    scanf("%d", &s);

    int area = 2 * s; // 밑변 * 높이 = 2 * 넓이
    
          // base < 약수(밑면)
    for (int base = 1; base * base <= area; base++) { // 제곱근까지만 반복; 제곱근까지만 해도 넓이 / 밑면 쌍으로 다 나오기 때문. 예) 25: 1 5 (5 + 1) 25, 30: 1 2 3 6 (5.4 + 1) 10 15 30
        if (area % base == 0) { // 나누어떨어지면 약수 쌍
            int height = area / base; // a로 나눠지면 당연히 a * b = s임
            if (base <= height) { // 밑변이 높이보다 크지 않게 ( 약수쌍 중 밑변의 넓이가 더 큰건 이론적으로 말이 안 됨)
                printf("%d x %d\n", base, height);
            }
        }
    }

    return 0;
}
