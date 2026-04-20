#include <stdio.h>
#include <stdlib.h>
int main()
{
    float o2, food, energy;
    int module;
    printf("Please enter the o2 level(0-100): ");
    scanf("%f", &o2);
    printf("Please enter the remaining kilos of food: ");
    scanf("%f", &food);
    printf("Please enter the energy level(0-100): ");
    scanf("%f", &energy);
    if (o2 < 0 || o2 > 100 || energy < 0 || energy > 100)
    {
        printf("Error!!! Please enter a valid value");
        return 1;
    }
    if (o2 < 20 || food < 50)
    {
        printf("Critical alert!!!\n");
    }
    else
    {
        printf("Oxygen and food levels are enough.\n");
    }
    printf("Please select a module\n");
    printf("1: Farming\n2: Generator\n3: Security\n");
    scanf("%d", &module);
    switch (module)
    {
    case 1:
        printf("Farming module is active. New harvest collected.\n");
        break;
    case 2:
        if (energy < 20)
        {
            printf("Unnecessary systems have been shut down and ultra power saving mode has been activated.\n");
        }
        else if (energy < 50)
        {
            printf("the systems is gone power saving mode\n");
        }
        else
        {
            printf("Generator is active. Unused systems have been shut down.\n");
        }
        break;
    case 3:
        printf("The security doors are locked.\n");
        break;
    default:
        printf("Invalid module! please enter a valid one.\n");
        break;
    }
    return 0;
}
