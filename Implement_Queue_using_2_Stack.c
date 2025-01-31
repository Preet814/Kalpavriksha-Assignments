#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} Node;
typedef struct
{
    Node *top;
} Stack;
typedef struct
{
    Stack stack1;
    Stack stack2;
} Queue;
void initializeStack(Stack *stack)
{
    stack->top = NULL;
}
void initializeQueue(Queue *queue)
{
    initializeStack(&queue->stack1);
    initializeStack(&queue->stack2);
}
void push(Stack *stack, int element)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = element;
    newNode->next = stack->top;
    stack->top = newNode;
}
int isStackEmpty(Stack *stack)
{
    if (stack->top == NULL)
    {
        return 1;
    }
    return 0;
}
int stackSize(Stack *stack)
{
    int size = 0;
    Node *curr = stack->top;
    while (curr != NULL)
    {
        size++;
        curr = curr->next;
    }
    return size;
}
int isQueueEmpty(Queue *queue)
{
    if (isStackEmpty(&queue->stack2) && isStackEmpty(&queue->stack1))
        return 1;
    return 0;
}
int pop(Stack *stack)
{
    if (isStackEmpty(stack))
    {
        printf("Underflow Condition: Stack is empty.\n");
        return -1;
    }
    Node *topNode = stack->top;
    int data = topNode->data;
    stack->top = stack->top->next;
    free(topNode);
    return data;
}
void enqueue(Queue *queue, int element)
{
    push(&queue->stack1, element);
}
void dequeue(Queue *queue)
{
    if (isStackEmpty(&queue->stack2))
    {
        while (!isStackEmpty(&queue->stack1))
        {
            int data = pop(&queue->stack1);
            push(&queue->stack2, data);
        }
    }
    if (isStackEmpty(&queue->stack2))
    {
        printf("Queue is empty.\n");
        return;
    }
    int poppedData = pop(&queue->stack2);
    printf("Element popped from the front of queue is %d.\n", poppedData);
}
void peek(Queue *queue)
{
    if (isStackEmpty(&queue->stack2))
    {
        while (!isStackEmpty(&queue->stack1))
        {
            int data = pop(&queue->stack1);
            push(&queue->stack2, data);
        }
    }
    if (isStackEmpty(&queue->stack2))
    {
        printf("Queue is empty.\n");
        return;
    }
    Node *frontNode = queue->stack2.top;
    int peekData = frontNode->data;
    printf("Data present on front of queue is %d.\n", peekData);
}
void size(Queue *queue)
{
    int size1 = stackSize(&queue->stack1);
    int size2 = stackSize(&queue->stack2);
    printf("Size of stack is %d", size1 + size2);
}
void display(Queue *queue)
{
    if (isStackEmpty(&queue->stack2))
    {
        while (!isStackEmpty(&queue->stack1))
        {
            int data = pop(&queue->stack1);
            push(&queue->stack2, data);
        }
    }
    if (isQueueEmpty(queue))
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    Node *curr = queue->stack2.top;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    while (!isStackEmpty(&queue->stack2))
    {
        int data = pop(&queue->stack2);
        push(&queue->stack1, data);
    }
    printf("\n");
}
int main()
{
    Queue queue;
    initializeQueue(&queue);
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
            enqueue(&queue, element);
            break;
        }
        case 2:
        {
            dequeue(&queue);
            break;
        }
        case 3:
        {
            peek(&queue);
            break;
        }
        case 4:
        {
            if (isQueueEmpty(&queue))
            {
                printf("Queue is empty.\n");
            }
            else
            {
                printf("Queue is not empty.\n");
            }
            break;
        }
        case 5:
        {
            size(&queue);
            break;
        }
        case 6:
        {
            display(&queue);
            break;
        }
        default:
            printf("Please enter a valid choice.");
        }
        printf("\n");
    }
    return 0;
}