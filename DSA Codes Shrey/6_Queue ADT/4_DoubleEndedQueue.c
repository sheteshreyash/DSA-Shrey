// C program to Implement Doubly Ended Queue using arrays

#include <stdio.h>
#include <stdlib.h>

struct deque {
    int size;
    int front;
    int rear;
    int* arr;
};

int isEmpty(struct deque* dq) {
    return dq->front == -1 && dq->rear == -1;
}

int isFull(struct deque* dq) {
    return (dq->rear + 1) % dq->size == dq->front;
}

void enqueueFront(struct deque* dq, int val) {
    if (isFull(dq)) {
        printf("Deque is full. Enqueue at front unsuccessful\n");
    } else {
        if (isEmpty(dq)) {
            dq->front = dq->rear = 0; // Initialize front and rear indices when the deque is empty
        } else {
            dq->front = (dq->front - 1 + dq->size) % dq->size; // Circular decrement of front
        }
        dq->arr[dq->front] = val;
        printf("Enqueue at front successful\n");
    }
}

void enqueueRear(struct deque* dq, int val) {
    if (isFull(dq)) {
        printf("Deque is full. Enqueue at rear unsuccessful\n");
    } else {
        if (isEmpty(dq)) {
            dq->front = dq->rear = 0; // Initialize front and rear indices when the deque is empty
        } else {
            dq->rear = (dq->rear + 1) % dq->size; // Circular increment of rear
        }
        dq->arr[dq->rear] = val;
        printf("Enqueue at rear successful\n");
    }
}

int dequeueFront(struct deque* dq) {
    int val = -1;
    if (isEmpty(dq)) {
        printf("Deque is empty. Dequeue from front unsuccessful\n");
    } else {
        val = dq->arr[dq->front];
        if (dq->front == dq->rear) {
            // If the deque becomes empty after dequeue, reset front and rear indices
            dq->front = dq->rear = -1;
        } else {
            dq->front = (dq->front + 1) % dq->size; // Circular increment of front
        }
        printf("Dequeue from front successful\n");
    }
    return val;
}

int dequeueRear(struct deque* dq) {
    int val = -1;
    if (isEmpty(dq)) {
        printf("Deque is empty. Dequeue from rear unsuccessful\n");
    } else {
        val = dq->arr[dq->rear];
        if (dq->front == dq->rear) {
            // If the deque becomes empty after dequeue, reset front and rear indices
            dq->front = dq->rear = -1;
        } else {
            dq->rear = (dq->rear - 1 + dq->size) % dq->size; // Circular decrement of rear
        }
        printf("Dequeue from rear successful\n");
    }
    return val;
}

void peekDeque(struct deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
    } else {
        printf("\nDeque:\n");
        int i = dq->front;
        do {
            printf("Element: %d\n", dq->arr[i]);
            i = (i + 1) % dq->size;
        } while (i != (dq->rear + 1) % dq->size);
    }
}

int main() {
    struct deque* dq = (struct deque*)malloc(sizeof(struct deque)); // Dynamically allocating memory for the deque
    if (dq == NULL) {
        printf("Memory allocation failed. Cannot create Deque\n");
        return -1; // or handle the error appropriately
    }

    printf("Enter the size of Array used for DEQueue: ");
    scanf("%d", &dq->size);

    if (dq->size <= 0) {
        printf("Invalid Deque size. Please enter a positive size.\n");
        free(dq);
        return -1; // or handle the error appropriately
    }

    // Allocating memory for the array inside the deque
    dq->arr = (int*)malloc(dq->size * sizeof(int));

    // Initialize front and rear indices to -1
    dq->front = dq->rear = -1;

    int choice, element;
    while (1) {
        printf("\nDEQueue Operations:\n");
        printf("1. Enqueue at Front\n");
        printf("2. Enqueue at Rear\n");
        printf("3. Dequeue from Front\n");
        printf("4. Dequeue from Rear\n");
        printf("5. Peek Deque\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue at front: ");
                scanf("%d", &element);
                enqueueFront(dq, element);
                break;
            case 2:
                printf("Enter the element to enqueue at rear: ");
                scanf("%d", &element);
                enqueueRear(dq, element);
                break;
            case 3:
                element = dequeueFront(dq);
                if (element != -1) {
                    printf("Dequeued element from front: %d\n", element);
                }
                break;
            case 4:
                element = dequeueRear(dq);
                if (element != -1) {
                    printf("Dequeued element from rear: %d\n", element);
                }
                break;
            case 5:
                peekDeque(dq);
                break;
            case 6:
                // Free the allocated memory before exiting
                free(dq->arr);
                free(dq);
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    return 0;
}

