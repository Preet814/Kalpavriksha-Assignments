#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} Node;
typedef struct
{
    Node *front;
    Node *rear;
} Queue;
typedef struct
{
    Queue queue1;
    Queue queue2;
} Stack;
void initializeQueue(Queue *queue)
{
    queue->front = NULL;
    queue->rear = NULL;
}
int isQueueEmpty(Queue *queue)
{
    if (queue->front == NULL)
        return 1;
    return 0;
}
void enqueue(Queue *queue, int element)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = element;
    newNode->next = NULL;
    if (isQueueEmpty(queue))
    {
        queue->front = newNode;
        queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}
int dequeue(Queue *queue)
{
    if (isQueueEmpty(queue))
    {
        printf("Underflow condition: Queue is empty.\n");
        return -1;
    }
    Node *frontNode = queue->front;
    int data = frontNode->data;
    queue->front = queue->front->next;
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    free(frontNode);
    return data;
}
void initializeStack(Stack *stack)
{
    initializeQueue(&stack->queue1);
    initializeQueue(&stack->queue2);
}
void push(Stack *stack, int element)
{
    enqueue(&stack->queue2, element);
    while (!isQueueEmpty(&stack->queue1))
    {
        int data = dequeue(&stack->queue1);
        enqueue(&stack->queue2, data);
    }
    Queue temp = stack->queue1;
    stack->queue1 = stack->queue2;
    stack->queue2 = temp;
}
int isStackEmpty(Stack *stack)
{
    if (isQueueEmpty(&stack->queue1))
    {
        return 1;
    }
    return 0;
}
void pop(Stack *stack)
{
    if (isStackEmpty(stack))
    {
        printf("Stack is empty. No element can be popped off.\n");
        return;
    }
    int data = dequeue(&stack->queue1);
    printf("Element popped from the top of stack is %d.\n", data);
}
void peek(Stack *stack)
{
    if (isStackEmpty(stack))
    {
        printf("Stack is empty. No peek element.\n");
        return;
    }
    Node *frontNode = stack->queue1.front;
    int data = frontNode->data;
    printf("Peek element present in stack is %d.\n", data);
}
void size(Stack *stack)
{
    if (isStackEmpty(stack))
    {
        printf("Size of stack is 0.\n");
        return;
    }
    int size = 0;
    Node *curr = stack->queue1.front;
    while (curr != NULL)
    {
        size++;
        curr = curr->next;
    }
    printf("Size of stack is %d.\n", size);
}
void display(Stack *stack)
{
    if (isStackEmpty(stack))
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack: \n");
    Node *curr = stack->queue1.front;
    while (curr != NULL)
    {
        printf("%d\n", curr->data);
        curr = curr->next;
    }
    printf("\n");
}
int main()
{
    Stack stack;
    initializeStack(&stack);
    int number_of_operations;
    printf("Enter number of operations to perform on stack: ");
    scanf("%d", &number_of_operations);
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
            push(&stack, element);
            break;
        }
        case 2:
        {
            pop(&stack);
            break;
        }
        case 3:
        {
            peek(&stack);
            break;
        }
        case 4:
        {
            if (isStackEmpty(&stack))
            {
                printf("Stack is Empty.\n");
            }
            else
            {
                printf("Stack is not empty.\n");
            }
            break;
        }
        case 5:
        {
            size(&stack);
            break;
        }
        case 6:
        {
            display(&stack);
            break;
        }
        default:
            printf("Please enter a valid choice.");
        }
        printf("\n");
    }
    return 0;
}