#include <stdio.h>
void applybonus(int *salaryptr, int performancescore);
int main()
{
    int mysalary = 3000;
    int performance = 90;
    printf("The salary without bonusses is %d\n", mysalary);
    applybonus(&mysalary, performance);
    printf("The salary with bonusses is %d\n", mysalary);
    return 0;
}
void applybonus(int *salaryptr, int performancescore)
{
    if (performancescore > 80)
    {
        *salaryptr += 1000;
    }
    else {
        *salaryptr += 200;
    }
}