#include <stdio.h>
int main()
{
    int type;
    char shift;
    float kwh;
    float price;
    printf("1: Residental\n2:Commercial\n3: Industrial");
    scanf("%d", &type);
    printf("Enter the used kwh: ");
    scanf("%f", &kwh);
    printf("D: Day\nN: Night(20%% Discount)");
    scanf(" %c", &shift);
    switch (type)
    {
    case 1:
        if (kwh > 0 && kwh <= 150)
        {
            price = kwh * 0.5;
        }
        else if (kwh > 150)
        {
            price = 75 + ((kwh - 150) * 0.75);
        }
        else
        {
            printf("Error!!!");
            return 0;
        }
        break;
    case 2:
        if (kwh > 0 && kwh <= 500)
        {
            price = kwh * 1;
        }
        else if (kwh > 500)
        {
            price = 500 + ((kwh - 500) * 1.5);
        }
        else
        {
            printf("Error!!!");
            return 0;
        }
        break;
    case 3:
        if (kwh > 0)
        {
            price = 500 + (kwh * 1.2);
        }
        else
        {
            printf("Error!!!");
            return 0;
        }
        break;
    default:
        printf("Error!!!");
        return 0;
        break;
    }
    switch (shift)
    {
    case 'n':
    case 'N':
        price = price * 0.8;
        break;
    case 'd':
    case 'D':
        price = price;
        break;
    default:
        printf("Error!!!");
        return 0;
        break;
    }
    if (price > 1000)
    {
        price = price + (price * 0.18);
    }
    else
    {
        price = price + (price * 0.08);
    }
    printf("The total price is: %.2f", price);
    return 0;
}