#include <stdio.h>
#include <stdlib.h>
int isSubsetSumEqualTarget(int *array, int idx, int size, int sum, int target)
{
    if (sum == target)
        return 1;
    if (idx == size || sum > target)
        return 0;
    int includeIdx = isSubsetSumEqualTarget(array, idx + 1, size, sum + array[idx], target);
    int excludeIdx = isSubsetSumEqualTarget(array, idx + 1, size, sum, target);
    if (includeIdx || excludeIdx)
        return 1;
    return 0;
}
int main()
{
    int sizeOfArray, targetSum;
    scanf("%d %d", &sizeOfArray, &targetSum);
    int *array = (int *)malloc(sizeOfArray * sizeof(int));
    for (int i = 0; i < sizeOfArray; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("Input: \n");
    printf("Array: ");
    for (int i = 0; i < sizeOfArray; i++)
        printf("%d ", array[i]);
    printf("\nTarget Sum: %d\n", targetSum);
    int sum = 0;
    int idx = 0;
    int flag = isSubsetSumEqualTarget(array, idx, sizeOfArray, sum, targetSum);
    if (flag == 1)
    {
        printf("True");
    }
    else
    {
        printf("False");
    }
    free(array);
    return 0;
}