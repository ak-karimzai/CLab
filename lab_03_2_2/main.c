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

void append_1(struct matrix *mat, int k)
{
    for (int i = mat->m; i > k; i--)
    {
        for (int j = 0; j < mat->n; j++)
            mat->a[i][j] = mat->a[i - 1][j];
    }
    for (int i = 0; i < mat->m; i++)
    {
        for (int j = 0; j < mat->n; j++)
        {
            if (i == k)
            {
                mat->a[i][j] = -1;
            }
        }
    }
    mat->m++;
}


void if_even(struct matrix *matr)
{
    int flag;
    int sum, elem;

    for (int i = 0; i < matr->m; i++)
    {
        flag = 0;
        for (int j = 0; j < matr->n; j++)
        {
            sum = 0;
            elem = matr->a[i][j];
            while (elem != 0)
            {
                sum += elem % 10;
                elem /= 10;
            }
            if (sum % 2 != 0)
                flag++;
        }
        if (flag >= 2)
        {
            append_1(matr, i);
            i++;
        }
    }
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
        return result;
    else
    {
        if_even(&matr);
        display(matr);
        return result;
    }
}