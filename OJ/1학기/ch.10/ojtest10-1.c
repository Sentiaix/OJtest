#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// function declaration
void standard_name(char* str);

int main(){
    char str[128];
    scanf("%[^\n]s", str);
    standard_name(str);
    printf("%s\n", str);
}

void standard_name(char* str){
    int i = 0;
    int j = 0;
    int space_flag = 0; // 연속 공백 여부 체크


    while(str[i] != '\0'){ // ASCII a = 97, ASCII A = 65

        // 앞글자 공백 제거
        while(str[i] == ' '){
            i++;
        }
        
        // 대문자로 변환
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] -= 32; // lowercase와 uppercase의 차이는 32
        }

        if(str[i] == ' '){
            if(!space_flag){ // space_flag가 0이면 여기로 들어옴
                str[j++] = str[i];
                space_flag = 1;
            }
        } else{ // 문자인 경우
            str[j++] = str[i];
            space_flag = 0; // 공백이 아니므로 초기화
        }

        i++;
    }

    str[j] = '\0';
}