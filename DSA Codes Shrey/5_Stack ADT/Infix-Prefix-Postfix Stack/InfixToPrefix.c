// C program to convert Infix Expression to Prefix

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
    int size;
    int top;
    char *arr;
};

struct stack *globalStackPointer = NULL;

void cleanup(void) {
    if (globalStackPointer != NULL) {
        free(globalStackPointer->arr);
        free(globalStackPointer);
        globalStackPointer = NULL;
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
        printf("Stack Overflow! Increase the stack size to handle the expression.\n");
        exit(EXIT_FAILURE);
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

char stackTop(struct stack* sp) {
    return sp->arr[sp->top];
}

int precedence(char ch) {
    if(ch == '*' || ch == '/')
        return 3;
    else if(ch == '+' || ch == '-')
        return 2;
    else
        return 0;
}

int isOperator(char ch) {
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 1;
    else
        return 0;
}

char* infixToPrefix(char* infix, int stackSize) {
    // Reverse the infix expression
    int len = strlen(infix);
    char reversedInfix[len + 1];
    for (int i = 0; i < len; i++) {
        reversedInfix[i] = infix[len - i - 1];
    }
    reversedInfix[len] = '\0';

    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = stackSize;
    sp->top = -1;
    sp->arr = (char *) malloc(sp->size * sizeof(char));

    char *prefix = (char *) malloc((len + 1) * sizeof(char));
    int i = 0;
    int j = 0;

    while (reversedInfix[i] != '\0') {
        if (!isOperator(reversedInfix[i])) {
            prefix[j] = reversedInfix[i];
            j++;
            i++;
        } else {
            if (precedence(reversedInfix[i]) >= precedence(stackTop(sp))) {
                push(sp, reversedInfix[i]);
                i++;
            } else {
                prefix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp)) {
        prefix[j] = pop(sp);
        j++;
    }
    prefix[j] = '\0';
    
    len = strlen(prefix);   // Reverse the prefix expression to get the final result
    for (i = 0; i < len / 2; i++) {
        char temp = prefix[i];
        prefix[i] = prefix[len - i - 1];
        prefix[len - i - 1] = temp;
    }
    free(sp->arr);
    free(sp);

    return prefix;
}

int main() {
    char infix[100];
    int stackSize;

    printf("\nConvert Infix Expression to Prefix using Stack\n");
    printf("Enter the expression: ");
    scanf("%s", infix);

    printf("Enter the stack size: ");
    scanf("%d", &stackSize);

    char *prefix = infixToPrefix(infix, stackSize);
    printf("Prefix is %s\n", prefix);

    free(prefix);
    cleanup();

    return 0;
}
