// Finding Minimum and maximum element value in bst

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
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

void freeTree(struct node *root)
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

struct node *constructBST(int *inorder, int start, int end)
{
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    struct node *root = createNode(inorder[mid]);

    root->left = constructBST(inorder, start, mid - 1);
    root->right = constructBST(inorder, mid + 1, end);
    return root;
}

void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int isBST(struct node *root, struct node **prev)
{
    if (root != NULL)
    {
        if (!isBST(root->left, prev))
            return 0;
        if ((*prev) != NULL && root->data <= (*prev)->data)
            return 0;
        *prev = root;
        return isBST(root->right, prev);
    }
    else
    {
        return 1;
    }
}

// Function to find the minimum element in BST
int findMin(struct node *root)
{
    if (root == NULL)
    {
        printf("BST is empty.\n");
        return -1; // Assuming -1 represents an invalid value for an empty tree
    }
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

// Function to find the maximum element in BST
int findMax(struct node *root)
{
    if (root == NULL)
    {
        printf("BST is empty.\n");
        return -1; // Assuming -1 represents an invalid value for an empty tree
    }
    while (root->right != NULL)
        root = root->right;
    return root->data;
}

int main()
{
    int numNodes;
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    if (numNodes <= 0)
    {
        printf("Invalid number of nodes. Exiting.\n");
        return 1;
    }

    int *inorder = (int *)malloc(numNodes * sizeof(int));
    printf("Enter values in inorder format :\n");
    for (int i = 0; i < numNodes; i++)
    {
        scanf("%d", &inorder[i]);
    }

    struct node *root = constructBST(inorder, 0, numNodes - 1);
    struct node *prev = NULL;

    printf("In-order traversal: ");
    inOrder(root);
    printf("\n");

    if (isBST(root, &prev))
    {
        printf("This is a BST.\n");
        printf("Minimum element in BST: %d\n", findMin(root));
        printf("Maximum element in BST: %d\n", findMax(root));
    }
    else
    {
        printf("This is not a BST.\n");
    }

    freeTree(root);
    free(inorder);
    return 0;
}
