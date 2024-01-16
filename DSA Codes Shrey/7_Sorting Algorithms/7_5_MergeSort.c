// C code for Merge sort with two different sorted arrays in same array

#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int A[], int mid, int low, int high) //merge function for merging two subarrays in same array
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void mergeSort(int A[], int low, int high) // mergeSort function for sorting elements
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, mid, low, high);
    }
}

int main()
{
    // int A[] = {9, 14, 4, 8, 7, 5, 6};

    printf("\nMerge Sort Algo \n");
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

    mergeSort(A, 0, n-1);

    printf("Array after Quick Sort:\n");
    printArray(A, n);
    return 0;
}

