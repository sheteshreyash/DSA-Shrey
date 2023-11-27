// Types of Insertion in a Doubly Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;  //Self referencing structure
};

void listTraversalDoublylist(struct Node *head) {  //function for traversal of doubly linked list

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *ptr = head;
    do
    {
        printf("Element is : %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    
}

struct Node *insertAtFirst(struct Node *head, int data) {  // Case 1
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }                 //At this moment, p points to the last node of the circular linked list
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}
void deallocateMemory(struct Node *head)
{
    if (head == NULL)
    {
        return;
    }

    struct Node *current = head;
    struct Node *nextNode;
    do
    {
        nextNode = current->next;
        free(current);
        current = nextNode;
    } while (current != head);
}

int main()
{
    int size;
    printf("Enter the size of the circular linked list: ");
    scanf("%d", &size);

    if (size <= 0)
    {
        printf("Invalid size.\n");
        return 1;
    }

    struct Node *head = NULL;
    struct Node *prevNode = NULL;

    for (int i = 0; i < size; ++i)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter the value for node %d: ", i);
        scanf("%d", &(newNode->data));

        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            prevNode->next = newNode;
        }
        prevNode = newNode;
    }

    if (head != NULL)     // Linking the last node to the head to make it circular (imp step)
    {
        prevNode->next = head;
    }

    printf("\nCircular Linked List created successfully.\n");
    listTraversalDoublylist(head);

    //Case 1 :- Element to be added at the Beginning/first Node 
    int val;
    printf("\n1) Enter the Node Value to be added at Beginning of List : ");
    scanf("%d", &val);
    head = insertAtFirst(head, val);// new element that to be updated at first node
    printf("\nUpdated Circular Linked List after inserting a new node at beginning:\n");
    listTraversalDoublylist(head);
    //

    // Case 2 :- Element to be added at a given index
    //
    deallocateMemory(head);
    return 0;
}

