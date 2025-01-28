#include <stdio.h>
#include <stdlib.h>
int linearSearch(int *array, int sizeOfArray, int target)
{
    for (int i = 0; i < sizeOfArray; i++)
    {
        if (array[i] == target)
            return i;
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
    printf("\nEnter element to search in array: ");
    targetElement = getValidInteger();
    int index = linearSearch(array, sizeOfArray, targetElement);
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