#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    int arr[10];

    printf("input the 10 integer values : ");

    for(int i = 0; i < 10; i++){
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < 10; i++){
        printf("%d : ", arr[i]);
        
        for(int j = 0; j < arr[i]; j++){
            printf("*");
        }
        printf("\n");
    }

    printf("\n");

    return 0;
}