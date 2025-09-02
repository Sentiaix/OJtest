#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// <문제>: 학생 명단과 점수를 입력하면 높은 점수를 얻은 m명의 학생 명단을 출력한다
// <조건 1>: m명의 데이터를 받고 높은 성적순으로 n명의 이름만 출력한다.
// <입력>: 1. 첫 줄에 m n 제시. 2. 이름 (공백) 점수 순으로 입력됨.

// vvvv struct save_score를 lib라고도 부를수 있게 함
typedef struct save_score{
    char name[10];
    int score;
} sc;

int main(){
    sc pt[100]; // sc의 내용을 main 함수에서 pt라는 이름(매개변수)로 부를거임

    int n, m;

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++){
        // name은 char형 arr니까 그냥 &없이 선언! 
        scanf("%s %d", pt[i].name, &pt[i].score);
    }

    // debug 1
    // for(int i = 0; i < n; i++){
    //     printf("%s %d\n", pt[i].name, pt[i].score);
    // }

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if( pt[j].score > pt[i].score){
                sc temp = pt[i];
                pt[i] = pt[j];
                pt[j] = temp;
            }
        }
    }

    for(int i = 0; i < m; i++){
        printf("%s\n", pt[i].name);
    }

    return 0;
}