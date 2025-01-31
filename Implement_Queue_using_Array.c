#include <stdio.h>
#include <stdlib.h>
void enqueue(int **array, int element, int *front, int *rear, int *size)
{
    (*array) = (int *)realloc((*array), (*size + 1) * sizeof(int));
    if (*front == -1)
    {
        *front = 0;
    }
    (*rear)++;
    (*array)[*rear] = element;
    (*size)++;
}
void dequeue(int **array, int *front, int *rear, int *size)
{
    if (*front == -1 || *front > *rear)
    {
        printf("Queue is Empty.\n");
        return;
    }
    int element = (*array)[*front];
    (*front)++;
    (*size--);
    if (*front > *rear)
    {
        *front = -1;
        *rear = -1;
    }
}
void peek(int **array, int *front, int *rear)
{
    if (*front == -1 || *front > *rear)
    {
        printf("Queue is empty.\n");
        return;
    }
    int element = (*array)[*front];
    printf("Peek element is %d.\n", element);
}
void isEmpty(int **array, int *front, int *rear)
{
    if (*front == -1 || *front > *rear)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue is not empty.\n");
    }
    return;
}
void size(int **array, int *front, int *rear)
{
    if (*front == -1 || *front > *rear)
    {
        printf("Queue is empty.\n");
    }
    int size = *rear - *front + 1;
    printf("Size of Queue %d.\n", size);
}
void display(int *array, int front, int rear)
{
    if (front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
int main()
{
    int *array = (int *)malloc(sizeof(array));
    int frontPtr = -1;
    int rearPtr = -1;
    int size_of_array = 0;
    int number_of_operations;
    printf("Enter number of operations to perform on queue: ");
    scanf("%d", &number_of_operations);
    while (number_of_operations--)
    {
        printf("1) Add element to the Queue.\n");
        printf("2) Remove the front element from the queue.\n");
        printf("3) Retreive the front element without removing it.\n");
        printf("4) Check if Queue is empty.\n");
        printf("5) Current size of Queue.\n");
        printf("6) Display queue.\n");
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
            enqueue(&array, element, &frontPtr, &rearPtr, &size_of_array);
            break;
        }
        case 2:
        {
            dequeue(&array, &frontPtr, &rearPtr, &size_of_array);
            break;
        }
        case 3:
        {
            peek(&array, &frontPtr, &rearPtr);
            break;
        }
        case 4:
        {
            isEmpty(&array, &frontPtr, &rearPtr);
            break;
        }
        case 5:
        {
            size(&array, &frontPtr, &rearPtr);
            break;
        }
        case 6:
        {
            display(array, frontPtr, rearPtr);
            break;
        }
        default:
            printf("Please enter a valid choice.");
        }
        printf("\n");
    }
    return 0;
}