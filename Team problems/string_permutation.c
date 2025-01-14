#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int length(char str[]){
    int i=0;
    while(str[i]!='\0')
        i++;
    return i;
}
void swap_char(char *a,char *b){
    char temp=*a;
    *a=*b;
    *b=temp;
}
void function(char str[],int idx,int size){
    if(idx==size){
        printf("%s  ",str);
        return;
    }
    for(int i=idx;i<size;i++){
        swap_char(&str[i],&str[idx]);
        function(str,idx+1,size);
        swap_char(&str[i],&str[idx]);
    }
}
int main(){
    char string[100];
    printf("Enter input: ");
    fgets(string,sizeof(string),stdin);
    string[strcspn(string,"\n")]='\0';
    printf("String: %s\n",string);
    int n=length(string);
    function(string,0,n);
    return 0;
}