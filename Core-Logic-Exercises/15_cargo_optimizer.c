#include <stdio.h>
float totalweightcalculator(int *cargonumber);
int main()
{
    int totalcargonumber = 0;
    float totalweight;
    printf("welcoma to weight and number tracker\n");
    totalweight = totalweightcalculator(&totalcargonumber);
    printf("The total weight of %d cargo are %.2f.", totalcargonumber, totalweight);
    return 0;
}
float totalweightcalculator(int *cargonumber)
{
    float totalweight = 0;
    float currentweight = 0;
    for (int i = 1; i < 6; i++)
    {
        printf("enter the %d. cargo's weight: ", i);
        scanf("%f", &currentweight);
        if (currentweight <= 50)
        {
            totalweight += currentweight;
            *cargonumber += 1;
        }
    }
    return totalweight;
}
