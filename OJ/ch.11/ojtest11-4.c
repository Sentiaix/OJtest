#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// 구조체를 이용하여 현재 시간을 표현하는 프로그램을 작성한다. 
// 사용자로부터 2개의 시간을 입력받아서 두 시간 사이의 차이를 계산하여 출력한다. 
// 단, 입력받는 2개의 시간은 어떤 것이 먼저이고, 어떤 것이 나중인지 모른다. 
// 시(hour)로 주어지는 숫자는 0보다 크고 23보다 작다. 
// 분(min)으로 주어지는 숫자는 0보다 크고 59보다 작다. 초(sec)로 주어지는 숫자는 0보다 크고 59보다 작다.

typedef struct time{ // 진짜 숫자 저장소
    int sum;
    int h;
    int m;
    int s;
} TIME;

typedef struct time_buffer{ // 숫자 임시 저장소
    int h;
    int m;
    int s;
} T_BUFFER;

// function declaration
TIME restore(int sum); // s로 표현된 시간을 다시 hh mm ss로 쪼개는 함수
T_BUFFER reset(); // T_BUFFER 값 초기화
int trans_sec(T_BUFFER t); // 입력받은 시간을 sec로 표현

int main(){
    TIME t;
    T_BUFFER b[2];

    for(int i =  0; i < 2; i++){
        b[i] = reset(); // 값 초기화 (h = 0, m = 0, s = 0)
        scanf("%d %d %d", &b[i].h, &b[i].m, &b[i].s);
    }
    
        int sum[2] = {0,};
        sum[0] = trans_sec(b[0]);
        sum[1] = trans_sec(b[1]);

        // 누가 큰지 검증
        int diff = sum[0] > sum[1] ? sum[0] - sum[1] : sum[1] - sum[0];

        t = restore(diff);
        printf("%d %d %d\n", t.h, t.m, t.s);

    return 0;
}

// define function
TIME restore(int sum){
    TIME T;
    T.sum = sum;

    T.h = T.sum / 60 / 60; T.sum %= 60 * 60;
    T.m = T.sum / 60; T.sum %= 60;
    T.s = T.sum;

    return T;
}
T_BUFFER reset(){
    T_BUFFER b;

    b.h = 0;
    b.m = 0;
    b.s = 0;

    return b;
}

int trans_sec(T_BUFFER t){
    int S = 0;

    S += t.h * 60 * 60;
    S += t.m * 60;
    S += t.s;

    return S;
}