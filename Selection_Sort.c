#include <stdio.h>
#include <stdlib.h>
void swap(int *value1, int *value2)
{
    int tempVariable = *value1;
    *value1 = *value2;
    *value2 = tempVariable;
}
void selectionSort(int *array, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[minIdx])
                minIdx = j;
        }
        swap(&array[i], &array[minIdx]);
    }
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
    printf("Array before selection sort: \n");
    for (int i = 0; i < sizeOfArray; i++)
    {
        printf("%d ", array[i]);
    }
    selectionSort(array, sizeOfArray);
    printf("\nArray after selection sort in ascending order: \n");
    for (int i = 0; i < sizeOfArray; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}