#include <stdio.h>

int main(){
    float a,b;
    printf("two real values : ");
    scanf("%f\n %f", &a, &b); // 주의! scanf에서 \n 사용할때는 다음 입력 전에 space를 둬야 함.
    printf("sum of integer parts : %d", (int)(a+b));
    
    return 0;      
}