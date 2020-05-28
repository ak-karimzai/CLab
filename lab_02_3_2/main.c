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

void display(const int *const a, const int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", a[i]);
}

int main()
{
    int a[N] = { 0 }, b[N] = { 0 }, n;
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
int if_arm(int n)
{
    int current_dig, digits_sum = 0, digits_count = 0;
    int m = n;
    int k = n;

    while (m > 0)
    {
        digits_count++;
        m /= 10;
    }

    while (n > 0)
    {
        current_dig = n % 10;
        digits_sum += pow(current_dig, digits_count);
        n /= 10;
    }

    if (digits_sum == k)
        return 1;
    else
        return 0;
}
int add_arm(const int *const a, int *b, const int n)
{
    int m = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0 && if_arm(a[i]))
        {
            b[m++] = a[i];
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
            display(b, m);
            return 0;
        }
    }
}