#include <stdio.h>
#include <math.h>
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
        if (*n > N || * n < 1)
        {
            printf("invlaid Input for size");
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
                    printf("Invalid element input");
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
        printf("incorrect input Size");
        return INCORRECT_S_INPUT;
    }
}
int add_arm(const int *const a, int *b, const int n);
int if_arm(int x);

int main()
{
    int a[N], b[N], n;
    printf("Enter the number of element's: \n");
    if (read_array(a, &n))
    {
        return INPUT_ERROR;
    }
    else
    {
        if (add_arm(a, b, n))
            return LOG_ERROR;
        else
            return 0;
    }
}
int if_arm(int num)
{
    int copy_of_num, sum = 0, rem;

    copy_of_num = num;
    while (num != 0)
    {
        rem = num % 10;
        sum = sum + (rem * rem * rem);
        num = num / 10;
    }
    if (copy_of_num == sum)
        return 1;
    return 0;
}
int add_arm(const int *const a, int *b, const int n)
{
    int m = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0 && if_arm(a[i]))
        {
            b[m] = a[i];
            m++;
        }
    }
    if (m == 0)
    {
        printf("Array without armstrong numbers");
        return LOG_ERROR;
    }
    else
    {
        if (m == n)
        {
            printf("All Elements are armstrong");
            return LOG_ERROR;
        }
        else
        {
            for (int i = 0; i < m; i++)
            {
                printf("%d ", b[i]);
            }
        }
    }
    return 0;
}