// C code for insertion of nodes in AVL tree

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
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
    n->height = 1;
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

int max(int a, int b)  // calculating max value given at console
{
    return (a > b) ? a : b;
}

int height(struct node *root)  // calculating max height of the tree
{
    if (root == NULL)
        return 0;
    return root->height;
}

int getBalance(struct node *root)  // balancing the bst into avl tree
{
    if (root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}

struct node *rightRotate(struct node *y)  // right rotation of avl tree
{
    struct node *x = y->left;
    struct node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct node *leftRotate(struct node *x)  // left rotation of avl tree
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

struct node *constructAVL(struct node *root, int data)  // construction avl tree function
{
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = constructAVL(root->left, data);
    else if (data > root->data)
        root->right = constructAVL(root->right, data);
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    if (balance > 1 && data < root->left->data)
        return rightRotate(root);

    if (balance < -1 && data > root->right->data)
        return leftRotate(root);

    if (balance > 1 && data > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && data < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inOrder(struct node *root)  // inorder traversal of avl tree
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int isAVL(struct node *root)  // function to check whether given tree is avl or not
{
    if (root == NULL)
        return 1;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (abs(leftHeight - rightHeight) > 1)
        return 0;

    return isAVL(root->left) && isAVL(root->right);
}

struct node *insertAndUpdate(struct node *root, int data)  // insertion in avl tree(if the tree is not avl then converting into avl)
{
    root = constructAVL(root, data);
    if (isAVL(root))
    {
        printf("In-order traversal after insertion: ");
        inOrder(root);
        printf("\n");
    }
    else
    {
        printf("Tree is not AVL after insertion. Performing rotations...\n");

        int balance = getBalance(root);
        if (balance > 1 && data < root->left->data) // Implement rotation operations based on the balance factor
        {
            // Left-Left case
            root = rightRotate(root);
        }
        else if (balance < -1 && data > root->right->data)
        {
            // Right-Right case
            root = leftRotate(root);
        }
        else if (balance > 1 && data > root->left->data)
        {
            // Left-Right case
            root->left = leftRotate(root->left);
            root = rightRotate(root);
        }
        else if (balance < -1 && data < root->right->data)
        {
            // Right-Left case
            root->right = rightRotate(root->right);
            root = leftRotate(root);
        }

        // Additional rotations based on the specific balance factor may be needed
        printf("In-order traversal after rotations: ");
        inOrder(root);
        printf("\n");
    }
    return root;
}

int main()
{
    int numNodes;
    printf("C Code for insertion operation in AVL Tree\n");
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
        root = insertAndUpdate(root, value);
    }

    printf("In-order traversal of the AVL tree: ");
    inOrder(root);
    printf("\n");

    int continueInsert = 1;
    while (continueInsert)
    {
        printf("Do you want to insert another node? (1 for yes, 0 for no): ");
        scanf("%d", &continueInsert);

        if (continueInsert)
        {
            int insertKey;
            printf("Enter the key to insert into the AVL tree: ");
            scanf("%d", &insertKey);

            root = insertAndUpdate(root, insertKey);
            printf("In-order traversal after insertion: ");
            inOrder(root);
            printf("\n");
        }
    }
    freeTree(root);
    return 0;
}