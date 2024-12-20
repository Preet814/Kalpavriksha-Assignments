#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int is_digit(char digit)
{
    if (digit >= '0' && digit <= '9')
        return 1;
    else
        return 0;
}
int is_operator(char operator)
{
    if (operator== '+' || operator== '-' || operator== '/' || operator== '*')
        return 1;
    else
        return 0;
}
long long int apply_operation(long long int number1, long long int number2, char operator)
{
    if (operator== '+')
        return number1 + number2;
    if (operator== '-')
        return number1 - number2;
    if (operator== '*')
        return number1 * number2;
    if (operator== '/')
    {
        if (number2 == 0)
        {
            printf("Error: Division by zero.\n");
            exit(0);
        }
        return number1 / number2;
    }
    return 0;
}
long long int evaluate_expression(char *expression)
{
    int expression_length = strlen(expression);
    int iterator = 0;
    long long int number_stack[100];
    char operator_stack[100];
    int number_stack_top = -1;
    int operator_stack_top = -1;
    int check_for_invalid_expression = 1;
    while (iterator < expression_length)
    {
        if (expression[iterator] == ' ')
        {
            iterator++;
            continue;
        }
        if (is_digit(expression[iterator]))
        {
            long long int number = 0;
            while (iterator < expression_length && is_digit(expression[iterator]))
            {
                number = number * 10 + (expression[iterator] - '0');
                iterator++;
            }
            number_stack[++number_stack_top] = number;
            check_for_invalid_expression = 0;
        }
        else if (is_operator(expression[iterator]))
        {
            if (check_for_invalid_expression == 1)
            {
                printf("Error: Invalid Expression.");
                exit(0);
            }
            while (operator_stack_top != -1 && ((operator_stack[operator_stack_top] == '*' || operator_stack[operator_stack_top] == '/') || ((expression[iterator] == '+' || expression[iterator] == '-') && (operator_stack[operator_stack_top] == '+' || operator_stack[operator_stack_top] == '-'))))
            {
                long long int number2 = number_stack[number_stack_top--];
                long long int number1 = number_stack[number_stack_top--];
                char operator= operator_stack[operator_stack_top--];
                number_stack[++number_stack_top] = apply_operation(number1, number2, operator);
            }
            operator_stack[++operator_stack_top] = expression[iterator];
            iterator++;
            check_for_invalid_expression = 1;
        }
        else
        {
            printf("Error: Invalid expression.\n");
            exit(0);
        }
    }
    while (operator_stack_top != -1)
    {
        long long int number2 = number_stack[number_stack_top--];
        long long int number1 = number_stack[number_stack_top--];
        char operator= operator_stack[operator_stack_top--];
        number_stack[++number_stack_top] = apply_operation(number1, number2, operator);
    }
    return number_stack[number_stack_top];
}
int main()
{
    char expression[256];
    printf("Enter a mathematical expression: ");
    fgets(expression, sizeof(expression), stdin);
    expression[strcspn(expression, "\n")] = '\0';
    if (expression[0] == '\0')
    {
        printf("Error: Enter expression properly.");
        return 0;
    }
    long long int result_of_expresssion = evaluate_expression(expression);
    printf("Result: %lld\n", result_of_expresssion);
    return 0;
}

// edge cases like
// a) 1++2,++5,1*/4
// b) "" no expression
// c) division by zero
// d) large input (long long int)
// e) 1_a
