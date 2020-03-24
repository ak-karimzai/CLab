#include <stdio.h>

#define FINISHED 0
#define SIZE_I_ERROR -1
#define CLEAR_I_ERROR -2
#define ELEM_I_ERROR -3
#define ARG_C_ERROR -4
#define INPUT_ERROR -5

#define DEFINED 1
#define NOT_DEFINED 0

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
            for (int i = 0; i < *n; i++)
            {
                for (int j = 0; j < *m; j++)
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
void display(int *const a, int m)
{
    printf("\n");
    for (int i = 0; i < m; i++)
    {
        printf("%d ", a[i]);
    }
}
int from_mat_to_arr(int a[N][N], int *const b, int m, int n)
{
    int monton_seq;
    if (m == 1)
    {
        for (int i = 0; i < m; ++i)
        {
            b[i] = NOT_DEFINED;
        }
    }
    else
    {
        for (int i = 0; i < m; i++)
        {
            monton_seq = 0;
            for (int j = 0; j < n - 1; j++)
            {
                if (a[i][j] < a[i][j + 1])
                    monton_seq++;
            }
            if (monton_seq == n - 1)
                b[i] = DEFINED;
            else
                b[i] = NOT_DEFINED;
        }
    }
    return FINISHED;
}
int main()
{
    int a[N][N], n, m;
    int b[N];
    
    if (read_mat(a, &m, &n))
        return INPUT_ERROR;
    else
    {
        from_mat_to_arr(a, b, m, n);
        display(b, m);
        return FINISHED;
    }
}