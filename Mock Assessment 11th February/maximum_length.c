#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int getLength(char *input)
{
    int i = 0;
    while (input[i] != '\0')
        i++;
    return i;
}
int getMax(int a, int b)
{
    if (a >= b)
        return a;
    else
        return b;
}
int check(char *word1, char *word2)
{
    int map[26] = {0};
    int len1 = getLength(word1);
    for (int i = 0; i < len1; i++)
    {
        map[word1[i] - 'a']++;
    }
    int len2 = getLength(word2);
    for (int i = 0; i < len2; i++)
    {
        map[word2[i] - 'a']--;
    }
    int cnt = 0;
    for (int i = 0; i < 26; i++)
    {
        if (map[i] != 0)
            cnt++;
    }
    if (cnt == (len1 + len2))
        return 1;
    else
        return 0;
}
int main()
{
    char **array = (char **)malloc(1000 * sizeof(char *));
    char ch;
    scanf("%c",&ch);
    int idx=0;
    while(1){
        scanf("%c",&ch);
        char input[100];
        int i=0;
        while(1){
            scanf("%c",&ch);
            if(ch=='"'){
                input[i]='\0';
                break;
            }
            input[i++]=ch;
        }
        array[idx]=(char *)malloc(i*sizeof(char));
        strcpy(array[idx],input);
        scanf("%c",&ch);
        if(ch==']')
            break;
        idx++;
    }
    int size=idx+1;
    printf("size: %d\n",size);
    printf("Input: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%s ", array[i]);
    }
    int max = 0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (check(array[i], array[j]))
            {
                int len1 = getLength(array[i]);
                int len2 = getLength(array[j]);
                max = getMax(max, (len1 * len2));
            }
        }
    }
    printf("\nOutput: %d", max);
    return 0;
}