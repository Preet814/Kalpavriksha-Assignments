#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} Node;
void push(Node **head, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    *head = newNode;
}
void pop(Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    Node *temp = *head;
    *head = (*head)->next;
    temp->next = NULL;
    printf("Element poped out from top of stack is : %d", temp->data);
    free(temp);
}
void peek(Node **head)
{
    if (*head == NULL)
    {
        printf("Stack is empty. No Peak element present in stack.\n");
        return;
    }
    printf("Peek element of stack is %d.\n", (*head)->data);
}
void check_if_empty(Node **head)
{
    if ((*head) == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        printf("Stack is not empty.\n");
    }
    return;
}
void size_of_stack(Node **head)
{
    int size = 0;
    Node *temp = *head;
    while (temp != NULL)
    {
        size++;
        temp = temp->next;
    }
    printf("Size of stack is %d.\n", size);
}
void display(Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    Node *head = NULL;
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
            push(&head, element);
            break;
        }
        case 2:
        {
            pop(&head);
            break;
        }
        case 3:
        {
            peek(&head);
            break;
        }
        case 4:
        {
            check_if_empty(&head);
            break;
        }
        case 5:
        {
            size_of_stack(&head);
            break;
        }
        case 6:
        {
            display(head);
            break;
        }
        default:
            printf("Please enter a valid choice.");
        }
        printf("\n");
    }
    return 0;
}