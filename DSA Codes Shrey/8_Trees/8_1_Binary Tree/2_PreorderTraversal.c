// Preorder traversal of a binary tree

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// struct node *createNode(int data)
// {
//     struct node *n;                                 // creating a node pointer
//     n = (struct node *)malloc(sizeof(struct node)); // Allocating memory in the heap
//     n->data = data;                                 // Setting the data
//     n->left = NULL;                                 // Setting the left and right children to NULL
//     n->right = NULL;                                // Setting the left and right children to NULL
//     return n;                                       // Finally returning the created node
// }

struct node *createNode(int data)   // minor changes in node creation function
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void freeTree(struct node *root)  // free the allocated memory function
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

struct node *constructBT(int *inorder, int start, int end)
{
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    struct node *root = createNode(inorder[mid]);

    root->left = constructBT(inorder, start, mid - 1);
    root->right = constructBT(inorder, mid + 1, end);

    return root;
}

void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// int main()
// {

//     // Constructing the root node - Using Function (Recommended)
//     struct node *p = createNode(4);
//     struct node *p1 = createNode(1);
//     struct node *p2 = createNode(6);
//     struct node *p3 = createNode(5);
//     struct node *p4 = createNode(2);
//     // Finally The tree looks like this:
//     //      4
//     //     / \
//     //    1   6
//     //   / \
//     //  5   2

//     // Linking the root node with left and right children
//     p->left = p1;
//     p->right = p2;
//     p1->left = p3;
//     p1->right = p4;

//     preOrder(p);
//     return 0;
// }


int main(int argc, char const *argv[])
{
    int numNodes;
    printf("Enter the number of nodes : ");
    scanf("%d", &numNodes);

    if (numNodes <= 0)
    {
        printf("Invalid number of nodes. Exiting.\n");
        return 1;
    }

    int *inorder = (int *)malloc(numNodes * sizeof(int));

    printf("Enter values in inorder traversal (left-root-right):\n");
    for (int i = 0; i < numNodes; i++)
    {
        scanf("%d", &inorder[i]);
    }

    struct node *root = constructBT(inorder, 0, numNodes - 1);

    printf("Pre-order traversal : ");
    preOrder(root);
    printf("\n");

    freeTree(root);
    free(inorder);

    return 0;
}
