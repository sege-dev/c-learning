#include <stdio.h>
int numberscanner(void);
int calculateCube(int number);
    
int main() {
    int number,result;
    number= numberscanner();
    result= calculateCube(number);
    printf("The cube of %d is :%d",number,result);
    return 0;
    
}
int numberscanner(void){
        int number;
        printf("Enter a number: ");
        scanf("%d",&number);
        return number;
    }
    int calculateCube(int number){
        return (number * number * number);
    }