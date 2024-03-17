// C program to delete the middle node of doubly linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void listTraversalDoublyll(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void reverseListTraversalDoublyll(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->prev;
    }
}

void freeList(struct Node *head)
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

void deleteMiddleNode(struct Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        printf("List is too short to delete the middle node.\n");
        return;
    }

    struct Node *slow = head;
    struct Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (slow->prev != NULL) // Delete the middle node (slow)
    {
        slow->prev->next = slow->next;
    }
    if (slow->next != NULL)
    {
        slow->next->prev = slow->prev;
    }
    free(slow);
}

int main()
{
    struct Node *head = NULL;
    struct Node *current = NULL;
    int n;

    printf("Enter the number of nodes: ");
    if (scanf("%d", &n) != 1 || n < 0)
    {
        printf("Invalid input. Exiting...\n");
        return 1;
    }

    for (int i = 0; i < n; ++i)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        if (!newNode)
        {
            printf("Memory allocation failed for node %d!\n", i + 1);
            freeList(head); // Free previously allocated memory
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
    reverseListTraversalDoublyll(head);

    deleteMiddleNode(head);
    printf("\nDoubly Linked List after deleting the middle node:\n");
    listTraversalDoublyll(head);

    freeList(head);
    return 0;
}
