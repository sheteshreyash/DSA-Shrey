// C program for identifying the element in an sorted array which only appears once
// A Linear Search based function to find the element that appears only once

// https://www.geeksforgeeks.org/find-the-element-that-appears-once-in-a-sorted-array/

#include <stdio.h>
#include <stdlib.h>

int search(int arr[], int n)
{
    int ans = -1;
    for (int i = 0; i < n; i += 2)
    {
        if (arr[i] != arr[i + 1])
        {
            ans = arr[i];
            break;
        }
    }
    if (arr[n - 2] != arr[n - 1])
        ans = arr[n - 1];
    return ans;
}

// Function to check if the array is sorted
int isSorted(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            return 0; // Not sorted
    }
    return 1; // Sorted
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    int sorted = 0; // Flag to check if the array is sorted

    do
    {
        // Input array elements from the user
        printf("Enter the elements of the sorted array:\n");
        for (int i = 0; i < n; i++)
        {
            printf("Element %d: ", i + 1);
            scanf("%d", &arr[i]);
        }
        if (isSorted(arr, n))
        {
            sorted = 1; // Set the flag to indicate a sorted array
            int result = search(arr, n);
            if (result != -1) // Check if an element is found
                printf("The Unique element is %d\n", result);
            else
                printf("No unique element found in the array.\n");
        }
        else
        {
            printf("The entered array is not sorted. Please enter a sorted array.\n");
        }
    } while (!sorted); // Continue until a sorted array is provided

    free(arr);
    return 0;
}
