#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// 다른분반 문제인데 내가 직접 문제를 추가수정할거임
// 1. 기본 틀은 같은데 info를 메모리가 아닌 storage에 저장할것.
// 2. 파일에 저장한걸 읽고 불러들이기도 할 것
// 3. 동적 메모리 할당은 고민해보기

// the enum value is {1, 2, 3, 4, 5}
enum menu {BookNum = 1, AuthorName, Title, AddNewBook, NumOfExistBook};

typedef struct book{
    int book_num;
    char author[20];
    char title[20];
} BOOK;

// function declaration
void announce(); // 안내사항 출력


int main(){
    BOOK* lib;
    int s_type; // search type
    int intvalue; // 정수형 값 저장
    char strvalue[30]; // str값 저장

    announce(); // 안내사항 출력
    printf("메뉴 중에서 하나를 선택하세요: ");
    scanf("%d", &s_type);

    switch(s_type){
        case BookNum :
            printf("번호를 입력하세요요");
    }

    return 0;
}

// define function
void announce(){
    printf("=========================\n");
    printf("1. 도서 번호로 책 찾기\n");
    printf("2. 저자 이름으로 책 찾기\n");
    printf("3. 제목으로 책 찾기\n");
    printf("4. 새로운 책 추가\n");
    printf("5. 도서관이 소유한 도서의 수 표시\n");
    printf("=========================\n");
}

