#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
// 문자열 받고 그 문자열로 한 글자씩 직각삼각형 출력하기.
// 예: <input>: hello, <output>: h\nhe\nhel\nhell\nhello

// function declaration
void rgt_triangle(char* str);

int main(){
    char str[128];

    scanf("%s", str);

    rgt_triangle(str);

    return 0;
}

// define function
void rgt_triangle(char* str){
    int len_str = strlen(str);

    // 문자열 길이만큼 출력>개행 반복
    for(int i = 0; i < len_str; i++){

        // 개행 할때마다 하나씩 더 출력
        for(int j = 0; j < i + 1; j++){
            printf("%c", str[j]);
        }
        printf("\n");
    }
}