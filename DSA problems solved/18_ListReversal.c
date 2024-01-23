// C program that reverses a linked list in groups of a given size

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void listTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *reverseInGroups(struct Node *head, int k)
{
    struct Node *current = head;
    struct Node *next = NULL;
    struct Node *prev = NULL;
    int count = 0;

    struct Node *temp = head;
    while (temp != NULL && count < k) // Count the number of nodes in the current group
    {
        temp = temp->next;
        count++;
    }

    if (count == k) // If there are enough nodes in the current group, reverse them
    {
        count = 0;
        while (current != NULL && count < k)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }
        if (next != NULL) // Recursively call for the remaining nodes
        {
            head->next = reverseInGroups(next, k);
        }
        return prev; // 'prev' is now the new head of the reversed group
    }
    return head; // If there are fewer than k nodes in the current group, return the head as is
}

void freeMemory(struct Node *head)
{
    struct Node *temp;
    while (head)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    struct Node *head = NULL;
    struct Node *current = NULL;
    int n; // Number of nodes

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

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

        if (!head)
        {
            head = newNode;
            current = newNode;
        }
        else
        {
            current->next = newNode;
            current = newNode;
        }
    }

    printf("\nOriginal Linked List:\n");
    listTraversal(head);

    int groupSize;
    printf("\nEnter the size of groups for reversal: ");
    scanf("%d", &groupSize);

    head = reverseInGroups(head, groupSize);
    printf("\nReversed Linked List in Groups:\n");
    listTraversal(head);

    freeMemory(head);
    return 0;
}
