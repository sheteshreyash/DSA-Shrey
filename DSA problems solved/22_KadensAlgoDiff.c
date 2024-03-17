// Different implementation of kaden's algorithm

#include <stdio.h>
#include <stdlib.h>

void subarrayWithMaxSum(int nums[], int size) // Function to print the elements of Subarray with maximum sum
{
    int currMax = nums[0];
    int globalMax = nums[0];
    int startIndex = 0;
    int globalMaxStartIndex = 0;
    int endIndex = 0;

    for (int i = 1; i < size; ++i)
    {
        if (nums[i] > nums[i] + currMax)
        {
            currMax = nums[i];
            startIndex = i;
        }
        else
        {
            currMax += nums[i];
        }
        if (currMax > globalMax)
        {
            globalMax = currMax;
            endIndex = i;
            globalMaxStartIndex = startIndex;
        }
    }

    printf("Subarray with maximum sum is: ");
    for (int i = globalMaxStartIndex; i <= endIndex; ++i)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; ++i)
    {
        scanf("%d", &arr[i]);
    }

    subarrayWithMaxSum(arr, size);
    free(arr);
    return 0;
}
