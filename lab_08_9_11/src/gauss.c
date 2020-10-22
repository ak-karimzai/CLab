#include "../inc/gauss.h"
#include <math.h>

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

int gauss_solution(matrix *mat)
{
    if (mat->col == mat->row + 1)
    {
        int idx_of_max_row;
        double max = 0.0;
        double temp = 0;
        for (int k = 0; k < mat->row; k++)
        {
            max = 0;
            idx_of_max_row = k;
            for (int i = k; i < mat->row; i++)
            {
                if (fabs(mat->mat[i][k]) > fabs(max))
                {
                    max = fabs(mat->mat[i][k]);
                    idx_of_max_row = i;
                }
            }
            if (idx_of_max_row != k)
                for (int i = k; i < mat->col; i++)
                    swap(&mat->mat[idx_of_max_row][i], &mat->mat[k][i]);
            temp = mat->mat[k][k];
            if (temp != 0)
            {
                for (int j = k; j < mat->col; j++)
                    mat->mat[k][j] = mat->mat[k][j] / temp;

                for (int i = k + 1; i < mat->row; i++)
                {
                    temp = mat->mat[i][k];
                    for (int j = k; j < mat->col; j++)
                        mat->mat[i][j] = mat->mat[i][j] - temp * mat->mat[k][j];
                }
            }
        }
        for (int k = mat->row - 1; k >= 0; k--)
        {
            for (int i = 0; i < k; i++)
            {
                temp = mat->mat[i][k];
                for (int j = k; j < mat->col; j++)
                    mat->mat[i][j] = mat->mat[i][j] - temp * mat->mat[k][j];
            }
        }
    }
    else
        return error;
    return find_solution(mat) == ok ? ok : error;
}