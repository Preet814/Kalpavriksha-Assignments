#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int size_row_col;
    scanf("%d",&size_row_col);
    int **array=(int **)malloc(size_row_col*sizeof(int*));
    for(int i=0;i<size_row_col;i++){
        array[i]=(int *)malloc(size_row_col*sizeof(int));
    }
    for(int i=0;i<size_row_col;i++){
        for(int j=0;j<size_row_col;j++){
            scanf("%d",&array[i][j]);
        }
    }
    printf("Matrix:\n");
    for(int i=0;i<size_row_col;i++){
        for(int j=0;j<size_row_col;j++){
            printf("%d ",array[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<size_row_col;i++){
        for(int j=i+1;j<size_row_col;j++){
            int temprory_variable=array[i][j];
            array[i][j]=array[j][i];
            array[j][i]=temprory_variable;
        }
    }
    printf("Output:\n");
    for(int i=0;i<size_row_col;i++){
        for(int j=0;j<size_row_col;j++){
            printf("%d ",array[i][j]);
        }
        printf("\n");
    }

    return 0;
}