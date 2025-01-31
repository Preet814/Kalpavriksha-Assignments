#include <stdio.h>
#include <stdlib.h>
int mod = 1e9 + 7;
long long power(long long x, long long y)
{
    if (y == 0)
        return 1;
    long long ans = power(x, y / 2);
    if (y % 2 == 0)
        return (ans * ans) % mod;

    else
        return (((ans * ans) % mod) * x) % mod;
}
int countGoodNumbers(long long n)
{
    long long odd = n / 2;
    long long even = (n / 2) + (n % 2);
    return (power(5, even) * power(4, odd)) % mod;
}
int main()
{
    int input_number;
    printf("N: ");
    scanf("%d", &input_number);
    int answer = countGoodNumbers(input_number);
    printf("Answer: %d", answer);
    return 0;
}