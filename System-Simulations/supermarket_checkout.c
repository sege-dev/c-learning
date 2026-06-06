#include <stdio.h>
float getPrice(int code)
{
    switch (code)
    {
    case 1:
        printf("Bread 5.00\n");
        return 5.00;
    case 2:
        printf("Water 3.50\n");
        return 3.50;
    case 3:
        printf("Milk 18.00\n");
        return 18.00;
    default:
        printf("Invalid product 0.00\n");
        return 0.0;
    }
}
void checkout(int itemcount)
{
    float subtotal = 0.0;
    int code, paymentmethod;
    for (int i = 1; i <= itemcount; i++)
    {
        printf("Item %d code: ", i);
        scanf("%d", &code);
        subtotal += getPrice(code);
    }
    printf("-------------------------------------\n");
    printf("Subtotal : %.2f\n", subtotal);
    printf("Payment method (1-Cash 2-Card 3-Contactless): ");
    scanf("%d", &paymentmethod);
    switch (paymentmethod)
    {
    case 1:
        printf("Payment received by cash.\n");
        break;
    case 2:
        printf("Payment received by card.\n");
        break;
    case 3:
        printf("Payment received by contactless.\n");
        break;
    default:
        printf("Unknown Payment method.\n");
        break;
    }
    float tax = subtotal * 0.18;
    float total = subtotal + tax;
    printf("\n====== RECEIPT ======\n");
    printf("Subtotal : %.2f\n", subtotal);
    printf("Tax (18%%) : %.2f\n", tax);
    printf("Total : %.2f\n", total);
}
int main()
{
    int count;
    printf("How many items? ");
    scanf("%d", &count);
    checkout(count);
    return 0;
}