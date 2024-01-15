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

int partition(int A[], int low, int high)  // partition function is necessary for partitionIndex value
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }
        while (A[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    // Swap A[low] and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j; // pivot will remain on j place finally
}

void quickSort(int A[], int low, int high)  //Quick sort function will take array of elements
{
    int partitionIndex; // Index of pivot after partition
    if (low < high)
    {
        partitionIndex = partition(A, low, high);  // returns index of lowest element
        //printArray(A, n);  // we can add printArray funtion to check partition order
        quickSort(A, low, partitionIndex - 1);  // sort left subarray
        quickSort(A, partitionIndex + 1, high); // sort right subarray
    }
}

int main()
{
    // int A[] = {3, 5, 2, 13, 12, 3, 2, 13, 45};
    // 3, 5, 2, 13, 12, 3, 2, 13, 45
    // 3, 2, 2, 13i, 12, 3j, 5, 13, 45
    // 3, 2, 2, 3j, 12i, 13, 5, 13, 45 --> first call to partition returns 3

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

    quickSort(A, 0, n-1); //quicksort function will run from 0 which is low and n-1 which is high

    printf("Array after Quick Sort:\n");
    printArray(A, n);
    return 0;
}

// Worst Case time complexity = O(n^2) where array is already sorted
// best case time complexity = O(nlogn) not always true
// average case time complexity = O(nlogn)