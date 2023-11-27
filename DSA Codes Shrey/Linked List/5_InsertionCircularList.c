// Types of Insertion in a Circular Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;  //Self referencing structure
};

void listTraversalCircularlist(struct Node *head) {  //function for traversal of Circular linked list

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
    } while (ptr != head && ptr != NULL); // Add condition to break if ptr is NULL
}

struct Node *insertAtFirst(struct Node *head, int data) {  // Case 1 : Insert element at first node/beginning
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

struct Node* insertAtIndex(struct Node* head, int data, int index) {  // Case 2 : Insert Element at a given index in Circular LinkedList
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;

    ptr->data = data;     // Insert at the beginning (index 0)
    if (index == 0) {
        ptr->next = head;
        head = ptr;
        return head; // Update the head to point to the new node
    }

    while (i < (index-1) && p->next != head)
    {
        p = p->next;
        i++;
    }

    if (i < (index - 1)) {
        printf("Invalid index.\n");
        free(ptr); // Free the allocated memory if the index is out of bounds
        return head;
    }

    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct Node* insertAtlast(struct Node* head, int data) {  // Case 3 : Insert Element at the end in LinkedList
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    if (head == NULL) {
        ptr->next = ptr; // For an empty list, make the new node point to itself
        head = ptr;
        return head;      // Update the head to point to the new node
    }

    struct Node *p = head;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

struct Node* insertAfterNode(struct Node* head,struct Node *prevNode, int data) {  // Case 4 : Insert Element after a node in Circular LinkedList
    
    if (head == NULL || prevNode == NULL) {
        printf("Invalid arguments.\n");
        return head;
    }
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return head;
    }

    ptr->data = data;
    ptr->next = NULL;
    if (prevNode->next == head) {    // Insert after the last node, making it circular
        ptr->next = head;
        prevNode->next = ptr;
        head = ptr; // update head to the first node 
    }
    else{          // Insert in between nodes
        ptr->next = prevNode->next;
        prevNode->next = ptr;
    }
    return head;
}

void deallocateMemory(struct Node *head) {
    struct Node *current = head;
    struct Node *nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

int main()
{
    int size;
    printf("Enter the size of the Circular linked list: ");
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
    listTraversalCircularlist(head);

    //Case 1 :- Element to be added at the Beginning/first Node 
    int val,index;
    printf("\n1) Enter the Node Value to be added at Beginning of List : ");
    scanf("%d", &val);
    head = insertAtFirst(head, val);// new element that to be updated at first node
    printf("\nUpdated Circular Linked List after inserting a new node at beginning:\n");
    listTraversalCircularlist(head);
    //

    //Case 2 :- Element to be added in between two nodes 
    printf("\n2) Enter the Node Value to be added in between two nodes: ");
    scanf("%d",&val);
    printf("\nEnter Index : ");
    scanf("%d", &index);
    head = insertAtIndex(head, val, index);
    printf("\nUpdated Circular Linked List after inserting new Element in between two nodes at given index:\n");
    listTraversalCircularlist(head);
    //
    // Note :- In this part, we cannot update the already updated head value from case 1 ie. Index 0
    

    // Case 3 :- Insert Element at the End/Last node in Circular Linked List
    printf("\n3) Enter the Node Value to be inserted at last position : ");
    scanf("%d", &val);
    head = insertAtlast(head, val);
    printf("\nUpdated Circular Linked List after inserting a new node at end:\n");
    listTraversalCircularlist(head);
    //

    // Case 4 :- Insert Element after a Node with Given pointer 
    printf("\n4) Enter Element to be inserted after a Node : ");
    scanf("%d", &val);
    printf("\nEnter index of the Node after which value is to be inserted : ");
    scanf("%d", &index);

    for (int i = 0; i < index; ++i) {
        if (prevNode == NULL) {
        printf("Invalid index.\n");
        return 1;
        }
        prevNode = prevNode->next;
    }   
    head = insertAfterNode(head, prevNode, val);
    printf("\nUpdated Circular Linked List after inserting a new node after a particular node at given index:\n");
    listTraversalCircularlist(head);
    //

    deallocateMemory(head);
    return 0;
}

