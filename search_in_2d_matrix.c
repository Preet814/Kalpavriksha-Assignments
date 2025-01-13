#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int search(int **matrix,int row,int col,int target){
    int row_ptr=0;
    int col_ptr=col-1;
    while(row_ptr<row && col_ptr>=0){
        if(matrix[row_ptr][col_ptr]==target){
            return 1;
        }
        else if(matrix[row_ptr][col_ptr]>target)
            col_ptr--;
        else
            row_ptr++;
    }
    return 0;
}
int main(){
    int row,col;
    printf("Enter row:");
    scanf("%d",&row);
    printf("Enter col:");
    scanf("%d",&col);
    int **matrix=(int **)malloc(row*sizeof(int*));
    for(int i=0;i<row;i++){
        matrix[i]=(int *)malloc(col*sizeof(int));
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            getchar();
            printf("Input at(%d,%d): ",i,j);
            scanf("%d",&matrix[i][j]);
        }
    }
    int target;
    printf("\nEnter target to search: ");
    scanf("%d",&target);
    printf("\nInput matrix: \n\n");
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    printf("\nTarget is : %d\n",target);
    int found=search(matrix,row,col,target);
    if(found==1)
        printf("Target found in matrix.");
    else
        printf("Target not found in matrix.");
    return 0;
}