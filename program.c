#include<stdio.h>
long long int evaluate_expression(long long int base_value,long long int exponent_value,long long int modulas_value){
    // square and multiply algorithm
    long long result=1;
    base_value=base_value%modulas_value;
    while(exponent_value>0){
        if(exponent_value&1){ //odd
            result=(result*base_value)%modulas_value;
        }
        base_value=(base_value*base_value)%modulas_value;
        exponent_value=exponent_value>>1;//divide by 2
    }
    if(result<0){
        result+=modulas_value;
    }
    return result;
}
int main(){
    long long int exponent_value;
    long long int modulas_value;
    long long int base_value;
    long long int result;
    printf("Enter Base value: ");
    scanf("%lld",&base_value);
    printf("Enter Exponential value: ");
    scanf("%lld",&exponent_value);
    printf("Enter Modulas value: ");
    scanf("%lld",&modulas_value);
    if(modulas_value<1)
        printf("Error: Input modular value greator then 1!");
    else if(exponent_value<0)
        printf("Error: Input modular value greator then or equal to 0!");
    else{
        result=evaluate_expression(base_value,exponent_value,modulas_value);
    }
    printf("Result: %lld",result);
    return 0;
}

