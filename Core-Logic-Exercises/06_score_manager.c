#include <stdio.h>
int getscore(void);
float finalscorer(int score1, int score2);
int main() {
    float finalscore;
    int score1, score2;
    score1 = getscore();
    score2 = getscore();
    finalscore= finalscorer(score1,score2);
    printf("\nYour final score is: %.2f",finalscore);
    return 0;
}

int getscore(void) {
    int score;
    printf("\nPlease enter a score: ");
    scanf("%d",&score);
    return score;
}
float finalscorer(int score1, int score2) {
    return (score1+score2)/2.0;
}