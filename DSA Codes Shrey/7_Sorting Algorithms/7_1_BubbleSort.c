// C Code to Implement Bubble sort algorithm

#include <stdio.h>
// #include <stdlib.h> 

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

    // Logic 1 :- Array size is fixed and have to fill the array completely
    // int A[n];   
    // printf("Enter %d elements of the array:\n", n);
    // for (int i = 0; i < n; i++) {
    //     scanf("%d", &A[i]);
    // }

    // Logic 2 :- Can fill Array elements less than or equal to total array size (flexible)
    int A[n];
    printf("Enter elements of the array (up to %d elements):\n", n);
    for (int i = 0; i < n; i++) {
        if (i >= n) {
            printf("Array is Full. Overflow condition\n");
            break;
        }
        else {
        scanf("%d", &A[i]);
        }
    }

    // int count = 0;
    // while (count < n) {
    //     scanf("%d", &A[count]);
    //     count++;
    // }

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
