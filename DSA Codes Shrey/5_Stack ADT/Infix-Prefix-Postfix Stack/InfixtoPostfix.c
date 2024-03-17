// C program to convert Infix Expression to Postfix

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack  // creating structure of stack
{
    int size;
    int top;
    char *arr;   // using character array instead of integer array
};

struct stack *globalStackPointer = NULL;  // Global variable to store the stack pointer

void cleanup(void) {
    if (globalStackPointer != NULL) {
        free(globalStackPointer->arr);
        free(globalStackPointer);
        globalStackPointer = NULL; // Set the global pointer to NULL after freeing
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
        printf("Stack Overflow! Increase the stack size to handle the expression.\n", val);
        exit(EXIT_FAILURE);  // termination of the program
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

char stackTop(struct stack* sp){  // stacktop function
    return sp->arr[sp->top];
}

int precedence(char ch){   // to check the precedence of the operator
    if(ch == '*' || ch=='/')
        return 3;
    else if(ch == '+' || ch=='-')
        return 2; 
    else
        return 0;
}

int isOperator(char ch){   // to define the types of operators function
    if(ch=='+' || ch=='-' ||ch=='*' || ch=='/') 
        return 1;
    else
        return 0;
}

char* infixToPostfix(char* infix, int stackSize){   // infix to postfix function
    struct stack * sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = stackSize; 
    sp->top = -1;
    sp->arr = (char *) malloc(sp->size * sizeof(char));
    char * postfix = (char *) malloc((strlen(infix)+1) * sizeof(char));
    int i=0; // Track infix traversal
    int j = 0; // Track postfix addition 
    while (infix[i]!='\0')
    {
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else{
            if(precedence(infix[i])> precedence(stackTop(sp))){
                push(sp, infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))    
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}


int main() {
    char infix[100];   // char * infix array initialization
    int stackSize;

    printf("\nConvert Infix Expression to Postfix using Stack \n");
    printf("Enter the expression: ");
    scanf("%s", infix);

    printf("Enter the stack size: ");
    scanf("%d", &stackSize);

    char *postfix = infixToPostfix(infix, stackSize);
    printf("postfix is %s", postfix);

    cleanup();  // manually free the memory at end
    free(postfix);
    return 0;
}
