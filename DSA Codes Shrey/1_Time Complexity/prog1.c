#include <stdio.h>
#include <stdlib.h>

void func1(int array[], int length)  {
    int sum = 0;
    int product = 1; //1

    for (int i = 0; i < length;i++) {  //2
        sum += array[i];
    }
    for (int i = 0; i < length;i++) {   //3
        product *= array[i];
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {3, 5, 66};
    func1(arr, 3);
    return 0;
}

/* We will split this program into 3 parts, first one is int, second is for loop and third is
another for loop  */

/*   Tn = k1 + k2N + k3N which will automatically considered as N
    therefore the time complexity will be Tc = O(length)
*/