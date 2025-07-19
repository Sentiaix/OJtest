#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strlen, strcpy
#include <stdlib.h> // malloc, realloc, free

// function declaration
char* to_str(int* str_size, unsigned int* arr); // 문제에서 요구하는 int > str 변환

// Do not touch main function
int main(){
	unsigned int arr[3];
	scanf("%u %u %u", arr, arr+1, arr+2);
	
	int str_size;
	char *str = to_str( &str_size, arr);
	printf("str_size: %d\n", str_size);
	printf("%s\n", str);
	free(str);
	return 0;
}

// define function
char* to_str(int* str_size, unsigned int* arr){
    // 메인함수에서 *로 배열선언했고, free문이 있으므로, malloc 해야함
    char* result = (char*)malloc(100); // 크기는 대충 100글자로 설정
    int idx = 0;

    for(int i = 0; i < 3; i++){
        char temp[11]; // 최대 10자리 + NULL문자 (EOF)
        int temp_idx = 0; // num값과 함께 임시로 

        // 예외처리: 숫자 0은 그냥 '0'으로 출력
        if(arr[i] == 0){ // 그저 입력이 0 인 경우
            temp[temp_idx++] = '0';
        }
        // 입력이 0 이 아닌 경우
        else{
            unsigned int num = arr[i]; // 배열의 값을 임시로 저장. 원래 값 손상 방지 + 코딩 중 쓰기 쉽게
            while(num > 0){ // 계속 나누면 0.n이 돼서 자료형(int)에 의해 
                // 뒷자릿수부터 저장하는거임!: 12345 > 54321로 저장됨
                temp[temp_idx++] = (num % 10) + '0';
                num /= 10;  // 숫자 1자리씩 나누기
            }
        }

        // 역순으로 복사
        for(int j = temp_idx - 1; j >= 0; j--){
            result[idx++] = temp[j];
        }

        // 마지막 숫자 뒤에 공백 추가 (마지막 케이스는 SPACE 없음)
        if(i < 2){
            result[idx++] = ' ';
        }
    }

    result[idx] = '\0'; // 문자열 종료
    *str_size = idx;

    return result;
}