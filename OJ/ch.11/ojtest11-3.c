#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// <문제>: 복소수의 입력을 받고 합을 출력하여라. 구조체 사용 필수.
// a+bi c+di >> (a+c)+(b+d)i
// -1.0+2.4i -0.9-2.3i >> -0.1+0.1i

// 문제 해결 과정
// 1. 일단 main함수에서 문자를 char로 받고 float으로 변환을 테스트. >> 안됨
// 1 - 1. 숫자를 정수부+소수부 + 허수부로 계산하기.
// 2. main함수에서 로직을 완성시키기 (실수와 허수 분리 등)
// 3. 구조체와 함수로 main함수에 있던 로직들을 모듈화하기

struct complex_number{ // 실수 허수 저장
    double real; // 실수 (real number)
    double imag; // 허수 (imaginary number)
};
struct input_number{ // 숫자 저장
    char number_1[20];
    char number_2[20];
};

struct transfer{ // 위의 두 struct 묶기
    struct complex_number CNum;
    struct input_number In;
};

// function declaration
struct input_number parsing();
double str_to_double(char* str);

int main(){
    struct transfer trans;

    scanf("%s %s", trans.In.number_1, trans.In.number_2);
    
    return 0;
}

struct input_number parsing(){
    struct input_number n;
    struct complex_number c;
    char part_1[5]; // operator 앞 뒤로 나누어 입력을 처리함
    char part_2[5]; // part1, part2와 같이 분리하여 검증하도록 하였음.

    int i = 0;
    while(1){
        if(n.number_1[i]){

        }
    }

}

double str_to_double(char* str){
    double num = 0.0f;
    double dot = 0.1; // 소수 몇번 나왔는지, n번째 소수면 더 작은 수로 처리해야함.
    int sign = 1; // 양수 음수 저장
    int i = 0;

    // 부호 확인
    if(str[i] == '-'){
        sign = -1;
        i++;
    } else if(str[i] == '+'){
        i++;
    }
    
    // 정수부
    while(str[i] >= '0' && str[i] <= '9'){
        // 0.0f에 10을 곱하면 첫 수행시 0.0f = 0.0f + str에 있는 값 
        num = num * 10 + (str[i] - '0');
    }

    // 소수
    if(str[i] == '.'){
        i++;
        while(str[i] >= '0' && str[i] <= '9'){
            num = num + (str[i] - '0') * dot;
            dot *= 0.1f;
            i++;
        }
    }

    return sign * num;
}