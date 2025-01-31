#include <stdio.h>
#include <stdlib.h>
int predict(int *nums, int sum1, int sum2, int flag, int i, int j)
{
    if (i > j)
    {
        if (sum1 >= sum2)
            return 1;
        return 0;
    }
    if (flag)
    {
        flag = 0;
        return predict(nums, sum1 + nums[i], sum2, flag, i + 1, j) || predict(nums, sum1 + nums[j], sum2, flag, i, j - 1);
    }
    else
    {
        flag = 1;
        return predict(nums, sum1, sum2 + nums[i], flag, i + 1, j) && predict(nums, sum1, sum2 + nums[j], flag, i, j - 1);
    }
}
int predictTheWinner(int *nums, int size)
{
    int flag = 1;
    return predict(nums, 0, 0, flag, 0, size - 1);
}
int main()
{
    printf("Input the array: \n");
    int num;
    int *array = (int *)malloc(sizeof(int));
    int idx = 0;
    char ch;
    while ((scanf("%d", &num)) == 1)
    {
        array = (int *)realloc(array, (idx + 1) * sizeof(int));
        array[idx++] = num;
        if ((ch = getchar()) == '\n')
            break;
    }
    int size = idx;
    int answer = predictTheWinner(array, size);
    if (answer == 1)
    {
        printf("True");
    }
    else
    {
        printf("False");
    }
    return 0;
}