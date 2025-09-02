#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function declaration
int* copy(char* str); // str을 받고 int배열에 값을 저장하는것. 아마 아스키로 저장해야하는듯

// Do not edit main function!!
int main(){
	char str[256];
	scanf("%[^\n]", str);
	//printf("%s\n", str);
	
	int* c = copy(str);
	
	int i = 0;
	while( c[i] != 0){
		printf("%c", c[i]);
		i++;
	}
	printf("\n");
	free(c);
	return 0;
}

// define function
int* copy(char* str){
    int len = strlen(str); // 반복할 횟수를 정하기 위해 strlen으로 문자열 길이 저장

    // 동적 메모리를 사용하는데, 마지막 칸에 EOF를 넣어야하므로 len + 1로 함
    int* p = (int*)malloc( (len + 1) * sizeof(int) );

    for(int i = 0; i < len; i++){
        p[i] = (int)str[i];
    }

    p[len] = 0; // 메인 함수에서 0을 만나면 출력이 멈춤!

    // 여기서 동적 메모리를 반환하면 안 됨!!
    // 주소가 사라져버려 p[0]값이나 아니면 통째로 오류가 발생함!
    return p;
}