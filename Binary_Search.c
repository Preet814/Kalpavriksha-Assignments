#include <stdio.h>
#include <stdlib.h>
int checkArrayIsSorted(int *array, int size)
{
    int swappedFlag = 1;
    int ansFlag = 0;
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
        if (swappedFlag == 0)
        {
            ansFlag = 1;
            break;
        }
    }
    if (ansFlag == 1)
        return 0;
    return 1;
}
int binarySearch(int *array, int sizeOfArray, int target)
{
    int startPtr = 0;
    int endPtr = sizeOfArray - 1;
    while (startPtr <= endPtr)
    {
        int middleIdx = startPtr + (endPtr - startPtr) / 2;
        int middleElement = array[middleIdx];
        if (middleElement == target)
            return middleIdx;
        else if (middleElement < target)
            startPtr = middleIdx + 1;
        else
            endPtr = middleIdx - 1;
    }
    return -1;
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
    int sizeOfArray, targetElement;
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
    printf("Enter elements in array: \n");
    for (int i = 0; i < sizeOfArray; i++)
    {
        printf("Enter integer value at index %d : ", i);
        array[i] = getValidInteger();
    }
    int checkSorted = checkArrayIsSorted(array, sizeOfArray);
    if (checkSorted == 0)
    {
        printf("Inputted array is not sorted.\n");
        free(array);
        return 0;
    }
    printf("\nEnter element to search in array: ");
    targetElement = getValidInteger();
    int index = binarySearch(array, sizeOfArray, targetElement);
    if (index == -1)
    {
        printf("Element not present in an array.\n");
    }
    else
    {
        printf("Element present on index : %d\n", index);
    }
    return 0;
}