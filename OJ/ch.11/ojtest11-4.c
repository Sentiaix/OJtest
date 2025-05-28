#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
// 구조체를 이용하여 현재 시간을 표현하는 프로그램을 작성한다. 
// 사용자로부터 2개의 시간을 입력받아서 두 시간 사이의 차이를 계산하여 출력한다. 
// 단, 입력받는 2개의 시간은 어떤 것이 먼저이고, 어떤 것이 나중인지 모른다. 
// 시(hour)로 주어지는 숫자는 0보다 크고 23보다 작다. 
// 분(min)으로 주어지는 숫자는 0보다 크고 59보다 작다. 초(sec)로 주어지는 숫자는 0보다 크고 59보다 작다.

typedef struct time{
    int sum;
    int h;
    int m;
    int s;
} TIME;

typedef struct time_buffer{
    int h;
    int m;
    int s; 
    char hh[3];
    char mm[3];
    char ss[3];
} T_BUFFER;

// function declaration
void restore(); // s로 표현된 시간을 다시 hh mm ss로 쪼개는 함수

int main(){
    TIME t;
    T_BUFFER b[2];
    
    // buffer value 초기화
    for(int i = 0; i < 2; i++){
        b[i].h = 0;
        b[i].m = 0;
        b[i].s = 0;
    }
    int m[2] = {0,};
    int s[2] = {0,};
    int kor_str = 0; // 한국어 발견 여부

    for(int i =  0; i < 2; i++){
        scanf("%s %s %s", b[i].hh, b[i].mm, b[i].ss);
    }

    // char to int
    // case 1 : number char
    // case 2 : kor char
    for(int i = 0; i < 2; i++){
        int pow = 1;
        for(int j = 0; j < 2; j++){
            if(b[i].hh[j] >= '0' && b[i].hh[j] <= '9' && b[i].hh[j] != '\0'){ // case 1
                b[i].h += (b[i].hh[j] - '0');
                if(strlen(b[i].hh) == 2 && j == 0) b[i].h *= 10; // h[i]값이 2자리여서 자릿수를 하나 밀어줌.
            } else if(b[i].hh[j] != '\0'){ // case 2, EOF가 아닌데 숫자도 아니면 >> 한글임
                kor_str = 1;
            }
            if(b[i].mm[j] >= '0' && b[i].mm[j] <= '9' && b[i].mm[j] != '\0'){
                b[i].m += (b[i].mm[j] - '0');
                if(strlen(b[i].mm) == 2 && j == 0) b[i].m *= 10;
            } else if(b[i].mm[j] != '\0'){
                kor_str = 1;
            }
            if(b[i].ss[j] >= '0' && b[i].ss[j] <= '9' && b[i].ss[j] != '\0'){
                b[i].s += (b[i].ss[j] - '0');
                if(strlen(b[i].ss) == 2 && j == 0) b[i].s *= 10;
            } else if(b[i].ss[j] != '\0'){
                kor_str = 1;
            }
            pow = 10;
        }
    }

    if(kor_str){
        printf("%s %s %s", b[0].hh, b[0].mm, b[0].ss);
    } else{
        int sum[2] = {0,};

        // hh mm ss >> second
        for(int i = 0; i < 2; i++){
            sum[i] += b[i].h * 60 * 60;
            sum[i] += b[i].m * 60;
            sum[i] += b[i].s; 
        }

        if(sum[0] > sum[1]){
            t.sum = sum[0] - sum[1];
            printf("Tsum: %d, %d, %d\n", t.sum, sum[0], sum[1]);
            restore();
            printf("%d %d %d\n", t.h, t.m, t.s); // hh mm ss로 결과 출력
        } else if(sum[0] == sum[1]){
            t.sum = sum[0];
            printf("Tsum: %d, %d, %d\n", t.sum, sum[0], sum[1]);
            restore();
            printf("%d %d %d\n", t.h, t.m, t.s); // hh mm ss로 결과 출력
        } else{
            t.sum = sum[1] - sum[0];
            printf("Tsum: %d, %d, %d\n", t.sum, sum[0], sum[1]);
            restore();
            printf("%d %d %d\n", t.h, t.m, t.s);
        }
    }

    return 0;
}

// define function
void restore(){
    TIME T;

    printf("**%d\n", T.sum);

    T.h = T.sum / 60 / 60; T.sum %= 60 * 60;
    T.m = T.sum / 60; T.sum %= 60;
    T.s = T.sum;
}