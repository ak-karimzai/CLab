#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

enum error_code
{
    ok,
    error
};

enum logic_condition
{
    false,
    true
};

enum matrix_type
{
    coordinate,
    dimension_mat,
    nothing
};

typedef struct
{
    int row;
    int col;
    double val;
} coordinate_data;

typedef struct 
{
    int row;
    int col;
    double **mat;
} matrix;

double **get_matrix(const int row, const int col)
{
    int rc = error;
    double **mat = malloc(row * sizeof(double *) + row * col * sizeof(double));
    if (mat)
    {
        for (int i = 0; i < row; i++)
            mat[i] = (double *)(char *)(mat + row * sizeof(double *) + row * i * sizeof(double));
        rc = ok;
    }
    return rc == ok ? mat : NULL;
}

// int get_matrix_type(FILE *input_file)
// {
//     int rc = nothing;
//     char *line = NULL;
//     size_t len = 0;
//     ssize_t read = getline(&line, &len, input_file);
//     if (read > 0)
//     {
//         char *temp = strtok(line, " ");
//         int count = 0;
//         while (temp != NULL)
//         {
//             if (atoi(temp))
//                 count++;
//             temp = strtok(NULL, " ");
//         }
//         if (count == 2)
//             rc = dimension_mat;
//         if (count == 3)
//             rc = coordinate;
//     }
//     free(line);
//     rewind(input_file);
//     return rc;
// }

void init_zero_mat(matrix *mat)
{
    for (int i = 0; i < mat->row; i++)
    {
        for (int j = 0; j < mat->col; j++)
            mat->mat[i][j] = 0.0;
    }
}

void display(matrix *mat)
{
    for (int i = 0; i < mat->row; i++)
    {
        for (int j = 0; j < mat->col; j++)
            printf("%lf ", mat->mat[i][j]);
        printf("\n");
    }
    printf("\n\n\n");
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
                        rc = error;
                        break;
                    }
        }
    }
    else
        rc = error;

    if (!(feof(input_file) || fgetc(input_file) == EOF))
        rc = error;

    return rc;
}

void fill_mat_with_coord_data(matrix *mat, coordinate_data *data, int non_zero)
{
    init_zero_mat(mat);
    for (int i = 0; i < non_zero; i++)
        memmove(&mat->mat[data[i].row][data[i].col], &data[i].val, sizeof(double));
}

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

matrix *get_matrix_from_file(FILE *input_file)
{
    int rc = ok;
    matrix *mat = NULL;
   
    // int mat_type = get_matrix_type(input_file); 
    // if (mat_type == coordinate)
    // {
    // mat = malloc(sizeof(matrix));
    // if (mat == NULL)
    //     rc = error;
    // else
    // {
    //     if (init_coordinate_matrix(input_file, mat) != ok)
    //     {
    //         free(mat);
    //         rc = error;
    //     }
    // }
    // }
    // else if (mat_type == dimension_mat)
    // {
    mat = malloc(sizeof(matrix));
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
    // }
    // else
    //     rc = error;
    return rc == ok ? mat : NULL;
}

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
                init_zero_mat(res);
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

void free_mat(matrix *mat)
{
    free(mat->mat);
    free(mat);
}

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

void add_solution_to_file(const matrix *mat, FILE *output)
{
    fprintf(output, "%d 1\n", mat->row);
    for (int i = 0; i < mat->row; i++)
        fprintf(output, "%lf\n", mat->mat[i][mat->row]);
}

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
            rc = error;
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
                // puts("im here");
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
    // printf("%d\n", rc);
    return rc;
}