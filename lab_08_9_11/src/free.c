#include <stdlib.h>
#include <stdio.h>
#include "../inc/free.h"

void free_mat(matrix *mat)
{
    free(mat->mat);
    free(mat);
}

void close_if_opened_file(FILE *in)
{
    if (in)
        fclose(in);
}