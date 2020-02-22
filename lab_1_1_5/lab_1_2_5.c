#include<stdio.h>
#include<stdlib.h>

int fib(n)
{
    if(n <= 2) return n;
    return fib(n - 2) + fib(n - 1);
}

int main()
{
    int n,m;
    scanf("%d",&n);
    m = fib(n);
    printf("%d\n",m);
}