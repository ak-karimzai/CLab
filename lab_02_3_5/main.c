#include <stdio.h>

#define N 10
#define SIZE_ERROR -1
#define ELEMENT_ERROR -2
#define ARRAY_N_FULL -3
#define INCORRECT_S_INPUT -4
#define INPUT_ERROR -5
#define LOG_ERROR -6

int read_array(int *const a, int *n)
{
    int rc, array_i;
    int count = 0;
    rc = scanf("%d", n);
    if (rc == 1)
    {
        if (*n > N || *n < 1)
        {
            printf("invalid input for size");
            return SIZE_ERROR;
        }
        else
        {
            for (int i = 0; i < *n; i++)
            {
                rc = scanf("%d", &array_i);
                if (rc == 1)
                {
                    a[i] = array_i;
                    count++;
                }
                else
                {
                    printf("invalid element input");
                    return ELEMENT_ERROR;
                }
            }
            if (count != *n)
            {
                printf("array not full");
                return ARRAY_N_FULL;
            }
            else
            {
                return 0;
            }
        }
    }
    else
    {
        printf("incorect input Size");
        return INCORRECT_S_INPUT;
    }
}
void fib_array(int *begin, int *end)
{
    for (int *i = ++begin; i != end; i++)
    {
        printf("%d ", *(i - 1) * *i);
    }
}
int main()
{
    int a[N], n;
    if (read_array(a, &n))
    {
        return LOG_ERROR;
    }
    else
    {
        if (n == 1)
        {
            printf("array only with one element");
            return INPUT_ERROR;
        }
        fib_array(a, (a + n));
        return 0;
    }
}