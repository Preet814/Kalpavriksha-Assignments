#include <stdio.h>
#include <stdlib.h>
int isValid(char **chessBoard, int row, int col, int size)
{
    int r = row;
    int c = col;
    while (r >= 0 && c >= 0)
    {
        if (chessBoard[r][c] == 'Q')
            return 0;
        r--;
        c--;
    }
    r = row;
    c = col;
    while (c >= 0)
    {
        if (chessBoard[r][c] == 'Q')
            return 0;
        c--;
    }
    c = col;
    while (r < size && c >= 0)
    {
        if (chessBoard[r][c] == 'Q')
            return 0;
        r++;
        c--;
    }
    return 1;
}
void displayChessBoard(char **chessBoard, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%c ", chessBoard[i][j]);
        }
        printf("\n");
    }
}
void solveNQueens(char **chessBoard, int col, int size)
{
    if (col == size)
    {
        displayChessBoard(chessBoard, size);
        printf("\n");
        return;
    }
    for (int i = 0; i < size; i++)
    {
        if (isValid(chessBoard, i, col, size))
        {
            chessBoard[i][col] = 'Q';
            solveNQueens(chessBoard, col + 1, size);
            chessBoard[i][col] = '.';
        }
    }
}
int main()
{
    int sizeOfChessBoard;
    scanf("%d", &sizeOfChessBoard);
    printf("Input: \n");
    printf("n: %d\n", sizeOfChessBoard);
    int row = 0;
    int col = 0;
    char **chessBoard = (char **)malloc(sizeOfChessBoard * sizeof(char *));
    for (int i = 0; i < sizeOfChessBoard; i++)
    {
        chessBoard[i] = (char *)malloc(sizeOfChessBoard * sizeof(char));
    }
    for (int i = 0; i < sizeOfChessBoard; i++)
    {
        for (int j = 0; j < sizeOfChessBoard; j++)
        {
            chessBoard[i][j] = '.';
        }
    }
    solveNQueens(chessBoard, col, sizeOfChessBoard);
    free(chessBoard);
    return 0;
}