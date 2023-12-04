// Code for Parenthesis matching using Stack

#include <stdio.h>
#include <stdlib.h>

struct stack  // creating structure of stack
{
    int size;
    int top;
    char *arr;   // using character array instead of integer array
};

struct stack *globalStackPointer = NULL;  // Global variable to store the stack pointer

// int isEmpty(struct stack *ptr)
// {
//     if (ptr->top == -1)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

// int isFull(struct stack *ptr)
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

// void push(struct stack* ptr, char val){
//     if(isFull(ptr)){
//         printf("Stack Overflow! Cannot push %d to the stack\n", val);
//     }
//     else{
//         ptr->top++;
//         ptr->arr[ptr->top] = val;
//     }
// }

// char pop(struct stack* ptr){  // pop function will be of char type not void
//     if(isEmpty(ptr)){
//         printf("Stack Underflow! Cannot pop from the stack\n");
//         return -1;
//     }
//     else{
//         char val = ptr->arr[ptr->top];
//         ptr->top--;
//         return val;
//     }
// }

// int parenthesisMatch(char * exp){  // parenthesis matching exp
//     # Create and initialize the stack
//     struct stack* sp;
//     sp->size = 100;
//     sp->top = -1;
//     sp->arr = (char *)malloc(sp->size * sizeof(char));  //new updated statement

//     for (int i = 0; exp[i]!='\0'; i++)
//     {
//         if(exp[i]=='('){
//             push(sp, '(');
//         }
//         else if(exp[i]==')'){
//             if(isEmpty(sp)){
//                 return 0;
//             }
//             pop(sp); 
//         }
//     }

//     if(isEmpty(sp)){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }
// int main()
// {
//     char * exp = "((8)(*--$$9))";
//     // Check if stack is empty
//     if(parenthesisMatch(exp)){
//         printf("The parenthesis is matching");
//     }
//     else{
//         printf("The parenthesis is not matching");
//     }
//     return 0;
// }

void cleanup(void) {
    if (globalStackPointer != NULL) {
        free(globalStackPointer->arr);
        free(globalStackPointer);
    }
}

int isEmpty(struct stack *ptr) {
    return ptr->top == -1;
}

int isFull(struct stack *ptr) {
    return ptr->top == ptr->size - 1;
}

void push(struct stack* ptr, char val) {
    if (isFull(ptr)) {
        printf("Stack Overflow! Cannot push %c to the stack\n", val);
    } else {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack* ptr) {
    if (isEmpty(ptr)) {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return '\0';
    } else {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int parenthesisMatch(char *exp, int stackSize) {
    struct stack *sp = (struct stack*)malloc(sizeof(struct stack));
    sp->size = stackSize;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    // Set the global stack pointer
    globalStackPointer = sp;

    int result = 1;  // Assume parentheses match
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(') {
            push(sp, '(');
        } else if (exp[i] == ')') {
            if (isEmpty(sp)) {
                return 0;  // Unmatched closing parenthesis
                break;
            }
            pop(sp);
        }
    }
    result = result && isEmpty(sp);   // Check if the stack is empty (all parentheses matched)
    return result;
}


int main() {
    char exp[100];
    int stackSize;

    printf("Enter the expression: ");
    scanf("%s", exp);

    printf("Enter the stack size: ");
    scanf("%d", &stackSize);

    if (parenthesisMatch(exp, stackSize)) {
        printf("The parenthesis is matching\n");
    } else {
        printf("The parenthesis is not matching\n");
    }

    cleanup();  // manually free the memory at end
    return 0;
}
