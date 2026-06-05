#include <stdio.h>
void encrypt_vault(int originalpin, int multiplier, int *resultpin);
int main()
{
    int multiplier = 1;
    int result = 0;
    int password;
    printf("Enter the password which you want to cryp: ");
    scanf("%d", &password);
    if (password == 2)
    {
        result = 2;
        printf("the crypted code: %d", result);
        return 0;
    }
    encrypt_vault(password, multiplier, &result);
    printf("the crypted code: %d", result);
    return 0;
}
void encrypt_vault(int originalpin, int multiplier, int *resultpin)
{

    if (originalpin == 0)
    {
        return;
    }
    int last = originalpin / 10;
    *resultpin += (((originalpin % 10) + 2) % 10) * multiplier;
    int nextmultiplier = multiplier * 10;

    encrypt_vault(last, nextmultiplier, resultpin);
}