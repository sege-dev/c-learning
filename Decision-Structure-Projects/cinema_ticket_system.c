#include <stdio.h>
int main(){
    int choice;
    printf("---Welcome to the Cinema---\n");
    printf("1: Student\n2: Child\n3: Adult\n4: Senior\n5: VIP\n");
    scanf("%d",&choice);
    switch(choice) {
        case 1:
        case 2:
            printf("The price is: 10$.");
        break;
        case 3:
        case 4:
            printf("The price is: 20$.");
        break;
        case 5:
            printf("The price is: 50$.");
        break;
        default:
            printf("Invalid value! Please enter 1-5.");
        break;
    }
return 0;
}
