// C code for implementing bfs traversal of graph data structure

#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct queue *q)
{
    return (q->r == q->f);
}

int isFull(struct queue *q)
{
    return (q->r == q->size - 1);
}

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("This Queue is full\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("This Queue is empty\n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

void freeMemory(struct queue *q)
{
    free(q->arr);
}

void bfs(int startNode, int size, int **a, int *visited, struct queue *q)
{
    visited[startNode] = 1;
    enqueue(q, startNode);

    while (!isEmpty(q))
    {
        int node = dequeue(q);
        printf("%d ", node);

        for (int j = 0; j < size; j++)
        {
            if (a[node][j] == 1 && visited[j] == 0)
            {
                visited[j] = 1;
                enqueue(q, j);
            }
        }
    }
}

void inorderTraversal(int startNode, int size, int **a, int *visited, struct queue *q)
{
    if (visited[startNode] == 0)
    {
        visited[startNode] = 1;

        for (int j = 0; j < size; j++)
        {
            if (a[startNode][j] == 1 && visited[j] == 0)
            {
                inorderTraversal(j, size, a, visited, q);
            }
        }
        printf("%d ", startNode);
    }
}

int main()
{
    int queueSize, matrixSize, startNode;

    // Input queue size
    printf("Enter the maximum number of elements in the graph (queue size): ");
    scanf("%d", &queueSize);

    // Input adjacency matrix size
    printf("Enter the size of the adjacency matrix: ");
    scanf("%d", &matrixSize);

    // Initializing Adjacency Matrix
    int **adjMatrix = (int **)malloc(matrixSize * sizeof(int *));
    for (int i = 0; i < matrixSize; i++)
    {
        adjMatrix[i] = (int *)malloc(matrixSize * sizeof(int));
    }

    // Inputting values into the Adjacency Matrix
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixSize; j++)
        {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    // Input starting node
    printf("Enter the starting node for BFS traversal: ");
    scanf("%d", &startNode);

    // Initializing Queue (Array Implementation)
    struct queue q;
    q.size = queueSize;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    // Initializing visited array
    int *visited = (int *)malloc(matrixSize * sizeof(int));
    for (int i = 0; i < matrixSize; i++)
    {
        visited[i] = 0;
    }

    // BFS Implementation
    printf("BFS Traversal: ");
    bfs(startNode, matrixSize, adjMatrix, visited, &q);
    printf("\n");

    // Reset visited array
    for (int i = 0; i < matrixSize; i++)
    {
        visited[i] = 0;
    }

    // Inorder Traversal
    printf("Inorder Traversal starting from node %d: ", startNode);
    inorderTraversal(startNode, matrixSize, adjMatrix, visited, &q);
    printf("\n");

    // Freeing allocated memory
    freeMemory(&q);

    for (int i = 0; i < matrixSize; i++)
    {
        free(adjMatrix[i]);
    }
    free(adjMatrix);
    free(visited);

    return 0;
}
