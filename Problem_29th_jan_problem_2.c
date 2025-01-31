#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int getLength(char word[])
{
    int i = 0;
    while (word[i] != '\0')
        i++;
    return i;
}
void push(char stack[], int *idx, char ch)
{
    (*idx)++;
    stack[*idx] = ch;
}
void pop(char stack[], int *idx)
{
    (*idx)--;
}
int checkSame(char word1[], char word2[], int size)
{
    for (int i = 0; i <= size; i++)
    {
        if (word1[i] != word2[i])
            return 0;
    }
    return 1;
}
int main()
{
    char stack1[200];
    char stack2[200];
    char word1[200];
    char word2[200];
    fgets(word1, sizeof(word1), stdin);
    word1[strcspn(word1, "\n")] = '\0';
    fgets(word2, sizeof(word2), stdin);
    word2[strcspn(word2, "\n")] = '\0';
    printf("Word 1 : %s\n", word1);
    printf("Word 2 : %s\n", word2);
    int size1 = getLength(word1);
    int size2 = getLength(word2);
    int idx1 = -1;
    for (int i = 0; i < size1; i++)
    {
        if (word1[i] == '#' && idx1 >= 0)
        {
            pop(stack1, &idx1);
        }
        else if (word1[i] != '#')
        {
            push(stack1, &idx1, word1[i]);
        }
    }
    int idx2 = -1;
    for (int i = 0; i < size2; i++)
    {
        if (word2[i] == '#' && idx2 >= 0)
        {
            pop(stack2, &idx2);
        }
        else if (word2[i] != '#')
        {
            push(stack2, &idx2, word2[i]);
        }
    }
    if (idx1 != idx2)
    {
        printf("False");
        return 0;
    }
    int check = checkSame(stack1, stack2, idx1);
    if (check == 1)
    {
        printf("True");
    }
    else
    {
        printf("False");
    }
    return 0;
}