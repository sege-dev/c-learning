#include <stdio.h>
int main() {
    char letter;
    printf("Please enter a letter: ");
    scanf(" %c",&letter);
    switch(letter) {
        case 'a': case 'A':
        case 'e': case 'E':
        case 'o': case 'O':
        case 'u': case 'U':
        case 'i': case 'I':
            printf("The %c is Vowel!\n",letter);
            break;
        default:
            printf("The %c is Consonant(or not a letter)!\n",letter);
            break;  
    }
return 0;
}