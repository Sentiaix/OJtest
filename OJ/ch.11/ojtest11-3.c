#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// <문제>: 복소수의 입력을 받고 합을 출력하여라. 구조체 사용 필수.
// a+bi c+di >> (a+c)+(b+d)i
// -1.0+2.4i -0.9-2.3i >> -0.1+0.1i

// 문제 해결 과정
// 1. 일단 main함수에서 문자를 char로 받고 float으로 변환을 테스트.
// 2. main함수에서 로직을 완성시키기 (실수와 허수 분리 등)
// 3. 구조체와 함수로 main함수에 있던 로직들을 모듈화하기

struct complex_number{ // 실수 허수 저장
    double real; // 실수 (real number)
    double image; // 허수 (imaginary number)
};
struct input_number{ // 숫자 저장
    char number_1[10];
    char number_2[10];
};

struct transfer{ // 위의 두 struct 묶기
    struct complex_number CNum;
    struct input_number In;
};

// function declaration
struct input_number detach();

int main(){
    struct transfer trans;

    scanf("%s %s", trans.In.number_1, trans.In.number_2);
    
    return 0;
}

struct input_number detach(){
    struct input_number n;
    struct complex_number c;
    char part_1[5]; // operator 앞 뒤로 나누어 입력을 처리함
    char part_2[5]; // part1, part2와 같이 분리하여 검증하도록 하였음.

    int i = 0; // operator에서 index가 멈춰있음
    while(1){
        if(n.number_1[0] == '-'){
            i = 1;
        }
        // example -0.9+1.2f
        if(n.number_1[i] == '-' || n.number_1[i] == '+'){
            break;
        }
        i++;
    }

    for(int j = 0; j < i; j++){
        part_1[j] = n.number_1[j];

        if(n.number_1[(i + 1) + j] != '\0'){
            part_2[j] = n.number_1[(i + 1) + j];
        }
    }

}