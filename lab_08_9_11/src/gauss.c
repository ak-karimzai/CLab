#include "../inc/gauss.h"
#include <math.h>
#include <stdio.h>

void swap(double *lhs, double *rhs)
{
    double temp = *lhs;
    *lhs = *rhs;
    *rhs = temp;
}

int find_solution(matrix *mat)
{
    int no_zero_in_row = false;
    int no_solution = false;
    int infinite_solution = false;
    
    for (int k = 0; k < mat->row; k++)
    {
        if (mat->mat[k][k] == 0)
        {
            no_zero_in_row = false;
            for (int j = k + 1; j < mat->row; j++)
                if (mat->mat[k][j] != 0)
                    no_zero_in_row = true;

            if (no_zero_in_row == false)
            {
                if (mat->mat[k][mat->row] != 0)
                    no_solution = true;
                else
                    infinite_solution = true;
            }
        }
    }
    return no_solution == true ? error : infinite_solution == true ? error : ok;
}

void reverse_motion(matrix *mat)
{
    double divisor;
    for (int k = mat->row - 1; k >= 0; k--)
    {
        for (int i = 0; i < k; i++)
        {
            divisor = mat->mat[i][k];
            for (int j = k; j < mat->col; j++)
                mat->mat[i][j] = (mat->mat[i][j] - divisor * mat->mat[k][j]);
        }
    }
}

void divide_and_subtract(matrix *mat, const int iter, double divisor)
{
    for (int j = iter; j < mat->col; j++)
        mat->mat[iter][j] = (mat->mat[iter][j] / divisor);

    for (int i = iter + 1; i < mat->row; i++)
    {
        divisor = mat->mat[i][iter];
        for (int j = iter; j < mat->col; j++)
            mat->mat[i][j] = (mat->mat[i][j] - divisor * mat->mat[iter][j]);
    }
}

int get_max_and_its_idx(matrix *mat, double *max, int iter)
{
    int idx_of_max_row = iter;
    for (int i = iter; i < mat->row; i++)
    {
        if (fabs(mat->mat[i][iter]) > fabs(*max))
        {
            *max = fabs(mat->mat[i][iter]);
            idx_of_max_row = i;
        }
    }
    return idx_of_max_row;
}

int gauss_solution(matrix *mat)
{
    if (mat->col == mat->row + 1)
    {
        for (int k = 0; k < mat->row; k++)
        {
            double max = 0.0;
            int idx_of_max_row = get_max_and_its_idx(mat, &max, k);
            if (idx_of_max_row != k)
                for (int i = k; i < mat->col; i++)
                    swap(&mat->mat[idx_of_max_row][i], &mat->mat[k][i]);

            double divisor = mat->mat[k][k];
            if (divisor != 0)
                divide_and_subtract(mat, k, divisor);
        }
        reverse_motion(mat);
    }
    else
        return error;
    return find_solution(mat);
}