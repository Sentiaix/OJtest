#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    int arr[5];

    printf("input the 5 values : ");

    for(int i = 0; i < 5; i++){
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5 - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("After bubble sorting : ");

    for(int i = 0; i < 5; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}