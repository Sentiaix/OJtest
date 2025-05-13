#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 함수 선언
int recursive_box(int h, int w);

int main(){ // 수정금지!!
	int height, width;
	while(1){
		scanf("%d %d", &height, &width);
		if( 0 >= width || 0 >= height) break; //w 또는 h가 0보다 작을 때 반복에서 탈출
		recursive_box(height, width);
	} // recursive : 재귀적인
}

// 함수 정의
// 반복문 쓰지 않기
int recursive_box(int h, int w){
    
    // 원본 widht를 저장하기 위함
    static int save_origin_w = 0;

    if(h == 0){ // 이거 없으면 죽을때까지 반복함
        return 0;
    }
    if(w > 1){ // 남은 width가 1칸일 때 까지 * 출력
        printf("*");
        save_origin_w++;
        return recursive_box(h, w - 1);
    } else if(w == 1){ // 마지막 칸이면 r 출력. 그리고 원래 w값을 다시 입력.
        printf("r\n");
        int temp = save_origin_w + 1;
        save_origin_w = 0;
        return recursive_box(h - 1, temp);
    }
}