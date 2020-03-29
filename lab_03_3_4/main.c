 

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

int read_matrix(struct matrix *mtr)
{
    int rc, matrix_el;
    int arg_count = 0;

    printf("Enter dimension:\n");
    rc = scanf("%d%d", &mtr->m, &mtr->n);

    if (rc == 2)
    {
        if (mtr->n > N || mtr->n < 1 || mtr->n != mtr->m)
        {
            printf("Matrix size input error");

            return SIZE_INPUT_ERR;
        }
        else
        {
            for (int i = 0; i < mtr->n; ++i)
            {
                for (int j = 0; j < mtr->m; j++)
                {
                    rc = scanf("%d", &matrix_el);
                    if (rc == 1)
                    {
                        mtr->a[i][j] = matrix_el;
                        arg_count++;
                    }
                    else
                    {
                        printf("Array element input error");

                        return ELEMENT_INPUT_ERR;
                    }
                }
            }

            if (arg_count != (mtr->n) * (mtr->m))
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
    while (m != mn)
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

    if (read_matrix(&mtr))
        return INPUT_ERR;
    else
    {
        transp(&mtr);
        swap_matr(&mtr);
        transp(&mtr);
        display(mtr);
        return OK;
    }
}