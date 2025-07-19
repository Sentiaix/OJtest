#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    int mat[3][5] = { {0} }; //3행 5열, kor eng math sum avg

    for(int i = 0; i < 3; i++){
        printf("%dth kor eng mat score : ", i + 1);

        for(int j = 0; j < 3; j++){
            scanf("%d", &mat[i][j]);
        }
    }

    for(int i = 0; i < 3; i++){
        mat[i][3] = (mat[i][0] + mat[i][1] + mat[i][2]);
        mat[i][4] = (mat[i][3] / 3);
    }

    printf("kor     eng    mat    sum    avg\n");

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            printf("%d      ", mat[i][j]);            
        }
        printf("\n");
    }

    return 0;
}