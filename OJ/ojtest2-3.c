#include <stdio.h>
int main(){
  int x, y; //변수명 조건 : 첫 글자는 _ 또는 영어(숫자X), 대소문자 구별, 공백사용불가
  printf("integers x, y: ");
  scanf("%d, %d", &x, &y);
  //sol 1; 한 줄씩 출력
  printf("x+y=%d\n",x+y);
  printf("x-y=%d\n",x-y);
  printf("x*y=%d\n",x*y);
  printf("x/y=%d\n",x/y);
  printf("x%y=%d\n",x%y); // % 연산자는 나눗셈의 나머지를 출력한다.

  //sol 2; 한 줄에 모두 출력
  //printf("x+y=%d\nx-y=%d\nx*y=%d\nx/y=%d\nx%y=%d\n",x+y,x-y,x*y,x/y,x%y);

  return 0;
}