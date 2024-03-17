// postorder traversal of binary tree

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
        printf("Memory allocation failed for a node.\n");
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

struct node *constructBT(int *postorder, int start, int end)
{
    if (start > end)
        return NULL;

    struct node *root = createNode(postorder[start]);

    int i;
    for (i = end; i > start; i--)
    {
        if (postorder[i] < root->data)
            break;
    }

    root->right = constructBT(postorder, i + 1, end);
    root->left = constructBT(postorder, start + 1, i);

    return root;
}

void postOrder(struct node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

int main(int argc, char const *argv[])
{
    int numNodes;
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    if (numNodes <= 0)
    {
        printf("Invalid number of nodes. Exiting.\n");
        return 1;
    }

    int *postorder = (int *)malloc(numNodes * sizeof(int));
    if (postorder == NULL)
    {
        printf("Memory allocation failed for postorder traversal.\n");
        return EXIT_FAILURE;
    }

    printf("Enter values in postorder traversal (root last): \n");
    for (int i = 0; i < numNodes; i++)
    {
        if (scanf("%d", &postorder[i]) != 1)
        {
            printf("Invalid input. Please enter valid integers.\n");
            free(postorder);
            return EXIT_FAILURE;
        }
    }

    struct node *root = constructBT(postorder, 0, numNodes - 1);

    printf("Postorder traversal: ");
    postOrder(root);
    printf("\n");

    freeTree(root);
    free(postorder);

    return 0;
}
