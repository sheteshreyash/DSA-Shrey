// C Code to Implement Bubble sort algorithm

#include <stdio.h>
// #include <stdlib.h>  // No Need to dynamically allocate heap memory 

void printArray(int *A, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void bubbleSort(int *A, int n) {  // Time Complexity O(n^2) worst case and Space complexity O(1) no additional or extra memory space required
    int temp;
    for (int i = 0; i < n - 1; i++) { // for no of passes
        printf("Working on pass number %d\n", i+1); 

        for (int j = 0; j < n - 1 - i; j++) {  // for comparison in each pass
            if (A[j] > A[j + 1]) {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

void bubbleSortAdaptive(int *A, int n) {  // To change the adaptability of bubble sort from O(n^2) to O(n)
    int temp;
    int isSorted = 0;  // To check if the elements are sorted after each pass
    for (int i = 0; i < n - 1; i++) {
        printf("Working on pass number %d\n", i + 1);
        isSorted = 1;  // array is sorted
        for (int j = 0; j < n - 1 - i; j++) {
            if (A[j] > A[j + 1]) {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                isSorted = 0;  // array is not sorted
            }
        }
        if (isSorted) {
            printf("Array is already sorted. Terminating early.\n");
            return;
        }
    }
}

int main() {
    int choice;
    printf("\nBubble Sort algorithm (Prefer Adaptive Bubble Sort):\n");
    printf("1. Bubble Sort\n");
    printf("2. Adaptive Bubble Sort\n");
    printf("\nEnter your choice : ");
    scanf("%d", &choice);

    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int A[n];
    printf("Enter %d elements of the array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    printf("\nArray before sorting:\n");
    printArray(A, n);

    if (choice == 1) {
        bubbleSort(A, n);
        printf("Array after Bubble Sort:\n");
    } else if (choice == 2) {
        bubbleSortAdaptive(A, n);
        printf("Array after Adaptive Bubble Sort:\n");
    } else {
        printf("Invalid choice\n");
        return 1; // Exit with an error code
    }
    printArray(A, n);

    return 0;
}
