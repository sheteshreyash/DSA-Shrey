// Find the time complexity of following code which tests whether a given number is prime or not

// This is a partially implemented code snippet
int isPrime(int n)
{
    if (n == 1)
    {
        return 0;  // this is first part of code K1
    }

    for (int i = 2; i * i < n; i++)  // This is second part of code K2 * rt2
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

/* Time Complexity Tc = O(n^(1/2))               */