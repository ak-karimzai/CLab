#include <stdlib.h>
#include "../inc/add_mul.h"


matrix *addition(const matrix *lhs, const matrix *rhs)
{
    int rc = ok;
    matrix *res = NULL;
    if (lhs->row == rhs->row && lhs->col == rhs->col)
    {
        res = malloc(sizeof(matrix));
        if (res)
        {
            res->col = lhs->col;
            res->row = lhs->row;
            res->mat = get_matrix(lhs->row, lhs->col);
            if (res->mat)
            {
                for (int i = 0; i < lhs->row; i++)
                    for (int j = 0; j < lhs->col; j++)
                        res->mat[i][j] = (lhs->mat[i][j] + rhs->mat[i][j]);
            }
            else
            {
                free(res);
                rc = error;
            }
        }
    }
    else
        rc = error;

    return rc == ok ? res : NULL;
}

matrix *multiplication(const matrix *lhs, const matrix *rhs)
{
    int rc = ok;
    matrix *res = NULL;
    if (lhs->col != rhs->row)
        rc = error;
    else
    {
        res = malloc(sizeof(matrix));
        if (res)
        {
            res->mat = get_matrix(lhs->row, rhs->col);
            if (res->mat)
            {
                res->row = lhs->row;
                res->col = rhs->col;
                fill_zero_mat(res);
                for (int i = 0; i < res->row; i++)
                    for (int j = 0; j < res->col; j++)
                        for (int k = 0; k < lhs->col; k++)
                            res->mat[i][j] += (lhs->mat[i][k] * rhs->mat[k][j]);
            }
            else
            {
                free(res);
                rc = error;
            }
        }
        else
            rc = error;
    }
    return rc == ok ? res : NULL;
}