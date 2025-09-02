#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define WORDS 5

void sort_dic(char dic[WORDS][2][30]);

int main(){
    char dic[WORDS][2][30] = {
		{ "책", "book" },
		{ "소년", "boy" },
		{ "컴퓨터", "computer" },
		{ "언어", "language" },
		{ "비", "rain" },
	};
    char input[10];
    int chk = 0; // dic에 탐색 실패하면 1을 반환. idx가 안에 있으면 0

    scanf("%s", input);

    for(int i = 0; i < WORDS; i++){
        if(strcmp(dic[i][0], input) == 0){ // dic[i][1]은 영어 출력
            printf("%s: %s\n", input, dic[i][1]);
            chk = 0;
            break;
        }
        chk = 1;
    }

    if(chk){
        sort_dic(dic);
        for(int i = 0; i < WORDS; i++){
            printf("%s %s\n", dic[i][0], dic[i][1]);
        }
    }

    return 0;
}

void sort_dic(char dic[WORDS][2][30]){
    char temp[30];
    for (int i = 0; i < WORDS - 1; i++){
        for (int j = 0; j < WORDS - 1 - i; j++){
            if (strcmp(dic[j][0], dic[j + 1][0]) > 0){
                // 한글 swap
                strcpy(temp, dic[j][0]);
                strcpy(dic[j][0], dic[j + 1][0]);
                strcpy(dic[j + 1][0], temp);
                // 영어 swap
                strcpy(temp, dic[j][1]);
                strcpy(dic[j][1], dic[j + 1][1]);
                strcpy(dic[j + 1][1], temp);
            }
        }
    }
}