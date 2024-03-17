// Given two strings, S1 and S2,
// the task is to find the length of the Longest Common Subsequence
// i.e. longest subsequence present in both of the strings

// A longest common subsequence (LCS) is defined as the longest subsequence which is
// common in all given input sequences.



// Examples:

// Input: S1 = “AGGTAB”, S2 = “GXTXAYB”
// Output: 4
// Explanation: The longest subsequence which is present in both strings is “GTAB”.

// Input: S1 = “BD”, S2 = “ABCD”
// Output: 2
// Explanation: The longest subsequence which is present in both strings is “BD”.


// Follow the below steps to implement the idea:

// Create a recursive function [say lcs()].
// Check the relation between the First characters of the strings that are not yet processed.
// Depending on the relation call the next recursive function as mentioned above.
// Return the length of the LCS received as the answer.


import java.util.Scanner;

public class LCS {

    // Returns length of LCS for X[0..m-1], Y[0..n-1]
    int lcs(String X, String Y, int m, int n, int[][] memo) {
        if (m == 0 || n == 0)
            return 0;

        // Check if result is already calculated
        if (memo[m][n] != -1)
            return memo[m][n];

        if (X.charAt(m - 1) == Y.charAt(n - 1))
            return memo[m][n] = 1 + lcs(X, Y, m - 1, n - 1, memo);
        else
            return memo[m][n] = max(lcs(X, Y, m, n - 1, memo),
                    lcs(X, Y, m - 1, n, memo));
    }

    // Utility function to get max of 2 integers
    int max(int a, int b) {
        return (a > b) ? a : b;
    }

    public static void main(String[] args) {
        LCS lcs = new LCS();
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the first string: ");
        String S1 = scanner.nextLine();

        System.out.print("Enter the second string: ");
        String S2 = scanner.nextLine();

        int m = S1.length();
        int n = S2.length();

        // Memoization array to store intermediate results
        int[][] memo = new int[m + 1][n + 1];

        // Initialize memoization array with -1
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                memo[i][j] = -1;
            }
        }
        System.out.println("Length of LCS is " + lcs.lcs(S1, S2, m, n, memo));
        scanner.close();
    }
}



// This is optimized version of the LCS, the memo array is used to store intermediate results.
// Before making a recursive call, the program checks whether the result for the given
// parameters is already calculated. If so, it directly returns the stored result,
// avoiding redundant calculations. This memoization technique reduces time complexity
// and improves the overall efficiency of the algorithm.

