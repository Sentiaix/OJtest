#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct complex{
    double real;
    double imag;
} Complex;

// function declaration
double parse_number(const char *str, int *idx); // str에 표현된 숫자를 double로 변환함
Complex parse_complex(const char *str);  // 실수부 허수부 분리

int main() {
    char input[32];
    Complex a, b, result;

    scanf("%s", input);
    a = parse_complex(input);

    scanf("%s", input);
    b = parse_complex(input);

    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;

    printf("%.2f%+.2fi\n", result.real, result.imag);
    return 0;
}

// define function
double parse_number(const char *str, int *idx){
    double num = 0.0;
    double frac = 0.0;
    int sign = 1;
    int i = *idx;

    if (str[i] == '-'){sign = -1; i++;}
    else if (str[i] == '+'){i++;}

    while(str[i] >= '0' && str[i] <= '9'){
        num = num * 10 + (str[i] - '0');
        i++;
    }

    if(str[i] == '.'){ // 소수부 연산
        i++;
        double div = 10.0;
        while(str[i] >= '0' && str[i] <= '9'){
            frac += (str[i] - '0') / div;
            div *= 10;
            i++;
        }
    }

    *idx = i;
    return sign * (num + frac);
}

Complex parse_complex(const char *str){
    Complex c;
    int idx = 0;

    c.real = parse_number(str, &idx);
    c.imag = parse_number(str, &idx);  // 연산자부터 다시 읽음
    return c;
}

// 작동 원리: Complex prase_complex에서 한 문자열을 가져옴
// 그 다음 prase_number로 str값을 변환해 double로 return받는다
// str을 double로 받으면 문자열이 두 숫자로 쪼개져 받아짐