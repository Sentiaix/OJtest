#include <stdio.h>
int main(){
  int iv;
  float fv;
  char cv;
  double dv;

  printf("get ");
  scanf("%d %f %c", &iv, &fv, &cv);
  
  dv = iv + fv + cv;
  printf("sum data type %lf", dv);
  return 0;
}