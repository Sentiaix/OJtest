/*# 문제 설명
월과 일을 입력 받은 후, 입력한 날을 포함하여 올해 남아있는 일수를 출력하라.
(단, 2월은 28일로 계산한다.)
월 일 입력은 다음과 같이 한다.
int m, d;
scanf("%d월 %d일", &m, &d);

# 입출력 예시 1: "12월 31일" 입력 "1일 남음" 출력
12월 31일
1일 남음

# 입출력 예시 2: "1월 1일" 입력 "365일 남음" 출력
1월 1일
365일 남음

# 입출력 예시 3: "7월 4일" 입력 "181일 남음" 출력
7월 4일

181일 남음

Jan: 31 | Feb: 28 | Mar: 31 | Apr: 30 | May: 31 | Jun: 30
Jul: 31 | Aug: 31 | Sep: 30 | Oct: 31 | Nov: 30 | Dec: 31
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// function declaration
int today(int month, int day);

int main(){
    int m, d;

    // scanf("%d%*s%d", &m, &d); // original code
    scanf("%d%*[^0-9]%d", &m, &d); // to ignore non-numeric char between numbers
    // printf("Input month: %d, day: %d\n", m, d); // debug

    int leftDays = 365 - today(m, d) + 1;


    // printf("%d Days left\n", leftDays); // English output; for debugging 

    printf("%d일 남음\n", leftDays);

    return 0;
}

// define function
int today(int month, int day){
    // printf("***month: %d, day: %d\n", month, day); // debug
    int daysOfMonth[12] = {31, 28, 31,
                           30, 31, 30,
                           31, 31, 30,
                           31, 30, 31};

    int totalDays = 0;

    for(int i = 0; i < month - 1; i++){
        totalDays += daysOfMonth[i];
        // printf("***totalDays: %d\n", totalDays); // debug
    }
    totalDays += day;
    // printf("***totalDays after adding day: %d\n", totalDays); // debug

    return totalDays;
}