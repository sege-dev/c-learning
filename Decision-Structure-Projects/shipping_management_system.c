#include <stdio.h>
int main()
{
    float price = 10;
    int type;
    float weight;
    int zone;
    printf("--------Welcome--------\nplease select a kargo type\n");
    printf("1: Standart\n2: Express(50%% extra)\n");
    scanf("%d", &type);
    printf("Please enter the weight: ");
    scanf("%f", &weight);
    printf("1: Local\n2: Domestic\n 3: Abroad");
    scanf("%d", &zone);
    switch (zone)
    {
    case 1:
        if (weight <= 5 && weight >= 0)
        {
            price = price;
        }
        else if (weight > 5)
        {
            price = 10 + ((weight - 5) * 2);
        }
        else
        {
            printf("Error!!!");
        }
        break;
    case 2:
        if (weight <= 5 && weight > 0)
        {
            price = 20;
        }
        else if (weight > 5)
        {
            price = 20 + ((weight - 5) * 5);
        }
        else
        {
            printf("Error!!!");
        }
        break;
    case 3:
        if (weight > 0)
        {
            price = 100 + (weight * 10);
        }
        else
        {
            printf("Error!!!");
        }
        break;
    default:
        printf("Error!!!");
    }
    switch (type)
    {
    case 1:
        price = price;
        break;
    case 2:
        price = price * 1.5;
        break;
    default:
        printf("Error!!!");
        break;
    }
    printf("The shipment price is: %.2f", price);
    return 0;
}