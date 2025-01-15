#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    char character;
    int character_count;
    int character_index;
}Map;
int mp_search(Map mp[],char character,int size){
    for(int i=0;i<size;i++){
        if(mp[i].character==character)
            return i;
    }
    return -1;
}
int main(){
    char string[100];
    fgets(string,sizeof(string),stdin);
    string[strcspn(string,"\n")]='\0';
    int n=strlen(string);
    char ch;
    scanf("%c",&ch);
    Map mp[52];
    int i=0;
    int mp_cnt=0;
    while(string[i]!='\0'){
        if(string[i]==' '){
            i++;
            continue;
        }
        if(mp_cnt==0){
            mp[mp_cnt].character=string[i];
            mp[mp_cnt].character_count=1;
            mp[mp_cnt].character_index=i;
            mp_cnt++;
        }
        else{
            int idx=mp_search(mp,string[i],mp_cnt);
            if(idx==-1){
                mp[mp_cnt].character=string[i];
                mp[mp_cnt].character_count=1;
                mp[mp_cnt].character_index=i;
                mp_cnt++;
            }
            else{
                mp[idx].character_count++;
            }
        }
        i++;
    }
    int idx=mp_cnt+1;
    for(int i=0;i<mp_cnt;i++){
        if(mp[i].character_count==1){
            if(mp[i].character_index<idx){
                idx=mp[i].character_index;
            }
        }
    }
    if(idx==mp_cnt+1){
        printf("%s",string);
        return 0;
    }
    string[idx]=ch;
    printf("%s",string);
    return 0;
}