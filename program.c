#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int isOperator(char ch){
    if(ch=='+' || ch=='-' || ch=='/' || ch=='*')
        return 1;
    else    
        return 0;
}
int solve(int a,int b,char op){
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
int evaluate_expression(char* expression){
    int n=strlen(expression);
    int i=0;
    int numbers[100];
    char operators[100];
    int num_top=-1;
    int op_top=-1;
    while(i<n){
        if(isspace(expression[i])){
            i++;
            continue;
        }
        if(isdigit(expression[i])){
            int num=0;
            while(i<n && isdigit(expression[i])){
                num=num*10+(expression[i]-'0');
                i++;
            }
            numbers[++num_top]=num;
        }
        else if(isOperator(expression[i])){
            while(op_top!=-1 && ((operators[op_top]=='*' || operators[op_top]=='/') || ((expression[i]=='+' || expression[i]=='-') && (operators[op_top]=='+' || operators[op_top]=='-')))){
                int b=numbers[num_top--];
                int a=numbers[num_top--];
                char operator=operators[op_top--];
                numbers[++num_top]=solve(a,b,operator);

            }
            operators[++op_top]=expression[i];
            i++;
        }
        else{
            printf("Error: Invalid expression.\n");
            break;
        }
    }
    while(op_top!=-1){
        int b=numbers[num_top--];
        int a=numbers[num_top--];
        char operator=operators[op_top--];
        numbers[++num_top]=solve(a,b,operator);
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