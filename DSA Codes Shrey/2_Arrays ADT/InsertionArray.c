// Implementation of insertion of element in array (order does not matter)

#include <stdio.h>
#include <stdlib.h>

void displayArray(int arr[], int n) {  // Traversal function
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
}

int indInsertion(int arr[], int size, int element, int capacity, int index) {  // Insertion function if sorting/order is not considered 
        if (size >= capacity)
        {
            return -1;
        }
        for (int i = (size-1); i >= index; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[index] = element;
        return 1;
}


int main(int argc, char const *argv[])
{
    // int arr[100] = {1, 4, 56, 23};  // Hardcoded array size value
    // int size = 5, element = 45, index = 3; // hardcoded element and index insertion

    int *arr;  // Declare a pointer for dynamic memory allocation
    int size, element, index;

    printf("Enter the Size of an Array : ");
    scanf("%d", &size);

    arr = (int *)malloc(size * sizeof(int));   // Dynamically allocate memory for the array

    if (arr == NULL) {       // Check if memory allocation is successful
        printf("Memory allocation failed.\n");
        return -1;
    }

    int initialElements;      // Initialize only the first few elements
    printf("Enter the number of initial elements to insert: ");
    scanf("%d", &initialElements);
    printf("Enter initial elements:\n");
    for (int i = 0; i < initialElements; i++) {
        printf("Enter element at index %d: ", i);
        scanf("%d", &arr[i]);
    }
    displayArray(arr, initialElements); // display function (displays the main array)

    printf("\nEnter Element you want to insert in Array : ");
    scanf("%d", &element);
    printf("\nEnter Index where you want to insert the element : ");
    scanf("%d", &index);

    int result = indInsertion(arr, initialElements, element, size, index);   // Array element insertion function 
    if (result == 1) {
        size += 1;
        printf("Insertion successful.\n");
    } else {
        printf("Insertion failed. The array is already full.\n");
    }

    displayArray(arr, initialElements); // displays the new modified array
    free(arr);      // Free the dynamically allocated memory
    return 0;
}
