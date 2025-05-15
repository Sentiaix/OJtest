#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// test input example: 15 28 14 19 36 23 9 3 1 47

// 함수 선언
void swap(int* px, int* py);

int main(){
    int arr[10];

    for(int i = 0; i < 10; i++){
        do{
            scanf("%d", &arr[i]);
        } while (arr[i] < 1 || arr[i] > 50); //do-while은 while이 참일때 탈출함!
    }

    swap(&arr[0], &arr[9]);

    return 0;
}

void swap(int* px, int* py){
    
    for(int* i = px; i < py; i++){
        for(int* j = px; j < py; j++){
            if(*j > *(j + 1)){
                int temp = *j;
                *j = *(j + 1);
                *(j + 1) = temp;
            }
        }
    }

    for(int* i = px; i < py + 1; i++){
        printf("%d ", *i);
    }
    // Sol2.
    // for(int i = 0; i < 10; i++){
    //     printf("%d ", *(px + i))
    // }

    printf("\n");
}