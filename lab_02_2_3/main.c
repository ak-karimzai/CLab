#include <stdio.h>
#include <math.h>

#define NO_PERFECT 3
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
void delete(int *a, int i, int *n)
{
    int j;
    for (j = i; j < *n - 1; j++)
    {
        a[j] = a[j + 1];
    }
    *n -= 1;
}
void display(int *a, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
int is_perfect_square(int number)
{
    for (int i = 0; i <= number; i++)
    {
        if (number == i * i)
            return 1;
    }
    return 0;
}
int main()
{
    int a[N];
    int i, n;
    if (read_array(a, &n))
    {
        return LOG_ERROR;
    }
    else
    {
        for (i = 0; i < n;i++)
        {
            if (is_perfect_square(a[i]))
            {
                delete(a, i, &n);
                i--;
            }
        }
        if (n)
            display(a, n);
        else
        {
            printf("Empty array\n");
            return NO_PERFECT;
        }
        return 0;
    }
}