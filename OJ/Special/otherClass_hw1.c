#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// 다른분반 문제인데 내가 직접 문제를 추가수정할거임
// 1. 기본 틀은 같은데 info를 메모리가 아닌 storage에 저장할것.
// 2. 파일에 저장한걸 읽고 불러들이기도 할 것 << 고민중
// 3. 동적 메모리 할당

// the enum value is {1, 2, 3, 4, 5, 6}
enum menu {BookNum = 1, AuthorName, Title, AddNewBook, NumOfExistBook, PrintMenu, SaveAsFile, RemoveFile};
enum response {NoMatchs = -1, No, Yes}; // 참 또는 거짓을 가시적으로 보여줌

typedef struct book{
    int book_num;
    char author[20];
    char title[20];
} BOOK;

typedef struct input{
    int type; // menu에서 고른 type을 저장
    int integer; // 숫자 정보 저장
    char str[30]; // 문자열 정보 저장
} INPUT;

// function declaration
void announce(); // 안내사항 출력
void search_info(BOOK* lib, INPUT input, int n); // 조건 만족 idx 출력.
void print_book(BOOK lib); // 정보 출력
void get_book(BOOK* lib); // 정보 입력
void save_book(BOOK* lib, int* n); // 파일로 저장
int YesOrNo(char* str); // 응답 판단 (Yes -> 1, No -> 0)

int main(){
    INPUT input = { 1, 0, '\0'};
    int n = 0; // 동적메모리 할당 변수
    int response = 0; // 응답 저장
    char resp_str[10]; // 응답 저장


    // 동적 메모리 할당
    BOOK* lib;
    lib = (BOOK*)malloc( n * sizeof(BOOK));

    announce(); // 안내사항 출력

    while(input.type != 0){

        printf("Choose an option from the menu: ");

        // 무한반복 대비 장치
        if (scanf("%d", &input.type) != 1) {
            printf("\nInvalid input. Please enter the number in menu.\n");
            while (getchar() != '\n'); // 입력 버퍼 지우기 (getchar()로 한글자씩 받아 지우는데, EOF만나면 그만 지우고 문자열 받기)
            continue;
        }

        // 1. 책 번호 검색
        if(input.type == BookNum){ 
            printf("Enter the Book number: ");
            scanf("%d", &input.integer);
            search_info(lib, input, n);
        } 
        // 2 and 3. 책 저자 또는 이름 검색
        else if(input.type == AuthorName || input.type == Title){
            printf("Enter the Author's name or the book title: ");
            scanf("%[^\n]s", input.str);
            search_info(lib, input, n);
        }
        // 4. 새로운 책 정보 추가
        else if(input.type == AddNewBook){
            printf("Enter the number of books to add: ");
            scanf("%d", &input.integer); // 저장할 책 수 입력
            printf("Enter the information of book like this (Book number, Author's name, Title): ");

            lib = realloc(lib, n * sizeof(BOOK)); // 동적 메모리 재선언

            for(int i = n - input.integer; i < n; i++){
                get_book(&lib[i]);
            }
            n += input.integer;
        }
        // 5. 존재하는 책의 수 출력
        else if(input.type == NumOfExistBook){
            printf("The number of books is: %d\n", n);
        }
        // 6. 메뉴 출력
        else if(input.type == PrintMenu){
            announce();
        }
        // 7. 파일에 저장
        else if(input.type == SaveAsFile){
            printf("All entered information has been saved. Are you sure you want to remove it from memory? (Y/N): ");
            while(1){
            scanf("%s", resp_str);
            int resp = YesOrNo(response);
                if(resp == Yes){
                    // 책 저장
                    save_book(lib, &n);
                    break;
                } else if(resp == No){
                    break;
                } else if(resp == NoMatchs){
                    printf("Try again.\n");
                }
            }
        }
        // 8. 파일 제거
        else if(input.type == RemoveFile){
            printf("Warning: This file will be permanently deleted and cannot be recovered. Are you sure? (Y/N): ");
            while(1){
                scanf("%s", response);
                int resp = YesOrNo(response);
                if(resp == Yes){
                    remove("Books Data");
                    break;
                } else if(resp == No){
                    break;
                } else if(resp == NoMatchs){
                    printf("Try again.\n");
                }
            }
        }
        // 입력값이 메뉴에 없는 경우
        else{
            printf("Enter type error. Please try again.\n");
        }

        printf("\n");
    }

    // 동적메모리 할당 해제
    free(lib);

    return 0;
}

// define function
void announce(){
    printf("==============================\n");
    printf("1. Search by book number\n");
    printf("2. Search by author's name\n");
    printf("3. Search by book title\n");
    printf("4. Add a new book\n");
    printf("5. Display the number of books in the library\n");
    printf("6. Print menu\n");
    printf("7. Move books to file (remove from memeory)\n");
    printf("8. Remove the file that stores book data\n");
    printf("==============================\n");
    printf("If you want to delete all saved books from storage, enter 99\n");
    printf("To exit, eneter 0\n");
    printf("==============================\n");
}

void search_info(BOOK* lib, INPUT input, int n){
    for(int i = 0; i < n; i++){
        // 책 번호 검색
        if(input.type == BookNum && lib[i].book_num == input.integer){
            print_book(lib[i]);
        }
        // 저자 검색
        else if(input.type == AuthorName && strcmp(lib[i].author, input.str) == 0){
            print_book(lib[i]);
        }
        // 제목 검색
        else if(input.type == Title && strcmp(lib[i].title, input.str) == 0){
            print_book(lib[i]);
        }
    }
}

void print_book(BOOK lib){
    printf("%d %s %s\n", lib.book_num, lib.author, lib.title);
}

void get_book(BOOK* lib){
    scanf("%d", &lib->book_num);
    getchar();
    scanf("%[^\n]", lib->author);
    getchar();
    scanf("[^\n]", lib->title);
}

void save_book(BOOK* lib, int* n){
    FILE* fp;
    
    fp = fopen("Books Data", "a");
    if(fp == NULL){
        printf("File open Error\n");
    }

    for(int i = 0; i < n; i++){
        fprintf(fp, "%d %s %s\n", lib[i].book_num, lib[i].author, lib[i].title);
    }
    
    // 메모리에 있는 내용 다 초기화했으면 메모리 크기 0으로 반환
    *n = 0;

    fclose(fp);
}

int YesOrNo(char* str){
    if(str[0] == 'Y' || str[0] == 'y'){
        return Yes;
    } else if(str[0] == 'N' || str[0] == 'n'){
        return No;
    } else{ // Y도 N도 아닌 경우
        return NoMatchs;
    }
}