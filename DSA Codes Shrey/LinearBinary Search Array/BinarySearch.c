// Implementation of Binary Search in an Array

#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[],int size, int element) {  // Binary Search function
    int low=0, mid, high=(size-1);
    //Keep searching until low <= high 
    while (low <= high)
    {
    mid = (low + high) / 2;   //searching started
    if (arr[mid] == element)
    {
        return mid;
    }
    if (arr[mid] < element)
    {
        low = mid + 1;
    }
    else {
        high = mid - 1;
        }
    }                     // searching ends here
    return -1;
}

void inputArray(int arr[], int size) {     // Function to input array elements

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

int isSorted(int arr[], int size) {  // Function to check if an array is sorted
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[i - 1]) {
            return 0; // Not sorted
        }
    }
    return 1; // Sorted
}

int main(int argc, char const *argv[])
{
    //Method 1 : using hardcoded values (sorted array for binary search)
    // int arr[] = {23, 45, 67, 54, 89, 66, 21};
    // int arrSize = sizeof(arr) / sizeof(int);
    // int element = 54;
    // int searchIndex = binarySearch(arr, arrSize, element);
    // printf("The element %d was found at Index %d \n", element, searchIndex);

    //Method 2 : using values from user
    int arrSize, element;

    printf("Enter the size of the array: "); // Input the size of the array
    scanf("%d", &arrSize);
    
    if (arrSize <= 0) {
        printf("Array size should be a positive integer.\n");
        return 1; // Exit with an error code
    }

    int arr[arrSize];
    inputArray(arr, arrSize);

    if (!isSorted(arr, arrSize)) {      // Check if the array is sorted
        printf("The array is not sorted. Binary search won't work correctly.\n");
        return 1; // Exit with an error code
    }


    printf("Enter the element to search: ");  // Input the element to search
    scanf("%d", &element);

    int searchIndex = binarySearch(arr, arrSize, element);   // Perform Binary search

    if (searchIndex != -1) {   // Output the result
        printf("The element %d was found at Index %d\n", element, searchIndex);
    } else {
        printf("The element %d was not found in the array\n", element);
    }
    return 0;
}
