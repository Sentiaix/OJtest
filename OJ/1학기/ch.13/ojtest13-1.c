#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// function declaration
int search_num(int a, int n, int* p); // 특정 수 찾기

int main(){
    int size; // 받을 숫자의 수
    int want; // 찾고자 하는 숫자
    int numOfint; // 찾은 숫자의 중복도

    printf("Enter size: ");
    scanf("%d", &size);

    // 동적 메모리 할당
    int* p = (int*)malloc( size * sizeof(int) );

    // 숫자 입력
    printf("Enter %d numbers: ", size);
    for(int i = 0; i < size; i++){
        scanf("%d", &p[i]);
    }

    // 찾고자 하는 숫자 입력
    printf("Find: ");
    scanf("%d", &want);

    numOfint = search_num(want, size, p);

    // if(numOfint == -1) printf("non found\n"); 
    printf("%d number of %d\n", numOfint, want);

    return 0;
}

// define function
int search_num(int a, int n, int* p){
    // a << 찾으려는 숫자 들어가는 곳
    // n << 반복 수
    // p << 찾아낼 수가 들어있는 곳
    int fnd = 0; // 발견된 개수만큼 증가

    for(int i = 0; i < n; i++){
        if(p[i] == a) fnd++;
    }

    return fnd;
}