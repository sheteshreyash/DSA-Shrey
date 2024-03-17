// Given an array arr[] of size N,
// the task is to find the length of the Longest Increasing Subsequence (LIS) i.e.,
// the longest possible subsequence in which the elements of the subsequence are sorted in increasing order.


// Examples:

// Input: arr[] = {3, 10, 2, 1, 20}
// Output: 3
// Explanation: The longest increasing subsequence is 3, 10, 20

// Input: arr[] = {3, 2}
// Output:1
// Explanation: The longest increasing subsequences are {3} and {2}

// Input: arr[] = {50, 3, 10, 7, 40, 80}
// Output: 4
// Explanation: The longest increasing subsequence is {3, 7, 40, 80}



// Longest Increasing Sequence using Recursion:
// The problem can be solved based on the following idea:

// Let L(i) be the length of the LIS ending at index i such that arr[i] is the last element of the LIS.
//  Then, L(i) can be recursively written as:

// L(i) = 1 + max(L(j) ) where 0 < j < i and arr[j] < arr[i]; or
// L(i) = 1, if no such j exists.
// Formally, the length of LIS ending at index i, is 1 greater than the maximum of lengths
// of all LIS ending at some index j such that arr[j] < arr[i] where j < i.



// Follow the steps mentioned below to implement the above idea:

// Create a recursive function.
// For each recursive call, Iterate from the i = 1 to the current position and do the following:
// Find the possible length of the longest increasing subsequence ending at the current position
// if the previous sequence ended at i.
// Update the maximum possible length accordingly.
// Repeat this for all indices and find the answer




import java.util.Arrays;
import java.util.Scanner;

class LIS {
    static int lis(int arr[], int n) {
        int[] tails = new int[n];
        int len = 1;
        tails[0] = arr[0];

        for (int i = 1; i < n; i++) {
            if (arr[i] < tails[0]) {
                tails[0] = arr[i];
            } else if (arr[i] > tails[len - 1]) {
                tails[len++] = arr[i];
            } else {
                int idx = Arrays.binarySearch(tails, 0, len, arr[i]);
                if (idx < 0) {
                    idx = -idx - 1;
                }
                tails[idx] = arr[i];
            }
        }
        return len;
    }

    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the size of the array: \n");
        int n = scanner.nextInt();

        int arr[] = new int[n];
        System.out.print("Enter the elements of the array: \n");
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        scanner.close();
        System.out.println("Length of LIS is " + lis(arr, n));
    }
}


// time complexity for above algorithm is O(nlogn) and space complexity is O(n)
// above algorithm uses binary search approach