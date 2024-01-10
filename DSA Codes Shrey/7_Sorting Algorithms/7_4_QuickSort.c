// C code for Quick Sort Algorithm

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



    printf("\nQuick Sort Algo \n");
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

    quickSort(A, n); //quicksort function

    printf("Array after Quick Sort:\n");
    printArray(A, n);
    return 0;
}
