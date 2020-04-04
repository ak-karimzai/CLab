#include <stdio.h>

#define N 10

enum error_type
{
    ok,
    size_input_err,
    clear_input_err,
    elemnt_input_err,
    arg_count_err,
    input_err
};

int result = ok;

int read_matrix(int a[N][N], int *const m, int *const n)
{
    int rc, matrix_el;
    int arg_count = 0;

    printf("Enter dimensions':\n");
    rc = scanf("%d%d", m, n);

    if (rc == 2)
    {
        if (*n > N || *n < 1 || *m > N || *m < 1)
        {
            return size_input_err;
            printf("input error");
        }
        else
        {
            for (int i = 0; i < *m; ++i)
            {
                for (int j = 0; j < *n; j++)
                {
                    rc = scanf("%d", &matrix_el);
                    if (rc == 1)
                    {
                        a[i][j] = matrix_el;
                        arg_count++;
                    }
                    else
                    {
                        return elemnt_input_err;
                        printf("input error");
                    }
                }
            }
            if (arg_count != (*n) * (*m))
            {
                return arg_count_err;
                printf("input error");
            }
            else
                result = ok;
        }
    }
    else
    {
        return clear_input_err;
        printf("input error");
    }
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sort_matrix(int a[N][N], int m, int n)
{
    static int b[N];
    int sum;
    for (int i = 0; i < m; i++)
    {
        sum = 1;
        for (int j = 0; j < n; j++)
        {
            sum *= a[i][j];
        }
        b[i] = sum;
    }
    for (int i = 0; i < m - 1; i++)
    {
        for (int j = 0; j < m - i - 1; j++)
        {
            if (b[j] > b[j + 1])
            {
                swap(&b[j], &b[j + 1]);
                for (int k = 0; k < n; k++)
                {
                    swap(&a[j][k], &a[j + 1][k]);
                }
            }
        }
    }
}

void display(int a[N][N], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int a[N][N], m, n;

    read_matrix(a, &m, &n);
    if (result)
        return result;
    else
    {
        sort_matrix(a, m, n);
        display(a, m, n);
        return result;
    }
}