#include <stdio.h>
void power(int base, int exp, int *son);
void factoriel(int n, int *result);
int main()
{
    int result = 1;
    int factoresult = 1;
    int sayi, us;
    printf("sayiyi girin: ");
    scanf("%d", &sayi);
    printf("ussu girin: ");
    scanf("%d", &us);
    power(sayi, us, &result);
    printf("%d to the power %d : %d", sayi, us, result);
    factoriel(sayi, &factoresult);
    printf("\nThe factoriel of %d: %d", sayi, factoresult);
    return 0;
}
void power(int base, int exp, int *son)
{
    *son *= base;
    int newexp = exp - 1;
    if (newexp == 0)
    {
        return;
    }
    power(base, newexp, son);
}
void factoriel(int n, int *result)
{
    int newn = n - 1;
    *result *= n;
    if (newn <= 1)
    {
        return;
    }
    factoriel(newn, result);
}