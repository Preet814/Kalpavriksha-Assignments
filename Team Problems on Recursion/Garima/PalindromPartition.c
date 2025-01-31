#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int getLength(char input[])
{
    int i = 0;
    while (input[i] != '\0')
        i++;
    return i;
}
int checkPalindrom(char word[], int size)
{
    int s = 0, e = size - 1;
    while (s <= e)
    {
        if (word[s] == word[e])
        {
            s++;
            e--;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}
void partition(char string[], char ans[100][100], int ansIdx, int idx, int stringSize)
{
    if (idx == stringSize)
    {
        printf("[");
        for (int i = 0; i < ansIdx; i++)
        {
            printf("%s ", ans[i]);
        }
        printf("]\n");
        return;
    }
    char check[100];
    int j = 0;
    for (int i = idx; i < stringSize; i++)
    {
        check[j++] = string[i];
        check[j] = '\0';
        if (checkPalindrom(check, j))
        {
            strcpy(ans[ansIdx], check);
            partition(string, ans, ansIdx + 1, i + 1, stringSize);
            strcpy(ans[ansIdx], "");
        }
    }
}
int main()
{
    char string[100];
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = '\0';
    printf("Input: %s\n", string);
    char ans[100][100];
    int ansIdx = 0;
    int stringSize = getLength(string);
    printf("Output: \n");
    partition(string, ans, ansIdx, 0, stringSize);
    return 0;
}