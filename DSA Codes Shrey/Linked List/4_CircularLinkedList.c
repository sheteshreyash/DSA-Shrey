// Creation and Traversal of a Circular Linked List

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
    } while (ptr != head);
    
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
   // Implementation 1 :- Using Hardcoded values 
    // struct Node *head;
    // struct Node *second;
    // struct Node *third;

    // //Dynamically allocate memory for nodes in the linked list in heap
    // head = (struct Node *)malloc(sizeof(struct Node));
    // second = (struct Node *)malloc(sizeof(struct Node));
    // third = (struct Node *)malloc(sizeof(struct Node));

    // //Linking the nodes  
    // head->data = 7;    
    // head->next = second;   //link first and second node
    
    // second->data = 78;    
    // second->next = third;   //link second and third node

    // third->data = 88;    
    // third->next = head;   //Terminate the list at last (third) node

    // listTraversalCircularlist(head); // Head is a pointer of struct node* type



    // Implementation 2: - Creating doubly linked list using dynamic allocation
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

    deallocateMemory(head);
    return 0;
}

