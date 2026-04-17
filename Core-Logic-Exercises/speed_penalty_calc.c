#include <stdio.h>
int main() {
    int speed;
    printf("please enter a speed value: ");
    scanf("%d",&speed);
    if (speed < 0){
        printf("please enter a valid speed value.\n");
    }
    else if(speed <= 80){
        printf("Safe driving.\n");
    }
    else if(speed <=100){
        printf("Low Penalty - 100$\n");
    }
    else if(speed <=120){
        printf("High Penalty - 200$\n");
    }
    else if(speed >=121){
        printf("Licence Revoked!\n");
    }
    else {
        printf("Invalid Speed.\n");
    }
    return 0;
}