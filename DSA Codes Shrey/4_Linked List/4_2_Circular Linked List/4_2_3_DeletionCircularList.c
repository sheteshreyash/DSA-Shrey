// Various cases of Deletion in Circular Linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;  //Self referencing Structure
};

void listTraversalCircularll(struct Node *head)  //List traversal
{
    struct Node *ptr = head;
    if (head != NULL)
    {
        do
        {
            printf("Element: %d\n", ptr->data);
            ptr = ptr->next;
        } while (ptr != head);
    }
}

struct Node *deleteFirstNodeCircularll(struct Node *head)  // Case 1
{
    if (head == NULL)
    {
        printf("Circular Linked list is empty.\n");
        return NULL;
    }

    struct Node *ptr = head;
    struct Node *temp = head;

    while (ptr->next != head)
    {
        ptr = ptr->next;
    }

    if (ptr == head) // Only one node in the list
    {
        free(ptr);
        return NULL;
    }

    ptr->next = head->next;
    head = head->next;
    free(temp);

    printf("Deleted the first element from the Circular linked list.\n");
    return head;
}

struct Node *deleteAtindexCircularll(struct Node *head, int index) // Case 2
{
    if (head == NULL)
    {
        printf("Linked list is empty. Deletion not possible.\n");
        return NULL;
    }

    if (index == 0)
    {
        return deleteFirstNodeCircularll(head);
    }

    struct Node *p = head;
    struct Node *q = head->next;

    for (int i = 0; i < index - 1 && q != head; i++)
    {
        p = p->next;
        q = q->next;
    }

    if (q == head)
    {
        printf("Index out of bounds.\n");
        return head;
    }

    p->next = q->next;
    free(q);

    printf("Deleted element at index %d from the Circular linked list.\n", index);
    return head;
}

struct Node *deleteLastNodeCircularll(struct Node *head)  // Case 3
{
    if (head == NULL)
    {
        printf("Linked list is empty.\n");
        return NULL;
    }

    struct Node *p = head;
    struct Node *q = head->next;

    if (p == head && q == head) // Only one node in the list
    {
        free(p);
        return NULL;
    }

    while (q->next != head)
    {
        p = p->next;
        q = q->next;
    }

    p->next = head; // Update the last node to point to the first node
    free(q);

    printf("Deleted the last element from the circular linked list.\n");
    return head;
}

struct Node *deleteAtGivenValueCircularll(struct Node *head, int value) // Case 4
{
    if (head == NULL)
    {
        printf("Linked list is empty. Deletion not possible.\n");
        return NULL;
    }

    struct Node *p = head;
    struct Node *q = head->next;

    if (p->data == value) // Check if the value to be deleted is in the first node
    {
        return deleteFirstNodeCircularll(head);
    }

    while (q != head && q->data != value)
    {
        p = p->next;
        q = q->next;
    }

    if (q == head)
    {
        printf("\nElement with value %d does not exist in the circular linked list.\n", value);
        return head;
    }

    p->next = q->next;
    free(q);

    printf("\nDeleted element with value %d from the circular linked list.", value);
    return head;
}


void freeMemory(struct Node *head)
{
    struct Node *temp;

    if (head != NULL)
    {
        do
        {
            temp = head;
            head = head->next;
            free(temp);
        } while (head != NULL);
    }
}

int main()
{
    struct Node *head = NULL;
    struct Node *current = NULL;
    int n; // Number of nodes

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) // Input data for each node
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
            head = newNode; // If it's the first node, set it as the head
            current = newNode;
        }
        else
        {
            current->next = newNode; // Link the current node to the new node
            current = newNode;       // Move the current pointer to the new node
        }
    }

    if (head != NULL)
    {
        current->next = head; // Make the last node point back to the first node
    }

    printf("\nCircular Linked List :\n");
    listTraversalCircularll(head);

    // Case 1: Deleting the first element from the circular linked list
    printf("\n1) Code for Deletion of first node\n");
    head = deleteFirstNodeCircularll(head);
    printf("Circular Linked List After Deletion of First Node:\n");
    listTraversalCircularll(head);

    // Case 2: Deleting the element at given index
    int index;
    printf("\n2) Code for Deletion of Element at Given Index:\n");
    printf("Enter Index No: ");
    scanf("%d", &index);
    head = deleteAtindexCircularll(head, index);
    printf("\nCircular Linked List After Deletion of an Element at given Index:\n");
    listTraversalCircularll(head);

    // Case 3: Deleting the last element/node from the circular linked list
    printf("\n3) Code for Deletion of last node\n");
    head = deleteLastNodeCircularll(head);
    printf("\nCircular Linked List After Deletion of Last Element:\n");
    listTraversalCircularll(head);
    //

    // Case 4 :- Delete a node with given value from the linked list
    int value;
    printf("\n4) Code for Deletion of Element with given value :");
    printf("\nEnter the Element : ");
    scanf("%d", &value);
    head = deleteAtGivenValueCircularll(head, value);  
    printf("Linked List After Deletion of an Element with given value :\n");
    listTraversalCircularll(head); //list after deletion of element with given value
    //

    freeMemory(head); // Free the allocated memory
    return 0;
}
