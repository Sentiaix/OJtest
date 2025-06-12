#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define PI 3.14
// < 문제 설명 >
// 삼각형, 사각형, 원을 동시에 표현할 수 있는 공용체를 사용한다. 
// 삼각형은 밑변과 높이, 사각형은 가로와 세로, 원은 반지름만 저장하도록 한다. 
// 현재의 공용체가 표현하고 있는 도형의 종류는 열거형 변수를 이용하여 나타낸다. 
// 원의 면적을 계산할 때는 3.14로 계산한다. 
// 도형의 종류와 도형의 데이터를 입력받아, 도형의 면적을 계산하는 프로그램을 작성하라.

// 조건1: 공용체를 사용해야 함.
// 조건2: 열거형 변수를 사용해야 함.

// value is {0   1   2}
enum type {TRI, REC, CIR};

struct Triangle{
    double w;
    double h;
};
struct Rectangle{
    double x;
    double y;
};
struct Circle{
    double r;
};
union P{ // 삼각,사각,원 구조체를 공용으로 묶어냄
    struct Triangle T;
    struct Rectangle R;
    struct Circle C;
};
struct Polygon{
    enum type kind; // enum type의 내용을 kind라는 매개변수를 통해 이 struct에서 불러낼것임.
    union P poly; // union P 내용을 poly라는 매개변수를 통해 이 struct에서 불러낼것임.
};

// function declaration
double Calculator(struct Polygon P);

int main(){
    struct Polygon Polygon;
    
    scanf("%d", &Polygon.kind);

    if(Polygon.kind == TRI){ // case 1: Triangle.
        // Polygon.poly.T.w 은 Polygon > union P > struct Triangle > double w에 접근하는 것이다.
        scanf("%lf %lf", &Polygon.poly.T.w, &Polygon.poly.T.h);
    } else if(Polygon.kind == REC){ // case 2: Rectangle
        scanf("%lf %lf", &Polygon.poly.R.x, &Polygon.poly.R.y);
    } else if(Polygon.kind == CIR){ // case 3: Circle
        scanf("%lf", &Polygon.poly.C.r);
    }

    printf("%lf\n", Calculator(Polygon));

    return 0;
}

// define function
double Calculator(struct Polygon P){
    double result = 0.0f;

    if(P.kind == TRI){ // Triangle; TRI value is 0
        result = (0.5f) * (P.poly.T.w) * (P.poly.T.h);
    } else if(P.kind == REC){ // Rectangle
        result = (P.poly.R.x) * (P.poly.R.y);
    } else if(P.kind == CIR){ // Circle
        result = (P.poly.C.r) * (P.poly.C.r) * PI;
    }

    return result;
}