// This is partially implemented code snippet
int isPrime(int n) {
for (int i = 2; i * i < 10000; i++)  // Value of N(10000) doesn't affect the final time required
    {                                // to calculate the output of program
        if (n % i == 0)
            return 0;
    }
    return 1;
}
isPrime(6);

/* Time Complexity Tn = O(1)          */