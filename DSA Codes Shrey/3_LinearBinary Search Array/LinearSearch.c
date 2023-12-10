// Implementation of Linear Search in an Array

#include <stdio.h>
#include <stdlib.h>

int linearSearch(int arr[], int size, int element) {   // linear search function
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

void inputArray(int arr[], int size) {     // Function to input array elements

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

int main(int argc, char const *argv[])
{
    //Method 1 : using hardcoded values
    // int arr[] = {23, 45, 67, 54, 89, 66, 21};
    // int arrSize = sizeof(arr) / sizeof(int);
    // int element = 54;
    // int searchIndex = linearSearch(arr, arrSize, element);
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

    printf("\nEnter the element to search: ");  // Input the element to search
    scanf("%d", &element);

    int searchIndex = linearSearch(arr, arrSize, element);   // Perform linear search

    if (searchIndex != -1) {   // Output the result
        printf("The element %d was found at Index %d\n", element, searchIndex);
    } else {
        printf("The element %d was not found in the array\n", element);
    }
    return 0;
}
