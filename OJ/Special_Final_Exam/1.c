#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*#문제 설명

키보드로부터 2와 9 사이의 정수 N을 입력받아 N x N 행렬의 대각선 원소에는
9를 그 오른쪽 원소에는 1씩 감소하면서 2차원 배열에 저장한 후, 아래 예시와
같이 출력하는 프로그램을 작성하시오

(단, 반드시 2차원 배열에 저장한 후 그 배열을 출력하여야 함.)

#입력 예시 1
2

#출력 예시 1
9 8
0 9

#입력 예시 2
5

#출력 예시2
9 8 7 6 5
0 9 8 7 6
0 0 9 8 7
0 0 0 9 8
0 0 0 0 9 */

int main(){
    int size; // 사이즈 입력
    int** arr; // 2차원 배열    
    scanf("%d", &size);

    arr = (int**)malloc( sizeof(int*) * size );
    for(int i = 0; i < size; i++){
        arr[i] = (int*)malloc( sizeof(int) * size );
    }

    // 배열에 값 할당
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(j < i) {
                arr[i][j] = 0; // 대각선 왼쪽은 0
            } else {
                arr[i][j] = 9 - (j - i); // 대각선부터 오른쪽 방향으로 1씩 감소
            }
        }
    }

    // 출력
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < size; i++){
        free(arr[i]);
    }
    free(arr);

    return 0;
}