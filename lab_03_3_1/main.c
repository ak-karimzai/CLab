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

void read_matrix(int a[N][N], int *const m, int *const n)
{
    int rc, matrix_el;
    int arg_count = 0;

    printf("Enter dimensions':\n");
    rc = scanf("%d%d", m, n);

    if (rc == 2)
    {
        if (*n > N || *n < 1 || *m > N || *m < 1)
        {
            result = size_input_err;
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
                        result = elemnt_input_err;
                        printf("input error");
                    }
                }
            }
            if (arg_count != (*n) * (*m))
            {
                result = arg_count_err;
                printf("input error");
            }
            else
                result = ok;
        }
    }
    else
    {
        result = clear_input_err;
        printf("input error");
    }
}

void display(const int *const a, const int m)
{
    for (int i = 0; i < m; ++i)
    {
        printf("%d ", a[i]);
    }
}

int array_from_matrix(int a[N][N], int *const b, const int m, const int n)
{
    int is_ordered_up, is_ordered_down;

    if (m == 1)
    {
        for (int i = 0; i < m; ++i)
            b[i] = 0;
    }
    else
    {
        for (int i = 0; i < m; ++i)
        {
            is_ordered_up = 1;
            is_ordered_down = 1;

            for (int j = 0; j < n - 1; ++j)
                if (a[i][j] <= a[i][j + 1])
                    is_ordered_up++;

            for (int j = 0; j < n - 1; ++j)
                if (a[i][j] >= a[i][j + 1])
                    is_ordered_down++;

            if (is_ordered_up == n || is_ordered_down == n)
                b[i] = 1;
            else
                b[i] = 0;
        }
    }

    return 0;
}

int main()
{
    int a[N][N], m, n;
    int b[N];

    read_matrix(a, &m, &n);
    if (result)
        return result;
    else
    {
        array_from_matrix(a, b, m, n);
        display(b, m);
        return result;
    }
}