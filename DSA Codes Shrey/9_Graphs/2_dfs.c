// C code for dfs implementation of graphs

#include <stdio.h>
#include <stdlib.h>

void DFS(int i, int size, int *A, int visited[size])
{
    printf("%d ", i);
    visited[i] = 1;
    for (int j = 0; j < size; j++)
    {
        if (A[i * size + j] == 1 && !visited[j])
        {
            DFS(j, size, A, visited);
        }
    }
}

void freeMemory(int size, int *A, int *visited)
{
    free(A);
    free(visited);
}

int main()
{
    int size;
    printf("Enter the size of the adjacency matrix: ");
    scanf("%d", &size);

    int stackSize;
    printf("Enter the stack size: ");
    scanf("%d", &stackSize);

    int *visited = (int *)malloc(size * sizeof(int));
    if (visited == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1; // Exit with an error code
    }

    int *A = (int *)malloc(size * size * sizeof(int));
    if (A == NULL)
    {
        printf("Memory allocation failed.\n");
        free(visited);
        return 1; // Exit with an error code
    }

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            scanf("%d", &A[i * size + j]);
        }
    }

    printf("DFS Traversal: ");
    DFS(0, size, A, visited);

    // Free dynamically allocated memory
    freeMemory(size, A, visited);

    return 0;
}
