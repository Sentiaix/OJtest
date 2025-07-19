#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h> // sqrt 사용하기 위함

// <문제 설명>
// 크기가 5인 int형 배열 v의 원소를 입력받고 원소의 평균과 표준편차를 출력하는 함수
// double get_array_avg(int *v, int n), double get_array_std(int *v, double avg, int n) 함수를 작성하라.
// get_array_std 함수의 매개변수는 배열, 평균, 배열의 크기이다.
// 평균과 표준편차를 출력하여라. (출력은 소수점 2자리까지 반올림하여 출력)
// test input > 10 20 30 40 50 > 30.00 14.14

// 함수 선언
double get_array_avg(int *v, int n); // 평균
double get_array_std(int *v, double avg, int n); //표준편차

int main(){
    int arr[5];

    for(int i = 0; i < 5; i++){
        scanf("%d", &arr[i]);
    }

    double avg = get_array_avg(arr, 5);
    double std = get_array_std(arr, avg, 5);

    printf("%.2lf %.2lf\n", avg, std);

    return 0;
}

// 함수 정의
double get_array_avg(int *v, int n){
    double avgf; // 자료형 주의!!
    double tmp_stacker = 0;

    for(int* i = v; i < v + n; i++){
        tmp_stacker += *i;
    }

    avgf = tmp_stacker / n;

    return avgf;
}

double get_array_std(int *v, double avg, int n){
    double stDev; // 표준편차 = sqrt( (분산)^2 / 관찰값 수 )
    double tmp_stacker = 0;

    for(int i = 0; i < n; i++){
        double temp_variance = v[i] - avg; // avg 함수와 다르게 variance(분산)을 대놓고 구함.
        tmp_stacker += temp_variance * temp_variance;
    }

    stDev = tmp_stacker / n;

    // sqrt : square root = 제곱근, 루트
    return sqrt(stDev);
}