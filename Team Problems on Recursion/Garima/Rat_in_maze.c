#include <stdio.h>
#include <stdlib.h>
// [[1,0,0,0],[1,1,0,1],[1,1,0,0],[0,1,1,1]]
int check(int **matrix, int **visited, int x, int y, int row, int col)
{
    if (x < 0 || x >= row || y < 0 || y >= col || visited[x][y] == 1 || matrix[x][y] != 1)
        return 0;
    return 1;
}
void printPaths(int **matrix, int **visited, int r, int c, int row, int col, char ans[], int ansIdx)
{
    if (r == row - 1 && c == col - 1)
    {
        printf("[");
        for (int i = 0; i < ansIdx; i++)
        {
            printf("%c", ans[i]);
        }
        printf("]\n");
        return;
    }
    visited[r][c] = 1;
    int x = r + 1;
    int y = c;
    if (check(matrix, visited, x, y, row, col))
    {
        ans[ansIdx] = 'D';
        printPaths(matrix, visited, x, y, row, col, ans, ansIdx + 1);
        ans[ansIdx] = ' ';
    }
    x = r;
    y = c + 1;
    if (check(matrix, visited, x, y, row, col))
    {
        ans[ansIdx] = 'R';
        printPaths(matrix, visited, x, y, row, col, ans, ansIdx + 1);
        ans[ansIdx] = ' ';
    }
    x = r - 1;
    y = c;
    if (check(matrix, visited, x, y, row, col))
    {
        ans[ansIdx] = 'U';
        printPaths(matrix, visited, x, y, row, col, ans, ansIdx + 1);
        ans[ansIdx] = ' ';
    }
    x = r;
    y = c - 1;
    if (check(matrix, visited, x, y, row, col))
    {
        ans[ansIdx] = 'L';
        printPaths(matrix, visited, x, y, row, col, ans, ansIdx + 1);
        ans[ansIdx] = ' ';
    }
    visited[r][c] = 0;
}
void findPath(int **matrix, int row, int col)
{
    if (matrix[0][0] == 0)
    {
        printf("No paths.\n");
        return;
    }
    int **visited = (int **)calloc(row, sizeof(int *));
    for (int i = 0; i < row; i++)
    {
        visited[i] = (int *)calloc(col, sizeof(int));
    }
    char ans[100] = "";
    int ansIdx = 0;
    printPaths(matrix, visited, 0, 0, row, col, ans, ansIdx);
    for (int i = 0; i < row; i++)
    {
        free(visited[i]);
    }
    free(visited);
}
int main()
{
    int **matrix = (int **)malloc(5 * sizeof(int *));
    for (int i = 0; i < 5; i++)
    {
        matrix[i] = (int *)malloc(5 * sizeof(int));
    }
    int row = 0;
    int col = 0;
    char ch;
    scanf("%c", &ch); //[
    while (1)
    {
        scanf("%c", &ch); //[
        while (1)
        {
            int num;
            scanf("%d", &num);
            matrix[row][col] = num;
            col++;
            scanf("%c", &ch); //,
            if (ch == ']')
                break;
        }
        scanf("%c", &ch);
        if (ch == ',')
        {
            row++;
            col = 0;
        }
        if (ch == ']')
        {
            row++;
            break;
        }
    }
    printf("Input: \n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("Output: \n");
    findPath(matrix, row, col);
    for (int i = 0; i < 5; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}