#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
/*
##문제  설명
정수 N (1 <= N <= 100)을 입력받아,
1-N*N까지 2차원 배열에 저장한 후 대각선에 있는 배열값들만 합하여 출력하시오.
예를 들어 3을 입력한다면,
1 2 3
4 5 6 
7 8 9
와 같이 배열에 저장한 0 대각선의 값인 1+5+9 15 출력하는 프로그램을 작성하시오
## 입력
정수 N 입력 (1 <= N <= 100)
## 출력
대각선의 합을 출력한다.
## 입력 예시1
3
## 출력 예시1
15
*/

int main(){
    int size; // 크기 입력
    int** arr;
    int n = 1; // 숫자

    scanf("%d", &size);

    arr = (int**)malloc( sizeof(int*) * size );
    for(int i = 0; i < size; i++){
        arr[i] = (int*)malloc( sizeof(int) * size );
    }

    // 배열에 값 할당
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            arr[i][j] = n++;
        }
    }

    int sum = 0; // 대각합 저장
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(i == j){
                sum += arr[i][j];
            }
        }
    }

    printf("%d\n", sum);

    for(int i = 0; i < size; i++){
        free(arr[i]);
    }
    free(arr);

    return 0;
}