#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int check_space(char name[]){
    int i=0;
    while(name[i]!='\0'){
        if(name[i]==' ')
            return 1;
        i++;
    }
    return 0;
}
int main(){
    int size_of_row,size_of_col;
    printf("Enter size of row (1<=row<=10): ");
    scanf("%d",&size_of_row);
    if(size_of_row<1 || size_of_row>10){
        printf("Error: Row size should be in range from 1 to 10!");
        return 0;
    }
    printf("Enter size of column (1<=column<=101): ");
    scanf("%d",&size_of_col);
    if(size_of_col<1 || size_of_col>101){
        printf("Error: Column size should be in range from 1 to 101!");
        return 0;
    }
    char ***names_matrix=(char ***)malloc(size_of_row*sizeof(char**));
    int i,j;
    for(i=0;i<size_of_row;i++){
        names_matrix[i]=(char **)malloc(size_of_row*sizeof(char **));
        for(j=0;j<size_of_col;j++){
            names_matrix[i][j]=(char *)malloc(50*sizeof(char *));
        }
    }
    getchar();
    int vowel_count=0;
    int max_length_of_name=0;
    for(i=0;i<size_of_row;i++){
        for(j=0;j<size_of_col;j++){
            printf("Name at (%d,%d): ",i,j);
            scanf("%[^\n]s",names_matrix[i][j]);
            if(check_space(names_matrix[i][j])){
                printf("Error: No Space is allowed in name!");
                return 0;
            }
            if((names_matrix[i][j][0]<'A' || names_matrix[i][j][0]>'Z') && (names_matrix[i][j][0]<'a' || names_matrix[i][j][0]>'z')){
                printf("Error: please start name with alphabet only!");
                return 0;
            }
            char check_vowel=names_matrix[i][j][0];
            if(check_vowel=='a' || check_vowel=='e' || check_vowel=='i' || check_vowel=='o' || check_vowel=='u' || 
            check_vowel=='A' ||check_vowel=='E' ||check_vowel=='I' ||check_vowel=='O' ||check_vowel=='U'){
                vowel_count++;
            }
            int length_of_name=strlen(names_matrix[i][j]);
            if(length_of_name>50){
                printf("Error: Enter name of maximum size 50 character only!\n");
                return 0;
            }
            if(length_of_name>max_length_of_name){
                max_length_of_name=length_of_name;
            }
            getchar();
        }
    }
    printf("\n");
    for(i=0;i<size_of_row;i++){
        for(j=0;j<size_of_col;j++){
            printf("%s ",names_matrix[i][j]);
        }
        printf("\n");
    }
    printf("\nNumber of names starting with a vowel: %d\n",vowel_count);
    for(i=0;i<size_of_row;i++){
        for(j=0;j<size_of_col;j++){
            int length_of_name=strlen(names_matrix[i][j]);
            if(max_length_of_name==length_of_name){
                printf("The longest name: %s",names_matrix[i][j]);
                return 0;
            }
        }
    }
    return 0;
}