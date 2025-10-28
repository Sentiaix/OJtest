/*##문제 설명 
정수 N(1~10)을 입력하면 Nx5 크기가 만들어지는 정수형 배열 a를 선언한다.
이후 배열 a에 Nx5개 정수를 입력한 후, 1차원 배열 b에 배열 a의 모든 값이 큰 수부터
정렬되도록 만드는 프로그램을 작성해 보자.

##입력 예시1 (1x5 배열 생성)
1
5 1 3 2 4

## 출력 예시1
5 4 3 2 1

--

##입력 예시2 (3x5 배열 생성)
3
7 2 14 1 5 12 9 3 8 15 6 4 10 13 11

## 출력 예시2
15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// function declaration
void bubble_sort(int* arr, int size);

int main(){
    int N = 0; // 정수 입력

    scanf("%d", &N);

    // 동적 메모리 할당 (stdlib.h)
    int size = N * 5;
    int* a = (int*)malloc( size * sizeof(int) );

    // 값 입력
    for(int i = 0; i < size; i++){
        scanf("%d", &a[i]);
    }

    // 정렬
    bubble_sort(a, size);

    // 출력
    for(int i = 0; i < size; i++){
        printf("%d ", a[i]);
    }    

    printf("\n");

    free(a); // 동적 메모리 해제

    return 0;
}

// define function
void bubble_sort(int* arr, int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - i - 1; j++){
            if (arr[j] < arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}