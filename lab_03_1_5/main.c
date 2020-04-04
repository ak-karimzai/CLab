#include <stdio.h>
#include <math.h>

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

struct matrix
{
    int a[N][N];
    int m;
    int n;
};

void read_matrix(struct matrix *matr)
{
    int rc, matrix_el;
    int arg_count = 0;

    printf("Enter dimensions':\n");
    rc = scanf("%d%d", &matr->m, &matr->n);

    if (rc == 2)
    {
        if (matr->m > N || matr->m < 1 || matr->n > N || matr->n < 1)
        {
            result = size_input_err;
            printf("input error");
        }
        else
        {
            for (int i = 0; i < matr->m; ++i)
            {
                for (int j = 0; j < matr->n; j++)
                {
                    rc = scanf("%d", &matrix_el);
                    if (rc == 1)
                    {
                        matr->a[i][j] = matrix_el;
                        arg_count++;
                    }
                    else
                    {
                        result = elemnt_input_err;
                        printf("input error");
                    }
                }
            }

            if (arg_count != matr->m * matr->n)
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

int sum_element(int n)
{
    if (n < 0)
        n = n * (-1);
    int sum = 0;
    while (n != 0)
    {
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}

int if_even(struct matrix *mtr)
{
    int flag = 0, k = 0;
    int ele[N * N];

    for (int i = 0; i < mtr->m; i++)
    {
        for (int j = 0; j < mtr->n; j++)
        {
            if (sum_element(mtr->a[i][j]) > 10)
            {
                ele[k++] = mtr->a[i][j];
                flag = 1;
            }
        }
    }
    int i = 3;
    while (i != 0)
    {
        int first = ele[0];
        for (int j = 0; j < k - 1; j++)
        {
            ele[j] = ele[j + 1];
        }
        ele[k - 1] = first;
        i--;
    }
    k = 0;
    for (int i = 0; i < mtr->m; i++)
    {
        for (int j = 0; j < mtr->n; j++)
        {
            if (sum_element(mtr->a[i][j]) > 10)
            {
                mtr->a[i][j] = ele[k++];
            }
        }
    }
    return flag;
}

void display(struct matrix matr)
{
    for (int i = 0; i < matr.m; i++)
    {
        for (int j = 0; j < matr.n; j++)
        {
            printf("%d ", matr.a[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    struct matrix matr;

    read_matrix(&matr);
    if (result)
        return input_err;
    else
    {
        if (if_even(&matr))
        {
            display(matr);
            return result;
        }
        else
        {
            return arg_count_err;
        }
    }
}