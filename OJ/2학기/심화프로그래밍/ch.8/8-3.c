/*# 문제 설명
문자를 입력 받은 후 알파벳 문자의 대문자와 소문자의 등장 횟수를 ‘*’로 나열하는 그래프를 출력하라.
교재 p. 308 문제와 다르게 '\n'이 입력되었을 때 while loop에서 나오게 작성하자.

입력 코딩 예시:
char ch;
while( (ch = getchar()) != '\n') {
  ...
}

# 입출력 예시 1: 입력 "Alphabet Only!"
Alphabet Only!
대문자**
소문자**********

# 입출력 예시 2: 입력 "Java VS C++"
Java VS C++
대문자****
소문자****/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(){
    char ch;
    int upperCount = 0;
    int lowerCount = 0;

    while( (ch = getchar()) != '\n') {
        if( ch >= 'A' && ch <= 'Z' ){
            upperCount++;
        }
        else if( ch >= 'a' && ch <= 'z' ){
            lowerCount++;
        }
    }

    printf("대문자");
    for(int i = 0; i < upperCount; i++) {
        printf("*");
    }
    printf("\n");

    printf("소문자");
    for(int i = 0; i < lowerCount; i++) {
        printf("*");
    }
    printf("\n");

    // printf("lowerCount: %d\n", lowerCount); // debug
    // printf("upperCount: %d\n", upperCount); // debug

    return 0;
}