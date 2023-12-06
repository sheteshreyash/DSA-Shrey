// CWH code for various push(), pop(), peek() and stackTop() operations of the stack


#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void stackLLTraversal(struct Node* ptr) {
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isStackEmpty(struct Node* top) {
    return top == NULL;
}

int isStackFull(struct Node* top) {
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    if (p == NULL) {
        free(p); // free the allocated memory
        return 1;
    }
    else {
        free(p); // free the allocated memory
        return 0;
    }
}

struct Node* top = NULL;
int stackTop() {
    if (!isStackEmpty(top)) {
        return top->data;
    }
    else {
        printf("Stack is empty.\n");
        return -1; // indicate error
    }
}

struct Node* push(struct Node* top, int x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    if (n == NULL) {
        printf("Stack Overflow\n");
    }
    else {
        n->data = x;
        n->next = top;
        top = n;
    }
    return top;
}

int pop(struct Node** top) {
    if (isStackEmpty(*top)) {
        printf("Stack Underflow\n");
        return -1; // indicate error
    }
    else {
        struct Node* n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int peek(int pos) {
    struct Node* ptr = top;
    for (int i = 0; i < pos - 1 && ptr != NULL; i++) {
        ptr = ptr->next;
    }
    if (ptr != NULL) {
        return ptr->data;
    }
    else {
        printf("Invalid position\n");
        return -1; // indicate error
    }
}

int main() {
    // 1: push() operations
    top = push(top, 78);
    top = push(top, 7);
    top = push(top, 8);
    stackLLTraversal(top);

    // 2: pop() operations
    int element = pop(&top);
    printf("Popped element is %d\n", element);
    stackLLTraversal(top);

    // 3: stackTop() operations
    int topElement = stackTop();
    if (topElement != -1) {
        printf("Element at the top of the stack: %d\n", topElement);
    }

    // 4: peek() operation
    top = push(top, 28);
    top = push(top, 18);
    top = push(top, 15);
    top = push(top, 7);

    for (int i = 1; i <= 7; i++) {
        printf("Value at position %d is: %d\n", i, peek(i));
    }
    stackLLTraversal(top);

    return 0;
}
