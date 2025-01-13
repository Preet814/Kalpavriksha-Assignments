#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void print(char *word)
{
    int i = 0;
    while (word[i] != '$')
    {
        printf("%c", word[i]);
        i++;
    }
    printf("\n");
}
int size(char word[]){
    int cnt=0;
    for(int i=0;word[i]!='$';i++){
        cnt++;
    }
    return cnt;
}
int main()
{
    int n;
    printf("Enter input: ");
    scanf("%d", &n);
    if (n == 1)
    {
        printf("1");
        return 0;
    }
    char word[5000]="11$";
    for(int i=1;i<n-1;i++){
        int idx=size(word);
        int k=0;
        char temp[5000];
        int cnt=1;
        for(int j=1;j<=idx;j++){
            if(word[j]!=word[j-1]){
                temp[k++]=cnt+'0';
                temp[k++]=word[j-1];
                cnt=1;
            }
            else{
                cnt++;
            }
            printf("j: %d\n",j);
        }
        temp[k]='$';
        strcpy(word,temp);
    }
    print(word);
    return 0;
}