// Implementation of Deletion of element in array (order does not matter)

#include <stdio.h>
#include <stdlib.h>

void displayArray(int arr[], int n) {  //Traversal function
    printf("Current Elements in the Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int indDeletion(int arr[], int *size, int index) {  // Deletion function if sorting/order is not considered 
    if (index < 0 || index >= *size) {
        printf("Invalid index for deletion.\n");
        return 0; // Deletion failed
    }

    for (int i = index; i < (*size - 1); i++) {  //important section of code 
        arr[i] = arr[i + 1];
    }
    *size -= 1; // Reduce the size after successful deletion
    return 1;   // Deletion successful
}

int main(int argc, char const *argv[]) {

    // int arr[100] = {1, 4, 56, 23};  // Hardcoded array size value
    // int size = 5, element = 45, index = 3; // hardcoded element and index insertion

    int *arr;  // Declare a pointer for dynamic memory allocation
    int size, initialElements, index;

    printf("Enter the Size of an Array: ");
    scanf("%d", &size);

    arr = (int *)malloc(size * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return -1;
    }

    printf("Enter the number of initial elements to insert: ");
    scanf("%d", &initialElements);

    printf("Enter initial elements:\n");
    for (int i = 0; i < initialElements; i++) {
        printf("Enter element at index %d: ", i);
        scanf("%d", &arr[i]);
    }
    displayArray(arr, initialElements); //displays the main array

    printf("\nEnter Index where you want to Delete the element: ");
    scanf("%d", &index);

    int result = indDeletion(arr, &initialElements, index);
    if (result == 1) {
        printf("Deletion successful.\n");
    } else {
        printf("Deletion failed.\n");
    }

    displayArray(arr, initialElements);  // displays the modified array (deleted elements)
    free(arr);
    return 0;
}
