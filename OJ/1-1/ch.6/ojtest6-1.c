#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    int x, y;
    int sum = 0; // 합치는 곳은 무조건 초기화 필수

    scanf(" %d %d", &x, &y);

    for(int i = x; i <= y; i++){ //x부터 y까지 더함.
        if((y-x)<0) break; //큰 수에서 작은수를 뺐는데 0보다 작다면 루프 취소.
        sum += i;
    }

    printf("%d\n", sum);

    return 0;
}