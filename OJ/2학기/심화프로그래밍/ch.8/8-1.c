/*# 문제 설명
정수 값 n을 입력 받은 후 각 줄마다 'A'를 n, n-1, n-2, ..., 2, 1개 출력하는 재귀 함수를 구현하라.

# 입출력 예시 1: 입력 3에 따른 출력 
3
AAA
AA
A

# 입출력 예시 2: 입력 4에 따른 출력 
4
AAAA
AAA
AA
A*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// function declaration
void printA(int n);

int main(){
    int n;

    scanf("%d", &n);
    printA(n);

    return 0;
}

// define function
void printA(int n) {
    if(n == 0){
        return ;
    }
    for(int i = 0; i < n; i++) {
        printf("A");
    }
    printf("\n");

    return printA(n - 1);
 }