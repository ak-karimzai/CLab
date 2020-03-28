#include <stdio.h>

#define FINISHED 0
#define SIZE_I_ERROR -1
#define CLEAR_I_ERROR -2
#define ELEM_I_ERROR -3
#define ARG_C_ERROR -4
#define INPUT_ERROR -5

#define N 10

int read_mat(int a[N][N], int *const m, int *const n)
{
    int rc, matrix_i;
    int count = 0;
    printf("Enter Dimensions:\n");
    rc = scanf("%d%d", m, n);
    if (rc == 2)
    {
        if (*n > N || *n < 1 || *m > N || *m < 1)
        {
            printf("size input error!\n");
            return SIZE_I_ERROR;
        }
        else
        {
            for (int i = 0; i < *m; i++)
            {
                for (int j = 0; j < *n; j++)
                {
                    rc = scanf("%d", &matrix_i);
                    if (rc)
                    {
                        a[i][j] = matrix_i;
                        count++;
                    }
                    else
                    {
                        printf("incorrect element input!\n");
                        return ELEM_I_ERROR;
                    }
                }
            }
            if (count != (*m) * (*n))
            {
                printf("argument's vount error\n");
                return ARG_C_ERROR;
            }
            else
            {
                return FINISHED;
            }
        }
    }
    else
    {
        printf("invalid size input\n");
        return INPUT_ERROR;
    }
}
void display(int a[N][N], int m, int n)
{
    for (int i = 0; i < m;i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
int is_monotone(int a[N][N], int *const b, int m, int n)
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
    return FINISHED;
}
void display_1(int *const a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
int main()
{
    int a[N][N], m, n;
    int b[N];
    if (read_mat(a, &m, &n))
        return INPUT_ERROR;
    else
    {
        is_monotone(a, b, m, n);
        display_1(b, m);
        return FINISHED;
    }
} 
