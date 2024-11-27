#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct User{
    int id;
    char name[100];
    int age;
};
void create_user(){
    FILE *file=fopen("users.txt","a");
    if(file==NULL){
        printf("Error opening file!\n");
        return;
    }
    struct User user;
    printf("Enter User ID: ");
    scanf("%d",&user.id);
    getchar();
    printf("Enter Name: ");
    scanf("%s",user.name);
    printf("Enter Age: ");
    scanf("%d",&user.age);
    fprintf(file,"%d %s %d\n",user.id,user.name,user.age);
    printf("User added successfully!\n");
    fclose(file);
}
void read_users(){
    FILE *file=fopen("users.txt","r");
    if(file==NULL){
        printf("Error opening file!\n");
        return;
    }
    struct User user;
    while(fscanf(file,"%d %s %d",&user.id,user.name,&user.age)!=EOF){
        printf("ID: %d,Name: %s,Age: %d\n",user.id,user.name,user.age);
    }
    fclose(file);
}
void update_user(){
    FILE *file=fopen("users.txt","r"); 
    if(file==NULL){
        printf("Error opening file!\n");
        return;
    }
    FILE *temp_file=fopen("temp.txt","w");
    if(temp_file==NULL){
        printf("Error creating temporary file!\n");
        fclose(file);
        return;
    }
    int id,found=0;
    struct User user;
    printf("Enter the ID of the user to update: ");
    scanf("%d",&id);
    while(fscanf(file, "%d %s %d", &user.id, user.name, &user.age)!=EOF){
        if(user.id==id){
            printf("Enter new Name: ");
            getchar();
            scanf("%s",user.name);
            printf("Enter new Age: ");
            scanf("%d",&user.age);
            found=1;
        }
        fprintf(temp_file,"%d %s %d\n",user.id,user.name,user.age);
    }
    fclose(file);
    fclose(temp_file);
    if(found){
        remove("users.txt");
        rename("temp.txt","users.txt");
        printf("User updated successfully!\n");
    }else{
        printf("User with ID %d not found!\n",id);
        remove("temp.txt");
    }
}
void delete_user() {
    FILE *file=fopen("users.txt","r");
    if(file==NULL){
        printf("Error opening file!\n");
        return;
    }
    FILE *temp_file=fopen("temp.txt","w");
    if(temp_file==NULL){
        printf("Error creating temporary file!\n");
        fclose(file);
        return;
    }
    int id,found=0;
    struct User user;
    printf("Enter the ID of the user to delete: ");
    scanf("%d",&id);
    while(fscanf(file,"%d %s %d",&user.id,user.name,&user.age)!=EOF){
        if(user.id!=id){
            fprintf(temp_file,"%d %s %d\n",user.id,user.name,user.age);
        }else{
            found=1;
        }
    }
    fclose(file);
    fclose(temp_file);
    if(found){
        remove("users.txt");
        rename("temp.txt","users.txt");
        printf("User deleted successfully!\n");
    }else{
        printf("User with ID %d not found!\n", id);
        remove("temp.txt");
    }
}

int main(){
    int choice;
    do {
        printf("\n--- User Management ---\n");
        printf("1. Create User\n");
        printf("2. Read Users\n");
        printf("3. Update User\n");
        printf("4. Delete User\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                create_user();
                break;
            case 2:
                read_users();
                break;
            case 3:
                update_user();
                break;
            case 4:
                delete_user();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }while(choice!=5);
    return 0;
}