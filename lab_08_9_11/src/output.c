#include <stdio.h>
#include <stdlib.h>
#include "../inc/output.h"

void add_mat_to_file(const matrix *mat, FILE *output_file)
{
    fprintf(output_file, "%d %d\n", mat->row, mat->col);
    for (int i = 0; i < mat->row; i++)
    {
        for (int j = 0; j < mat->col; j++)
            fprintf(output_file, "%lf ", mat->mat[i][j]);
        fprintf(output_file, "\n");
    }
}

void add_solution_to_file(const matrix *mat, FILE *output)
{
    fprintf(output, "%d 1\n", mat->row);
    for (int i = 0; i < mat->row; i++)
        fprintf(output, "%lf\n", mat->mat[i][mat->row]);
}