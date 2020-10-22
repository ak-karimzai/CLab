#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "./inc/main.h"

int main(int argc, char **argv)
{
    int rc = ok;

    if (argc == 5 && (strcmp(argv[1], "a") == ok || strcmp(argv[1], "m") == ok))
    {
        FILE *left_mat = fopen(argv[2], "r");
        FILE *right_mat = fopen(argv[3], "r");
        FILE *output = fopen(argv[4], "w");
        if (left_mat && right_mat && output)
        {
            matrix *lhs_mat = get_matrix_from_file(left_mat);
            matrix *rhs_mat = get_matrix_from_file(right_mat);
            matrix *res = NULL;
            if (lhs_mat && rhs_mat)
            {
                if (strcmp(argv[1], "a") == ok)
                {
                    res = addition(lhs_mat, rhs_mat);
                    if (res)
                        add_mat_to_file(res, output);
                    else
                        rc = error;
                }
                else if (strcmp(argv[1], "m") == ok)
                {
                    res = multiplication(lhs_mat, rhs_mat);
                    if (res)
                        add_mat_to_file(res, output);
                    else
                        rc = error;
                }
                else
                    rc = error;
                if (res)
                    free_mat(res);
                free_mat(lhs_mat);
                free_mat(rhs_mat);
            }
            else
                rc = error;
            fclose(left_mat);
            fclose(right_mat);
            fclose(output);
        }
        else
        {
            close_if_opened_file(right_mat);
            close_if_opened_file(left_mat);
            close_if_opened_file(output);
            rc = error;
        }
    }
    else if (argc == 4 && strcmp(argv[1], "o") == ok)
    {
        FILE *matrix_data = fopen(argv[2], "r");
        FILE *output = fopen(argv[3], "w");
        if (matrix_data && output)
        {
            matrix *mat = get_matrix_from_file(matrix_data);;
            if (mat)
            {
                if (gauss_solution(mat) != ok)
                    rc = error;
                else
                    add_solution_to_file(mat, output);
                free_mat(mat);
            }
            else
                rc = error;
            fclose(matrix_data);
            fclose(output);
        }
        else
            rc = error;
    }
    else
        rc = error;
    return rc;
}