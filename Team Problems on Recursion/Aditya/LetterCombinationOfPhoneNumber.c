#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int getLength(char *digits)
{
    int i = 0;
    while (digits[i] != '\0')
        i++;
    return i;
}
void solve(char *digits, char mapping[10][4], int idx, int digitsLength, char ans[], int ansIdx)
{
    if (idx == digitsLength)
    {
        for (int i = 0; i < ansIdx; i++)
        {
            printf("%c", ans[i]);
        }
        printf(" ");
        return;
    }
    int digit = digits[idx] - '0';
    char *temp = mapping[digit];
    for (int i = 0; temp[i] != '\0'; i++)
    {
        ans[ansIdx] = temp[i];
        solve(digits, mapping, idx + 1, digitsLength, ans, ansIdx + 1);
    }
    free(temp);
}
int main()
{
    char *digits = (char *)malloc(5 * sizeof(char));
    fgets(digits, 5, stdin);
    digits[strcspn(digits, "\n")] = '\0';
    printf("Digits: %s\n", digits);
    char mapping[10][4] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int digitIdx = 0;
    int digitsLength = getLength(digits);
    char ans[100] = "";
    int ansIdx = 0;
    printf("Output: \n");
    solve(digits, mapping, digitIdx, digitsLength, ans, ansIdx);
    free(digits);
    return 0;
}