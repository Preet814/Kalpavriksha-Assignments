#include <stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    char word[100];
    int count;
}Map;
int mp_search(Map mp[],char name[],int size){
    for(int i=0;i<size;i++){
        if(strcmp(mp[i].word,name)==0){
            return i;
        }
    }
    return -1;
}
int check_space(char fruit[]){
    int i=0;
    while(fruit[i]!='\0'){
        if(fruit[i]==' ')
            return 1;
        i++;
    }
    return 0;
}
int main()
{
    int row,col;
    Map mp[100];
    scanf("%d",&row);
    scanf("%d",&col);
    char ***matrix=(char ***)malloc(row*sizeof(char**));
    for(int i=0;i<row;i++){
        matrix[i]=(char **)malloc(col*sizeof(char *));
        for(int j=0;j<col;j++){
            matrix[i][j]=(char *)malloc(50*sizeof(char));
        }
    }
    getchar();
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            scanf("%[^\n]s",matrix[i][j]);
            if(check_space(matrix[i][j])==1){
                printf("Error: do not enter name of fruit with space!\n");
                return 1;
            }
            getchar();
        }
    }
    int mp_count=row*col;
    int cnt=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(i==0 && j==0){
                strcpy(mp[0].word,matrix[i][j]);
                mp[cnt].count=1;
                mp_count++;
                cnt++;
            }
            else{
                int idx=mp_search(mp,matrix[i][j],cnt);
                if(idx==-1){
                    strcpy(mp[cnt].word,matrix[i][j]);
                    mp[cnt].count=1;
                    cnt++;
                }
                else{
                    mp[idx].count++;
                }
            }
        }
    }
    printf("\n");
    for(int i=0;i<mp_count;i++){
        if(mp[i].count>1){
            printf("%s - %d\n",mp[i].word,mp[i].count);
        }
    }
    int flag=1;
    for(int i=0;i<mp_count;i++){
        if(mp[i].count>1){
            flag=0;
        }
    }
    if(flag==1){
        printf("No word found!\n");
    }
    return 0;
}
