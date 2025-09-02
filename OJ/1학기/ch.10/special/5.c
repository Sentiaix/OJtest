#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h> // isupper('a') >> 0(false) , toupper('a') >> A

int main(){
    char str[100];

    scanf("%[^\n]s", str);
    
    for(int i = 0; str[i] != '\0'; i++){
        // 문장 부호 추가
        if(str[i + 1] == '\0'){
            if(str[i] != '.' && str[i] != '!' && str[i] != '?'){
                str[i + 1] = '.';
                str[i + 2] = '\0';
            }
        }
        // 앞글자 크게 만들기
        if(!(isupper(str[0]))){
            str[0] = toupper(str[0]);
        }
    }

    printf("%s\n", str);

    return 0;
}