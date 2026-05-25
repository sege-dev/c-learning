#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double getNumberFromUser(void);

int main(void)
{
    double userNum;
    double positiveNum;
    double rootResult;

    userNum = getNumberFromUser();
    positiveNum = fabs(userNum);
    rootResult = sqrt(positiveNum);

    printf("\nYour number: %lf\n", userNum);
    printf("Absolute value (Mutlak Deger): %lf\n", positiveNum);
    printf("Square root (Karekok): %lf\n", rootResult);

    return 0;
}

double getNumberFromUser(void)
{
    double input;
    printf("Enter a number (positive or negative): ");
    scanf("%lf", &input);
    return input;
}