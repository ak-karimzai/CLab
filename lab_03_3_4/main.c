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

void transp(struct matrix *mtr)
{
    struct matrix matr;
    matr.n = mtr->n;
    matr.m = mtr->m;
    for (int i = 0; i < mtr->n; i++)
    {
        for (int j = 0; j < mtr->m; j++)
        {
            matr.a[i][j] = mtr->a[j][i];
        }
    }
    *mtr = matr;
}

void swap_matr(struct matrix *mtr)
{
    int m = 0, mn = mtr->n - 1;
    int temp[N], start = 0, stop = mtr->n;
    if ((mtr->n % 2 == 0) || mtr->n == 1)
    {
        do
        {
            for (int i = start; i < stop; i++)
            {
                temp[i] = mtr->a[m][i];
                mtr->a[m][i] = mtr->a[mn][i];
                mtr->a[mn][i] = temp[i];
            }
            m++;
            mn--;
            start++;
            stop--;
        } while (start != (mtr->n / 2) + 1);
    }
    else
    {
        do
        {
            for (int i = start; i < stop; i++)
            {
                temp[i] = mtr->a[m][i];
                mtr->a[m][i] = mtr->a[mn][i];
                mtr->a[mn][i] = temp[i];
            }
            m++;
            mn--;
            start++;
            stop--;
        } while (m != mn);
    }
}

void display(struct matrix mtr)
{
    for (int i = 0; i < mtr.n; i++)
    {
        for (int j = 0; j < mtr.m; j++)
        {
            printf("%d ", mtr.a[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    struct matrix mtr;

    read_matrix(&mtr);
    if (result)
        return result;
    else
    {
        transp(&mtr);
        swap_matr(&mtr);
        transp(&mtr);
        display(mtr);
        //printf("success\n");
        return result;
    }
}