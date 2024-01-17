// Linked Represenation of Binary Tree

#include <stdio.h>
#include <stdlib.h>

struct node  // selft reference structure
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n;                                 // creating a node pointer
    n = (struct node *)malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data;                                 // Setting the data
    n->left = NULL;                                 // Setting the left and right children to NULL
    n->right = NULL;                                // Setting the left and right children to NULL
    return n;                                       // Finally returning the created node
}

void freeTree(struct node *root)  // free allocated memory
{
    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

void printTree(struct node *root, int space)  // print tree function
{
    if (root == NULL)
        return;

    space += 5; // Increase distance between levels
    printTree(root->right, space); // Print right child first

    // Print current node with appropriate spacing
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%d", root->data);
    printTree(root->left, space); // Print left child
}

// int main()
// {
//     /*
//     // Constructing the root node
//     struct node *p;
//     p = (struct node *) malloc(sizeof(struct node));
//     p->data = 2;
//     p->left = NULL;
//     p->right = NULL;

//     // Constructing the second node
//     struct node *p1;
//     p1 = (struct node *) malloc(sizeof(struct node));
//     p->data = 1;
//     p1->left = NULL;
//     p1->right = NULL;

//     // Constructing the third node
//     struct node *p2;
//     p2 = (struct node *) malloc(sizeof(struct node));
//     p->data = 4;
//     p2->left = NULL;
//     p2->right = NULL;
//     */

//     // Constructing the root node - Using Function (Recommended)
//     struct node *p = createNode(2);
//     struct node *p1 = createNode(1);
//     struct node *p2 = createNode(4);

//     // Linking the root node with left and right children
//     p->left = p1;
//     p->right = p2;

//     return 0;
// }


int main(int argc, char const *argv[])
{
    int numNodes;
    printf("Enter the number of nodes in the binary tree: ");
    scanf("%d", &numNodes);

    if (numNodes <= 0)
    {
        printf("Invalid input. Number of nodes should be greater than 0.\n");
        return 1;
    }

    int rootData; // Creating the root node
    printf("Enter data for the root node: ");
    scanf("%d", &rootData);
    struct node *root = createNode(rootData);

    // Creating the rest of the nodes
    for (int i = 1; i < numNodes; i++)
    {
        int nodeData;
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &nodeData);

        // Function to add the node to the binary tree
        // The nodes are inserted at the leftmost available position.
        struct node *current = root;
        while (current->left != NULL || current->right != NULL)
        {
            if (current->left != NULL)
                current = current->left;
            else
                current = current->right;
        }

        if (current->left == NULL)
            current->left = createNode(nodeData);
        else
            current->right = createNode(nodeData);
    }

    printf("\nBinary Tree:\n");
    printTree(root, 0);

    freeTree(root);  //free memory
    return 0;
}
