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
int charToInt(char* str); // char 자료형을 int로 변환, %s로 받은 값을 사번으로 복구하기 위함.
void search_info(EMPLOYEE* E, char* name_str, int _case, int* age_r, int n); // 조건에 부합하는 정보를 검색

int main(){
    EMPLOYEE E[10];
    int n; // 반복 횟수 저장
    int srch_kind; // 검색 종류 저장 (이름? 나이?)
    int age_range[2]; // 나이 범위
    char srch_name[10]; // 검색할 이름 저장

    // 1. 입력 형식 제공
    // {반복 횟수}, {검색 조건}
    scanf("%d %d", &n, &srch_kind);
    if(srch_kind == 1){ // 이름 검색
        scanf("%s", srch_name);
    } else if(srch_kind == 2){ // 나이 범위
        scanf("%d %d", &age_range[0], &age_range[1]);
    }

    // 2. 입력 형식에 따른 추가정보 입력
    // {이름}, {사번/전번}, {나이}
    for(int i = 0; i < n; i++){
        // 이름, 사번/전번, 나이
        scanf("%s %s %d", E[i].name, E[i].num.n_info.pn, &E[i].age);
        if(strlen(E[i].num.n_info.pn) == 3){ // 사번/전번 란에 3개의 문자인 경우 int로 값 변환 > 사번으로 인식하기 위함
            E[i].num.n_info.wn = charToInt(E[i].num.n_info.pn);
            E[i].num.kind = WN; // E[i]번 num에는 사번(WN)이 저장돼 있음을 알림.
        } else{
            E[i].num.kind = PN; // E[i]번 num에는 전화번호(PN)가 저장돼 있음을 알림.
        }
    }

    // 3. 검색 알고리즘
    search_info(E, srch_name, srch_kind, age_range, n);


    

    return 0;
}

// define function

//                           검색한 이름, {이름/나이 검색}, 나이 범위, 추가된 정보 수
void search_info(EMPLOYEE* E, char* name_str, int _case, int* age_r, int n) {
    int ERR_chk = 1; // 판독에 이상 없음 >> 0

    // 함수로 넘어오는 case
    // 1. 이름 검색
    // 2. 나이 범위 검색
    
    // 출력 과정 경우의 수(구조체의 kind 변수를 이용하여 쪼갬)
    // 1. 사번만 있는 경우
    // 2. 전화번호만 있는 경우

    // <strcmp에 대한 설명>
    // strcmp는 두 string에서 각 char idx의 값을 ASCII 코드로 비교하는 lib함수입니다
    // 맨 앞부터 한 글자씩 판독하며, 다르면 판독을 멈추고, ASCII값의 차를 반환합니다
    // 예: strcmp("aa", "ab") >> 97 - 98 = -1, str이 일치하면 0을 반환합니다   
    for (int i = 0; i < n; i++) {
        if (_case == 1 && strcmp(E[i].name, name_str) == 0) { // 이름 검색
            if(E[i].num.kind == WN){ // 사번(int)인 경우
                printf("%s %d %d\n", E[i].name, E[i].num.n_info.wn, E[i].age);
            } else{ // 전화번호(char*)인 경우
                printf("%s %s %d\n", E[i].name, E[i].num.n_info.pn, E[i].age);
            }
            ERR_chk = 0;
        }
        else if (_case == 2 && (E[i].age >= age_r[0] && E[i].age <= age_r[1])) { // 나이 검색
            if(E[i].num.kind == WN){ // 사번(int)인 경우
                printf("%s %d %d\n", E[i].name, E[i].num.n_info.wn, E[i].age);
            } else{ // 전화번호(char*)인 경우
                printf("%s %s %d\n", E[i].name, E[i].num.n_info.pn, E[i].age);
            }
            ERR_chk = 0;
        }
    }

    if(ERR_chk){
        printf("-1\n");
    }
}

int charToInt(char* str){
    int result = 0;
    for(int i = 0; str[i] != '\0'; i++){
        result = result * 10 + (str[i] - '0');
    }
    return result;
}
