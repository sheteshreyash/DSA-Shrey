// C code for Count Sort

#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}



int main()
{
    // int A[] = {9, 14, 4, 8, 7, 5, 6};

    printf("\nCount Sort Algo \n");
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int A[n]; // fixed sized array
    printf("Enter %d elements of the array:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("\nArray before sorting:\n");
    printArray(A, n);

    countSort(A, 0, n - 1);

    printf("Array after Count Sort:\n");
    printArray(A, n);
    return 0;
}
