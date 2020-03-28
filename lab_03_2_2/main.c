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

int read_matrix(int a[N][N], int *const n, int *const m)
{
    int rc, matrix_el;
    int arg_count = 0;

    printf("Enter dimensions':\n");
    rc = scanf("%d%d", n, m);

    if (rc == 2)
    {
        if (*n > N || *n < 1 || *m > N || *m < 1)
        {
            printf("Matrix size input error");

            return SIZE_INPUT_ERR;
        }
        else
        {
            for (int i = 0; i < *n; ++i)
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
                        printf("Array element input error");

                        return ELEMENT_INPUT_ERR;
                    }
                }
            }

            if (arg_count != (*n) * (*m))
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

int if_even(int a[N][N], int m, int n)
{
    int flag;
    int sum, elem;
    for (int i = 0; i < m; i++)
    {
        flag = 0;
        for (int j = 0; j < n; j++)
        {
            sum = 0;
            elem = a[i][j];
            while (elem)
            {
                sum = elem % 10;
                elem /= 10;
            }
            if (sum % 2 != 0)
                flag++;
        }
        if (flag >= 2)
        {
            for (int j = 0; j < n; j++)
            {
                a[i][j] = -1;
            }
        }
    }
    return OK;
}

void display(int a[N][N], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int a[N][N], m, n;
    int b[N];

    if (read_matrix(a, &m, &n))
        return INPUT_ERR;
    else
    {
        if_even(a, m, n);
        display(a, m, n);
        return OK;
    }
}