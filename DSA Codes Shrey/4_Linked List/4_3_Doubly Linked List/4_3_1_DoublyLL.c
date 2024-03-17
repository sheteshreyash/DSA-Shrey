// Creation and Traversal(forward and reverse) of doubly linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next; // Pointer to the next node
    struct Node *prev; // Pointer to the previous node
};

void listTraversalDoublyll(struct Node *ptr)  // traversal
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void reverseListTraversalDoublyll(struct Node *ptr)  // reverse traversal
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->prev;
    }
}

void freeList(struct Node *head)  // free allocated memory
{
    struct Node *temp;
    while (head)
    {
        temp = head;
        head = head->next;
        temp->next = NULL;
        temp->prev = NULL;
        free(temp);
    }
}

int main()
{
    struct Node *head = NULL;
    struct Node *current = NULL;
    int n; // Number of nodes

    printf("Enter the number of nodes: ");
    if (scanf("%d", &n) != 1)
    {
        printf("Invalid input. Exiting...\n");
        return 1;
    }

    for (int i = 0; i < n; ++i)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        if (!newNode)
        {
            printf("Memory allocation failed !");
            return 1;
        }

        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        newNode->prev = NULL;

        if (!head)
        {
            head = newNode;
            current = newNode;
        }
        else
        {
            current->next = newNode;
            newNode->prev = current;
            current = newNode;
        }
    }

    printf("\nDoubly Linked List:\n");
    listTraversalDoublyll(head);

    printf("\nReverse traversal of Doubly Linked List:\n");
    reverseListTraversalDoublyll(current); // Start from the last node

    freeList(head);
    return 0;
}
