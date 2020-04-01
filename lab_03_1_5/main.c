#include <stdio.h>
#include <math.h>

#define OK 0
#define SIZE_INPUT_ERR -1
#define CLEAR_INPUT_ERR -2
#define ELEMENT_INPUT_ERR -3
#define ARG_COUNT_ERR -4
#define INPUT_ERR -5

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
                printf("%d \n", sum_element(mtr->a[i][j]));
                ele[k++] = mtr->a[i][j];
                flag = 1;
            }
        }
    }
    //for (int i = 0; i < k; i++) printf("%d \n", ele[i]);
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

    if (read_matrix(&matr))
        return INPUT_ERR;
    else
    {
        if (if_even(&matr))
        {
            display(matr);
            return OK;
        }
        else
        {
            return ARG_COUNT_ERR;
        }
    }
}