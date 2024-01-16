// C code for Count Sort

#include <stdio.h>
#include <limits.h> // used because of INT_MIN
#include <stdlib.h> // used because of dymamic memory allocation

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int maximum(int A[], int n) // identify maximum element
{
    int max = INT_MIN; // Initialize max to the smallest possible value for an int
    for (int i = 0; i < n; i++)
    {
        if (max < A[i])
        {
            max = A[i];
        }
    }
    return max;
}

void countSort(int *A, int n) // count sort function
{
    int i, j;
    // Find the maximum element in A
    int max = maximum(A, n);

    // Create the count array
    int *count = (int *)malloc((max + 1) * sizeof(int));

    // Initialize the array elements to 0
    for (i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }

    // Increment the corresponding index in the count array
    for (i = 0; i < n; i++)
    {
        count[A[i]] = count[A[i]] + 1;
    }

    i = 0; // counter for count array
    j = 0; // counter for the given array A

    while (i <= max)
    {
        if (count[i] > 0)
        {
            A[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
    free(count); // Free the dynamically allocated memory
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

    countSort(A, n);

    printf("Array after Count Sort:\n");
    printArray(A, n);
    return 0;
}

// The time complexity of Counting Sort is O(n + k), where :
//     n is the number of elements in the input array,
//     k is the range of input values(the difference between the maximum and minimum values in the array)