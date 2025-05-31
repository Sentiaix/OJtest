#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strcpy 사용
// <문제> : ch.11 5번 문제 심화버전
// 기존은 저장된 데이터의 호출인데, 11-6은 입력 case를 주고(기존과 비슷함) 데이터를 즉석에서 추가제공하여 그 추가제공된 데이터 속에서 정보를 찾는다
// Input Format : {입력받을 데이터의 양(n)} {사번} 또는 {전화번호} {나이}

// {name 1}은 영문 이름이다. 
// {사번}/{전화번호}는 사번(정수) 또는 전화번호{문자열}이다. 어떤 것인지 판단하여 **공용체**에 저장해야 한다.
// {나이}는 정수이다. 

enum type {WN, PN}; // WN: 사번, PN: 전화번호

union WPN {  // 사번과 전화번호에 대한 union
    int wn;
    char pn[10];
};
struct info {  // union의 타입과 값을 저장하기 위한 구조체
    enum type kind;
    union WPN n_info;
};
typedef struct employee {  // union을 포함하는 employee에 대한 구조체
    char name[10];
    struct info num;
    int age;
} EMPLOYEE;

// function declaration
int charToInt(char* str); // char 자료형을 int로 변환, %s로 받은 사번을 복구하기 위함
void search_info(EMPLOYEE* E, int _case, char* str, int idf, int* age_r); // 조건에 부합하는 정보를 검색

int main(){
    EMPLOYEE E[10];
    int n; // 반복 횟수 저장
    int input_type; // 인풋 타입 저장
    int age_range[2]; // 나이 범위
    char srch_name[10]; // 검색할 이름 저장

    // {반복 횟수}, {검색 조건}
    scanf("%d %d", &n, &input_type);
    if(input_type == 1){ // 이름 검색
        scanf("%s", srch_name);
    } else if(input_type == 2){ // 나이 범위
        scanf("%d %d", &age_range[0], &age_range[1]);
    }

    for(int i = 0; i < n; i++){
        // 이름, 사번/전번, 나이
        scanf("%s %s %d", E[i].name, E[i].num.n_info.pn, E[i].age);
        if(strlen(E[i].num.n_info.wn) <= 3){
            E[i].num.n_info.wn = 0;
            for(int j = 0; j < 3; j++){
                E[i].num.n_info.wn += {E[i].num.n_info.pn[j] - '0'}
            }
        }
    }
    // EMPLOYEE E[10] = {
    //  // { 이름,   사번, 전화-번호, 나이 }
        
    // };

    // int _case; // 1: 이름, 2: 사번, 3: 전번, 4: 나이
    // int age_range[2] = {0,}; // 나이 범위 받기
    // int idf = 0; // 사번 받기
    // char idx_str[20];

    // // case 1 : 이름이 들어온 경우
    // // case 2 : 이름이 아닌 정보가 들어온 경우
    // // Sol : scanf의 기본 입력 구조를 이용하여, 둘로 쪼개 scanf를 사용함.
    // scanf("%d", &_case);
    // if(_case == 1 || _case == 3){
    //     scanf("%s", idx_str);
    //     search_info(E, _case, idx_str, idf, age_range);
    // } else if(_case == 4){
    //     scanf("%d %d", &age_range[0], &age_range[1]);
    //     search_info(E, _case, idx_str, idf, age_range);
    // } else if(_case == 2){
    //     scanf("%d", &idf);
    //     search_info(E, _case, idx_str, idf, age_range);
    // }

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