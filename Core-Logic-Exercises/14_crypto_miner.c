#include <stdio.h>
float findmaxtemp();
float valuecontroller(float temp);
int main()
{
    float maxtemp;
    printf("max temp scaner \n");
    maxtemp = findmaxtemp();
    printf("The max temp: %.2f", maxtemp);
    return 0;
}
float findmaxtemp()
{
    float maxtemp = 0;
    for (int i = 1; i < 5; i++)
    {
        float currenttemp = 0;
        printf("please enter %d. temp: ", i);
        scanf("%f", &currenttemp);
        currenttemp = valuecontroller(currenttemp);
        if (maxtemp < currenttemp)
        {
            maxtemp = currenttemp;
        }
    }
    return maxtemp;
}
float valuecontroller(float temp)
{
    while (temp < 0)
    {
        printf("please enter a valid value: ");
        scanf("%f", &temp);
    }
    return temp;
}