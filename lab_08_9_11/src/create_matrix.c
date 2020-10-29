#include <stdlib.h>
#include <stdio.h>
#include "../inc/create_matrix.h"

void fill_zero_mat(matrix *mat)
{
    for (int i = 0; i < mat->row; i++)
        for (int j = 0; j < mat->col; j++)
            mat->mat[i][j] = 0.0;
}

double **get_matrix(const int row, const int col)
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
            for (int i = 0; i < mat->row; i++)
                for (int j = 0; j < mat->col; j++)
                    if (fscanf(input_file, "%lf ", &mat->mat[i][j]) != 1)
                    {
                        free(mat->mat);
                        return error;
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


// void fill_mat_with_coord_data(matrix *mat, coordinate_data *data, int non_zero)
// {
//     init_zero_mat(mat);
//     for (int i = 0; i < non_zero; i++)
//         memmove(&mat->mat[data[i].row][data[i].col], &data[i].val, sizeof(double));
// }

// int read_coordinate_data(coordinate_data *data, FILE *input_file, matrix *mat, const int non_zero_elems)
// {
//     int rc = ok;
//     for (int i = 0; i < non_zero_elems; i++)
//     {
//         if (fscanf(input_file, "%d", &data[i].row) == 1)
//         {
//             data[i].row--;
//             if (data[i].row < 0 || data[i].row >= mat->row)
//             {
//                 rc = error;
//                 break;
//             }
//         }
//         else
//         {
//             rc = error;
//             break;
//         }
//     }
//     if (rc == ok)
//     {
//         for (int i = 0; i < non_zero_elems; i++)
//         {
//             if (fscanf(input_file, "%d", &data[i].col) == 1)
//             {
//                 data[i].col--;
//                 if (data[i].col < 0 || data[i].col >= mat->col)
//                 {
//                     rc = error;
//                     break;
//                 }
//             }
//             else
//             {
//                 rc = error;
//                 break;
//             }
//         }
//     }
//     if (rc == ok)
//     {
//         for (int i = 0; i < non_zero_elems; i++)
//         {
//             if (fscanf(input_file, "%lf ", &data[i].val) != 1 || data[i].val == 0)
//             {
//                 rc = error;
//                 break;
//             }
//         }
//     }
//     return rc;
// }

// int init_coordinate_matrix(FILE *input_file, matrix *mat)
// {
//     int rc = ok;
//     int non_zero_elems;
//     if (fscanf(input_file, "%d %d %d", &mat->row, &mat->col, &non_zero_elems) == 3 
//                         && mat->row > 0 && mat->col > 0 && non_zero_elems > 0)
//     {
//         coordinate_data *data = malloc(non_zero_elems * sizeof(coordinate_data));
//         mat->mat = get_matrix(mat->row, mat->col);
//         if (data && mat)
//         {
//             if (read_coordinate_data(data, input_file, mat, non_zero_elems) != ok)
//                 rc = error;
//             else
//                 fill_mat_with_coord_data(mat, data, non_zero_elems);
//             free(data);
//         }
//         else
//             rc = error;
//     }
//     else
//         rc = error;
//     return rc;
// }