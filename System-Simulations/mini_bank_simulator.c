#include <stdio.h>
void balancec(float balance);
float deposit(float balance);
float withdraw(float balance);
void investment(void);
int main()
{
    float balance = 1000;
    int menu;
    do
    {
        printf("1: Balance\n2: Deposit\n3: Withdraw\n4: Investment\n5: Exit");
        scanf("%d", &menu);
        switch (menu)
        {
        case 1:
            balancec(balance);
            break;
        case 2:
            balance = deposit(balance);
            balancec(balance);
            break;
        case 3:
            balance = withdraw(balance);
            balancec(balance);
            break;
        case 4:
            investment();
            break;
        case 5:
            printf("Have a good day!");
            break;
        default:
            printf("Enter a valid number\n");
        }
    } while (menu != 5);
    return 0;
}
void balancec(float balance)
{
    printf("Balance: %.2f", balance);
}
float deposit(float balance)
{
    float value;
    do
    {
        printf("Enter the deposit value");
        scanf("%f", &value);
    } while (value <= 0);
    return balance + value;
}
float withdraw(float balance)
{
    int value;
    do
    {
        printf("Enter the value: ");
        scanf("%d", &value);
    } while (value <= 0 || value > balance);
    return balance - value;
}
void investment(void)
{
    float money;
    int term;
    printf("\nEnter a money: ");
    scanf("%f", &money);
    printf("\nEnter a term: ");
    scanf("%d", &term);
    printf("The last money: %.2f", (money + (money / 10) * term));
}