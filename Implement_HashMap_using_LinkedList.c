#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define hash_table_size 10;
typedef struct node
{
    int key;
    int value;
    int index;
    struct node *next;
    struct node *right;
} Node;
Node *createNode(Node **head, int value, int key)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->index = key % hash_table_size;
    newNode->next = NULL;
    newNode->right = NULL;
    return newNode;
}
void addNodeInDictionary(Node **head, int value, int key)
{
    Node *newNode = createNode(head, value, key);
    int index = key % hash_table_size;
    if ((*head) == NULL)
    {
        (*head) = newNode;
        return;
    }
    Node *curr = (*head);
    while (curr->next != NULL && curr->index != index)
    {
        curr = curr->next;
    }
    if (curr->next == NULL && curr->index != index)
    {
        curr->next = newNode;
    }
    else
    {
        Node *temp = curr;
        while (temp->right != NULL && temp->key != key)
        {
            temp = temp->right;
        }
        if (temp->key == key)
        {
            temp->value = value;
            free(newNode);
        }
        else
        {
            temp->right = newNode;
        }
    }
}
void searchInDictionary(Node *head, int key)
{
    int index = key % hash_table_size;
    if (head == NULL)
    {
        printf("Dictionary is Empty.\n");
        return;
    }
    Node *curr = head;
    while (curr != NULL && curr->index != index)
    {
        curr = curr->next;
    }
    if (curr == NULL)
    {
        printf("Key %d is not present in dictionary.\n", key);
        return;
    }
    Node *temp = curr;
    while (temp != NULL && temp->key != key)
    {
        temp = temp->right;
    }
    if (temp == NULL)
    {
        printf("Key %d is not present in dictionary.\n", key);
        return;
    }
    printf("Value: %d\n", temp->value);
}
void deleteInDictionary(Node **head, int key)
{
    int index = key % hash_table_size;
    if ((*head) == NULL)
    {
        printf("Dictionary is empty. Deletion cannot be performed.\n");
        return;
    }
    Node *prev = NULL;
    Node *curr = (*head);
    while (curr != NULL && curr->index != index)
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL)
    {
        printf("Key %d is not present in Dictionary.\n", key);
        return;
    }
    Node *prevTemp = NULL;
    Node *currTemp = curr;
    while (currTemp != NULL && currTemp->key != key)
    {
        prevTemp = currTemp;
        currTemp = currTemp->right;
    }
    if (currTemp == NULL)
    {
        printf("Key %d is not present in Dictionary.\n", key);
        return;
    }
    printf("Key %d deleted.\n", key);
    if (prev == NULL && prevTemp == NULL)
    {
        if (currTemp->right == NULL)
        {
            (*head) = currTemp->next;
        }
        else
        {
            (*head) = currTemp->right;
            Node *currNext = curr->next;
            (*head)->next = currNext;
            curr->right = NULL;
            curr->next = NULL;
            free(curr);
        }
    }
    else if (prev == NULL && prevTemp != NULL)
    {
        prevTemp->right = currTemp->right;
        currTemp->right = NULL;
        free(currTemp);
    }
    else
    {
        if (prevTemp == NULL)
        {
            if (currTemp->right == NULL)
            {
                Node *currNext = curr->next;
                prev->next = currNext;
                curr->next = NULL;
                free(curr);
            }
            else
            {
                Node *currTempRight = currTemp->right;
                Node *currNext = curr->next;
                prev->next = currTempRight;
                currTempRight->next = currNext;
                currTemp->next = NULL;
                currTemp->right = NULL;
                free(currTemp);
            }
        }
        else
        {
            Node *currTempRight = currTemp->right;
            prevTemp->right = currTempRight;
            currTemp->right = NULL;
            free(currTemp);
        }
    }
}
void display(Node *head)
{
    if (head == NULL)
    {
        printf("Dictionary is empty.\n");
        return;
    }
    printf("Dictionary : \n");
    Node *curr = head;
    while (curr != NULL)
    {
        Node *temp = curr;
        printf("Index %d: ", curr->index);
        while (temp->right != NULL)
        {
            printf(" (%d,%d) ->", temp->key, temp->value);
            temp = temp->right;
        }
        printf(" (%d,%d)", temp->key, temp->value);
        printf("\n");
        curr = curr->next;
    }
    printf("\n");
}
int getInputChoice()
{
    int input;
    char ch;
    while (1)
    {
        printf("\nEnter your choice: ");
        if ((scanf("%d%c", &input, &ch) == 2 && ch == '\n'))
            break;
        printf("\nError: Enter input correctly!\n");
        while (getchar() != '\n')
            ;
    }
    return input;
}
int getInputKey()
{
    int input;
    char ch;
    while (1)
    {
        printf("Enter Key: ");
        if (scanf("%d", &input) == 1)
        {
            ch = getchar();
            if (ch == '\n' && input >= 0)
            {
                break;
            }
            else
            {
                printf("\nError: Key should be a positive integer.\n");
                while (ch != '\n' && ch != EOF)
                {
                    ch = getchar();
                }
            }
        }
        else
        {
            printf("\nError: Key should be a positive integer.\n");
            while ((ch = getchar()) != '\n' && ch != EOF)
                ;
        }
    }
    return input;
}
int getInputValue()
{
    int input;
    char ch;
    while (1)
    {
        printf("Enter Value: ");
        if (scanf("%d", &input) == 1)
        {
            ch = getchar();
            if (ch == '\n' && input >= 0)
            {
                break;
            }
            else
            {
                printf("\nError: Value should be a positive integer.\n");
                while (ch != '\n' && ch != EOF)
                {
                    ch = getchar();
                }
            }
        }
        else
        {
            printf("\nError: Value should be a positive integer.\n");
            while ((ch = getchar()) != '\n' && ch != EOF)
                ;
        }
    }
    return input;
}
int main()
{
    Node *head = NULL;
    while (1)
    {
        printf("\n---------------Hash Map Dictionary-------------\n");
        printf("1) Insert(Put)\n");
        printf("2) Search(Get)\n");
        printf("3) Delete(Remove)\n");
        printf("4) Display\n");
        printf("5) Exit\n");
        int choice = getInputChoice();
        if (choice == 5)
        {
            printf("Exitting ...\n");
            break;
        }
        switch (choice)
        {
        case 1:
        {
            int key = getInputKey();
            int value = getInputValue();
            addNodeInDictionary(&head, value, key);
            break;
        }
        case 2:
        {
            int key = getInputKey();
            searchInDictionary(head, key);
            break;
        }
        case 3:
        {
            int key = getInputKey();
            deleteInDictionary(&head, key);
            break;
        }
        case 4:
        {
            display(head);
            break;
        }
        default:
            printf("Error: Please enter valid choice !\n");
        }
    }
    return 0;
}