// C program for two sum and three sum integers in an array

#include <stdio.h>

int findTwoSum(int arr[], int n, int target)  // iterative approach
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                printf("Two elements found: %d and %d\n", arr[i], arr[j]);
                return 1; // Found
            }
        }
    }
    return 0; // Not found
}

int findTwoSumRecursive(int arr[], int start, int end, int target)  // recursive approach
{
    if (start >= end)
    {
        return 0; // Not found
    }
    if (arr[start] + arr[end] == target)
    {
        printf("Two elements found: %d and %d\n", arr[start], arr[end]);
        return 1; // Found
    }
    else if (arr[start] + arr[end] < target)
    {
        return findTwoSumRecursive(arr, start + 1, end, target);
    }
    else
    {
        return findTwoSumRecursive(arr, start, end - 1, target);
    }
}

int findThreeSum(int arr[], int n, int target)  // iterative approach
{
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == target)
                {
                    printf("Three elements found: %d, %d, and %d\n", arr[i], arr[j], arr[k]);
                    return 1; // Found
                }
            }
        }
    }
    return 0; // Not found
}

int findThreeSumRecursive(int arr[], int start, int end, int target)  // recursive approach 
{
    if (start >= end)
    {
        return 0; // Not found
    }
    int remaining = target - arr[start];
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] + findTwoSumRecursive(arr, i + 1, end, remaining))
        {
            printf("Three elements found: %d, %d, and %d\n", arr[start], arr[i], remaining);
            return 1; // Found
        }
    }
    return 0; // Not found
}


int main()
{
    int n;
    printf("Enter the number of elements in the array: \n");
    scanf("%d", &n);

    int arr[n], target, choice;
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    do
    {
        printf("\nChoose an option:\n");
        printf("1. Two Sum (Iterative)\n");
        printf("2. Two Sum (Recursive)\n");
        printf("3. Three Sum (Iterative)\n");
        printf("4. Three Sum (Recursive)\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the target sum: ");
            scanf("%d", &target);
            if (!findTwoSum(arr, n, target))
            {
                printf("No elements found with the given sum.\n");
            }
            break;
        case 2:
            printf("Enter the target sum: ");
            scanf("%d", &target);
            if (!findTwoSumRecursive(arr, 0, n - 1, target))
            {
                printf("No elements found with the given sum.\n");
            }
            break;
        case 3:
            printf("Enter the target sum: ");
            scanf("%d", &target);
            if (!findThreeSum(arr, n, target))
            {
                printf("No elements found with the given sum.\n");
            }
            break;
        case 4:
            printf("Enter the target sum: ");
            scanf("%d", &target);
            if (!findThreeSumRecursive(arr, 0, n - 1, target))
            {
                printf("No elements found with the given sum.\n");
            }
            break;
        case 0:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
            break;
        }
    } while (choice != 0);
    return 0;
}