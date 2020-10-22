#ifndef _MAIN_H
#define _MAIN_H

#define ACTION 1
#define LHS_MAT 2
#define RHS_MAT 3
#define RESULT 4

#define MATRIX 2
#define SOULUTION 3

#define ADDITION "a"
#define MULTI "m"
#define GAUSS "o"
#define READ "r"
#define WRITE "w"

#include "data_structure.h"
#include "error_code.h"

matrix *addition(const matrix *lhs, const matrix *rhs);
matrix *multiplication(const matrix *lhs, const matrix *rhs);
matrix *get_matrix_from_file(FILE *input_file);
void add_mat_to_file(const matrix *mat, FILE *output_file);
void add_solution_to_file(const matrix *mat, FILE *output);
void free_mat(matrix *mat);
int gauss_solution(matrix *mat);
void close_if_opened_file(FILE *in);
void free_mat_if_not_null(matrix *mat);

#endif //_MAIN_H