#include <stdio.h>

#define FINISHED 0
#define SIZE_I_ERROR -1
#define CLEAR_I_ERROR -2
#define ELEM_I_ERROR -3
#define ARG_C_ERROR -4
#define INPUT_ERROR -5

#define N 10

int read_matrix(int a[N][N], int *const n, int *const m)
{
    int rc, matrix_el;
    int count = 0;

    rc = scanf("%d%d", m, n);
    if (rc == 2)
    {
        if (*n > N || *n < 1 || *m > N || *m < 1)
        {
            printf("size input error");
            return SIZE_I_ERROR;
        }
        else
        {
            for (int i = 0; i < *m; ++i)
            {
                for (int j = 0; j < *n; j++)
                {
                    rc = scanf("%d", &matrix_el);
                    if (rc)
                    {
                        a[i][j] = matrix_el;
                        count++;
                    }
                    else
                    {
                        printf("element input error");
                        return ELEM_I_ERROR;
                    }
                }
            }

            if (count != (*n) * (*m))
            {
                printf("arguments count error");
                return ARG_C_ERROR;
            }
            else
                return FINISHED;
        }
    }
    else
    {
        printf("Input clearance error");
        return CLEAR_I_ERROR;
    }
}

void display(int *const a, const int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", a[i]);
    }
}

int is_monotone(int a[N][N], int *const b, const int n, const int m)
{
    int is_ordered_up, is_ordered_down;

    if (m == 1)
    {
        for (int i = 0; i < n; ++i)
            b[i] = 0;
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            is_ordered_up = 1;
            is_ordered_down = 1;

            for (int j = 0; j < m - 1; ++j)
                if (a[i][j] <= a[i][j + 1])
                    is_ordered_up++;

            for (int j = 0; j < m - 1; ++j)
                if (a[i][j] >= a[i][j + 1])
                    is_ordered_down++;

            if (is_ordered_up == m || is_ordered_down == m)
                b[i] = 1;
            else
                b[i] = 0;
        }
    }
    return FINISHED;
}

int main()
{
    int a[N][N], m, n;
    int b[N];

    if (read_matrix(a, &m, &n))
        return INPUT_ERROR;
    else
    {
        is_monotone(a, b, m, n);
        display(b, m);
        return FINISHED;
    }
}