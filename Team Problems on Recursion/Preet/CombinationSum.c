#include <stdio.h>
#include <stdlib.h>
int getSum(int temp[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += temp[i];
    return sum;
}
void combinationSum(int *arr, int temp[], int tempIdx, int arrIdx, int target, int size)
{
    int tempSum = getSum(temp, tempIdx);
    if (tempSum == target)
    {
        printf("[");
        for (int i = 0; i < tempIdx; i++)
        {
            printf("%d ", temp[i]);
        }
        printf("]\n");
    }
    if (tempSum > target)
        return;
    for (int i = arrIdx; i < size; i++)
    {
        temp[tempIdx] = arr[i];
        combinationSum(arr, temp, tempIdx + 1, i, target, size);
    }
}
int main()
{
    int num;
    char ch;
    int *arr = (int *)malloc(sizeof(int));
    int idx = 0;
    while ((scanf("%d", &num)) == 1)
    {
        arr = (int *)realloc(arr, (idx + 1) * sizeof(int));
        arr[idx++] = num;
        if ((ch = getchar()) == '\n')
            break;
    }
    int size = idx;
    int target;
    scanf("%d", &target);
    printf("Input: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nTarget: %d\n", target);
    int temp[100];
    int tempIdx = 0;
    int arrIdx = 0;
    printf("Output: \n");
    combinationSum(arr, temp, tempIdx, arrIdx, target, size);
    free(arr);
    return 0;
}