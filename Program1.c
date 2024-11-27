#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
void remove_spaces(char* expression) {
    int i=0,j=0;
    while(expression[i]!='\0'){
        if(expression[i] !=' '){ 
            expression[j++]=expression[i];
        }
        i++;
    }
    expression[j] ='\0';
}
int check_operator(char c){
    if(c=='+'||c=='-'||c=='*'||c=='/')
        return 1;
    else    
        return 0;
}
int apply_operation(int a,int b,char op){
    if (op=='+') 
        return a+b;
    if (op=='-') 
        return a-b;
    if (op=='*') 
        return a*b;
    if (op=='/'){
        if(b==0){
            printf("Error: Division by zero.\n");
            exit(0);
        }
        return a/b;
    }
    return 0;
}
int evaluate_expression(char *expression) {
    int numbers[100];
    char operators[100];
    int num_top=-1;
    char op_top=-1;

    int i=0;
    int n=strlen(expression);
    while(i<n){
        if(isspace(expression[i])){
            i++;
            continue; 
        }
        if(isdigit(expression[i])){
            int num = 0;
            while(i<n && isdigit(expression[i])){
                num=num*10+(expression[i]-'0');
                i++;
            }
            numbers[++num_top]=num;
        }else if(check_operator(expression[i])){
            while(op_top!=-1 && 
                  ((operators[op_top]=='*'||operators[op_top]=='/')|| 
                  ((expression[i]=='+'||expression[i]=='-')&&(operators[op_top]=='+'||operators[op_top]=='-')))){
                int b=numbers[num_top--];
                int a=numbers[num_top--];
                char op=operators[op_top--];
                numbers[++num_top]=apply_operation(a, b, op);
            }
            operators[++op_top]=expression[i];
            i++;
        }else{
            printf("Error: Invalid expression.\n");
            exit(0);
        }
    }

    while(op_top!=-1){
        int b=numbers[num_top--];
        int a=numbers[num_top--];
        char op=operators[op_top--];
        numbers[++num_top]=apply_operation(a, b, op);
    }

    return numbers[num_top];
}
int main() {
    char expression[256];
    printf("Enter a mathematical expression: ");
    gets(expression);
    int result = evaluate_expression(expression);
    printf("Result: %d\n", result);

    return 0;
}
