#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 함수 선언
void draw_box(int h, int w, char c1, char c2);
double area(int h, int w);

int main(){ // 수정금지!!
	int h, w = 0;
	char c1, c2;

	scanf("%d %d %c %c", &h, &w, &c1, &c2);
	draw_box(h, w, c1, c2 );

	printf("area is %f\n", area(h,w));
}

// 함수 정의
void draw_box(int h, int w, char c1, char c2){
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if((i == 0 || j == 0) || (i == h - 1 || j == w - 1)){
                printf("%c", c1);
            } else{
                printf("%c", c2);
            }
        }
        printf("\n");
    }
}

double area(int h, int w){
    
    return h * w;
}