#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 함수 선언
int print_sum(int n);

void main(){ // 수정금지!!
	int n;
	while(1){
		scanf("%d", &n);
		if( 0 >= n) break; // n이 0보다 같거나 작으면 루프 정지
		print_sum(n);
	}
}

// 함수 정의
int print_sum(int n){
    static int numOfLoop = 0; // 순환호출해도 저장한 값을 잊지 않는 용도
    int helper = numOfLoop; // 마지막 실행때 numOfLoop 대신 return하는 용도

    // static 자료형에 n값을 계속 쌓음.
    numOfLoop += n;

    printf("%d", n);

    if(n > 0){
        printf("+");
        return print_sum(n - 1);
    } else{
        printf("=%d\n", helper);
        numOfLoop = 0;
        return helper;
    }
}