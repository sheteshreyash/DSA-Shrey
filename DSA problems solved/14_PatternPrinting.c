/* Print this pattern        *
                           * *
                         * * *
                       * * * *         */


#include <stdio.h>

int main()
{
    int rows, i, j;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    // Print the pattern
    for (i = 1; i <= rows; i++)
    {
        // Print spaces before the stars
        for (j = 1; j <= rows - i; j++)
        {
            printf("  ");
        }

        for (j = 1; j <= i; j++)
        {
            printf("   *");
        }
        printf("\n");
    }
    return 0;
}
