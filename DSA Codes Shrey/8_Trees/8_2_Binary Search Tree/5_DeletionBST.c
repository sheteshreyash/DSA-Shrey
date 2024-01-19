// C code for deletion operation in bst

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

void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

struct node *findMin(struct node *root) // identify the minumum value
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct node *deleteNode(struct node *root, int key) // deletion function
{
    if (root == NULL)
        return root;

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        // Node with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct node *temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main()
{
    int numNodes;
    printf("C Code for Deletion operation in BST\n");
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    if (numNodes <= 0)
    {
        printf("Invalid number of nodes. Exiting.\n");
        return 1;
    }

    int *inorder = (int *)malloc(numNodes * sizeof(int));
    printf("Enter values in inorder format:\n");
    for (int i = 0; i < numNodes; i++)
    {
        scanf("%d", &inorder[i]);
    }

    struct node *root = constructBST(inorder, 0, numNodes - 1);
    printf("In-order traversal of the BST: ");
    inOrder(root);
    printf("\n");

    struct node *prev = NULL;
    if (isBST(root, &prev))
    {
        printf("This is a BST.\n");

        while (1) // Loop to allow multiple deletions
        {
            int deleteKey;
            printf("Enter the key to delete from the BST (Enter -1 to exit): \n");
            scanf("%d", &deleteKey);

            if (deleteKey == -1)
                break; // Exit the loop if -1 is entered

            root = deleteNode(root, deleteKey);

            if (root == NULL)
            {
                printf("Key %d not found in the BST.\n", deleteKey);
                break; // Exit the loop if the key is not found
            }
            else
            {
                printf("In-order traversal after deletion: ");
                inOrder(root);
                printf("\n");
            }
        }
    }
    else
    {
        printf("This is not a BST. Deletion is not possible\n");
    }

    freeTree(root);
    free(inorder);
    return 0;
}
