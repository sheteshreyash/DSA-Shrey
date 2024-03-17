// C program to find fibonacci series upto a number

#include <stdio.h>

void printFibonacci(int n, int a, int b)
{
    if (n > 0)
    {
        printf("%d ", a);
        printFibonacci(n - 1, b, a + b);
    }
}

int main()
{
    int n;
    do
    {
        printf("Enter the number of elements (non-negative): \n");
        scanf("%d", &n);
    } while (n < 0);

    printf("Fibonacci Series: ");

    // Special case for 0 elements
    if (n == 0)
    {
        // No elements to print
        printf("\n");
        return 0;
    }

    // Special case for 1 element
    if (n == 1)
    {
        printf("0\n");
        return 0;
    }

    // Print the Fibonacci series starting from the third element
    printFibonacci(n - 2, 0, 1);

    return 0;
}
