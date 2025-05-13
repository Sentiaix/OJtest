#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    int a;

    scanf("%d", &a);

    for(int i = 0; i < a/2 + 1; i++){
        for(int j = 0; j < a; j++){
            if((a/2) - i<= j && j <= (a/2) + i){ //*가 a값 중앙으로부터 좌, 우로 한칸씩 점점 늘어남
                printf("*");
            } else{
                printf("^");
            }
        }
        printf("\n");
    }

    return 0;
}