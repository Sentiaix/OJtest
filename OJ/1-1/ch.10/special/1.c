#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    char str[100];

    scanf("%[^\n]s", str);

    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] >= 'a' && str[i] <= 'z') printf("%c", str[i]);
        if (str[i] >= 'A' && str[i] <= 'Z') printf("%c", str[i]);
        if (str[i] >= '0' && str[i] <= '9') printf("%c", str[i]);
    }

    printf("\n");

    return 0;
}