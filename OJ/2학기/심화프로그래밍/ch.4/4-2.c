/*# 문제 설명 

읽어 들인 두 양의 정수의 모든 공약수를 순서대로 출력한 후
공약수의 개수도 출력하는 프로그램을 작성한다.

# 입력 예시 1
12 18

# 출력 예시 1
1 2 3 6 
공약수는 4개

# 입력 예시 2
10 1

# 출력 예시 2
1 
공약수는 1개
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// function declaration
void soinsoo(int a, int b);

int main(){
    int a, b;

    scanf("%d %d", &a, &b);

    soinsoo(a, b);
 
    return 0;
}

// define function
void soinsoo(int a, int b){
    int count = 0;
    int min = (a < b) ? a : b;

    for(int i = 1; i <= min; i++){
        if (a % i == 0 && b % i == 0){
            printf("%d ", i);
            count++;
        }
    }
    
    printf("\n공약수는 %d개\n", count);
}