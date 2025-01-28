#include <stdio.h>
#include <stdlib.h>
void merge(int *array, int startPtr, int middlePtr, int endPtr)
{
    int i = startPtr;
    int j = middlePtr + 1;
    int *tempArray = (int *)malloc((endPtr - startPtr + 1) * sizeof(int));
    int tempIdx = 0;
    while (i <= middlePtr && j <= endPtr)
    {
        if (array[i] <= array[j])
            tempArray[tempIdx++] = array[i++];
        else
            tempArray[tempIdx++] = array[j++];
    }
    while (i <= middlePtr)
        tempArray[tempIdx++] = array[i++];
    while (j <= endPtr)
        tempArray[tempIdx++] = array[j++];
    for (int i = startPtr; i <= endPtr; i++)
    {
        array[i] = tempArray[i - startPtr];
    }
    free(tempArray);
}
void mergeSort(int *array, int startPtr, int endPtr)
{
    if (startPtr >= endPtr)
        return;
    int middleIdx = (startPtr + endPtr) / 2;
    mergeSort(array, startPtr, middleIdx);
    mergeSort(array, middleIdx + 1, endPtr);
    merge(array, startPtr, middleIdx, endPtr);
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
    int sizeOfArray;
    printf("Enter size of array: ");
    sizeOfArray = getValidInteger();
    if (sizeOfArray < 0)
    {
        printf("Error: Size of array must be positive!\n");
        return 0;
    }
    if (sizeOfArray == 0)
    {
        printf("Error: Size of array can't be zero!\n");
        return 0;
    }
    int *array = (int *)malloc(sizeOfArray * sizeof(int));
    printf("Enter elements in an array: \n");
    for (int i = 0; i < sizeOfArray; i++)
    {
        printf("Enter integer at index %d: ", i);
        array[i] = getValidInteger();
    }
    printf("Array before merge sort: \n");
    for (int i = 0; i < sizeOfArray; i++)
    {
        printf("%d ", array[i]);
    }
    mergeSort(array, 0, sizeOfArray - 1);
    printf("\nArray after merge sort in ascending order: \n");
    for (int i = 0; i < sizeOfArray; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}