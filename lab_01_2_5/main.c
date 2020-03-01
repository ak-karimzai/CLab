#include<stdio.h>

int fib(int n)
{
    int t0 = 0, t1 = 1, s = 0, i;
    if (n < 2)
    {
        return n;
    }
    for (i = 2; i <= n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}
int main()
{
    int n, r, m;
    printf("Enter the number\n");
    r = scanf("%d", &n);
    
    if (n < 0)
    {
        printf("input error");
        return 1;
    }
    if (r == 1)
    {
        m = fib(n);
        printf("Answer\n");
        printf("%d\n", m);
        return 0;
    } 
    else
    {
        printf("input error");
        return 2;
    }
}
