// Various cases of deletion in a doubly linked list

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

struct Node * deleteFirstNodeDoublyll(struct Node * head) {  // Case 1 
    struct Node *ptr = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL; // Set the previous pointer of the new head to NULL
    }
    free(ptr);
    return head;
}

struct Node *deleteAtindexDoublyll(struct Node *head, int index) {  // Case 2

    if (head == NULL) {
        printf("Linked list is empty. Deletion not possible.\n");
        return NULL;
    }
    struct Node *p = head;
    struct Node *q = head->next;

    if (index == 0) {
        head = deleteFirstNodeDoublyll(head);
        return head;
    }
    for (int i = 0; i < index - 1 && p != NULL; i++) {
        p = p->next;
        q = q->next;
    }
    if (p == NULL || q == NULL) {
        printf("Index out of bounds. Deletion not possible.\n");
        return head;
    }
    p->next = q->next;
    free(q);
    printf("Deleted element at index %d from the linked list.\n", index);
    return head;
}

struct Node *deleteLastNodeDoublyll(struct Node *head) {  // Case 3

    if (head == NULL) {
        printf("Linked list is empty \n");
        return NULL;
    }
    struct Node *p = head;
    struct Node *q = head->next;

    while (q->next != NULL) {
        p = p->next;
        q = q->next;
    }
    if (p == NULL || q == NULL) {
        printf("Index out of bounds. Deletion not possible.\n");
        return head;
    }
    p->next = NULL;
    free(q);
    printf("\n3) Deleted the last element from the linked list.\n");
    return head;
}

struct Node *deleteAtGivenValueDoublyll(struct Node *head, int value) {  // Case 4

    if (head == NULL) {
        printf("Linked list is empty. Deletion not possible.\n");
        return NULL;
    }
    struct Node *p = head;
    struct Node *q = head->next;

    while(q->data !=value && q->next != NULL){
        p = p->next;
        q = q->next;
    }
    if (p == NULL || q == NULL) {
        printf("Index out of bounds. Deletion not possible.\n");
        return head;
    }
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
        printf("Deleted element with value %d from the linked list.\n", value);
    }
    else {
        printf("Element with value %d does not exist in the linked list.\n", value);
    }
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
    if (scanf("%d", &n) != 1 || n<=0)
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

        // Case 1 :- Deleting the first element from the linked list
    head = deleteFirstNodeDoublyll(head);
    printf("\n1) Linked List After Deletion of First Node/element :\n");   //list after deletion of first element
    listTraversalDoublyll(head);
    //


    // Case 2 :- Deleting the element at given index
    int index;
    printf("\n2) Code for Deletion of Element at Given Index :");
    printf("\nEnter Index No : ");
    scanf("%d", &index);
    head = deleteAtindexDoublyll(head, index);  
    printf("Linked List After Deletion of an Element at given Index :\n");
    listTraversalDoublyll(head); //list after deletion of element at given index
    //


    // Case 3 :- Deleting the last element/node from the linked list
    head = deleteLastNodeDoublyll(head);
    printf("Linked List After Deletion of Last Element : \n");
    listTraversalDoublyll(head); //list after deletion of last element
    //


    // Case 4 :- Delete a node with given value from the linked list
    int value;
    printf("\n4) Code for Deletion of Element with given value ");
    printf("\nEnter the Element : ");
    scanf("%d", &value);
    head = deleteAtGivenValueDoublyll(head, value);  
    printf("\nLinked List After Deletion of an Element with given value :\n");
    listTraversalDoublyll(head); //list after deletion of element with given value
    //

    freeList(head);
    return 0;
}
