// Given an array arr[] of size N.
// The task is to find the sum of the contiguous subarray within a arr[] with the largest sum.

// The idea of Kadane’s algorithm is to maintain a variable max_ending_here that stores
// the maximum sum contiguous subarray ending at current index and a variable max_so_far stores
// the maximum sum of contiguous subarray found so far,
// Everytime there is a positive - sum value in max_ending_here compare it
// with max_so_far and update max_so_far if it is greater than max_so_far.

// The subarray with negative sum is discarded (by assigning max_ending_here = 0 in code).
// We carry subarray till it gives positive sum.

// Pseudocode of Kadane’s algorithm:
// Initialize:
//     max_so_far = INT_MIN
//     max_ending_here = 0

// Loop for each element of the array :
//   (a) max_ending_here = max_ending_here + a[i]
//   (b) if(max_so_far < max_ending_here)
//             max_so_far = max_ending_here
//   (c) if(max_ending_here < 0)
//             max_ending_here = 0
// return max_so_far


// Follow the below steps to Implement the idea:
// Initialize the variables max_so_far = INT_MIN and max_ending_here = 0
// Run a for loop from 0 to N-1 and for each index i:
// Add the arr[i] to max_ending_here.
// If  max_so_far is less than max_ending_here then update max_so_far  to max_ending_here.
// If max_ending_here < 0 then update max_ending_here = 0
// Return max_so_far




#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int maxSubArraySum(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));

    printf("Enter the array values:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int max_sum = maxSubArraySum(a, n);
    printf("Maximum contiguous sum is %d\n", max_sum);

    free(a);  // free memory function
    return 0;
}
