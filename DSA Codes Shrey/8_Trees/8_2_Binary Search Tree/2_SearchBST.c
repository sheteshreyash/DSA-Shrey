// C code for recursive search operation in BST
// Time complexity lies between (logn <= h <= n)

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

        if (*prev != NULL && root->data <= (*prev)->data)
            return 0;

        *prev = root;
        return isBST(root->right, prev);
    }
    else
    {
        return 1;
    }
}

int searchBST(struct node *root, int key)  // REcursive search
{
    while (root != NULL)
    {
        if (key < root->data)
            root = root->left;
        else if (key > root->data)
            root = root->right;
        else
            return root->data; // Element found
    }

    return -1; // Element not found
}

int main()
{
    int numNodes;
    printf("C Code for Recursive search operation in BST \n");
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

    printf("In-order traversal: ");
    inOrder(root);
    printf("\n");

    struct node *prev = NULL;
    if (isBST(root, &prev))
    {
        printf("This is a BST.\n");

        int searchKey;
        printf("Enter the key to search: ");
        scanf("%d", &searchKey);

        int result = searchBST(root, searchKey);
        if (result != -1)
        {
            printf("Key %d found in the BST with value %d.\n", searchKey, result);
        }
        else
        {
            printf("Key %d not found in the BST.\n", searchKey);
        }
    }
    else
    {
        printf("This is not a BST. Recursive Searching is not applicable.\n");
    }

    freeTree(root);
    free(inorder);

    return 0;
}
