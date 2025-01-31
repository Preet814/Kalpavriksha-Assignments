#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} Node;
void enque(Node **front, Node **rear, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (*rear == NULL)
    {
        *front = newNode;
        *rear = newNode;
        return;
    }
    (*rear)->next = newNode;
    *rear = newNode;
}
void dequeue(Node **front, Node **rear)
{
    if (*front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }
    Node *temp = *front;
    *front = (*front)->next;
    if (*front == NULL)
    {
        *rear = NULL;
    }
    temp->next = NULL;
    printf("Element removed from front of queue is %d.\n", temp->data);
    free(temp);
}
void peek(Node **front)
{
    if (*front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Front of queue is %d.\n", (*front)->data);
}
void isEmpty(Node **front)
{
    if (*front == NULL)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue is not empty.\n");
    }
}
void size(Node *front)
{
    if (front == NULL)
    {
        printf("Size of queue is 0.\n");
        return;
    }
    Node *temp = front;
    int size = 0;
    while (temp != NULL)
    {
        size++;
        temp = temp->next;
    }
    printf("Size of queue is %d.\n", size);
}
void display(Node *front)
{
    if (front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }
    Node *temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    Node *front = NULL;
    Node *rear = NULL;
    int number_of_operations;
    printf("Enter number of operations to perform on Queue: ");
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
            printf("Enter element to push at top of Queue: ");
            scanf("%d", &element);
            enque(&front, &rear, element);
            break;
        }
        case 2:
        {
            dequeue(&front, &rear);
            break;
        }
        case 3:
        {
            peek(&front);
            break;
        }
        case 4:
        {
            isEmpty(&front);
            break;
        }
        case 5:
        {
            size(front);
            break;
        }
        case 6:
        {
            display(front);
            break;
        }
        default:
            printf("Please enter a valid choice.");
        }
        printf("\n");
    }
    return 0;
}