#include <stdio.h>
int dividenumbers(int dividend, int divisor, int *remainderptr);
int main()
{
    int a = 13, b = 4;
    int quotient;
    int remainder;
    quotient = dividenumbers(a, b, &remainder);
    printf("For %d / %d: \n", a, b);
    printf("Quotient : %d\n", quotient);
    printf("REaminder : %d\n", remainder);
    return 0;
}
int dividenumbers(int dividend, int divisor, int *remainderptr)
{
    *remainderptr = dividend % divisor;
    return dividend / divisor;
}