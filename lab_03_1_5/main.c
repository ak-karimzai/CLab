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

struct element
{
    int i;
    int j;
    int x;
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

int if_even(struct matrix *matr)
{
    int sum, elem, k = 0, km = 0, flag = 0;
    static int a[N * N];

    for (int i = 0; i < matr->m; i++)
    {
        for (int j = 0; j < matr->n; j++)
        {
            sum = 0;
            elem = matr->a[i][j];
            while (elem != 0)
            {
                sum += elem % 10;
                elem /= 10;
            }
            if (sum > 10)
            {
                ele[k].i = i;
                ele[k].j = j;
                ele[k].x = matr->a[i][j];
                k++;
                flag = 1;
            }
        }
    }
    if (flag == 1)
    {
        int i = 3;
        while (i != 0)
        {
            int first = ele[k - 1].x;
            for (int j = k; j > 0; j--)
            {
                ele[j].x = ele[j - 1].x;
            }
            ele[0].x = first;
            i--;
        }
        for (int i = 0; i < matr->m; i++)
        {
            for (int j = 0; j < matr->n; j++)
            {
                if (i == ele[km].i && j == ele[km].j)
                {
                    matr->a[i][j] = ele[km++].x;
                }
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
            printf("Unsoccessful\n");
            return ARG_COUNT_ERR;
        }
    }
}