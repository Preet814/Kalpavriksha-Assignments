#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void sort(char word[])
{
    int n = strlen(word);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (word[i] > word[j])
            {
                char temp = word[i];
                word[i] = word[j];
                word[j] = temp;
            }
        }
    }
}
void group_anagrams(char **str, int size)
{
    char *sorted_str[size];
    for (int i = 0; i < size; i++)
    {
        sorted_str[i] = (char *)malloc((strlen(str[i]) + 1) * sizeof(char));
        strcpy(sorted_str[i], str[i]);
        sort(sorted_str[i]);
    }
    printf("\n");
    int visited[size];
    memset(visited, 0, sizeof(visited));
    printf("[");
    for (int i = 0; i < size; i++)
    {
        if (visited[i] == 0)
        {
            printf("[\"%s\"", str[i]);
            visited[i] = 1;
            for (int j = i + 1; j < size; j++)
            {
                if (visited[j] == 0 && strcmp(sorted_str[j], sorted_str[i]) == 0)
                {
                    printf(",\"%s\"", str[j]);
                    visited[j] = 1;
                }
            }
            if (i == size - 1)
                printf("]");
            else
                printf("],");
        }
    }
    printf("]");
}
int main()
{
    char string[100];
    printf("Enter string: ");
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = '\0';
    printf("String: %s\n", string);
    char *data = string + 1;
    data[strlen(data) - 1] = '\0';
    char **array = NULL;
    int word_cnt = 0;
    char *token = strtok(data, ",");
    if (sizeof(token) == 4)
    {
        printf("[["
               "]]");
        return 0;
    }
    while (token != NULL)
    {
        char *word_start = token + 1;
        char *word_end = word_start + strlen(word_start) - 1;
        *word_end = '\0';
        array = realloc(array, (word_cnt + 1) * sizeof(char *));
        array[word_cnt] = malloc((strlen(word_start) - 1) * sizeof(char));
        strcpy(array[word_cnt], word_start);
        word_cnt++;
        token = strtok(NULL, ",");
    }
    printf("Stored words:\n");
    for (int i = 0; i < word_cnt; i++)
    {
        printf("%s ", array[i]);
    }
    printf("\n\n");
    group_anagrams(array, word_cnt);
    return 0;
}
