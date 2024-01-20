// C code for creating AVL trees

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height; // New attribute for AVL tree
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
    n->height = 1; // Initialize height to 1 for a new node
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

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(struct node *root)
{
    if (root == NULL)
        return 0;
    return root->height;
}

int getBalance(struct node *root)
{
    if (root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}

struct node *rightRotate(struct node *y)  // right rotation of a node
{
    struct node *x = y->left;
    struct node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct node *leftRotate(struct node *x)  // left rotation of a node
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

struct node *constructAVL(struct node *root, int data)
{
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = constructAVL(root->left, data);
    else if (data > root->data)
        root->right = constructAVL(root->right, data);
    else // Duplicate keys are not allowed
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && data < root->left->data)
        return rightRotate(root);

    // Right Right Case
    if (balance < -1 && data > root->right->data)
        return leftRotate(root);

    // Left Right Case
    if (balance > 1 && data > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && data < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

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

    struct node *root = NULL;

    printf("Enter values to construct AVL tree:\n");
    for (int i = 0; i < numNodes; i++)
    {
        int value;
        scanf("%d", &value);
        root = constructAVL(root, value);
    }

    printf("In-order traversal of AVL tree: ");
    inOrder(root);
    printf("\n");

    freeTree(root);

    return 0;
}
