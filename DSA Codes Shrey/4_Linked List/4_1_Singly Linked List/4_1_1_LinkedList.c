// Creation and Traversal of Linked List

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
int main()
{
    //Implementation 1 :- Using Hardcoded values 
    // struct Node *head;
    // struct Node *second;
    // struct Node *third;

    //Dynamically allocate memory for nodes in the linked list in heap
    // head = (struct Node *)malloc(sizeof(struct Node));
    // second = (struct Node *)malloc(sizeof(struct Node));
    // third = (struct Node *)malloc(sizeof(struct Node));

    //Linking the nodes  
    // head->data = 7;    
    // head->next = second;   //link first and second node
    
    // second->data = 78;    
    // second->next = third;   //link second and third node

    // third->data = 88;    
    // third->next = NULL;   //Terminate the list at last (third) node

    // listTraversal(head); // Head is a pointer of struct node* type



    // Implementation 2 :- Using values for user 
    struct Node *head = NULL;
    struct Node *current = NULL;
    int n; // Number of nodes

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)      // Input data for each node
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
            head = newNode;               // If it's the first node, set it as the head
            current = newNode;
        }
        else
        {
            current->next = newNode;               // Link the current node to the new node
            current = newNode;               // Move the current pointer to the new node
        }
    }

    printf("\nLinked List:\n");       // Traverse and print the linked list
    listTraversal(head);

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

