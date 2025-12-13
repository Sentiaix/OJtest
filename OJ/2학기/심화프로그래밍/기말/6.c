#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
    char name[50];
    int score1;
    int score2;
    int score3;
} Std;

int total_score(struct Student* p);
struct Student* find_top(struct Student arr[], int n);

int main() {
    int n = 0;
    
    scanf("%d", &n);

    Std* s = (Std*)malloc(sizeof(Std) * n);

    for (int i = 0; i < n; i++) {
        scanf("%s %d %d %d",
              s[i].name, &s[i].score1, &s[i].score2, &s[i].score3);
        // printf("%d: %s %d %d %d\n", i, s[i].name, s[i].score1
        //                           , s[i].score2, s[i].score3);
    }    

    Std* top = find_top(s, n);
    int tscore = total_score(top);
    
    printf("top = %s (%d)", top->name, tscore);

    free(s);

    return 0;
}

int total_score(struct Student* p) {
    return (p->score1 + p->score2 + p->score3);
}
struct Student* find_top(struct Student arr[], int n) {
    int maxscore = 0;
    int top_idx = 0;
    int score = 0;
    for (int i = 0; i < n; i++) {
        score = total_score(&arr[i]);
        if (maxscore < score) {
            maxscore = score;
            top_idx = i;
        }
    }

    return &arr[top_idx];
}