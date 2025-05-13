#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// test input > 25 36 86 95 45 > 45 95 86 36 25
// test input2 > 1 2 3 4 5 > 5 4 3 2 1

// define function
void reverse_print(int* arr, int n);

int main(){
    int arr[5];

    for(int i = 0; i < 5; i++){
        scanf("%d", &arr[i]);
    }

    reverse_print(arr, 5);

    return 0;
}

// funtion declaration
void reverse_print(int* arr, int n){
    int temp_arr[5] = {0,};

    for(int i = 0; i < n; i++){
        temp_arr[n - 1 - i] = arr[i];
    }

    for(int i = 0; i < 5; i++){
        printf("%d ", temp_arr[i]);
    }

    printf("\n");
}