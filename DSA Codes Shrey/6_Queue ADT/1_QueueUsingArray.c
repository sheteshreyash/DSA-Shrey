// C code for Queue implementation of Array

#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int size;
    int f;  // frontInd for Deletion(Dequeue) purpose
    int r;   // RearInd for Insetion(Enqueue) purpose
    int* arr;
};

int isEmpty(struct queue *q) {
    return q->f == -1;
}

int isFull(struct queue *q) {
    return q->r == q->size - 1;
}

void enqueue(struct queue *q, int val) {
    if (isFull(q)) {
        printf("This Queue is full\n");
    }
    else {
        if (isEmpty(q)) {
            q->f = 0; // Initialize front index when the queue is empty
        }
        q->r++;
        q->arr[q->r] = val;
        printf("Enqueued element: %d\n", val);
    }
}

int dequeue(struct queue *q) {
    int a = -1;
    if (isEmpty(q)) {
        printf("This Queue is empty\n");
    }
    else {
        a = q->arr[q->f];
        if (q->f == q->r) {
            // If the queue becomes empty after dequeue, reset front and rear indices
            q->f = q->r = -1;
        }
        else {
            q->f++;
        }
    }
    return a;
}

void peekQueue(struct queue *q) {
    if (isEmpty(q)) {
        printf("This Queue is empty\n");
    }
    else {
        printf("Queue elements: ");
        for (int i = q->f; i <= q->r; i++) {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));  // Dynamically allocating memory for the queue
    if (q == NULL) {
        printf("Memory allocation failed. Cannot create Queue\n");
        return -1; // or handle the error appropriately
    }

    printf("Enter the size of Queue: ");
    scanf("%d", &q->size);

    if (q->size <= 0) {
        printf("Invalid Queue size. Please enter a positive size.\n");
        free(q);
        return -1; // or handle the error appropriately
    }

    // Allocating memory for the array inside the queue
    q->arr = (int*)malloc(q->size * sizeof(int));

    // Initialize front and rear indices to -1
    q->f = q->r = -1;

    int choice, element;
    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek Queue\n");
        printf("4. Quit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &element);
                enqueue(q, element);
                break;
            case 2:
                element = dequeue(q);
                if (element != -1) {
                    printf("Dequeued element: %d\n", element);
                }
                break;
            case 3:
                peekQueue(q);
                break;
            case 4:
                // Free the allocated memory before exiting
                free(q->arr);
                free(q);
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    return 0;
}
