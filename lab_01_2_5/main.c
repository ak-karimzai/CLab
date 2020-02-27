#include<stdio.h>
#include<stdlib.h>

int fib(int n)
{
    if(n <= 2) return n;
    return fib(n - 2) + fib(n - 1);
}

int main()
{
    int n, m;
    printf("Enter the number\n");
    scanf("%d", &n);
    m = fib(n);
    printf("Answer\n");
    printf("%d\n", m);
}