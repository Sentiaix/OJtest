/*## 문제 설명
정수형 숫자 N(1~100)을 입력하면 Nx4 배열이 만들어 지고 배열 안의 값을 지그재그로
그리며 정수형으로 출력하는 프로그램을 만들어보자.
배열에 채워지는 숫자는 0부터 시작한다.

##입력 예시 1
2

##출력 예시 1
0123
7654

##입력 예시 2
4

##출력 예시 2
0123
7654
891011
15141312*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N = 0; // 행 개수 입력
    scanf("%d", &N);

    int cols = 4; // 열 개수는 고정
    int** arr = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        arr[i] = (int*)malloc(cols * sizeof(int));
    }

    int num = 0;

    // 배열 채우기
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {  // 짝수 행: 왼쪽→오른쪽
            for (int j = 0; j < cols; j++) {
                arr[i][j] = num++;
            }
        } else {            // 홀수 행: 오른쪽→왼쪽
            for (int j = cols - 1; j >= 0; j--) {
                arr[i][j] = num++;
            }
        }
    }

    // 출력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }

    // 메모리 해제
    for (int i = 0; i < N; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}