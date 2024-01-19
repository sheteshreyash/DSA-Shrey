// C code for Insertion operation in BST

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

struct node *insertBST(struct node *root, int key)  // insertion operation in bst
{
    struct node *newNode = createNode(key);
    if (root == NULL)
    {
        return newNode;
    }

    struct node *current = root;
    struct node *parent = NULL;

    while (current != NULL)
    {
        parent = current;
        if (key < current->data)
        {
            current = current->left;
        }
        else if (key > current->data)
        {
            current = current->right;
        }
        else
        {
            // Duplicate keys are not allowed in this implementation
            printf("Duplicate key %d found.\n", key);
            free(newNode); // Free the allocated memory for the new node
            return root;
        }
    }

    if (key < parent->data) // At this point, 'parent' is the node where the new node should be attached
    {
        parent->left = newNode;
    }
    else
    {
        parent->right = newNode;
    }
    return root;
}


int main()
{
    int numNodes;
    printf("C Code for insertion operation in BST\n");
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

        int insertKey;
        printf("Enter the key to insert into the BST: ");
        scanf("%d", &insertKey);

        root = insertBST(root, insertKey);

        printf("In-order traversal after insertion: ");
        inOrder(root);
        printf("\n");
    }
    else
    {
        printf("This is not a BST. Insertion is not applicable.\n");
    }

    freeTree(root);
    free(inorder);

    return 0;
}
