/*연도(year)와 월(month)을 입력받아, 해당 월의 달력을 출력하는 프로그램을 작성하시오.
달력 계산에 필요한 다음의 기능을 반드시 직접 구현해야 하며, 포인터를 이용하여 날짜 값을 처리해야 한다.
윤년(leap year) 판정 함수
월별 날짜 수 계산 함수
Zeller 공식 또는 누적일 계산 방식을 이용한 시작 요일 계산
달력 출력은 아래 예시 형식과 동일해야 함
또한 배열 인덱스 직접 접근을 최소화하고, 가능한 한 포인터 연산으로 날짜를 처리해야 한다.

(제약조건)
1 ≤ year ≤ 9999
1 ≤ month ≤ 12
배열 인덱스 사용은 최소화 (가능하면 포인터 중심)
printf, scanf는 사용 가능
달력 전체를 저장하는 2D 배열 금지 → 바로 출력해야 함

(출력규직정리)
요일 시작은 Sunday(0) ~ Saturday(6)
달력의 첫 줄은 시작 요일 이전까지 공백을 출력
각 날짜는 폭 2(두 칸) 정렬 후 공백 1칸
마지막 주에 불필요한 공백 출력 금지
윤년 판정 조건은 다음과 같음:
year % 400 == 0 → 윤년
year % 100 == 0 → 평년
year % 4 == 0 → 윤년
나머지는 평년

[입력]
year month

[출력]
요일 헤더:
Su Mo Tu We Th Fr Sa
달력 날짜 출력(각 날짜는 폭 2, 공백 1 포함):

[입력예시]
2024 2
[출력예시]
Su Mo Tu We Th Fr Sa
             1  2  3
 4  5  6  7  8  9 10
11 12 13 14 15 16 17
18 19 20 21 22 23 24
25 26 27 28 29*/

/* --- 핵심 로직 --- */
/* 
    1. 윤년 판정 함수 (int year) -> int
        > year을 입력받고, 윤년이면 1, 평년이면 0 반환
    2. 월별 날짜 수 계산 함수 (int year, int month) -> int
        > year과 month를 입력받고, 해당 월의 날짜 수 반환
    3. 시작 요일 계산 함수 (int year, int month) -> int
        > year과 month를 입력받고, 해당 월의 시작 요일(0=일요일, 1=월요일, ..., 6=토요일) 반환
        * Zeller 공식 사용 ( 어려우니 추가 학습 필요 )
        * Zeller 공식은 토요일이 0(시작점)으로 계산되므로, 이를 일요일이 0이 되도록 변환함.
    4. 달력 출력 함수 (int year, int month) -> void
        > year과 month를 입력받아 달력을 출력
        > 시작 요일 전까지 공백을 출력,
        > 시작 날짜 + 출력한 날짜 값이 7의 배수이면 개행
        > 7의 배수가 아니면 ' '(1칸 공백) 출력
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// function declaration
int isLeapYear(int year);
int getDaysInMonth(int year, int month);
int getStartDay(int year, int month);
void printCalendar(int year, int month);

int main(){
    int month, year;

    scanf("%d %d", &year, &month);

    printCalendar(year, month);

    return 0;
}

// define function
int isLeapYear(int year){
    if (year % 400 == 0) return 1; // 윤년
    if (year % 100 == 0) return 0; // 평년
    if (year % 4 == 0) return 1;
    return 0;
}

int getDaysInMonth(int year, int month){
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return daysInMonth[month - 1];
}

int getStartDay(int year, int month){
    if (month < 3) { // 1월과 2월은 전년도의 13월, 14월로 간주
        month += 12;
        year--;
    }
    int k = year % 100; // 연도의 마지막 두 자리
    int j = year / 100; // 세기(century)
    int f = 1 + (13 * (month + 1)) / 5 + k + (k / 4) + (j / 4) - (2 * j);

    // Zeller의 공식 (단, 나눗셈에서 생긴 나머지는 모두 버림)
    // <연도 앞 두자리수>를 4로 나눈 나머지 * 5
    // <연도 뒤 두자리수>를 4로 나눈 몫
    // <연도 뒤 두자리수>
    // 1월-전월까지의 월별 나머지의 합
    // 날짜
    // <각 항을 7로 나눈 나머지>의 합을 7로 나눈 나머지
    // >> 결과가 0이면 토요일, 1이면 일요일, ..., 6이면 금요일

    // Zeller 공식에서는 토요일이 0(시작값)이므로, 이를 일요일이 0이 되도록 변환
    return (f % 7 + 7) % 7 - 1;
}

void printCalendar(int year, int month){
    printf("Su Mo Tu We Th Fr Sa\n");

    int startDay = getStartDay(year, month);
    int daysInMonth = getDaysInMonth(year, month);
    int day; // 날짜 카운터

    // 빈칸 출력
    for (day = 0; day < startDay; day++) {
        printf("   ");
    }
    // 날짜 출력
    for (day = 1; day <= daysInMonth; day++) {
        printf("%2d", day);
        if ((day + startDay) % 7 == 0 || day == daysInMonth) {
            printf("\n");
        } else {
            printf(" ");
        }
    }
}