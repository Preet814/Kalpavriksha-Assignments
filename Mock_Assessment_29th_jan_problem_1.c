#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    int id;
    char severity[100];
    struct node* next;
}Node;
typedef struct {
    int id;
}Map;
int mp_search(Map mp[],int size,int id){
    for(int i=0;i<size;i++){
        if(mp[i].id==id)
            return i;
    }
    return -1;
}
void display(Node* head){
    if(head==NULL){
        printf("List is empty.\n");
        return ;
    }
    Node* temp=head;
    while(temp!=NULL){
        printf("%d %s\n",temp->id,temp->severity);
        temp=temp->next;
    }
    printf("\n");
}
void addNode(Node** head,int p_id,char condition[]){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->id=p_id;
    strcpy(newNode->severity,condition);
    newNode->next=NULL;
    if(*head==NULL){
        *head=newNode;
        return;
    }
    Node* temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}
int main(){
    int n;
    Map mp[100];
    int mpIdx=0;
    Node* criticalHead=NULL;
    Node* seriousHead=NULL;
    Node* stableHead=NULL;
    scanf("%d",&n);
    while(n!=0){
        int id;
        scanf("%d",&id);
        getchar();
        char condition[100];
        fgets(condition,sizeof(condition),stdin);
        condition[strcspn(condition,"\n")]='\0';
        int idx=mp_search(mp,mpIdx,id);
        if(idx!=-1){
            printf("This id is already inserted before.\n");
            continue;
        }
        if(strcmp(condition,"Critical")==0){
            addNode(&criticalHead,id,condition);
        }
        else if(strcmp(condition,"Serious")==0){
            addNode(&seriousHead,id,condition);
        }
        else if(strcmp(condition,"Stable")==0){
            addNode(&stableHead,id,condition);
        }
        else{
            printf("Please enter correct severity.\n");
            continue;
        }
        if(idx==-1){
            mp[mpIdx].id=id;
            mpIdx++;
        }
        n--;
    }
    Node* criticalPtr=criticalHead;
    Node* seriousPtr=seriousHead;
    Node* stablePtr=stableHead;
    while(criticalPtr->next!=NULL){
        criticalPtr=criticalPtr->next;
    }
    while(seriousPtr->next!=NULL){
        seriousPtr=seriousPtr->next;
    }
    while(stablePtr->next!=NULL){
        stablePtr=stablePtr->next;
    }
    if(criticalHead==NULL){
        if(seriousHead==NULL){
            criticalHead=stableHead;
        }
        else
            criticalHead=seriousHead;
    }
    if(seriousHead==NULL){
        criticalPtr->next=stableHead;
    }
    else{
        criticalPtr->next=seriousHead;
    }
    seriousPtr->next=stableHead;
    printf("Output:\n");
    display(criticalHead);
}