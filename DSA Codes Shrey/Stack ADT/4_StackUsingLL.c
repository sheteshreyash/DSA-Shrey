// Minor Updations with all stack operations using linked list

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;  // top should be declared globally 

void stackLLTraversal(struct Node* ptr) {
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

bool isStackEmpty(struct Node* top) {
    return top == NULL;
}

bool isStackFull(int size) {
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    if (p == NULL) {
        printf("Error: Memory allocation failed.\n");
        return true;  // Considered full due to allocation failure
    } else {
        free(p);
        int count = 0;
        struct Node* temp = top;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count >= size;
    }
}

int stackTop() {
    if (!isStackEmpty(top)) {
        return top->data;
    } else {
        printf("Stack is empty.\n");
        return -1; // indicate error
    }
}

struct Node* push(int x, int size) {
    if (x < 0) {
        printf("Error: Cannot push negative numbers onto the stack.\n");
    } else if (isStackFull(size)) {
        printf("Error: Stack Overflow. Element %d could not be pushed into the stack.\n", x);
    } else {
        struct Node* n = (struct Node*)malloc(sizeof(struct Node));
        if (n == NULL) {
            printf("Error: Memory allocation failed. Element %d could not be pushed into the stack.\n", x);
        } else {
            n->data = x;
            n->next = top;
            top = n;
            printf("Element %d pushed into the stack.\n", x);
        }
    }
    return top;
}

int pop(int size) {
    if (isStackEmpty(top)) {
        printf("Error: Stack Underflow. Cannot pop from an empty stack.\n");
        return -1; // indicate error
    } else {
        struct Node* n = top;
        top = top->next;
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
    } else {
        printf("Invalid position\n");
        return -1; // indicate error
    }
}

void freeMemory(struct Node* top) {
    struct Node* temp;
    while (top != NULL) {
        temp = top;
        top = top->next;
        free(temp);
    }
}

int main() {
    int size;
    printf("Enter the size of the stack: ");
    scanf("%d", &size);

    int choice, element;
    do {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                top = push(element, size);
                break;
            case 2:
                element = pop(size);
                if (element != -1) {
                    printf("Element %d popped from the stack.\n", element);
                }
                break;
            case 3:
                printf("Enter position to peek: ");
                scanf("%d", &element);
                printf("Value at position %d is: %d\n", element, peek(element));
                break;
            case 4:
                printf("\nStack elements:\n");
                stackLLTraversal(top);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    freeMemory(top);

    return 0;
}
