// C program to check the Multiple Parenthesis in a given expression using stack

#include <stdio.h>
#include <stdlib.h>

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

char stackTop(struct stack* sp){  // stacktop function
    return sp->arr[sp->top];
}

int match(char a, char b){
    if(a=='{' && b=='}'){
        return 1;
    }
    if(a=='(' && b==')'){
        return 1;
    }
    if(a=='[' && b==']'){
        return 1;
    }
    return 0;  
}

int parenthesisMatch(char *exp, int stackSize) {
    struct stack *sp = (struct stack*)malloc(sizeof(struct stack));
    sp->size = stackSize;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char popped_ch;

    // Set the global stack pointer
    globalStackPointer = sp;

    int result = 1;  // Assume parentheses match
    for (int i = 0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            push(sp, exp[i]);
        }
        else if(exp[i]==')'|| exp[i]=='}' || exp[i]==']'){
            if(isEmpty(sp)){
                return 0;
            }
            popped_ch = pop(sp);
            if(!match(popped_ch, exp[i])){ 
            return 0;  
            }
        }
    }
    result = result && isEmpty(sp);   // Check if the stack is empty (all parentheses matched)
    return result;
}


int main() {
    char exp[100];
    int stackSize;

    printf("\nMultiple Parenthesis Code \n");
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
