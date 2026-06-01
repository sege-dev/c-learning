#include <stdio.h>
int main() {
    int steptracker;
    int zero=0;
    int one=1;
    int sum;
    printf("Welcome to fibonacci calculator!!");
    printf("please enter a step what u want : ");
    scanf("%d",&steptracker);
    int i=1;
    while(i < steptracker) {
        sum=zero+one;
        zero=one;
        one=sum;
        i++;
        printf("%d,%d,%d\n",zero,one,sum);
    }
    if(steptracker==0) {
        printf("The 0. step is 0!");
    }
    else {
        printf("The %d. step is %d!!",steptracker,sum);
    }
    return 0;
}