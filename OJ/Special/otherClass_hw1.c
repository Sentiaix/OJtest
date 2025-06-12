#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// 다른분반 문제인데 내가 직접 문제를 추가수정할거임
// 1. 기본 틀은 같은데 info를 메모리가 아닌 storage에 저장할것.
// 2. 파일에 저장한걸 읽고 불러들이기도 할 것 << 고민중
// 3. 동적 메모리 할당
// 4. 저장된 파일 자동으로 메모리에 호출하기. << 아직 안 함

// the enum value is {1, 2, 3, 4, 5, 6}
enum menu {BookNum = 1, AuthorName, Title, AddNewBook, NumOfExistBook, PrintMenu, SaveAsFile, RemoveFile, LoadToMem};
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
void load_book(BOOK* lib, int* n); // 파일에서 책 정보를 가져옴
int YesOrNo(char* str); // 응답 판단 (Yes -> 1, No -> 0)

int main(){
    INPUT input = { 1, 0, ""};
    int n = 0; // 동적메모리 할당 변수
    char response[20]; // 응답 저장

    announce(); // 안내사항 출력

    // 동적 메모리 할당
    BOOK* lib;
    lib = (BOOK*)malloc( n * sizeof(BOOK));

    while(1){

        printf("Choose an option from the menu: ");
        // 무한반복 대비 장치
        if (scanf("%d", &input.type) != 1) {
            printf("\nInvalid input. Please enter the number in menu.\n");
            while (getchar() != '\n'); // 입력 버퍼 지우기 (getchar()로 한글자씩 받아 지우는데, EOF만나면 그만 지우고 문자열 받기)
            continue;
        }
        // 0 입력시 종료
        if(input.type == 0){
            break;
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

            // 새롭게 추가할 책의 수만큼 메모리를 확장
            // 현재 n개의 책이 있고, input.integer 개의 책을 추가할 것이므로,
            // 총 (n + input.integer) * sizeof(BOOK) 만큼의 공간이 필요함.
            BOOK* temp_lib = (BOOK*)realloc(lib, (n + input.integer) * sizeof(BOOK));

            // realloc이 성공했다면, lib 포인터를 새로운 메모리 주소로 업데이트합니다.
            lib = temp_lib;

            printf("Enter the information of book like this (Book number, Author's name, Title)\n");

            // 새롭게 추가되는 책들에 대한 정보를 입력받음
            for(int i = n; i < n + input.integer; i++){
                get_book(&lib[i]);
            }
            // 총 책의 개수를 업데이트
            n += input.integer;
        }
        // 5. 메모리에 존재하는 책의 수 출력
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
            scanf("%s", response);
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
        // 9. 파일에서 메모리로 가져오기
        else if(input.type == LoadToMem){
            while(1){
                scanf("%s", response);
                int resp = YesOrNo(response);
                if(resp == Yes){
                    // 메모리로 호출하는 함수
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
    printf("1. Search by book number        ");
    printf("2. Search by author's name      ");
    printf("3. Search by book title         ");
    printf("4. Add a new book             \n");
    printf("5. Display the number of books in the library");
    printf("                   6. Print menu");
    printf("                   7. Move books to file (remove from memeory)\n");
    printf("8. Remove the file that stores book data");
    printf("                        9. Load books to memory\n");
    printf("==============================\n");
    printf("To exit, enter 0\n");
    printf("==============================\n");
}

void search_info(BOOK* lib, INPUT input, int n){
    int found = 0; // 매칭하는 정보를 찾지 못한 경우 0을 반환

    for(int i = 0; i < n; i++){
        // 책 번호 검색
        if(input.type == BookNum && lib[i].book_num == input.integer){
            print_book(lib[i]); found = 1;
        }
        // 저자 검색
        else if(input.type == AuthorName && strcmp(lib[i].author, input.str) == 0){
            print_book(lib[i]); found = 1;
        }
        // 제목 검색
        else if(input.type == Title && strcmp(lib[i].title, input.str) == 0){
            print_book(lib[i]); found = 1;
        }
    }
    if (!found) printf("No matches found.\n");
}

void print_book(BOOK lib){
    printf("%d %s %s\n", lib.book_num, lib.author, lib.title);
}

void get_book(BOOK* lib){
    printf("Book number: ");
    scanf("%d", &lib->book_num); // 귀찮아서 예외처리 안 함
    while(getchar() != '\n');

    printf("Author: ");
    scanf("%[^\n]", lib->author);
    while(getchar() != '\n');

    printf("Title: ");
    scanf("%[^\n]", lib->title);
}

void save_book(BOOK* lib, int* n){
    FILE* fp = fopen("Books Data", "a");
    
    if(fp == NULL){
        printf("File open Error\n");
        return;
    }

    for(int i = 0; i < *n; i++){
        fprintf(fp, "%d \"%s\" \"%s\"\n", lib[i].book_num, lib[i].author, lib[i].title);
    }

    fclose(fp);
    
    // 메모리에 있는 내용 다 초기화했으면 메모리 크기 0으로 반환
    *n = 0;
    printf("Books saved and memory cleared\n");    
}

int YesOrNo(char* str){
    if(str[0] == 'Y' || str[0] == 'y') return Yes;
    if(str[0] == 'N' || str[0] == 'n') return No;
    // Y도 N도 아닌 경우
    return NoMatchs;
}

void load_book(BOOK* lib, int* n){
    FILE* fp = fopen("Books Data", "r"); // 파일을 읽기 모드로 호출
    int i = 0;
    lib = (BOOK*)malloc(sizeof(BOOK));
    while(1){
        fscanf(fp, "%d \"%[^\"]\" \"%[^\"]\"\n", &lib[i].book_num, lib[i].author, lib[i].title);
        if(!(feof(fp))) break;
        i++;
    }

    *n = i; // 책 수 옮기기

    fclose(fp);
}