/* Consider the recursive algo below, Where the random(int n) spends one unit of time to return
    a random integer which is evenly distributed within the range of [0, n]. If the average 
    processing time is T(n), what is the value of T(6) where other system calls don't take that 
    much time ?                  */

#include <stdio.h>
#include <stdlib.h>

int random(int a) {    // random(6) = will return any number from 0 to 6 not particularly 6 [0,5]
    int i;
    int num = (rand() % (a + 1));
    return num;
}

int function(int n) {
    int i = 0;
    if(n<=0) {
        return 0;
    }
    else {
        i = random(n - 1);
        printf("this\n");
        return function(i) + function(n - 1 - i);
    }
}

int main(int argc, char const *argv[])
{
    function(6);
    return 0;
}

/* Time complexity Tn = O(n)
    therefore T6 = 6         */
