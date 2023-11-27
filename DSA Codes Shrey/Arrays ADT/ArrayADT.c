// Implementation of ADT for an Abstract Array using Structure and pointer

#include <stdio.h>
#include <stdlib.h>  

struct myArray   // this is abstract data type of array
{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct myArray * a, int tSize, int uSize) {  // *a is a pointer, so it will accept an address
    (*a).total_size = tSize; //(*a) is being dereferenced
    (*a).used_size = uSize;   // if we want Structure from given address, we use (* = Value at operator)
    (*a).ptr = (int *)malloc(tSize * sizeof(int)); // malloc allocates memory in heap section


    //Shortcut Method ->
    // a->total_size = tSize; 
    // a->used_size = uSize;  
    // a->ptr = (int *)malloc(tSize * sizeof(int));

}  // We can't use constructor in C unlike java and Cpp, so here we used a function/method

void show(struct myArray * a) {   // to create an array
    for (int i = 0; i < ((*a).used_size); i++)
    {
        printf("%d ", (*a).ptr[i]);
    }
    printf(" \n ");
}
void setVal(struct myArray * a) {   // to print the values

    int n;
    for (int i = 0; i < ((*a).used_size); i++)
    {
        printf("Enter Array Elements : %d  ", i);
        scanf("%d", &n);
        (*a).ptr[i] = n;
    }
}

void deleteArray(struct myArray* a) {
    free((*a).ptr); // Free the dynamically allocated memory
}
int main(int argc, char const *argv[])
{
    struct myArray marks;
    createArray(&marks, 10, 2);  // if we want address from given structure, we use (& = address at operator)

    printf("We are using 'setVal' now\n");
    setVal(&marks);

    printf("We are using 'show' now\n");
    show(&marks);

    deleteArray(&marks); // Free the dynamically allocated memory when you're done with the array
    return 0;
}
