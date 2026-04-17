#include <stdio.h>
int main() {
    float balance= 1000;
    int choice;
    float amount;
    printf("1: Check balance\n2: Deposit\n3: Withdraw\n");
    scanf("%d",&choice);
    if(choice==1){
        printf("Your balance is %.2f\n",balance);
    }
    else if(choice==2){
        printf("please enter the Deposit amount: ");
        scanf("%f",&amount);
        if(amount<=0){
            printf("Invalid amount!\n");
        }
        else {
            balance=balance+amount;
            printf("Your new balance is: %.2f\n",balance);
        }
    }
    else if(choice==3){
        printf("please enter the Withdraw amount: ");
        scanf("%f",&amount);
        if(amount > balance){
            printf("Insufficient funds!\n");
        }
        else if(amount <=0){
            printf("Invalid amount! Withdraw must be positive.\n");
        }
        else {
            balance=balance-amount;
            printf("Your new balance is: %.2f\n",balance);
        }
    }
    else {
        printf("Invalid transaction!\n");
    }
    return 0;
}
