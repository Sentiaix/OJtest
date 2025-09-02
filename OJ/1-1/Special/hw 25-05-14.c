#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>// strlen 사용
// 1. char>> str받고 char 받아서 str 글자마다 compare
// 2. str>> str 받고 val 받아서 str 글자마다 val 첫글자랑 같은지 비교.
// 2-1. 그 다음 글자를 비교하는데, 중간에 끊기거나 하면 안됨.
//      >> strlen써서 글자수 맞게 확인했고, 모든 글자가 일치했으면 정답.
// <문제점 1>: 첫 글자가 달라도 반복문에 들어갈 가능성 있음 >> 최적화를 위해 if추가
// <문제점 2>: str을 센 만큼 같이 i++하기

// function declaration
int count_char(char* char_input, char c); // str 받고 특정 char 찾기
int count_str(char* str_input, char* str); // str 받고 특정 str 찾기

int main(){
    char str[128]; //str is &str[0] // 주의! 문자열을 char+배열로 받을 경우, 마지막 칸은 EOF 전용 칸으로 남겨두어야 함.

    scanf("%[^\n]s", str); //standby EOF
    printf("%s\n", str);

    printf("how many %c? %d\n", 'e', count_char(str, 'e'));
    printf("how many %s? %d\n", "foot", count_str(str, "foot"));

    return 0;
}

// define function
int count_char(char* char_input, char c){
    int cnt = 0;
    // for 반복문에서 char_input[i] 값이 마지막 글자가 아니면 계속 반복
    // char + 배열은 EndOfFile의 약자로 한 문자열(FILE)의 끝남을 알리는 코드임. stdio.h에서 -1의 정수값으로 내장돼있음
    for(int i = 0; char_input[i] != '\0'; i++){
        if(char_input[i] == c){
            cnt++;
        }
    }

    return cnt;
}

int count_str(char* str_input, char* str){
    int str_length = strlen(str); // 성능향상을 위해 strlen(str)은 한 번만 호출하도록 바꿈
    int str_cnt = 0; // str안에 word가 있으면 +1 
    int i = 0;

    while(str_input[i]){ // EOF = 0
        int len_chk = 0; // str의 len값 끝까지 받았는지 확인. ex) foo만 받았어도 48row if문에 문제발생

        if(str_input[i] == str[0]){ // 첫글자 파악
            for(int j = 1; str[j] != '\0'; j++){
                if(str_input[i + j] == str[j]){
                    len_chk++; // str's len == len_chk?
                    if(len_chk == str_length - 1){ // 첫 글자는 확인헀으니 -1을 해야함.
                        i += len_chk; // 읽어들인만큼 i 추가
                        str_cnt++;
                        continue; // 혹시나 다음 else문으로 들어가 i += 중복시행을 방지
                    }
                } else{
                    i += len_chk; // 읽어들인마늠 i 추가
                    break;
                }
            }
        }
        i++;
    }
   
    return str_cnt;
}