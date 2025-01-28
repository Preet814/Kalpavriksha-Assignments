#include <stdio.h>
#include <stdlib.h>
void swap(int *value1, int *value2)
{
    int tempVariable = *value1;
    *value1 = *value2;
    *value2 = tempVariable;
}
int partition(int *array, int start, int end)
{
    int pivot = array[end];
    int i = start - 1;
    for (int j = start; j < end; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[end]);
    return i + 1;
}
void quickSort(int *array, int startPtr, int endPtr)
{
    if (startPtr >= endPtr)
        return;
    int pivotIdx = partition(array, startPtr, endPtr);
    quickSort(array, startPtr, pivotIdx - 1);
    quickSort(array, pivotIdx + 1, endPtr);
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
    printf("Array before quick sort: \n");
    for (int i = 0; i < sizeOfArray; i++)
    {
        printf("%d ", array[i]);
    }
    quickSort(array, 0, sizeOfArray - 1);
    printf("\nArray after quick sort in ascending order: \n");
    for (int i = 0; i < sizeOfArray; i++)
    {
        printf("%d ", array[i]);
    }
    free(array);
    return 0;
}