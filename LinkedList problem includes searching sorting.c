#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} Node;
int isValidInteger(char *str)
{
    int i = 0;
    if (str[0] == '-')
        i++;
    if (str[i] == '\0')
        return 0;
    for (; str[i] != '\0'; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return 0;
    }
    return 1;
}

int stringToInteger(char *str)
{
    int result = 0, sign = 1, i = 0;
    if (str[0] == '-')
    {
        sign = -1;
        i++;
    }
    for (; str[i] != '\0'; i++)
    {
        result = result * 10 + (str[i] - '0');
    }
    return sign * result;
}
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
    Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}
int takeInput(Node **head)
{
    char input[100];
    char *token;

    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    token = strtok(input, " ");
    while (token != NULL)
    {
        if (isValidInteger(token))
        {
            int inputNumber = stringToInteger(token);
            addNode(head, inputNumber);
        }
        else
        {
            printf("Error: Invalid input! Please enter valid integers.\n", token);
            return 0;
        }
        token = strtok(NULL, " ");
    }
    return 1;
}
void printList(Node *head)
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
Node *getMid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node *mergeTwoSortedList(Node *left, Node *right)
{
    Node *ans = (Node *)malloc(sizeof(Node));
    ans->next = NULL;
    Node *temp = ans;
    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }
    while (left != NULL)
    {
        temp->next = left;
        temp = left;
        left = left->next;
    }
    while (right != NULL)
    {
        temp->next = right;
        temp = right;
        right = right->next;
    }
    ans = ans->next;
    return ans;
}
Node *sortList(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *mid = getMid(head);
    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;
    left = sortList(left);
    right = sortList(right);
    Node *ans = mergeTwoSortedList(left, right);
    return ans;
}
int listSize(Node *head)
{
    Node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}
Node *getMiddleNode(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *slow = head;
    Node *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
float findMedianInList(Node *head)
{
    float median;
    int size = listSize(head);
    if (size & 1)
    {
        Node *medianNode = getMiddleNode(head);
        median = medianNode->data;
    }
    else
    {
        Node *middleNode1 = getMiddleNode(head);
        Node *middleNode2 = middleNode1->next;
        median = (middleNode1->data + middleNode2->data) / 2.0;
    }
    return median;
}
int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;
    printf("Input integers for list 1: \n");
    if(takeInput(&head1)==0){
        return 0;
    }
    printf("Input integers for list 2: \n");
    if(takeInput(&head2)==0){
        return 0;
    }
    printf("\nInput : \n");
    printf("List 1 : ");
    printList(head1);
    printf("List 2 : ");
    printList(head2);
    Node *sortedHead1 = sortList(head1);
    Node *sortedHead2 = sortList(head2);
    Node *mergedSortedList = mergeTwoSortedList(sortedHead1, sortedHead2);
    printf("\nOutput: \n");
    printf("List : ");
    printList(mergedSortedList);
    float median = findMedianInList(mergedSortedList);
    printf("Median : %.1f", median);
    return 0;
}