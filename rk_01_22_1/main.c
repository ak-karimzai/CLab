#include <stdio.h>

#define N 20

enum type_error
{
    ok,
    size_err,
    element_err,
    array_n_full,
    incorrect_s_input,
    input_err,
    log_err
};

int result = ok;

void read_array(int *const a, int *n)
{
    int rc, array_i;
    int count = 0;
    rc = scanf("%d", n);
    if (rc == 1)
    {
        if (*n > N || * n < 1)
        {
            result = size_err;
            printf("invlaid Input for size");
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
                    result = element_err;
                    printf("Invalid element input");
                }
            }
            if (count != *n)
            {
                result = array_n_full;
            }
        }
    }
    else
    {
        result = incorrect_s_input;
        printf("incorrect input Size");
    }
}

void display(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

void delete(int *a, int *n, int j)
{
    for (; j < *n - 1; j++)
    {
        a[j] = a[j + 1];
    }
    *n = *n - 1;
}

void search_in_array(int *a, int *n, int m)
{
    for (int i = 1; i < *n; i++)
    {
        if (a[i] % m == 0)
        {
            delete(a, n, i);
        }
    }
}

int main()
{
    int a[N] = { 0 }, n = 0, m = 0;

    read_array(a, &n);
	scanf("%d", &m);
    if (result != ok)
    {
        return input_err;
    }
    
    else
    {
		search_in_array(a, &n, m);
        display(a, n);
    }
    return ok;
}