#include <stdio.h>
int main(){
    int a;
    printf("positive number : ");
    scanf("%d", &a);
    // bit 연산자는 01001과 같은 2진수(bit)형을 이용하여 연산한다.
    printf("negative number : %d", ~a+1);
    
    return 0;
}