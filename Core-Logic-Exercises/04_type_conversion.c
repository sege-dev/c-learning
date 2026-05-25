#include <stdio.h>
int Salarycalculator(int hours, int haurlyrate);
float hoursscanner(void);
float ratescanner(void);
int main()
{
    float hours, rate;
    int salary;
    rate = ratescanner();
    hours = hoursscanner();
    salary = Salarycalculator(hours, rate);
    printf("\nThe salary is: %d", salary);
    return 0;
}
int Salarycalculator(int hours, int haurlyrate)
{
    return hours * haurlyrate;
}
float hoursscanner(void)
{
    float hours;
    printf("Please enter the work hours: ");
    scanf("%f", &hours);
    return hours;
}
float ratescanner(void)
{
    float rate;
    printf("\nPlease enter the hourly rate:");
    scanf("%f", &rate);
    return rate;
}