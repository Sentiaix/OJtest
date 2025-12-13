/*학생 3명의 이름과 키를 구조체 배열로 입력받아,
가장 키가 큰 학생의 이름을 출력하시오.

[입력]
이름과 키가 총 3줄 주어진다.

이름1 키1
이름2 키2
이름3 키3

[출력]
tallest = <이름>

------
[입력 예시]
Anna 160
Bob 172
Chris 168

[출력 예시]
tallest = Bob
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

typedef struct Student {
    char name[50];
    int tall;
} Std;

// function declaration
Std find_tallest(Std* p);

int main() {
    int n = SIZE;
    
    Std* s = (Std*)malloc(sizeof(Std) * n);

    for (int i = 0; i < n; i++) {
        scanf("%s %d", s[i].name, &s[i].tall);
    }
    
    Std top = find_tallest(s);

    printf("tallest = %s\n", top.name);

    free(s);

    return 0;
}

// define function
Std find_tallest(Std* p){
    Std tallest = p[0];

    for (int i = 0; i < SIZE; i++) {
        if (tallest.tall < (p + i)->tall) {
            tallest = p[i];
        }
    }

    return tallest;
}