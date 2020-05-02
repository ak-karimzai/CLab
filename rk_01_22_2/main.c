#include <stdio.h>

#define N 20

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

void read_matrix(int a[N][N], int *const m)
{
    int rc, matrix_el;
    int arg_count = 0;

    printf("Enter dimensions':\n");
    rc = scanf("%d", m);

    if (rc == 1)
    {
        if (*m > N || *m < 1)
        {
            result = size_input_err;
            printf("input error");
        }
        else
        {
            for (int i = 0; i < *m; ++i)
            {
                for (int j = 0; j < *m; j++)
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
            if (arg_count != (*m) * (*m))
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

void print(int matr[N][N], int m)
{
    int sum_1 = 0, sum_2 = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j > i)
            {
                sum_1 += matr[i][j];
            }
            else if (i > j)
            {
                sum_2 += matr[i][j];
            }
        }
    }
    if (sum_1 == sum_2)
    {
        printf("%d", matr[m][m - 1]);
    }
    else
    {
        printf("-1");
    }
}
int main()
{
    int a[N][N], m;

    read_matrix(a, &m);
    if (result != ok)
        return result;
    else
    {
        print(a, m);
        return result;
    }
}
