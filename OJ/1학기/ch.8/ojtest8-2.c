#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int count1, count2;

// 함수 선언
void print_line(int input_s);

int main(){ // 수정금지!!
	int s;
	count1 = 0;
	count2 = 0;
	while(1){
		scanf("%d", &s);
		if( 0 >= s || s>9) break; // 0<s<10의 수를 받음.
		print_line(s); 
	}
	printf("the number of - prints is %d\n", count1);
	printf("the number of * prints is %d\n", count2);
}

//함수 정의
void print_line(int input_s){

    // "-" 출력만 for에 넣고 *출력은 그냥 앞뒤에 넣은다음 count2 += 2 하니까 66.7점임
    for(int i = 0; i < input_s; i++){
        if( i == 0 || i == input_s - 1){
            printf("*");
            count2++;
        } else{
            printf("-");
            count1++;
        }
    }

    printf("\n");
}