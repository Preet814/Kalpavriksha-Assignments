#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int get_length(char *s){
    int i=0;
    while(s[i]!='\0'){
        i++;
    }
    return i;
}
int check_same(char *s1,char *s2){
    int i=0;
    while(s1[i]!='\0'){
        if(s1[i]!=s2[i])
            return 0;
        i++;
    }
    return 1;
}
int main(){
    int n;
    scanf("%d",&n);
    char *string_1=(char *)malloc(n*sizeof(char));
    char *string_2=(char *)malloc(n*sizeof(char));
    getchar();
    printf("Enter input in string 1 of %d size only:",n);
    scanf("%[^\n]",string_1);
    getchar();
    string_1[n]='\0';
    printf("Enter input in string 2 of %d size only:");
    scanf("%[^\n]",string_2);
    string_2[n]='\0';
    if(check_same(string_1,string_2))
        printf("True");
    int cnt=0;
    int idx1=0;
    int idx2=0;
    int is_flag=0;
    for(int i=0;i<n;i++){
        if(string_1[i]!=string_2[i]){
            cnt++;
            if(idx1==0 && is_flag==0){
                is_flag=1;
                idx1=i;
            }
            else
                idx2=i;
        }
    }
    if(cnt==0 || cnt==2){
        if(string_1[idx1]==string_2[idx2] && string_1[idx2]==string_2[idx1])
            printf("True");
        else
            printf("False");
    }
    else
        printf("False");
    
    return 0;
}