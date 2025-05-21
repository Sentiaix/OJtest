#include <stdio.h>

struct abc{
 char a;
 char b[50];
 float c;
};

struct abc get_abc(char a, char* b, float c);

void scanf_abc(struct abc* p);

int main(){
 struct abc i;

 // i = get_abc(i.a, i.b, i.c);
 scanf_abc( &i );
 
 printf("%c %s %f\n", i.a, i.b, i.c);

}

struct abc get_abc(char a, char* b, float c){
 struct abc result;
 
 printf("input char string float: ");
 
 scanf("%c %s %f", &result.a, result.b, &result.c);
 
 return result; 
}

void scanf_abc(struct abc* p){

 scanf("%c %s %f", &p->a, p->b, &p->c);
 // same as
 // scanf("%c %s %f", &(*p).a, (*p).b, &(*p).c); 
}