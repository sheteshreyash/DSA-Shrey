// C code for printing a given matrix in spiral form

#include <stdio.h>
#include <stdbool.h>

void spiralOrder(int m, int n, int matrix[][n])
{
    int dr[] = {0, 1, 0, -1};
    int dc[] = {1, 0, -1, 0};
    bool seen[m][n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            seen[i][j] = false;
        }
    }

    int x = 0, y = 0, di = 0;
    for (int i = 0; i < m * n; i++)
    {
        printf("%d ", matrix[x][y]);
        seen[x][y] = true;

        int newX = x + dr[di];
        int newY = y + dc[di];

        if (0 <= newX && newX < m && 0 <= newY && newY < n && !seen[newX][newY])
        {
            x = newX;
            y = newY;
        }
        else
        {
            di = (di + 1) % 4;
            x += dr[di];
            y += dc[di];
        }
    }
}

int main()
{
    int m, n;
    printf("Enter the number of rows: ");
    scanf("%d", &m);

    printf("Enter the number of columns: ");
    scanf("%d", &n);
    int a[m][n];

    printf("Enter the matrix elements:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Spiral Order: ");
    spiralOrder(m, n, a);
    return 0;
}
