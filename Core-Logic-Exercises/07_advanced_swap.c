#include <stdio.h>

void swapNumbers(int *ptr1, int *ptr2);

int main(void) {
    int x = 5, y = 10;

    printf("Before swap: x = %d, y = %d\n", x, y);

    swapNumbers(&x, &y);

    printf("After swap: x = %d, y = %d\n", x, y);

    return 0;
}

void swapNumbers(int *ptr1, int *ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}