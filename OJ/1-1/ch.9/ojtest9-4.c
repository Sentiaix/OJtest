#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 5

// test input > 50 -69 85 20 -100 > -14

// function declaration
int get_arry_sum(int *A, int size);

int main(){
    int arr[SIZE];

    for(int i = 0; i < SIZE; i++){
        scanf("%d", &arr[i]);
    }

    int rt_value = get_arry_sum(arr, SIZE);

    printf("%d\n", rt_value);

    return 0;
}

// define function
int get_arry_sum(int *A, int size){
    int sum = 0;

    for(int i = 0; i < size; i++){
        sum += A[i];
    }
    // for(int* i = A; i < A + size; i++){
    //     sum += *i;
    // }
    // 라고 해도 됨.
    
    return sum;
}
