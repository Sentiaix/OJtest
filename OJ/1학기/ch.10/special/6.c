#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(){
    char str[100];

    scanf("%[^\n]", str);

    int len = strlen(str);
    int chk = 1; // 회문 아니면 0

    for(int i = 0; i <= len / 2; i++){
        // printf("%c %c\n", str[i], str[len - i - 1]);
        if(str[i] != str[len - i - 1]){
            chk = 0;
            break;
        }
    }

    if(chk){
        printf("Yes\n");
    } else{
        printf("No\n");
    }

    return 0;
}