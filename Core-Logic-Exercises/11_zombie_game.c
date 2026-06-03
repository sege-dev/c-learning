#include <stdio.h>
void takedamage(int *healthptr, int damage);
int main()
{
    int playerhealth = 100;
    for (int i = 1; i < 6; i++)
    {
        printf("The %d. wave\n", i);
        takedamage(&playerhealth, 15);
        if (playerhealth <= 0)
        {
            printf("You died in wave game over.");
            break;
        }
        else
        {
            printf("You survived in that wave. health: %d\n", playerhealth);
        }
    }
    if (playerhealth > 0)
    {
        printf("Congrats! you have survived all waves the last health is %d\n", playerhealth);
    }
    return 0;
}
void takedamage(int *healthptr, int damage)
{
    *healthptr -= damage;
    printf("You took %d damage in that wave\n", damage);
}