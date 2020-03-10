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
int add_arm(int a[], int x, int j);
int if_arm(int x);
int main()
{
    int a[N], b[N], n, count = 0, i, j = 0;
    printf("Enter the number of element's: \n");
    read_array(a, &n);
    for (i = 0; i < n; i++)
    {
        if (if_arm(a[i]))
        {
            count++;
            j = add_arm(b, a[i], j);
        }
    }
    if (count)
    {
        for (i = 0; i < count; i++)
        {
            printf("%d ", b[i]);
        }
    }
    else
    {
        printf("not finded arm number");
        return 2;
    }
    return 0;
}
int if_arm(int num)
{
    int copy_of_num, sum=0, rem;

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
int add_arm(int a[], int x, int j)
{
    a[j++] = x;
    return j;
}