#include "../inc/create_matrix.h"

void fill_zero_mat(matrix *mat)
{
    for (int i = 0; i < mat->row; i++)
        for (int j = 0; j < mat->col; j++)
            mat->mat[i][j] = 0.0;
}

double **get_matrix(const size_t row, const size_t col)
{
    int rc = error;
    double **mat = malloc(row * sizeof(double *) + row * col * sizeof(double));
    if (mat)
    {
        for (int i = 0; i < row; i++)
            mat[i] = (double *)((char *) mat + row * sizeof(double *) + col * i * sizeof(double));
        rc = ok;
    }
    return rc == ok ? mat : NULL;
}

int init_matrix(FILE *input_file, matrix *mat)
{
    int rc = ok;
    if (fscanf(input_file, "%d %d", &mat->row, &mat->col) == 2 && mat->col > 0 && mat->row > 0)
    {
        mat->mat = get_matrix(mat->row, mat->col);
        if (mat->mat)
        {
            for (int i = 0; i < mat->row && rc == ok; i++)
                for (int j = 0; j < mat->col; j++)
                    if (fscanf(input_file, "%lf ", &mat->mat[i][j]) != 1)
                    {
                        free(mat->mat);
                        rc = error;
                    }
        }
        else
            rc = error;
    }
    else
        rc = error;

    if (!(feof(input_file) || fgetc(input_file) == EOF))
        rc = error;

    return rc;
}

matrix *get_matrix_from_file(FILE *input_file)
{
    int rc = ok;
    matrix *mat = malloc(sizeof(matrix));
    if (mat == NULL)
        rc = error;
    else
    {
        if (init_matrix(input_file, mat) != ok)
        {
            free(mat);
            rc = error;
        }
    }
    return rc == ok ? mat : NULL;
}