#include <stdio.h>
#include <stdlib.h>

void func(int n) {
    int sum = 0;  // first part of program (consist of constant in time complexity)
    int product = 1;

    for (int i = 0; i < n;i++) {   // second part of code (Will run from 0 values of i to n values)
        for (int j = 0; j < n; j++) { // third part of code (will run from 0 values of j to n values)
            printf("%d, %d\n", i, j);   // Biggest dominant term (KN^2) will get created
        }
    }
}

int main(int argc, char const *argv[])
{
    func(4);
    return 0;
}

/* Time Complexity of the prgram is Tc = O(n^2)  */