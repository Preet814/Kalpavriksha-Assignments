#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}Node;
void addNode(Node** head,int value){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    newNode->next=NULL;
    newNode->prev=NULL;
    if(*head==NULL){
        *head=newNode;
        return;
    }
    Node* temp=*head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newNode;
    newNode->prev=temp;
    return;
}
int calculateLastKSum(Node* head,int k_nodes){
    if(head==NULL)
        return 0;
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    int sum=0;
    while(temp!=NULL && k_nodes--){
        sum+=temp->data;
        temp=temp->prev;
    }
    return sum;
    
}
void displayList(Node* head){
    if(head==NULL){
        printf("List is empty.\n");
        return;
    }
    Node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main(){
    int number_of_operations,k_number_of_nodes;
    Node* head=NULL;
    scanf("%d",&number_of_operations);
    scanf("%d",&k_number_of_nodes);
    int *answer_array=(int *)malloc(sizeof(int));
    int idx=0;
    for(int i=0;i<number_of_operations;i++){
        getchar();
        char operation_character;
        scanf("%c",&operation_character);
        if(operation_character=='A'){
            int nodeValue;
            scanf("%d",&nodeValue);
            addNode(&head,nodeValue);
        }
        else if(operation_character=='S'){
            int sum=calculateLastKSum(head,k_number_of_nodes);
            answer_array=(int *)realloc(answer_array,idx+1*sizeof(int));
            answer_array[idx++]=sum;
        }
        else{
            printf("Error: Enter valid operation.\n");
            break;
        }
    }
    printf("output: \n");
    int size_of_array=idx;
    for(int i=0;i<size_of_array;i++){
        printf("%d\n",answer_array[i]);
    }
    printf("list is : ");
    displayList(head);
    return 0;
}