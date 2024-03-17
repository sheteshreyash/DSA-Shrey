// C code for Implemention of Queue using Linked list

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* f = NULL;  // frontIndex Pointer
struct Node* r = NULL;  // RearIndex Pointer

void enqueue(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Exiting program\n");
        exit(1);
    }
    newNode->data = val;
    newNode->next = NULL;
    if (r == NULL) {
        f = r = newNode;
    } else {
        r->next = newNode;
        r = newNode;
    }
    printf("Enqueue successful\n");
}

int dequeue() {
    int val = -1;
    if (f == NULL) {
        printf("Queue is Empty. Dequeue unsuccessful\n");
    } else {
        struct Node* ptr = f;
        f = f->next;
        val = ptr->data;
        free(ptr);
        printf("Dequeue successful\n");
    }
    return val;
}

void listTraversal() {
    struct Node* ptr = f;
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void freeMemory() {  // free memory
    struct Node* current = f;
    struct Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    f = r = NULL; // Reset front and rear pointers
    printf("Memory freed successfully\n");
}

int main() {

    int choice, data;
    while (1) {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Free Memory and Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                printf("Dequeuing element %d\n", dequeue());
                break;
            case 3:
                printf("\nQueue:\n");
                listTraversal();
                break;
            case 4:
                freeMemory();
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    return 0;
}

// Wanted to add the option for manually reserve nodes in memory and then do enqueue-dequeue operations but its showing errors