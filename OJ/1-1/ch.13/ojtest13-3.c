#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// function declaration
int* to_int_array(int* size, char* str); // char로 숫자를 받고, int로 변환 후 반환

// Do not edit main function
int main(){
	char str[256];
	scanf("%[^\n]", str);
	//printf("%s\n", str);
	
	int* array;
	int size;
	array = to_int_array( &size, str);
	printf("size: %d\n", size);
	for( int i = 0 ; i < size; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
	free(array);
	return 0;
}

// define function

// 여기서 int* size는 size 변수의 주소를 받아 main 함수의 "실제 변숫값"을 수정할것임을 생각해야함
int* to_int_array(int* size, char* str){
    int* p = (int*)malloc(100 * sizeof(int)); // 최대 100개 숫자 처리
    int idx = 0; // 몇 번째 칸에 숫자를 넘기는지
    int temp = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            temp = temp * 10 + (str[i] - '0');
        } else if (str[i] == ' ') {
            p[idx++] = temp;
            temp = 0;
        }
    }

    // 마지막 글자 처리
    p[idx++] = temp;

    *size = idx;
    return p; 
}