// // C code for implementing bfs traversal of a graph

// #include <stdio.h>
// #include <stdlib.h>

// struct queue
// {
//     int size;
//     int f;
//     int r;
//     int *arr;
// };

// int isEmpty(struct queue *q)
// {
//     return (q->r == q->f);
// }

// int isFull(struct queue *q)
// {
//     return (q->r == q->size - 1);
// }

// void enqueue(struct queue *q, int val)
// {
//     if (isFull(q))
//     {
//         printf("This Queue is full\n");
//     }
//     else
//     {
//         q->r++;
//         q->arr[q->r] = val;
//     }
// }

// int dequeue(struct queue *q)
// {
//     int a = -1;
//     if (isEmpty(q))
//     {
//         printf("This Queue is empty\n");
//     }
//     else
//     {
//         q->f++;
//         a = q->arr[q->f];
//     }
//     return a;
// }

// void freeMemory(struct queue *q)
// {
//     free(q->arr);
// }

// void bfs(int startNode, int size, int **a, int *visited, struct queue *q, int *bfsOrder)
// {
//     int orderIndex = 0;
//     visited[startNode] = 1;
//     enqueue(q, startNode);

//     while (!isEmpty(q))
//     {
//         int node = dequeue(q);
//         bfsOrder[orderIndex++] = node;

//         for (int j = 0; j < size; j++)
//         {
//             if (a[node][j] == 1 && visited[j] == 0)
//             {
//                 visited[j] = 1;
//                 enqueue(q, j);
//             }
//         }
//     }
// }

// void inorderTraversal(int startNode, int size, int **a, int *visited, struct queue *q, int *bfsOrder)
// {
//     bfs(startNode, size, a, visited, q, bfsOrder);
//     printf("Inorder Traversal starting from node %d: ", startNode);

//     for (int i = 0; i < size; i++)
//     {
//         int node = bfsOrder[i];
//         if (visited[node] == 0)
//         {
//             inorderTraversal(node, size, a, visited, q, bfsOrder);
//         }
//         printf("%d ", node);
//     }
// }

// int main()
// {
//     int queueSize, matrixSize, startNode;

//     // Input queue size
//     printf("Enter the maximum number of elements in the graph (queue size): \n");
//     scanf("%d", &queueSize);

//     // Input adjacency matrix size
//     printf("Enter the size of the adjacency matrix (a*a): \n");
//     scanf("%d", &matrixSize);

//     // Initializing Adjacency Matrix
//     int **adjMatrix = (int **)malloc(matrixSize * sizeof(int *));
//     for (int i = 0; i < matrixSize; i++)
//     {
//         adjMatrix[i] = (int *)malloc(matrixSize * sizeof(int));
//     }

//     // Inputting values into the Adjacency Matrix
//     printf("Enter the adjacency matrix: \n");
//     for (int i = 0; i < matrixSize; i++)
//     {
//         for (int j = 0; j < matrixSize; j++)
//         {
//             scanf("%d", &adjMatrix[i][j]);
//         }
//     }

//     // Input starting node
//     printf("Enter the starting node for BFS traversal: ");
//     scanf("%d", &startNode);

//     // Initializing Queue (Array Implementation)
//     struct queue q;
//     q.size = queueSize;
//     q.f = q.r = 0;
//     q.arr = (int *)malloc(q.size * sizeof(int));

//     // Initializing visited array
//     int *visited = (int *)malloc(matrixSize * sizeof(int));
//     for (int i = 0; i < matrixSize; i++)
//     {
//         visited[i] = 0;
//     }

//     // BFS Implementation
//     int *bfsOrder = (int *)malloc(matrixSize * sizeof(int));
//     printf("BFS Traversal: ");
//     bfs(startNode, matrixSize, adjMatrix, visited, &q, bfsOrder);
//     for (int i = 0; i < matrixSize; i++)
//     {
//         printf("%d ", bfsOrder[i]);
//     }
//     printf("\n");

//     // Reset visited array
//     for (int i = 0; i < matrixSize; i++)
//     {
//         visited[i] = 0;
//     }

//     // Inorder Traversal
//     inorderTraversal(startNode, matrixSize, adjMatrix, visited, &q, bfsOrder);
//     printf("\n");

//     // Freeing allocated memory
//     freeMemory(&q);
//     free(bfsOrder);

//     for (int i = 0; i < matrixSize; i++)
//     {
//         free(adjMatrix[i]);
//     }
//     free(adjMatrix);
//     free(visited);
//     return 0;
// }


// // Doubtful logic



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
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
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
        // printf("Enqued element: %d\n", val);
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

int main()
{
    // Initializing Queue (Array Implementation)
    struct queue q;
    q.size = 400;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    // BFS Implementation
    int node;
    int i = 1;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int a[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};
    printf("%d", i);
    visited[i] = 1;
    enqueue(&q, i); // Enqueue i for exploration
    while (!isEmpty(&q))
    {
        int node = dequeue(&q);
        for (int j = 0; j < 7; j++)
        {
            if (a[node][j] == 1 && visited[j] == 0)
            {
                printf("%d", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }
    return 0;
}
