// Implementation of Stack using Array with push(), pop() and peek() operations

#include <stdio.h>
#include <stdlib.h>

struct stack  // this is a stack structure consist of array size, top value and pointer to array
{
    int size;  // Size of array for Stack Creation
    int top;
    int *arr;
};

// int isStackEmpty(struct stack *ptr)  // Check if the stack is empty or not
// {
//     if (ptr->top == -1){
//         return 1;
//     }
//     else{   // not required
//         return 0;
//     }
// }

// int isStackFull(struct stack *ptr)  // Check if the stack is full or not
// {
//     if (ptr->top == ptr->size - 1)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

#define EMPTY -1
int isStackEmpty(struct stack *ptr) {  // Check if the stack is empty (Updated)
    return (ptr->top == EMPTY);
}

int isStackFull(struct stack *ptr) {   // Check if the stack is full (Updated)
    return (ptr->top == ptr->size - 1);
}

void pushIntoStack(struct stack *ptr, int value) {  //Push function
    if (isStackFull(ptr)) {
        printf("Stack Overflow. Cannot push %d\n", value);
    } else {
        ptr->top++;
        ptr->arr[ptr->top] = value;
        printf("%d pushed to the stack\n", value);
    }
}

int popFromStack(struct stack *ptr) {  // Pop function
    if (isStackEmpty(ptr)) {
        printf("Stack Underflow. Cannot pop from an empty stack\n");
        return -1; // Assuming -1 as an error value
    } else {
        int popped = ptr->arr[ptr->top];
        ptr->top--;
        return popped;
    }
}

void printStack(struct stack *ptr) {  // function for printing stack
    for (int i = 0; i <= ptr->top; i++) {
        printf("%d ", ptr->arr[i]);
    }
    printf("\n");
}

int peekStack(struct stack *ptr, int position) {   // peek stack function
    if (isStackEmpty(ptr) || position < 0 || position > ptr->top) {
        printf("Invalid position to peek\n");
        return -1; // Assuming -1 as an error value
    } else {
        return ptr->arr[ptr->top - position];
    }
}    

int stackTop(struct stack *ptr) {   // Function to get the top element of the stack
    if (isStackEmpty(ptr)) {
        printf("Stack is empty\n");
        return -1; // Assuming -1 as an error value
    } else {
        return ptr->arr[ptr->top];
    }
}

int stackBottom(struct stack *ptr) {  // Function to get the bottom element of the stack
    if (isStackEmpty(ptr)) {
        printf("Stack is empty\n");
        return -1; // Assuming -1 as an error value
    } else {
        return ptr->arr[0];
    }
}

int main(int argc, char const *argv[])
{
    // struct stack s;  // here s was stack structure
    // s.size = 80;
    // s.top = -1; // Top is empty
    // s.arr = (int *)malloc(s.size * sizeof(int));

    // struct stack *s;   // here s is pointer of stack structure which can be useful further like we can give it to the various functions
    // s->size = 80;  // I want this stack size value from user at runtime
    // s->top = -1; // Top is empty
    // s->arr = (int *)malloc(s->size * sizeof(int));
    
    // s->arr[0] = 7;  //Pushing an element manually 
    // s->top++;

    // if(isStackEmpty(s)){        // Implementation of isEmpty function
    //     printf("The stack is empty");
    // }
    // else{
    //     printf("The stack is not empty");
    // }

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));  // Dynamically allocating *s memory into heap 
    if (s == NULL) {
    printf("Memory allocation failed. Cannot Create Stack\n");
    return -1; // or handle the error appropriately
    }

    printf("Enter the size of the stack: ");
    scanf("%d", &s->size);

    if (s->size <= 0) {
    printf("Invalid stack size. Please enter a positive size.\n");
    free(s);
    return -1; // or handle the error appropriately
    }

    s->top = -1;  // Top value is empty
    s->arr = (int *)malloc(s->size * sizeof(int));

    for (int i = 0; i < s->size; i++) {     // Pushing elements to the stack
        int element;
        printf("\nEnter element %d: ", i + 1);
        scanf("%d", &element);
        pushIntoStack(s, element);
    }

    printf("\n1) Original Stack : \n");   
    printStack(s);   // Original stack


    printf("\n2) Peek operation:\n");    // Peek operations
    int peekPosition;
    printf("Enter the position to peek (0 for top): ");
    scanf("%d", &peekPosition);

    if (!isStackEmpty(s)) {
        int peekedElement = peekStack(s, peekPosition);
        if (peekedElement != -1) {
            printf("\nElement at position %d is: %d\n", peekPosition, peekedElement);
        }
    }


    printf("\n3) Pop operations:\n");       // Popping elements from the stack
    int popOption;
    do {
    printf("\nEnter 1 to pop the topmost element ");
    printf("\nPress 0 to Exit..");
    printf("\nEnter Value : ");
    scanf("%d", &popOption);

    if (popOption == 1) {
        if (!isStackEmpty(s)) {  // Check if the stack is not empty before popping
            int poppedElement = popFromStack(s);
            printf("\n%d popped from the stack\n", poppedElement);
            
            if (!isStackEmpty(s)) {               // Check if the stack is not empty before printing
                printf("\nUpdated Stack : \n");
                printStack(s);
            } else {
                printf("\nStack is Empty\n");
                }
            } 
        } 
        else if(popOption != 0) {
        printf("Invalid Option. Press 1 or 0\n");
        }
    } while (popOption != 0 && !isStackEmpty(s));

    printf("\nStack After Pop Operations : \n");
    if (isStackEmpty(s)) {
    printf("Stack is Empty\n");
    } else {
    printStack(s);   // Updated stack
    }

    printf("\n4) Top and Bottom of the stack..");
    printf("\nTop Element of the Stack: %d\n", stackTop(s));
    printf("Bottom Element of the Stack: %d\n", stackBottom(s));
    
    free(s->arr);
    free(s);
    s = NULL;

    return 0;
}
