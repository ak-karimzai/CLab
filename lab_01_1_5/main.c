#include <stdio.h>

void mod_num(int a, int d, int *div_n, int *mod_n)
{
    int div_part = 0;
    while (a >= d)
    {
        a -= d;
        div_part += 1;
    }
    *mod_n = a;
    *div_n = div_part;
}

int main()
{
    int a, d, rc;
    int div_n, mod_n;

    rc = scanf("%d%d", &a, &d);
    if (rc == 2)
    {
        if (a > 0 && d > 0)
        {
            mod_num(a, d, &div_n, &mod_n);
            printf("%d %d", div_n, mod_n);
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