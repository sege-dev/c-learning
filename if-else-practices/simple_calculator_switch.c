#include <stdio.h>
int main() {
    char operator;
    float number1, number2;
    printf("Please enter the first number: ");
    scanf("%f",&number1);
    printf("Please enter the operator: ");
    scanf(" %c",&operator);
    printf("Please enter the second number: ");
    scanf("%f",&number2);
    switch(operator) {
        case '+': 
            printf("The result is: %.2f",number1+number2);
            break;
        case '-' :
            printf("The result is: %.2f",number1-number2);
            break;
        case '*' :
            printf("The result is: %.2f",number1 * number2);
            break;
        case '/' : 
            if(number2 == 0){
                printf("The divisor can not be 0. Please enter a valid value.\n");
            }
            else{
                printf("The result is: %.2f",number1/number2);
            }
        break;
        default:
            printf("Invalid operator! Please use +,-,*,/\n");
    }
return 0;    
}