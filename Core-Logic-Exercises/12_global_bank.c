#include <stdio.h>
int bankaccount = 5000;
void deposit();
void withdraw();
void balance();
void request();
int main()
{
    printf("welcome to bank ui!\n");
    balance();
    request();
    balance();
}
void deposit()
{
    int amount;
    printf("enter amount: ");
    scanf("%d", &amount);
    bankaccount += amount;
    printf("you deposited %d\nThe new balance is %d", amount, bankaccount);
}
void withdraw()
{
    int amount;
    printf("enter amount:");
    scanf("%d", &amount);
    bankaccount -= amount;
    printf("you withdrawed %d\nThe new balance is %d", amount, bankaccount);
}
void balance()
{
    printf("The balance is %d\n", bankaccount);
}
void request()
{
    int request;
    printf("1:withdraw\n2:deposit\n");
    scanf("%d", &request);
    while (request != 1 && request != 2)
    {
        printf("please enter a valid number: ");
        scanf("%d", &request);
    }
    if (request == 1)
    {
        withdraw();
    }
    else if (request == 2)
    {
        deposit;
    }
    else
    {
        printf("Error!!!");
    }
}