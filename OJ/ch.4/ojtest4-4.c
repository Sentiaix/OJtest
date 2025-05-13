#include <stdio.h>
#define PI 3.141592 // #define 을 이용하여 PI = 3.141592임을 알리기.

int main(){
    int r;

    printf("radius of the sphere : ");
    scanf("%d", &r);

    printf("surface area : %.3f\nvolume : %.3f", 4*PI*r*r, (4.0/3.0)*PI*r*r*r);
    // %.3 < 소수점(.) 이후로 3자리 표기, f < 실수 자료형 표기 = %.3f 소수점 3째 자리까지 실수 자료형
    return 0;
}