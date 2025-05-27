#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// 구조체를 이용하여 현재 시간을 표현하는 프로그램을 작성한다. 
// 사용자로부터 2개의 시간을 입력받아서 두 시간 사이의 차이를 계산하여 출력한다. 
// 단, 입력받는 2개의 시간은 어떤 것이 먼저이고, 어떤 것이 나중인지 모른다. 
// 시(hour)로 주어지는 숫자는 0보다 크고 23보다 작다. 
// 분(min)으로 주어지는 숫자는 0보다 크고 59보다 작다. 초(sec)로 주어지는 숫자는 0보다 크고 59보다 작다.

struct time{
    int h;
    int m; // char 자료형으로 다시 짜야함.. ㅆ
    int s;
};

// function declaration
void comp_time();
void trans_time(int tot_sec);

int main(){
    struct time t[2];

    scanf("%d %d %d", &t[0].h, &t[0].m, &t[0].s);
    scanf("%d %d %d", &t[1].h, &t[1].m, &t[1].s);

    printf("%d");

    return 0;
}

// define function
void comp_time(){
    int total_time[2] = {0,};
    struct time t[2];

    // 시간을 초로 변환
    for(int i = 0; i < 2; i++){
        total_time[i] += t[i].h * 60 * 60;
        total_time[i] += t[i].m * 60;
        total_time[i] += t[i].s;
    }

    if(total_time[0] > total_time[1]){
        trans_time(total_time[0] - total_time[1]);
    } else if(total_time[0] == total_time[1]){
        trans_time(total_time[0]);
    } else{
        trans_time(total_time[1] - total_time[0]);
    }
}

void trans_time(int tot_sec){
    struct time t;

    t.h = tot_sec / 60 / 60; tot_sec %= 60 * 60;
    t.m = tot_sec / 60; tot_sec %= 60;
    t.s = tot_sec;
}