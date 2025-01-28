#include <stdio.h>
#include <stdlib.h>
void sortArray(int *array, int size)
{
    int swappedFlag = 1;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swappedFlag = 0;
            }
        }
        if (swappedFlag == 1)
        {
            break;
        }
    }
}
int twoPointerSearch(int *array, int sizeOfArray, int target)
{
    int startPtr = 0;
    int endPtr = sizeOfArray - 1;
    int ansFlag = 0;
    while (startPtr < endPtr)
    {
        int sum = array[startPtr] + array[endPtr];
        if (sum == target)
        {
            printf("%d %d\n", array[startPtr], array[endPtr]);
            ansFlag = 1;
            startPtr++;
            endPtr--;
        }
        else if (sum < target)
            startPtr++;
        else
            endPtr--;
    }
    if (ansFlag == 0)
        return 0;
    else
        return 1;
}
int getValidInteger()
{
    int value = 0;
    char inputCharacter;
    int isValid = 0;
    int sign = 1;
    while (isValid == 0)
    {
        isValid = 1;
        while ((inputCharacter = getchar()) != '\n')
        {
            if (inputCharacter == '-')
            {
                sign = -1;
                continue;
            }
            else if (inputCharacter < '0' || inputCharacter > '9')
            {
                isValid = 0;
                break;
            }
            value = value * 10 + (inputCharacter - '0');
        }
        if (isValid == 0)
        {
            printf("Please enter valid integer only.\n");
            while (getchar() != '\n')
                ;
        }
    }
    return value * sign;
}
int main()
{
    int sizeOfArray, targetSum, resultArraySize;
    printf("Enter size of an array: ");
    sizeOfArray = getValidInteger();
    if (sizeOfArray < 0)
    {
        printf("Enter size of array a positive integer.\n");
        return 0;
    }
    if (sizeOfArray == 0)
    {
        printf("Enter size of integer greator then 0.\n");
        return 0;
    }
    int *array = (int *)malloc(sizeOfArray * sizeof(int));
    printf("Enter sorted elements in array: \n");
    for (int i = 0; i < sizeOfArray; i++)
    {
        printf("Enter integer value at index %d : ", i);
        array[i] = getValidInteger();
    }
    sortArray(array, sizeOfArray);
    printf("Target: ");
    targetSum = getValidInteger();
    if (twoPointerSearch(array, sizeOfArray, targetSum) == 1)
    {
        printf("Pairs with sum equals to target is present.\n");
    }
    else
    {
        printf("No pairs with sum equals to target.\n");
    }
    return 0;
}