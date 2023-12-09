// Implementing various cases of Deletion in Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;  //Self referencing structure
};

void listTraversal(struct Node *ptr) {
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node * deleteFirstNode(struct Node * head) {  // Case 1 
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node *deleteAtindex(struct Node *head, int index) {  // Case 2

    if (head == NULL) {
        printf("Linked list is empty. Deletion not possible.\n");
        return NULL;
    }
    struct Node *p = head;
    struct Node *q = head->next;

    if (index == 0) {
        head = deleteFirstNode(head);
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

struct Node *deleteLastNode(struct Node *head) {  // Case 3

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
    printf("Deleted the last element from the linked list.\n");
    return head;
}

struct Node *deleteAtGivenValue(struct Node *head, int value) {  // Case 4

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

void freeMemory(struct Node *head) {  // Function to free the allocated memory
    struct Node *temp;
    while (head != NULL) {
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
            head = newNode;   // If it's the first node, set it as the head
            current = newNode;
        }
        else
        {
            current->next = newNode;     // Link the current node to the new node
            current = newNode;        // Move the current pointer to the new node
        }
    }

    printf("\nLinked List Before Deletion :\n");  // list before deletion 
    listTraversal(head);

    // Case 1 :- Deleting the first element from the linked list
    head = deleteFirstNode(head);
    printf("\n1) Linked List After Deletion of First Node/element :\n");   //list after deletion of first element
    listTraversal(head);
    //


    // Case 2 :- Deleting the element at given index
    int index;
    printf("\nCode for Deletion of Element at Given Index :");
    printf("\nEnter Index No : ");
    scanf("%d", &index);
    head = deleteAtindex(head, index);  
    printf("\n2) Linked List After Deletion of an Element at given Index :\n");
    listTraversal(head); //list after deletion of element at given index
    //


    // Case 3 :- Deleting the last element/node from the linked list
    head = deleteLastNode(head);
    printf("\n3) Linked List After Deletion of Last Element : \n");
    listTraversal(head); //list after deletion of last element
    //


    // Case 4 :- Delete a node with given value from the linked list
    int value;
    printf("\nCode for Deletion of Element with given value :");
    printf("\nEnter the Element : ");
    scanf("%d", &value);
    head = deleteAtGivenValue(head, value);  
    printf("\n4) Linked List After Deletion of an Element with given value :\n");
    listTraversal(head); //list after deletion of element with given value
    //

    freeMemory(head);     // Free the allocated memory
    return 0;
}

