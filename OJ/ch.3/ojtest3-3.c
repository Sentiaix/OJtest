#include <stdio.h>

int main(){
    int sq_length, sq_width;
    
    scanf(" %d", &sq_length); //사각형 가로길이 입력
    scanf(" %d", &sq_width); //사각형 세로길이 입력

    printf("직사각형의 넓이 : %d\n", sq_length*sq_width);
    printf("직사각형의 둘레 : %d\n", 2*sq_length+2*sq_width);

        return 0;
}