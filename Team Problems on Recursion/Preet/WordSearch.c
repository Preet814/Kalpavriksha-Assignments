// Input format:
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
// word: ABCCED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int getLength(char *word)
{
    int i = 0;
    while (word[i] != '\0')
        i++;
    return i;
}
int checkWordExist(char **board, int row, int col, int i, int j, int k, char *word, int wordLength)
{
    if (k == wordLength)
        return 1;
    if (i < 0 || i >= row || j < 0 || j >= col || board[i][j] != word[k])
        return 0;
    char ch = board[i][j];
    board[i][j] = '0';
    int option_1 = checkWordExist(board, row, col, i + 1, j, k + 1, word, wordLength);
    int option_2 = checkWordExist(board, row, col, i, j + 1, k + 1, word, wordLength);
    int option_3 = checkWordExist(board, row, col, i - 1, j, k + 1, word, wordLength);
    int option_4 = checkWordExist(board, row, col, i, j - 1, k + 1, word, wordLength);
    if (option_1 || option_2 || option_3 || option_4)
        return 1;
    board[i][j] = ch;
    return 0;
}
int wordExist(char **board, int row, int col, char *word)
{
    int wordLength = getLength(word);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (checkWordExist(board, row, col, i, j, 0, word, wordLength))
                return 1;
        }
    }
    return 0;
}
int main()
{
    char ch;
    char **matrix = (char **)malloc(6 * sizeof(char *));
    for (int i = 0; i < 6; i++)
    {
        matrix[i] = (char *)malloc(6 * sizeof(char));
    }
    int row = 0, col = 0;
    scanf("%c", &ch); //[
    while (1)
    {
        scanf("%c", &ch); //[
        while (1)
        {
            scanf("%c", &ch); //"
            scanf("%c", &ch); // character
            matrix[row][col] = ch;
            col++;
            scanf("%c", &ch); // "
            scanf("%c", &ch); // , or ]
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
    getchar();
    char word[16];
    printf("Word: ");
    fgets(word, sizeof(word), stdin);
    word[strcspn(word, "\n")] = '\0';

    printf("Input: \n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("Word: %s\n", word);
    printf("Output: \n");
    int flag = wordExist(matrix, row, col, word);
    if (flag == 1)
    {
        printf("True");
    }
    else
    {
        printf("False");
    }
    free(matrix);
    return 0;
}