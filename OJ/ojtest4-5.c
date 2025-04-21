#include <stdio.h>

int main(){
    int a;

    printf("number : ");
    scanf("%d", &a);

    a = (a<<3)>>2; // a의 비트를 왼쪽으로 3칸 옮긴 후, 우로 2칸 옮기기

    printf("3-bit left shift and 2-bit right shift : %d\n", a);

    return 0;
}