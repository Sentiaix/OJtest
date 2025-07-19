#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// function declaration
int check_password(char* str);

int main(){
	char str[128];
	while(1){
		printf("enter new password: ");
		scanf("%s", str);
		if( check_password(str) ){
			break;
		}
	}
	printf("i hate these rules\n");
}

// define function
int check_password(char* str){
    int i = 0;
    int upp_chk = 0;
    int low_chk = 0;
    int num_chk = 0;
    int len_str = strlen(str); // 글자는 8자 이상이여야 함
    int hav_some_err = 0;

    while(str[i] != '\0'){
        if(str[i] >= 'A' && str[i] <= 'Z'){ // ASCII A = 65, Z = 90
            upp_chk = 1; // 대문자 확인
        } else if(str[i] >= 'a' && str[i] <= 'z'){ // ASCII a = 97, z = 122
            low_chk = 1; //
        } else if(str[i] >= '0' && str[i] <= '9'){ // ASCII 0 = 48, 9 = 57
            num_chk = 1; // 숫자 확인
        }
        i++;
    }

    // 구성이 돼있으면 1
    if(!upp_chk){
        printf("upper case char needed\n");
        hav_some_err = 1;
    }
    if(!low_chk){
        printf("lower case char needed\n");
        hav_some_err = 1;
    }
    if(!num_chk){
        printf("number char needed\n");
        hav_some_err = 1;
    }
    if(len_str < 8){ // 문자열이 8보다 길면 1
        printf("minimum 8 char\n");
        hav_some_err = 1;
    }

    return (hav_some_err == 0);
}