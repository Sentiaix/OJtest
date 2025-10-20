#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// define function
void temp(int *arr){
    for(int i = 0; i < 5; i++){
        scanf("%d", &arr[i]);
    }
}

int main(){
    int arr[5];

    temp(arr);

    for(int i = 0; i < 5; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}