#include "../inc/free.h"

void free_mat(matrix *mat)
{
    free(mat->mat);
    free(mat);
}

void free_mat_if_not_null(matrix *mat)
{
    if (mat)
        free_mat(mat);
}

void close_if_opened_file(FILE *in)
{
    if (in)
        fclose(in);
}