// C program for merging two sorted linked lists

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

struct Node *mergeSortedLists(struct Node *list1, struct Node *list2)
{
    struct Node *mergedList = NULL;
    struct Node *tail = NULL;

    while (list1 != NULL && list2 != NULL)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

        if (!newNode)
        {
            printf("Memory allocation failed!");
            exit(1);
        }

        if (list1->data <= list2->data)
        {
            newNode->data = list1->data;
            list1 = list1->next;
        }
        else
        {
            newNode->data = list2->data;
            list2 = list2->next;
        }

        newNode->next = NULL;
        if (mergedList == NULL)
        {
            mergedList = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // If one of the lists is not empty, append the remaining nodes
    if (list1 != NULL)
    {
        if (tail == NULL)
        {
            mergedList = list1;
        }
        else
        {
            tail->next = list1;
        }
    }

    if (list2 != NULL)
    {
        if (tail == NULL)
        {
            mergedList = list2;
        }
        else
        {
            tail->next = list2;
        }
    }
    return mergedList;
}

int main()
{
    struct Node *list1 = NULL;
    struct Node *list2 = NULL;
    struct Node *current = NULL;
    int n1, n2; // Number of nodes for list1 and list2
    printf("Enter the number of nodes for list1: ");
    scanf("%d", &n1);

    for (int i = 0; i < n1; ++i)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        if (!newNode)
        {
            printf("Memory allocation failed!");
            return 1;
        }

        printf("Enter data for node %d in list1: ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (!list1)
        {
            list1 = newNode;
            current = newNode;
        }
        else
        {
            current->next = newNode;
            current = newNode;
        }
    }

    printf("\nEnter the number of nodes for list2: ");
    scanf("%d", &n2);

    for (int i = 0; i < n2; ++i)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        if (!newNode)
        {
            printf("Memory allocation failed!");
            freeMemory(list1); // Free memory before exiting
            return 1;
        }

        printf("Enter data for node %d in list2: ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (!list2)
        {
            list2 = newNode;
            current = newNode;
        }
        else
        {
            current->next = newNode;
            current = newNode;
        }
    }

    printf("\nList 1:\n");
    listTraversal(list1);

    printf("\nList 2:\n");
    listTraversal(list2);

    struct Node *mergedList = mergeSortedLists(list1, list2); // Merge two sorted lists
    printf("\nMerged List:\n");
    listTraversal(mergedList);

    freeMemory(list1);
    freeMemory(list2);
    freeMemory(mergedList);
    return 0;
}
