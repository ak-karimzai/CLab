#include <stdio.h>

int div_num(int a, int d)
{
    int div_part = 0;
    while (a >= d)
    {
        a -= d;
        div_part += 1;
    }
    return div_part;
}

int mod_num(int a, int d)
{
    int div_part = 0;
    while (a >= d)
    {
        a -= d;
        div_part += 1;
    }
    return a;
}

int main()
{
    int a, d, rc;

    rc = scanf("%d%d", &a, &d);
    if (rc == 2)
    {
        if (a > 0 && d > 0)
        {
            printf("%d %d", div_num(a, d), mod_num(a, d));
            return 0;
        }
        else
        {
            printf("Logic error");
            return 2;
        }
    }
    else
    {
        printf("Input error");
        return 1;
    }
}