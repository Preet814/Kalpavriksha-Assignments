#include <stdio.h>
void generateParenthesis(int n, int open, int close, char ans[100], int ansIdx)
{
    if (open + close == 2 * n)
    {
        for (int i = 0; i < ansIdx; i++)
        {
            printf("%c", ans[i]);
        }
        printf(" ");
        return;
    }
    if (open < n)
    {
        ans[ansIdx] = '(';
        generateParenthesis(n, open + 1, close, ans, ansIdx + 1);
    }
    if (close < open)
    {
        ans[ansIdx] = ')';
        generateParenthesis(n, open, close + 1, ans, ansIdx + 1);
    }
}
int main()
{
    int numberOfPairOfParenthesis;
    scanf("%d", &numberOfPairOfParenthesis);
    printf("Input: \n");
    printf("N: %d\n", numberOfPairOfParenthesis);
    int openBracketCount = 0;
    int clodeBracketCount = 0;
    char ans[100] = "";
    int ansIdx = 0;
    printf("Output: ");
    printf("[ ");
    generateParenthesis(numberOfPairOfParenthesis, openBracketCount, clodeBracketCount, ans, ansIdx);
    printf(" ]");
    return 0;
}