#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int getLength(char *input)
{
    int i = 0;
    while (input[i] != '\0')
        i++;
    return i;
}
void printQueue(char *queue,int front,int rear){
    printf("Queue: \n");
    for(int i=front;i<=rear;i++){
        printf("%c ",queue[i]);
    }
    printf("\n");
}
int main()
{
    char *input = (char *)malloc(100000 * sizeof(char));
    fgets(input, 100000, stdin);
    input[strcspn(input, "\n")] = '\0';
    printf("Input : %s\n", input);
    int len = getLength(input);
    char *queue = (char *)malloc(len * sizeof(char));
    int front = -1;
    int rear = -1;
    char *answer = (char *)malloc(100000 * sizeof(char));
    int ansIdx = 0;
    int i=0;
    while(i<len)
    {
        if (rear == -1)
        {
            front = 0;
            rear = 0;
            queue[front] = input[i];
            answer[ansIdx++] = queue[front];
            i++;
        }
        else if (queue[front] == input[i])
        {
            while(input[i]==queue[front] && i<len){
                answer[ansIdx++] = '-';
                answer[ansIdx++]='1';
                i++;
            }
            front++;
            if(front>rear){
                front=-1;
                rear=-1;
            }

        }
        else
        {
            answer[ansIdx++] = queue[front];
            rear++;
            queue[rear] = input[i];
            i++;
        }
        // printf("char : %c\n",answer[ansIdx-1]);
        // printQueue(queue,front,rear);
    }
    answer[ansIdx]='\0';
    printf("Answer : %s", answer);
    return 0;
}