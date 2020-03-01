#include<stdio.h>

int main()
{
    int a,d,r,q, rc;
    printf("Enter the values\n");
    rc = scanf("%d%d", &a, &d);
    r = a, q = 0;
    if (a < 0 || d < 0)
    {
        printf("incorrext input");
        return 2;   
    }
    if (rc == 2)
    {
        while(!(r < d))
        {
            r = r - d;
            q++;
        }
        printf("%d", q);
        printf("%d", r);
        return 0;
    }
    else
    {
        printf("incorrect input");
        return 1;
    }
}