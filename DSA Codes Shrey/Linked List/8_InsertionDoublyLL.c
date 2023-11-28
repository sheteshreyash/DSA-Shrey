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

// Case 1 : Function to insert a new node at the beginning
struct Node *insertAtBeginningDoublyll(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    newNode->prev = NULL;

    if (head != NULL)
    {
        head->prev = newNode;
    }
    return newNode;
}

// Case 2 : Function to insert a new node at a specific index
struct Node *insertAtIndexDoublyll(struct Node *head, int data, int index)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if (index == 0 || head == NULL)
    {
        newNode->next = head;
        newNode->prev = NULL;

        if (head != NULL)
        {
            head->prev = newNode;
        }
        return newNode;
    }

    struct Node *current = head;
    for (int i = 0; i < index - 1 && current != NULL; ++i)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        // Handle invalid index
        printf("Invalid index. Node not inserted.\n");
        return head;
    }

    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL)
    {
        current->next->prev = newNode;
    }
    current->next = newNode;
    return head;
}

// Case 3 : Function to insert a new node at the end
struct Node *insertAtEndDoublyll(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL;
        return newNode;
    }

    struct Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;

    return head;
}

// Case 4 : Function to insert a new node after a specific node
struct Node *insertAfterNodeDoublyll(struct Node *head, struct Node *prevNode, int data)
{
    if (prevNode == NULL)
    {
        printf("Invalid previous node. Node not inserted.\n");
        return head;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = prevNode->next;
    newNode->prev = prevNode;

    if (prevNode->next != NULL)
    {
        prevNode->next->prev = newNode;
    }
    prevNode->next = newNode;
    return head;
}

// Case 5: Function to update the value of a node at a specific index
struct Node *updateNodeAtIndex(struct Node *head, int newValue, int index)
{
    struct Node *current = head;
    for (int i = 0; i < index && current != NULL; ++i)     // Traverse to the desired index
    {
        current = current->next;
    }

    if (current == NULL)     // to Check if the index is valid
    {
        printf("Invalid index. Node not updated.\n");
        return head;
    }
    current->data = newValue;     // Update the value of the node
    return head;
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

    //Case 1 :- Element to be added at the Beginning/first Node 
    int val, index;
    printf("\n1) Enter the Node Value to be added at Beginning of List : ");
    scanf("%d", &val);
    head = insertAtBeginningDoublyll(head, val);// new element that to be updated at first node
    printf("\nUpdated Doubly Linked List :\n");
    listTraversalDoublyll(head);
    //

    //Case 2 :- Element to be added in between two nodes 
    printf("\n2) Enter the Node Value to be added in between two nodes : ");
    scanf("%d",&val);
    printf("\nEnter Index No : ");
    scanf("%d", &index);
    head = insertAtIndexDoublyll(head, val, index);
    printf("\nUpdated Doubly Linked List after inserting new Element in between two nodes at given index:\n");
    listTraversalDoublyll(head);
    //

    // Case 3 :- Insert Element at the End/Last node in Linked List
    printf("\n3) Enter the Node Value to be inserted at last position : ");
    scanf("%d", &val);
    head = insertAtEndDoublyll(head, val);
    printf("\nUpdated Doubly Linked List after inserting a new node at end:\n");
    listTraversalDoublyll(head);
    //

    // Case 4 :- Insert Element after a Node with Given pointer 
    printf("\n4) Enter the Value to be inserted after a Node : ");
    scanf("%d", &val);
    printf("\nEnter index of the Node after which value is to be inserted : ");
    scanf("%d", &index);

    struct Node *prevNode = head;  // Find the node after which the new node is to be inserted
    for (int i = 0; i < index; ++i) {
        if (prevNode == NULL) {
            printf("Invalid index.\n");
            return 1;
        }
        prevNode = prevNode->next;
    }   
    head = insertAfterNodeDoublyll(head, prevNode, val);
    printf("\nUpdated Doubly Linked List after inserting a new node after a particular node at given index:\n");
    listTraversalDoublyll(head);

    // Case 5: Update the value of a node at a specific index
    printf("\n5) Enter the new value to update at a specific index: ");
    scanf("%d", &val);
    printf("\nEnter the index where the value should be updated: ");
    scanf("%d", &index);
    head = updateNodeAtIndex(head, val, index);

    printf("\nUpdated Doubly Linked List after updating value at a specific index:\n");
    listTraversalDoublyll(head);
    //

    freeList(head);
    return 0;
}
