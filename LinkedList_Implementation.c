#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    int data;
    struct node* next;
}Node;
Node *head=NULL;
void insertAtBeginning(int value){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    if(head==NULL){
        newNode->next=NULL;
        head=newNode;
        return;
    }
    newNode->next=head;
    head=newNode;
}
void insertAtEnd(int value){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    if(head==NULL){
        newNode->next=NULL;
        head=newNode;
        return;
    }
    Node *tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    tail->next=newNode;
    newNode->next=NULL;
}
void insertAtPosition(int value,int position){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    if(position<=0){
        printf("Error: Invalid Position(Position is 1 based indexing)!\n");
        free(newNode);
        return;
    }
    if(position==1){
        if(head==NULL){
            newNode->next=NULL;
            head=newNode;
            return;
        }
        else{
            newNode->next=head;
            head=newNode;
            return;
        }
    }
    Node* temp=head;
    while(position!=2 && temp!=NULL){
        position--;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Error: Invalid Position(Entered position must be in present in the list)!\n");
        free(newNode);
        return;
    }
    Node* next=temp->next;
    temp->next=newNode;
    newNode->next=next;
    return;
}
void updateAtPosition(int value,int position){
    if(position<=0){
        printf("Error: Invalid Position(Position is 1 based indexing)!\n");
        return;
    }
    Node* temp=head;
    int i=1;
    while(i<position && temp!=NULL){
        i++;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Error: Invalid Position(Entered position must be in present in the list)!\n");
        return;
    }
    temp->data=value;
}
void deleteAtBeginning(){
    if(head==NULL){
        printf("Error: No element present in list to delete!\n");
        return;
    }
    Node *temp=head;
    head=temp->next;
    temp->next=NULL;
    free(temp);
}
void deleteAtEnd(){
    if(head==NULL){
        printf("Error: No element present in list to delete!\n");
        return;
    }
    if(head->next==NULL){
        head=NULL;
        free(head);
        return;
    }
    Node* temp=head;
    Node* prev=NULL;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    free(temp);
}
void deleteAtPosition(int position){
    if(head==NULL){
        printf("Error: No element present in list to delete!\n");
        return;
    }
    if(position<=0){
        printf("Error: Invalid Position(Position is 1 based indexing)!\n");
        return;
    }
    int i=1;
    if(position==1){
        if(head->next==NULL){
            head=NULL;
            free(head);
        }
        else{
            Node* temp=head;
            head=temp->next;
            temp->next=NULL;
            free(temp);
        }
        return;
    }
    Node* prev=NULL;
    Node* temp=head;
    while(i<position && temp!=NULL){
        i++;
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Error: Invalid Position(Entered position must be in present in the list)!\n");
        return ;
    }
    prev->next=temp->next;
    temp->next=NULL;
    free(temp);
}
void display_list(){
    if(head==NULL){
        printf("List is Empty.\n");
        return;
    }
    Node* temp=head;
    printf("List : ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    free(temp);
    printf("\n");
}
int main(){
    int n;
    printf("Input number of operations: ");
    scanf("%d",&n);
    if(n<1 || n>100){
        printf("Error: Number of operation must be in range of 1 to 100!");
        return 0;
    }
    while(n--){
        int operation_number;
        scanf("%d",&operation_number);
        switch(operation_number){
            case 1:{
                int value;
                scanf("%d",&value);
                if(value<-1000 || value>1000){
                    printf("Error: Value to input in node must be in range of -10^3 to 10^3!\n");
                    return 0;
                }
                insertAtEnd(value);
                break;
            }
            case 2:{
                int value;
                scanf("%d",&value);
                if(value<-1000 || value>1000){
                    printf("Error: Value to input in node must be in range of -10^3 to 10^3!\n");
                    return 0;
                }
                insertAtBeginning(value);
                break;
            }
            case 3:{
                int value;
                int position;
                scanf("%d",&position);
                scanf("%d",&value);
                if(value<-1000 || value>1000){
                    printf("Error: Value to input in node must be in range of -10^3 to 10^3!\n");
                    return 0;
                }
                insertAtPosition(value,position);
                break;
            }
            case 4:{
                display_list();
                break;
            }
            case 5:{
                int value;
                int position;
                scanf("%d",&position);
                scanf("%d",&value);
                if(value<-1000 || value>1000){
                    printf("Error: Value to input in node must be in range of -10^3 to 10^3!\n");
                    return 0;
                }
                updateAtPosition(value,position);
                break;
            }
            case 6:{
                deleteAtBeginning();
                break;
            }
            case 7:{
                deleteAtEnd();
                break;
            }
            case 8:{
                int position;
                scanf("%d",&position);
                deleteAtPosition(position);
                break;
            }
            default: {
                printf("Error: Enter correct operation number!\n");
                return 0;
            }
        }
    }
    return 0;
}
