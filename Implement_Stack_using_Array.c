#include <stdio.h>
#include <stdlib.h>
void push(int **array, int element, int *top_of_stack, int *size_of_array)
{
    *array = (int *)realloc((*array), ((*size_of_array) + 1) * sizeof(int));
    (*top_of_stack)++;
    (*array)[(*top_of_stack)] = element;
    (*size_of_array)++;
}
void pop(int **array, int *top_of_stack, int *size_of_array)
{
    if ((*top_of_stack) == -1)
    {
        printf("UnderFlow Condition: Stack is empty.\n");
        return;
    }
    int element = (*array)[(*top_of_stack)];
    (*top_of_stack)--;
    (*size_of_array)--;
    (*array) = (int *)realloc((*array), (*size_of_array) * sizeof(int));
    printf("%d popped from the top of stack.\n", element);
}
void peek(int **array, int *top_of_stack)
{
    if ((*top_of_stack) == -1)
    {
        printf("No peek element, stack is empty.\n");
        return;
    }
    int element = (*array)[(*top_of_stack)];
    printf("Element at peek is %d.\n", element);
}
void check_if_empty(int *top_of_stack)
{
    if ((*top_of_stack) == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack is not empty.\n");
    }
}
void size_of_stack(int *size_of_array)
{
    printf("Size of stack is : %d.\n", (*size_of_array));
}
void display(int *array, int size)
{
    if (size == 0)
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack: ");
    for (int i = size - 1; i >= 0; i--)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
int main()
{
    int *array = (int *)malloc(sizeof(int));
    int number_of_operations;
    printf("Enter number of operations to perform on stack: ");
    scanf("%d", &number_of_operations);
    int top_of_stack = -1;
    int size_of_array = 0;
    while (number_of_operations--)
    {
        printf("1) Push element in stack.\n");
        printf("2) Pop element from stack.\n");
        printf("3) Top element in stack.\n");
        printf("4) Check if stack is empty.\n");
        printf("5) Current size of stack.\n");
        printf("6) Display Stack.\n");
        printf("7) Exit!");
        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        if (choice == 7)
        {
            break;
        }
        switch (choice)
        {
        case 1:
        {
            int element;
            printf("Enter element to push at top of stack: ");
            scanf("%d", &element);
            push(&array, element, &top_of_stack, &size_of_array);
            break;
        }
        case 2:
        {
            pop(&array, &top_of_stack, &size_of_array);
            break;
        }
        case 3:
        {
            peek(&array, &top_of_stack);
            break;
        }
        case 4:
        {
            check_if_empty(&top_of_stack);
            break;
        }
        case 5:
        {
            size_of_stack(&size_of_array);
            break;
        }
        case 6:
        {
            display(array, size_of_array);
            break;
        }
        default:
            printf("Please enter a valid choice.");
        }
        printf("\n");
    }
    return 0;
}
