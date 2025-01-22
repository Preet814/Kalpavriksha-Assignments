#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} Node;
void addNode(Node **head, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *tempNode = *head;
    while (tempNode->next != NULL)
    {
        tempNode = tempNode->next;
    }
    tempNode->next = newNode;
    return;
}
void displayList(Node *head)
{
    if (head == NULL)
    {
        printf("list is empty.\n");
        return;
    }
    Node *tempNode = head;
    while (tempNode != NULL)
    {
        printf("%d ", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("\n");
}
Node *reverseList(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    while (curr != NULL)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
Node *reverseKNodes(Node *head, int k_nodes)
{
    Node *dummy = (Node *)malloc(sizeof(Node));
    Node *dummy_ptr = dummy;
    dummy->next = head;
    while (dummy != NULL)
    {
        int count_nodes = k_nodes;
        Node *temproryNode = dummy->next;
        Node *currHead = temproryNode;
        while (count_nodes != 1 && temproryNode != NULL)
        {
            temproryNode = temproryNode->next;
            count_nodes--;
        }
        if (temproryNode == NULL)
        {
            dummy->next = reverseList(currHead);
            break;
        }
        Node *nextNode = temproryNode->next;
        temproryNode->next = NULL;
        dummy->next = reverseList(currHead);
        while (dummy->next != NULL)
        {
            dummy = dummy->next;
        }
        if (dummy == NULL)
            break;
        dummy->next = nextNode;
        dummy = nextNode;
        count_nodes = k_nodes;
        while (count_nodes != 1 && dummy != NULL)
        {
            dummy = dummy->next;
            count_nodes--;
        }
        if (dummy == NULL)
            break;
    }
    return dummy_ptr->next;
}

int main()
{
    Node *head = NULL;
    int nodeValue;
    char characterForSpaceandNextLine;
    while ((scanf("%d", &nodeValue)) == 1)
    {
        addNode(&head, nodeValue);
        if ((characterForSpaceandNextLine = getchar()) == '\n')
            break;
    }
    int kNodes;
    scanf("%d", &kNodes);
    if (kNodes <= 0)
    {
        printf("Error: Value of k must be greator than 0.\n");
        return 0;
    }
    printf("Input: \n");
    displayList(head);
    printf("k: %d\n", kNodes);
    printf("Output: \n");
    Node *newHead = reverseKNodes(head, kNodes);
    displayList(newHead);
    return 0;
}