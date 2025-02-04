#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum
{
    VIP = 3,
    SENIOR_CITIZEN = 2,
    GENERAL = 1
} Passenger_type;
typedef struct
{
    int id;
    Passenger_type category;
    char name[100];
} Passenger;
Passenger_type getPassengerType(char *category)
{
    if (strcmp(category, "VIP") == 0)
    {
        return VIP;
    }
    else if (strcmp(category, "SENIOR_CITIZEN") == 0)
    {
        return SENIOR_CITIZEN;
    }
    else
    {
        return GENERAL;
    }
}
void merge(Passenger **queue, int start, int mid, int end)
{
    int i = start;
    int j = mid + 1;
    int tempSize = end - start + 1;
    Passenger *temp = (Passenger *)malloc(tempSize * sizeof(Passenger));
    int tempIdx = 0;
    while (i <= mid && j <= end)
    {
        if ((*queue)[i].category >= (*queue)[j].category)
        {
            temp[tempIdx].id = (*queue)[i].id;
            temp[tempIdx].category = (*queue)[i].category;
            strcpy(temp[tempIdx].name, (*queue)[i].name);
            i++;
        }
        else
        {
            temp[tempIdx].id = (*queue)[j].id;
            temp[tempIdx].category = (*queue)[j].category;
            strcpy(temp[tempIdx].name, (*queue)[j].name);
            j++;
        }
        tempIdx++;
    }
    while (i <= mid)
    {
        temp[tempIdx].id = (*queue)[i].id;
        temp[tempIdx].category = (*queue)[i].category;
        strcpy(temp[tempIdx].name, (*queue)[i].name);
        i++;
        tempIdx++;
    }
    while (j <= end)
    {
        temp[tempIdx].id = (*queue)[j].id;
        temp[tempIdx].category = (*queue)[j].category;
        strcpy(temp[tempIdx].name, (*queue)[j].name);
        j++;
        tempIdx++;
    }
    for (int i = start; i <= end; i++)
    {
        (*queue)[i].id = temp[i - start].id;
        (*queue)[i].category = temp[i - start].category;
        strcpy((*queue)[i].name, temp[i - start].name);
    }
}
void sortQueue(Passenger **queue, int start, int end)
{
    if (start >= end)
        return;
    int mid = start + (end - start) / 2;
    sortQueue(queue, start, mid);
    sortQueue(queue, mid + 1, end);
    merge(queue, start, mid, end);
}
void enqueue(Passenger **queue, int *front, int *rear, int id, Passenger_type category, char name[])
{
    if ((*rear) == -1)
    {
        (*front) = 0;
        (*rear) = 0;
    }
    else
    {
        (*rear)++;
    }
    (*queue)[*rear].id = id;
    (*queue)[*rear].category = category;
    strcpy((*queue)[*rear].name, name);
}
char *getCategoryName(int category)
{
    if (category == 3)
    {
        return "VIP";
    }
    else if (category == 2)
    {
        return "SENIOR_CITIZEN";
    }
    else
    {
        return "GENERAL";
    }
}
void dequeue(Passenger **queue, int *front, int *rear)
{
    if (*front == -1)
    {
        printf("Passenger list is empty.\n");
        return;
    }
    printf("Serving Passenger : ID %d, Name %s, Type %s\n", (*queue)[*front].id, (*queue)[*front].name, getCategoryName((*queue)[*front].category));
    (*front)++;
    if (*front > *rear)
    {
        *front = 0;
        *rear = 0;
    }
}
void display(Passenger *queue, int front, int rear)
{
    printf("Waiting Passengers: \n");
    for (int i = front; i <= rear; i++)
    {
        printf("id: %d , Name : %s , Type : %s\n", queue[i].id, queue[i].name, getCategoryName(queue[i].category));
    }
}
int main()
{
    Passenger *queue = (Passenger *)malloc(1000 * sizeof(Passenger));
    int front = -1;
    int rear = -1;
    int number_of_operations;
    scanf("%d", &number_of_operations);
    while (number_of_operations--)
    {
        int choice;
        scanf("%d", &choice);
        getchar();
        if (choice == 1)
        {
            int id;
            char category[30];
            char name[10];
            scanf("%d,%[^,],\"%[^\"]\";", &id, category, name);
            Passenger_type type = getPassengerType(category);
            enqueue(&queue, &front, &rear, id, type, name);
            sortQueue(&queue, front, rear);
        }
        else if (choice == 2)
        {
            dequeue(&queue, &front, &rear);
        }
        else if (choice == 3)
        {
            display(queue, front, rear);
        }
        else
        {
            printf("Enter valid choice.\n");
            number_of_operations++;
        }
    }
    return 0;
}