#include <stdio.h>

#define OK 0
#define SIZE_INPUT_ERR -1
#define CLEAR_INPUT_ERR -2
#define ELEMENT_INPUT_ERR -3
#define ARG_COUNT_ERR -4
#define INPUT_ERR -5

#define ORDERED 1
#define NOT_ORDERED 0

#define N 10

struct matrix
{
    int a[N][N];
    int m;
    int n;
};

int read_matrix(struct matrix *matr)
{
    int rc, matrix_el;
    int arg_count = 0;

    printf("Enter dimensions':\n");
    rc = scanf("%d%d", &matr->m, &matr->n);

    if (rc == 2)
    {
        if (matr->m > N || matr->m < 1 || matr->n > N || matr->n < 1)
        {
            printf("Matrix size input error");

            return SIZE_INPUT_ERR;
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
                        printf("Array element input error");

                        return ELEMENT_INPUT_ERR;
                    }
                }
            }

            if (arg_count != matr->m * matr->n)
            {
                printf("Arguments' count error");

                return ARG_COUNT_ERR;
            }
            else
                return OK;
        }
    }
    else
    {
        printf("Input clearance error");

        return CLEAR_INPUT_ERR;
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

    if (read_matrix(&matr))
        return INPUT_ERR;
    else
    {
        if_even(&matr);
        display(matr);
        return OK;
    }
}