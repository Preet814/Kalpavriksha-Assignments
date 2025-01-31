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
    Stack stack;
} Queue;
void initializeStack(Stack *stack)
{
    stack->top = NULL;
}
void initializeQueue(Queue *queue)
{
    initializeStack(&queue->stack);
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
int isQueueEmpty(Queue *queue)
{
    if (isStackEmpty(&queue->stack))
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
    push(&queue->stack, element);
}
void dequeue(Queue *queue)
{
    if (isQueueEmpty(queue))
    {
        printf("Queue is empty.\n");
        return;
    }
    if (queue->stack.top->next == NULL)
    {
        int topData = pop(&queue->stack);
        printf("Element popped from front of queue is %d.\n", topData);
        return;
    }
    int topData = pop(&queue->stack);
    dequeue(queue);
    push(&queue->stack, topData);
}
void peek(Queue *queue)
{
    if (isQueueEmpty(queue))
    {
        printf("Queue is empty. No peek element.\n");
        return;
    }
    if (queue->stack.top->next == NULL)
    {
        int topData = queue->stack.top->data;
        printf("Peek element present at front of list is %d.\n", topData);
        // push(&queue->stack,topData);
        return;
    }
    int topData = pop(&queue->stack);
    peek(queue);
    push(&queue->stack, topData);
}
void size(Queue *queue)
{
    if (isQueueEmpty(queue))
    {
        printf("Size of queue is 0.\n");
        return;
    }
    int size = 0;
    Node *topNode = queue->stack.top;
    while (topNode != NULL)
    {
        size++;
        topNode = topNode->next;
    }
    printf("Size of queue is %d.\n", size);
}
void display(Queue *queue)
{
    if (isQueueEmpty(queue))
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    Node *curr = queue->stack.top;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
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