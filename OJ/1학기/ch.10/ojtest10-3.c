#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
// str을 받고, n을 받아서 문자를 rotate하는 함수.
// <input>: hello 1, <output>: ohell  
// <input>: test 2, <output>: stte

// function declaration
void rotate_str(char* str, int n);

int main(){
    char str[128];
    int n;

    scanf("%s %d", str, &n);
    rotate_str(str, n);
    printf("%s\n", str);

    return 0;
}

// define function
void rotate_str(char* str, int n){
    char transer[129];
    int len_str = strlen(str);

    n %= len_str; // 과하게 돌아가는걸 방지함.

    for(int i = 0; i < n; i++){
        
        // rotate
        for(int j = 0; j < len_str - 1; j++){
            transer[j + 1] = str[j]; // 밀린 글자들을 저장
            transer[0] = str[len_str - 1]; // 맨 끝글자를 앞으로 가져옴
        }

        // printf("%s\n", transer); test pr

        for(int k = 0; k < len_str; k++){
            str[k] = transer[k];
        }
    }
    
    str[len_str] = '\0';
}