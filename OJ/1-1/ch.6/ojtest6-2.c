#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    int a;
    int sum = 0;

    do{
        scanf("%d", &a);
        sum += a;
    } while(a != 0); //괄호 속이 거짓이면 do-while 문 중단

    printf("%d\n", sum);

    return 0;
}