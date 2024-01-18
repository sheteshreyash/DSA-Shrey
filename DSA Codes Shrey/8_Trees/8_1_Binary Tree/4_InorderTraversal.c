// inorder traversal of a binary tree

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data) // minor changes in node creation function
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

void freeTree(struct node *root) // free the allocated memory function
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

struct node *constructBT(int *inorder, int start, int end) // construct binary tree
{
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    struct node *root = createNode(inorder[mid]);

    root->left = constructBT(inorder, start, mid - 1);
    root->right = constructBT(inorder, mid + 1, end);

    return root;
}

void inOrder(struct node *root) // inorder function
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

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

    printf("In-order traversal : ");
    inOrder(root);
    printf("\n");

    freeTree(root);
    free(inorder);

    return 0;
}
