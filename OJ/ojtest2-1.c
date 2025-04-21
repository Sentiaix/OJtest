#include <stdio.h>
int main(){
  int iv;
  float fv;
  printf("get ");
  scanf("%d", &iv);
  fv = iv;
  printf("data type %f %d", fv, iv);
  return 0;
}