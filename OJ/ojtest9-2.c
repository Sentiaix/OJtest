#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// test input > 5 10 20 30 60 > 125

int main(){
    int* pt; // 문제 요구사항(수정금지지)
    int arr[5]; // 배열값 받는곳
    int stacker = 0; // 저장소

    for(int i = 0; i < 5; i++){
        scanf("%d", &arr[i]);
        pt = &arr[i];
        stacker += *pt;
    }



    printf("%d\n", stacker);

    return 0;
}