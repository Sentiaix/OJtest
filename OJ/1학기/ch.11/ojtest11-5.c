#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strcpy 사용

typedef struct employee{
    // int로 받고 char로 받지 않는 이유: 그냥 받은 값이 char이면 그냥 비교하고, int이면 char > int로 변환하면 됨.
    char name[10]; // 이름
    int idf_num; // 사번
    char digits[10]; // 휴대폰 번호
    int age; // 나이
} EMPLOYEE;

// function declaration
void search_info(EMPLOYEE* E, int _case, char* str, int idf, int* age_r); // 조건에 부합하는 정보를 검색

int main(){
    EMPLOYEE E[10] = {
     // { 이름,   사번, 전화-번호, 나이 }
        { "Jeon",  123, "2345-7890", 32 },
        { "Kim",   125, "3458-9990", 22 },
        { "Lee",   133, "7345-9870", 45 },
        { "Bae",   140, "5321-1234", 54 },
        { "Kang",  205, "4916-5052", 48 },
        { "Lee",   245, "2039-3458", 25 },
        { "Kim",   777, "4708-2323", 34 },
        { "Smith", 900, "6408-3298", 39 },
        { "Park",  428, "3482-9283", 21 },
        { "Kim",   973, "8934-2738", 25 }
    };

    int _case; // 1: 이름, 2: 사번, 3: 전번, 4: 나이
    int age_range[2] = {0,}; // 나이 범위 받기
    int idf = 0; // 사번 받기
    char idx_str[20];

    // case 1 : 이름이 들어온 경우
    // case 2 : 이름이 아닌 정보가 들어온 경우
    // Sol : scanf의 기본 입력 구조를 이용하여, 둘로 쪼개 scanf를 사용함.
    scanf("%d", &_case);
    if(_case == 1 || _case == 3){
        scanf("%s", idx_str);
        search_info(E, _case, idx_str, idf, age_range);
    } else if(_case == 4){
        scanf("%d %d", &age_range[0], &age_range[1]);
        search_info(E, _case, idx_str, idf, age_range);
    } else if(_case == 2){
        scanf("%d", &idf);
        search_info(E, _case, idx_str, idf, age_range);
    }

    return 0;
}

// define function
void search_info(EMPLOYEE* E, int _case, char* str, int idf, int* age_r) {
        int ERR_chk = 1; // 판독에 이상 없음 >> 0    

    // <strcmp에 대한 설명>
    // strcmp는 두 string에서 각 char idx의 값을 ASCII 코드로 비교하는 lib함수입니다
    // 맨 앞부터 한 글자씩 판독하며, 다르면 판독을 멈추고, ASCII값의 차를 반환합니다
    // 예: strcmp("aa", "ab") >> 97 - 98 = -1, str이 일치하면 0을 반환합니다
    for (int i = 0; i < 10; i++) {

        if (_case == 1 && strcmp(E[i].name, str) == 0) { // 이름 검색
            printf("%s %d %s %d\n", E[i].name, E[i].idf_num, E[i].digits, E[i].age);
            ERR_chk = 0;
        }
        else if (_case == 2 && E[i].idf_num == idf) { // 사번 검색
            printf("%s %d %s %d\n", E[i].name, E[i].idf_num, E[i].digits, E[i].age);
            ERR_chk = 0;
        }
        else if (_case == 3 && strcmp(E[i].digits, str) == 0) { // 전화번호 검색
            printf("%s %d %s %d\n", E[i].name, E[i].idf_num, E[i].digits, E[i].age);
            ERR_chk = 0;
        }
        else if (_case == 4 && (E[i].age >= age_r[0] && E[i].age <= age_r[1])) { // 나이 검색
            printf("%s %d %s %d\n", E[i].name, E[i].idf_num, E[i].digits, E[i].age);
            ERR_chk = 0;
        }
    }

    if(ERR_chk){
        printf("-1\n");
    }
}