#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct
{
    int rows;
    int cols;
    int **mat;
} matrix;

enum error_code
{
    ok,
    error
};

matrix *create_matrix(const size_t rows, const size_t cols)
{
    matrix *tmp = malloc(sizeof(matrix));
    if (tmp)
    {
        tmp->rows = rows;
        tmp->cols = cols;
        tmp->mat = malloc(rows * sizeof(int *) + rows * cols * sizeof(int));
        if (tmp->mat)
        {
            for (int i = 0; i < rows; i++)
                tmp->mat[i] = (int *)((char *) tmp->mat + rows * sizeof(int *) + i * cols * sizeof(int));
        }
        else
            free(tmp);
    }
    return tmp;
}

void display_mat(matrix *mat)
{
    for (int i = 0; i < mat->rows; i++)
    {
        for (int j = 0; j < mat->cols; j++)
            printf("%5d ", mat->mat[i][j]);
        printf("\n");
    }
}

int fill_mat(matrix *mat)
{
    int x;
    for (int i = 0; i < mat->rows; i++)
    {
        for (int j = 0; j < mat->cols; j++)
        {
            if (fscanf(stdin, "%d", &x) != 1)
                return error;
            mat->mat[i][j] = x;
        }
    }
    return ok;
}

int cmpint(const void *lhs, const void *rhs)
{
    return *(int *) lhs - *(int *) rhs;
}

void fill_mat_eles_with_arr(matrix *mat, int *arr)
{
    int i, k = 0, l = 0, d = mat->cols * mat->rows - 1; 
  
    int m = mat->rows, n = mat->cols;
  
    while (k < m && l < n) 
    { 
        for (i = l; i < n; ++i) 
        { 
            mat->mat[k][i] = arr[d--];
        } 
        k++; 
  
        for (i = k; i < m; ++i) 
        { 
            mat->mat[i][n - 1] = arr[d--]; 
        } 
        n--; 
       
        if (k < m)
        { 
            for (i = n - 1; i >= l; --i) 
            { 
                mat->mat[m - 1][i] = arr[d--];
            } 
            m--; 
        } 
  
        if (l < mat->cols) 
        { 
            for (i = m - 1; i >= k; --i) 
            { 
                mat->mat[i][l] = arr[d--]; 
            } 
            l++;     
        }         
    } 
}

void fill_arr_ele_with_mat(matrix *mat, int *arr)
{
    for (int i = 0; i < mat->rows; i++)
    {
        for (int j = 0; j < mat->cols; j++)
        { 
            arr[i * mat->cols + j] = mat->mat[i][j];
        }
    }
}

void sort_snake_like_mat(matrix *mat)
{
    int *temp_mat = malloc(mat->rows * mat->cols * sizeof(int));
    if (temp_mat)
    {
        fill_arr_ele_with_mat(mat, temp_mat);
        qsort(temp_mat, mat->rows * mat->cols, sizeof(int), cmpint);
        fill_mat_eles_with_arr(mat, temp_mat);
        free(temp_mat);
    }
}

void free_mat(matrix *mat)
{
    free(mat->mat);
    free(mat);
}

int in_range(int x)
{
    return x > 0 && x < 100;
}

int main()
{
    int m, n, rc = ok;
    if (scanf("%d %d", &m, &n) == 2 && in_range(m) && in_range(n) && m == n)
    {
        matrix *mat = create_matrix(m, n);
        if (mat)
        {
            if (fill_mat(mat) == ok)
            {
                sort_snake_like_mat(mat);
                display_mat(mat);
            }
            else 
            {
                free_mat(mat);
                rc = error;
            }
            free_mat(mat);
        }
        else
            rc = error;
    }
    else
        rc = error;
    return rc;
}