// Various cases of Insertion in a Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;  //Self referencing structure
};

void listTraversal(struct Node *ptr) {  //List Traversal
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node* insertAtfirst(struct Node* head, int data) {  // 1 Insert Element at first in LinkedList
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = head;
    return ptr;
}

struct Node* insertAtIndex(struct Node* head, int data, int index) {  // 2 Insert Element at a given index in LinkedList
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;

    if (index == 0) {
        ptr->data = data;
        ptr->next = head;
        return ptr; // Update the head to point to the new node
    }

    while (i !=(index-1))
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct Node* insertAtlast(struct Node* head, int data) {  // 3 Insert Element at the end in LinkedList
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

struct Node* insertAfterNode(struct Node* head,struct Node *prevNode, int data) {  // 4 Insert Element after a node in LinkedList
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

int main()
{
    struct Node *head = NULL;
    struct Node *current = NULL;
    int n; // Number of nodes

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)  // Input data for each node
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
            head = newNode;  // If it's the first node, set it as the head
            current = newNode;
        }
        else
        {
            current->next = newNode;    // Link the current node to the new node
            current = newNode;          // Move the current pointer to the new node
        }
    }

    printf("\nLinked List:\n");  // Traverse and print the linked list
    listTraversal(head);

    //Case 1 :- Element to be added at the Beginning/first Node
    int val, index;
    printf("\n1) Enter the Node Value to be added at Beginning of List : ");
    scanf("%d", &val);
    head = insertAtfirst(head, val);// new element that to be updated at first node
    printf("\nUpdated Linked List after inserting a new node at beginning:\n");
    listTraversal(head);
    //

    //Case 2 :- Element to be added in between two nodes
    printf("\n2) Enter the Node Value to be added in between two nodes : ");
    scanf("%d",&val);
    printf("\nEnter Index No : ");
    scanf("%d", &index);
    head = insertAtIndex(head, val, index);
    printf("\nUpdated Linked List after inserting new Element in between two nodes at given index:\n");
    listTraversal(head);
    //

    // Case 3 :- Insert Element at the End/Last node in Linked List
    printf("\n3) Enter the Node Value to be inserted at last position : ");
    scanf("%d", &val);
    head = insertAtlast(head, val);
    printf("\nUpdated Linked List after inserting a new node at end:\n");
    listTraversal(head);
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
    head = insertAfterNode(head, prevNode, val);
    printf("\nUpdated Linked List after inserting a new node after a particular node at given index:\n");
    listTraversal(head);
    //

    // Free the allocated memory
    struct Node *temp;
    while (head)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}

