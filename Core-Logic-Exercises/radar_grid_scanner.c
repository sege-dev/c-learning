#include <stdio.h>
int main()
{
    int rows, cols;
    printf("=== Radar Grid Scanner ===\n");
    printf("Enter rows: ");
    scanf("%d", &rows);
    printf("Enter cols: ");
    scanf("%d", &cols);
    int center_row = rows / 2;
    int center_cols = cols / 2;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i == center_row && j == center_cols)
            {
                printf("T ");
            }
            else
            {
                printf(". ");
            }
        }
        printf("\n");
    }
    return 0;
}