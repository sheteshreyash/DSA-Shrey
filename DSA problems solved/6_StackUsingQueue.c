// Implementation of stack using queue

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Queue Node structure
struct QueueNode
{
    int data;
    struct QueueNode *next;
};

// Queue structure
struct Queue
{
    struct QueueNode *front;
    struct QueueNode *rear;
};

// Stack structure using two queues
struct StackUsingQueues
{
    struct Queue *q1;
    struct Queue *q2;
};

// Function to check if the queue is empty
bool isEmpty(struct Queue *queue)
{
    return queue->front == NULL;
}

// Function to create a new queue node
struct QueueNode *createQueueNode(int data)
{
    struct QueueNode *newNode = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    if (newNode == NULL)
    {
        printf("Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new empty queue
struct Queue *createQueue()
{
    struct Queue *newQueue = (struct Queue *)malloc(sizeof(struct Queue));
    if (newQueue == NULL)
    {
        printf("Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newQueue->front = newQueue->rear = NULL;
    return newQueue;
}

// Function to enqueue a node into the queue
void enqueue(struct Queue *queue, int data)
{
    struct QueueNode *newNode = createQueueNode(data);
    if (queue->rear == NULL)
    {
        queue->front = queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to dequeue a node from the queue
int dequeue(struct Queue *queue)
{
    if (queue->front == NULL)
    {
        printf("Error: Queue is empty.\n");
        exit(EXIT_FAILURE);
    }
    struct QueueNode *temp = queue->front;
    int data = temp->data;
    queue->front = temp->next;
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    free(temp);
    return data;
}

// Function to initialize a stack using two queues
struct StackUsingQueues *createStack()
{
    struct StackUsingQueues *stack = (struct StackUsingQueues *)malloc(sizeof(struct StackUsingQueues));
    if (stack == NULL)
    {
        printf("Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    stack->q1 = createQueue();
    stack->q2 = createQueue();
    return stack;
}

// Function to push an element onto the stack
void push(struct StackUsingQueues *stack, int data)
{
    // Enqueue the new element to q2
    enqueue(stack->q2, data);

    // Dequeue all elements from q1 and enqueue to q2
    while (!isEmpty(stack->q1))
    {
        enqueue(stack->q2, dequeue(stack->q1));
    }

    // Swap q1 and q2
    struct Queue *temp = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = temp;
}

// Function to pop an element from the stack
int pop(struct StackUsingQueues *stack)
{
    if (isEmpty(stack->q1))
    {
        printf("Error: Stack is empty.\n");
        exit(EXIT_FAILURE);
    }
    return dequeue(stack->q1);
}

// Function to display the stack
void display(struct StackUsingQueues *stack)
{
    struct QueueNode *temp = stack->q1->front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to free the memory used by the stack
void freeStack(struct StackUsingQueues *stack)
{
    free(stack->q1);
    free(stack->q2);
    free(stack);
}

int main()
{
    struct StackUsingQueues *stack = createStack();

    int choice, element;
    do
    {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("\nEnter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            // Handle non-integer input
            printf("Invalid input. Please enter a valid integer.\n");
            // Clear the input buffer
            while (getchar() != '\n')
                continue;
            continue;
        }

        switch (choice)
        {
        case 1:
            printf("Enter element to push: ");
            if (scanf("%d", &element) != 1)
            {
                printf("Invalid input for element. Please enter a valid integer.\n");
                // Clear the input buffer
                while (getchar() != '\n')
                    continue;
                break;
            }
            push(stack, element);
            break;
        case 2:
            element = pop(stack);
            if (element != -1)
            {
                printf("Element %d popped from the stack.\n", element);
            }
            break;
        case 3:
            // Peek operation not directly supported in stack using queues
            printf("Peek operation is not supported in a stack using queues.\n");
            break;
        case 4:
            printf("\nStack elements:\n");
            display(stack);
            break;
        case 5:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 5);

    freeStack(stack);
    return 0;
}
