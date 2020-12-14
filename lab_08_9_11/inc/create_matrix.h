#ifndef _CREATE_MATRIX_H
#define _CREATE_MATRIX_H

#include <stdlib.h>
#include <stdio.h>

#include "data_structure.h"
#include "error_code.h"

double **get_matrix(const size_t row, const size_t col);
int init_matrix(FILE *input_file, matrix *mat);
matrix *get_matrix_from_file(FILE *input_file);
void fill_zero_mat(matrix *mat);

#endif //_CREATE_MATRIX_H