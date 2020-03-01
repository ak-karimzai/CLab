#include<stdio.h>

long int fib(int n)
{
    long int t0 = 0, t1 = 1, s = 0, i;
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
    int n, r;
    long int m;
    printf("Enter the number\n");
    r = scanf("%d", &n);
    
    if (n < 0)
    {
        printf("input error");
        return 1;
    }
    else if (n > 150)
    {
        printf("incorect input");
        return 3;
    }
    if (r == 1)
    {
        m = fib(n);
        printf("Answer\n");
        printf("%lu\n", m);
        return 0;
    } 
    else
    {
        printf("input error");
        return 2;
    }
}
